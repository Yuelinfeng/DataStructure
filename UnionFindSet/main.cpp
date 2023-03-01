//
// Created by 25328 on 2023/3/1.
//
#include <iostream>
#include "quickFindSet.h"
#include "quickUnion.h"
int test01()
{
    int n = 9;
    QuickFindSet *QFSet = createQuickFindSet(n);
    Element data[9];
    for (int i = 0; i < sizeof(data)/sizeof(data[0]); ++i) {
        data[i] = i;
    }
    initQuickFindSet(QFSet,data,n);
    unionQF(QFSet, 3,4);
    unionQF(QFSet,8,0);
    unionQF(QFSet,2,3);
    unionQF(QFSet,5,6);
    if (isSameQF(QFSet,0,2)) {
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    if (isSameQF(QFSet,2,4)) {
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    unionQF(QFSet,5,1);
    unionQF(QFSet,7,3);
    unionQF(QFSet,1,6);
    unionQF(QFSet,4,8);
    if (isSameQF(QFSet,0,2)) {
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    if (isSameQF(QFSet,2,4)) {
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    releaseQuickFinSet(QFSet);
}
int test02()
{
    int n = 9;

    QuickUnionSet *setQU = createQuickUnionSet(n);
    int data[9];
    for (int i = 0; i < n; ++i) {
        data[i] = i;
    }
    initQuickUnionSet(setQU,data,n);
    unionQU(setQU,3,4);
    unionQU(setQU,8,0);
    unionQU(setQU,2,3);
    unionQU(setQU,5,6);
    if (isSameQU(setQU,0,2))
        printf("Yes\n");
    else
        printf("No\n");
    if (isSameQU(setQU,2,4))
        printf("Yes\n");
    else
        printf("No\n");
    unionQU(setQU,5,1);
    unionQU(setQU,7,3);
    unionQU(setQU,1,6);
    unionQU(setQU,4,8);
    if (isSameQU(setQU,0,2))
        printf("Yes\n");
    else
        printf("No\n");
    if (isSameQU(setQU,2,4))
        printf("Yes\n");
    else
        printf("No\n");
    releaseQuickUnionSet(setQU);
}
int main()
{
    test01();
    test02();
}