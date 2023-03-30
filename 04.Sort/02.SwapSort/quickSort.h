//
// Created by 25328 on 23/3/30.
//

#ifndef DATASTRUCTURE_QUICKSORT_H
#define DATASTRUCTURE_QUICKSORT_H
#include "../sortHelper.h"
#include <ctime>
#include <cstdlib>
static void quickSortRecur(SortTable *table, int l, int r) {
    if (l >= r) return;
    int x = table->data[(l + r) >> 1].key;
    int i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (table->data[i].key < x);
        do j--; while (table->data[j].key > x);
        if (i < j) swapElement(&table->data[i],&table->data[j]);
    }
    quickSortRecur(table,l,j);
    quickSortRecur(table, j + 1 ,r);
}
void quickSort(SortTable *table);

void quickSortV1(SortTable *table);
void quickSortV2(SortTable *table);
#endif //DATASTRUCTURE_QUICKSORT_H