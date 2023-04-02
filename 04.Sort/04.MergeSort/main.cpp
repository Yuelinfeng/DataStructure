//
// Created by 25328 on 23/4/2.
//
#include "mergeSort.h"
void test01() {
    int n = 10000000;
    SortTable *table1 = generateRandomArray(n,0,n);
    testSort("MergeSort : ", mergeSort, table1);
    releaseSortTable(table1);
}
int main()
{
    test01();
}