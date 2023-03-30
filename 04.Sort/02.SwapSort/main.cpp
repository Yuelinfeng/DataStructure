//
// Created by 25328 on 23/3/30.
//
#include <cstdio>
#include "bubbleSort.h"
#include "quickSort.h"
void test01() {
    int n = 10000;
    SortTable *table1 = generateRandomArray(n,0,n);
    SortTable *table2 = copySortTable(table1);
    SortTable *table3 = copySortTable(table1);
    testSort("Bubble Sort V1: ",bubbleSortV1,table1);
    testSort("Bubble Sort V2: ",bubbleSortV2,table2);
    testSort("Bubble Sort V3: ", bubbleSortV3, table3);

    releaseSortTable(table3);
    releaseSortTable(table1);
    releaseSortTable(table2);
}
void test02() {
    int n = 10000000;
    SortTable *table1 = generateRandomArray(n,0,n);
    SortTable *table2 = copySortTable(table1);
    SortTable *table3 = copySortTable(table1);
    testSort("Quick Sort : ", quickSort, table1);
    testSort("Quick Sort V1: ", quickSortV1, table1);
    testSort("Quick Sort V2: ", quickSortV2, table1);
    releaseSortTable(table1);
}
int main() {
    test01();
    test02();
}