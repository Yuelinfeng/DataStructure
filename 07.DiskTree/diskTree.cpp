//
// Created by 25328 on 23/4/13.
//

#include "diskTree.h"
#include <istream>
#include <cstring>

// 从节点中，搜索符合条件的key的位序
static int searchNodePos(BTNode *node, KeyType key) {
    int i = 1;			// 从1号索引开始搜索
    while (i <= node->keyNum && key > node->key[i]) {
        i++;
    }
    return i;
}

DiskBTree *createDiskTree() {
    DiskBTree *bTree = new DiskBTree;
    bTree->root == nullptr;
    bTree->count = 0;
    return bTree;
}
static void destroyBTNode(DiskBTree *tree, BTNode *node) {
    if (node) {
        for (int i = 0; i <= node->keyNum; ++i) {
            destroyBTNode(tree, node->ptr[i]);
        }
        delete node;
    }
}

void releaseDiskBTree(DiskBTree *tree) {
    if (tree) {
        destroyBTNode(tree, tree->root);
        delete tree;
    }
}

/* ========================= 插入节点 ============================ */
/* 将node节点分裂成为两个节点，前一半保留在原节点，后一半移动到other节点
 *  1. 申请新节点，将后半部分信息拷贝到新节点上
 *  2. 新申请的节点的子节点
 * */
static void split(BTNode **node, int s, BTNode **other) {
    int i = s + 1;      // 老节点搬移位置
    int j = 1;          // 新节点待放入的位置
    int n = (*node)->keyNum;
    BTNode  *splitNode = new BTNode;
    memset(splitNode, 0, sizeof(BTNode));
    *other = splitNode;
    splitNode->ptr[0] = (*node)->ptr[s];
    for (; i <= n; ++i) {
        splitNode->key[j] = (*node)->key[i];
        splitNode->ptr[j] = (*node)->ptr[i];
        (*node)->key[i] = 0;
        (*node)->ptr[i] = nullptr;
    }
    splitNode->keyNum = MaxOrder - s;
    splitNode->parent = (*node)->parent;
    for (i = 0; i < n - s; ++i) {
        if (splitNode->ptr[i]) {
            splitNode->ptr[i]->parent = splitNode;
        }
    }
    (*node)->keyNum = s - 1;
}

/* 从节点node的pos处，插入key值
 * 若是上移，child就非空
 * 在叶子节点插入，child就为null
 * */
static void insertNode(BTNode *node, int pos, KeyType key, BTNode *child) {
    // 从节点中，移动pos及pos后的元素，最后再更新pos位置的值
    int i;
    int n = node->keyNum;
    for (i = n; i >= pos; --i) {
        node->key[i + 1] = node->key[i];
        node->ptr[i + 1] = node->ptr[i];
    }
    node->key[pos] = key;
    node->ptr[pos] = child;
    if (child) {
        child->parent = node;
    }
    node->keyNum++;
}

// 创建一个根节点
static BTNode *createRootNode(KeyType key, BTNode *p0, BTNode *p1) {
    BTNode *node = new BTNode;

    node->keyNum = 1;
    node->key[1] = key;
    node->ptr[0] = p0;
    node->ptr[1] = p1;
    if (p0) {
        p0->parent = node;
    }
    if (p1) {
        p1->parent = node;
    }
    node->parent = nullptr;
    return node;
}


//将key值插入到B树中的node节点的pos位序处，根据B树的规则来决定是否分离
static void insertBTree(DiskBTree *tree, KeyType key, BTNode *node, int pos) {
    int mid;
    BTNode *child = nullptr;
    KeyType x = key;
    int finish = 0;
    int needNewRoot = 0;

    if (node) {     // 有父节点，要么直接插入，要么进行分离
        while (!finish && !needNewRoot) {
            insertNode(node, pos, x, child);
            if (node->keyNum < MaxOrder) {
                finish = 1;
            } else {
                mid = (MaxOrder + 1) / 2;
                x = node->key[mid];
                split(&node, mid, &child);
                if (node->parent) {
                    node = node->parent;
                    pos = searchNodePos(node, x);
                }
                else
                {
                    needNewRoot = 1;
                }
            }
        }
    } else {        // 无父节点，现在插入的一定是一个根节点
        tree->root = createRootNode(key, nullptr, nullptr);
        tree->count = 1;
    }
    if (needNewRoot) {
        tree->root = createRootNode(x, node, child);
    }
}

void insertKey(DiskBTree *tree, KeyType key) {
    Result res;
    // 1. 查找key在B树的待插入位置
    searchBTree(tree, key, &res);
    if (res.tag == 1) {
        printf("key %d have exists\n", key);
    } else {
        insertBTree(tree, key, res.ptr, res.pos);
        tree->count++;
    }
}

/* ==================== B树的辅助函数 ==================================== */

void searchBTree(DiskBTree *tree, KeyType key, Result *res) {
    BTNode *cur = tree->root;   // 定义当前节点索引
    BTNode *pre = nullptr;      // 定义指向父节点的索引
    int pos;
    int tag = 0;
    while (cur && !tag) {
        /* 遍历当前节点的所有key值，确定是否在这个节点上
            如果不在这个节点，还要标记出下一个节点的位置*/
        pos = searchNodePos(cur, key);
        if (pos <= cur->keyNum && cur->key[pos] == key) {
            tag = 1;
        } else {
            pre = cur;
            cur = pre->ptr[pos - 1];
        }
    }
    // 查找成功
    if (tag) {
        res->tag = 1;
        res->ptr =cur;
        res->pos = pos;
    } else {
        // 查找失败，把父节点信息更新
        res->tag = 0;
        res->ptr = pre;
        res->pos = pos;
    }
}

void printBTree(const BTNode *node, int tab) {
    if (node == nullptr) {
        return;
    }
    int i;
    for (i = 0; i <= tab; ++i) {
        printf("    ");
    }
    for (i = 1; i <= node->keyNum; ++i) {
        printf("%d", node->key[i]);
        if (i != node->keyNum) {
            printf(", ");
        }
    }
    printf("\n");
    for (i = 0; i <= node->keyNum; ++i) {
        printBTree(node->ptr[i], tab+1);
    }
}
