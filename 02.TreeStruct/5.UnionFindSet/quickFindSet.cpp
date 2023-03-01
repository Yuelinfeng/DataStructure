//
// Created by 25328 on 2023/2/28.
//

#include "quickFindSet.h"

QuickFindSet *createQuickFindSet(int n) {
    QuickFindSet *setQF = new QuickFindSet;
    setQF->n = n;
    setQF->data = new Element[n];
    setQF->groupID = new Element[n];
    return setQF;
}

void initQuickFindSet(QuickFindSet *setQF, const Element *data, int n) {
    for (int i = 0; i < n; ++i) {
        setQF->data[i] = data[i];   //元素的赋值
        setQF->groupID[i] = i;      //第i个元素组id就是i
    }
}

void releaseQuickFinSet(QuickFindSet *setQF) {
    if (setQF)
    {
        if (setQF->data)
            delete setQF->data;
        if (setQF->groupID)
            delete setQF->groupID;
        delete setQF;
    }
}

static int findIndex(QuickFindSet *setQF, Element a)
{
    if (setQF)
        for (int i = 0; i < setQF->n; ++i) {
            if (setQF->data[i] == a)
                return i;           //返回索引号
        }
    // 找不到该元素
    return -1;
}
int isSameQF(QuickFindSet *setQF, Element a, Element b) {
    // 把元素转换为并查集中对应的索引号
    int aIndex = findIndex(setQF,a);    // a对应的索引号
    int bIndex = findIndex(setQF,b); // b对应的索引号
    if (aIndex == -1 || bIndex == -1)
        return -1;
    // 根据索引号，找到元素a和b的组ID，如果ID相等，在一个集合
    return setQF->groupID[aIndex] == setQF->groupID[bIndex];
}

// 将元素a和b合并，把所有和b元素组信息修改为a的组ID，把b元素合并到a
void unionQF(QuickFindSet *setQF, Element a, Element b) {
    if (isSameQF(setQF,a,b) == 1)
        return;
    int aIndex = findIndex(setQF,a);
    int bIndex = findIndex(setQF,b);
    const int bGrpID = setQF->groupID[bIndex];
    // 将所以和b老大相同的元素的老大修改为a的老大
    for (int i = 0; i < setQF->n; ++i) {
        if (bGrpID == setQF->groupID[i])
            setQF->groupID[i] = setQF->groupID[aIndex];
    }
}
