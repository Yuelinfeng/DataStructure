//
// Created by 25328 on 23/3/29.
//
#include "insertSort.h"
void test01()
{
    int n = 10000;
    SortTable* table1 = generateRandomArray(n, 0, n);
    SortTable* table2 = generateLinearArray(n,10);
    testSort("random insertSort: ", insertSortV1, table1);
    testSort("linear insertSort: ", insertSortV1, table2);
    releaseSortTable(table1);
}
void test02() {
    int n = 100000;
    SortTable* table1 = generateRandomArray(n, 0, n);
    SortTable* table2 = generateLinearArray(n,10);
    testSort("random insertSort: ", insertSort, table1);
    testSort("linear insertSort: ", insertSort, table2);
    releaseSortTable(table1);
}
void test03() {
    int n = 10000;
    SortTable *table2 = generateLinearArray(n,10);
    SortTable *table1 = generateRandomArray(n,0,n);
    testSort("random insertSort: ", shellSort, table1);
    testSort("linear insertSort: ", shellSort, table2);
}
int main() {
    test01();
    test02();
    test03();
    return 0;
}