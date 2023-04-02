//
// Created by 25328 on 23/4/1.
//
#include <cstdio>
#include "miniHeap.h"
#include "heapSort.h"
#include "../sortHelper.h"
void test01() {
    int data[]{9,3,7,6,5,1,10,2};
    int n{20};
    MiniHeap *miniHeap = createMiniHeap(n);
    for (int i : data) {
        insertMiniHeap(miniHeap,i);
    }
    printf("array: ");
    for (int i = 1; i <= miniHeap->len; ++i)
        printf("\t%d", miniHeap->data[i]);
    printf("\nextra: ");
    for (int i = 0; i < sizeof(data) / sizeof (data[0]); ++i) {
        printf("\t%d", extractMiniHeap(miniHeap));
    }
//    keyType tmp;
//    do {
//        tmp = extractMiniHeap(miniHeap);
//        printf("\t%d",tmp);
//    } while (tmp);
    releaseMiniHeap(miniHeap);
}
void test02() {
    int n = 1000000;
    SortTable *table1 = generateRandomArray(n,0,n);
    testSort("03.HeapSort: ",miniHeapSort,table1);
    releaseSortTable(table1);
}
int main() {
    test01();
    printf("\n");
    test02();
}