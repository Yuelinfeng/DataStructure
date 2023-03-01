//
// Created by 25328 on 2023/3/1.
//

#include "quickUnion.h"

QuickUnionSet *createQuickUnionSet(int n) {
    QuickUnionSet *setQU = new QuickUnionSet;
    setQU->n = n;
    setQU->parent = new int[n];
    setQU->data = new int[n];
    setQU->size = new int[n];
    return setQU;
}

void releaseQuickUnionSet(QuickUnionSet *setQU) {
    if (setQU)
    {
        if(setQU->size)
            delete setQU->size;
        if(setQU->data)
            delete setQU->data;
        if(setQU->parent)
            delete setQU->parent;
    }
}

void initQuickUnionSet(QuickUnionSet *setQU, const int *data, int n) {
    if(setQU)
    {
        for (int i = 0; i < n; ++i) {
            setQU->data[i] = data[i];
            setQU->parent[i] = i;
            setQU->size[i] = 1;
        }

    }
}

static int findIndex(QuickUnionSet *setQF, int a)
{
    if (setQF)
        for (int i = 0; i < setQF->n; ++i) {
            if (setQF->data[i] == a)
                return i;           //返回索引号
        }
    // 找不到该元素
    return -1;
}
// 找e的父亲，再找这个父亲的父亲，直到发现父亲的父亲是自己，那就是根了
// 普通的查找根节点的方式
/*static int findRootIndex(QuickUnionSet *setQU, int e)
{
    if(setQU)
    {
        int curIndex = findIndex(setQU, e); //
        if(curIndex == -1)
            return -1;
        // 向上遍历,直到找到最终的根节点
        while (setQU->parent[curIndex] != curIndex) // 当前的索引号不等于本身，则还不是根节点
            curIndex = setQU->parent[curIndex];     // 将当前

        return curIndex;
    }
    return -1;
}*/
static SetStack *push(SetStack *stack, int index)
{
    SetStack *node = new SetStack;
    node->index = index;
    node->next = stack;
    return node;
}
static SetStack *pop(SetStack *stack, int *index)
{
        SetStack *tmp = stack;
        *index = stack->index;
        stack = stack->next;
        delete tmp;
        return stack;
}
// 带路径压缩的查找算法，向上查找时，记录路径的信息，然后再恢复，将所有路径的元素的父节点都指向根节点
static int findRootIndex(QuickUnionSet *setQU, int e) {
    int curIndex = findIndex(setQU,e);  // 找到当前的父节点的索引
    SetStack *path = nullptr;
    while (setQU->parent[curIndex] != curIndex) // 找到最终的根节点
    {
        path = push(path,curIndex);
        curIndex = setQU->parent[curIndex];
    }
    while (path != nullptr) {
        int pos{};
        path = pop(path,&pos);
        setQU->parent[pos] = curIndex;  //此时curIndex就是根，将pos位置的父节点更换为根节点
    }
    return curIndex;
}
int isSameQU(QuickUnionSet *setQU, const int a, const int b) {
    // 先找到a和b的根节点
    int aRoot = findRootIndex(setQU,a);
    int bRoot = findRootIndex(setQU,b);
    if (aRoot == -1 || bRoot == -1)
        return -1;
    return aRoot == bRoot;
}

/*
 * 1. 找到a和b的根节点
 * 2. 将b的父节点指向a的索引
 * 根据size做优化
 *      谁的元素多，就将另一个接入元素多的根
 * */
void unionQU(QuickUnionSet *setQU, int a, int b) {
    int aRoot = findRootIndex(setQU,a);
    int bRoot = findRootIndex(setQU,b);
    if (aRoot == -1 || bRoot == -1)
        return;
    if (aRoot == bRoot)
        return;
    // 根据根节点元素个数来决定合并顺序
    int aSize = setQU->size[aRoot]; // a的根节点有多少个小弟
    int bSize = setQU->size[bRoot]; // b的根节点有多少个小弟
    if (aSize >= bSize) {
        setQU->parent[bRoot] = aRoot;
        setQU->size[aRoot] += bSize;
    }else {
        setQU->parent[aRoot] = bRoot;
        setQU->size[bRoot] += aSize;
    }
}
