//
// Created by 25328 on 23/3/30.
//

#include "bubbleSort.h"
/* 找最大值，把最大值放到了右边，右边变为有序序列
 * */
void bubbleSortV1(SortTable *table) {
    for (int i = 0; i < table->length; ++i) {
        for (int j = 0; j < table->length - i - 1; ++j) {
            if (table->data[j].key > table->data[j + 1].key)
                swapElement(&table->data[j], &table->data[j + 1]);
        }
    }
}

/* 引入是否有序标记，
 *    当发现某一轮冒泡有序时，就退出循环
 * */
void bubbleSortV2(SortTable *table) {
    for (int i = 0; i < table->length; ++i) {
        int isSorted = 1;
        for (int j = 0; j < table->length - i - 1; ++j) {
            if (table->data[j].key > table->data[j + 1].key) {
                swapElement(&table->data[j], &table->data[j + 1]);
                isSorted = 0;
            }
        }
        if (isSorted) break;
    }
}

/* 存下标，作为下次外层循环的标志
 * */
void bubbleSortV3(SortTable *table) {
    int newIndex;
    int n = table->length;
    do {
        newIndex = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (table->data[i].key > table->data[i + 1].key) {
                swapElement(&table->data[i], &table->data[i + 1]);
                newIndex = i + 1;
            }
        }
        n = newIndex;
    } while (newIndex > 0);
}
