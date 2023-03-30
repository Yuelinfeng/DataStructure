//
// Created by 25328 on 23/3/29.
//

#include "insertSort.h"
// ++ 和 --
void insertSortV1(SortTable *table) {
    for (int i = 1; i < table->length; ++i) {
        // 每个无序区域里的值，不断的和前面元素进行交换
        Element e = table->data[i];
        int j;
        // j 始终指向要插入的元素值，与前面的 有序数列 进行比较
        for (j = i; j > 0 && table->data[j - 1].key > e.key; --j) {
            swapElement(&table->data[j], &table->data[j - 1]);
        }
        table->data[j] = e;
    }
}

/* 1. 默认第一个元素就是有序，那么从第二个元素开始和前面有序的区域进行比较
 * 2. 待插入的元素i，和有序区域从后往前依次查找
 *      若待插入元素的值 < 已经有序区域的值，则后移一位
 *      插入查找的位置：[0...i-1]
 * */
void insertSort(SortTable *table) {
    for (int i = 1; i < table->length; ++i) {
        if (table->data[i].key < table->data[i - 1].key) {
            // 用j辅助值来找到插入元素的真正位置
            int j = i - 1;
            Element temp = table->data[i];
            // 查找正确插入位置
            for (; j > -1 && table->data[j].key > temp.key; --j) {
                table->data[j + 1] = table->data[j];
            }
            table->data[j + 1] = temp;
        }
    }
}

void shellSort(SortTable *table) {
    int gap;
    //gap为步长，每次减少一半，直到等于1
    for (gap = table->length / 2; 0 < gap ; gap /= 2) {
        for (int i = gap; i < table->length; ++i) {
            Element temp = table->data[i];
            int j;
            for (j = i; j >= gap && table->data[j - gap].key > temp.key; j -= gap) {
                swapElement(&table->data[j], &table->data[j - gap]);
            }
            table->data[j] = temp;
        }
    }
}
