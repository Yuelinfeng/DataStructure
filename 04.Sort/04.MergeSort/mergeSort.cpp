//
// Created by 25328 on 23/4/2.
//

#include "mergeSort.h"
static void mergeSortRecur(SortTable *table,SortTable *tmp,int l, int r) {
    if (l >= r)
        return;
    int mid = (l + r) >> 1;
    mergeSortRecur(table, tmp, l, mid);
    mergeSortRecur(table, tmp, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (table->data[i].key <= table->data[j].key)
            tmp->data[k++] = table->data[i++];
        else
            tmp->data[k++] = table->data[j++];
    }
    while (i <= mid)
        tmp->data[k++] = table->data[i++];
    while (j <= r)
        tmp->data[k++] = table->data[j++];
    for (int i = l, j = 0; i <= r; ++i, ++j)
        table->data[i] = tmp->data[j];
}
void mergeSort(SortTable *table) {
    SortTable *tmp = copySortTable(table);
    mergeSortRecur(table,tmp,0,table->length);
}
