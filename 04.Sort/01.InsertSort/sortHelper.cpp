//
// Created by 25328 on 23/3/27.
//

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "sortHelper.h"
/*交换a和b的元素值*/
void swapElement(Element *a, Element *b) {
    Element tmp;
    memcpy(&tmp, a, sizeof(Element));
    memcpy(a, b, sizeof(Element));
    memcpy(b, &tmp, sizeof(Element));
}
/*产生n个随机数的排序表，值的范围是[low, high]*/
SortTable *generateRandomArray(int n, int low, int high) {
    SortTable *table = new SortTable;
    table->length = n;
    table->data = new Element[n];
    srand(time(NULL) + 1);
    for (int i = 0; i < n; ++i) {
        table->data[i].key = (rand() % (high - low + 1)) + low;
        table->data[i].data = NULL;
    }
    return table;
}
/*产生n个随机交换swapTimes次的有序顺序表*/
SortTable *generateLinearArray(int n, int swapTimes) {
    SortTable *table = new SortTable;
    table->data = new Element[n];
    table->length = n;
    for (int i = 0; i < n; ++i) {
        table->data[i].key = i;
        table->data[i].data = NULL;
    }
    // 在已经有序的排序表中，交换swapTimes次
    srand(time(NULL) + 2);
    for (int i = 0; i < swapTimes; ++i) {
        int pos1 = rand() % n;
        int pos2 = rand() % n;
        swapElement(&table->data[pos1], &table->data[pos2]);
    }
    return table;
}
/* 拷贝一个排序表，使用同样的数据进行不同排序算法的测试 */
SortTable *copySortTable(SortTable *old) {
    SortTable *table = new SortTable;
    table->length = old->length;
    table->data = new Element[old->length];
    for (int i = 0; i < old->length; ++i) {
        table->data[i].key = old->data[i].key;
        table->data[i].data = old->data[i].data;
    }
    return table;
}
/* 释放table */
void releaseSortTable(SortTable *table) {
    if (table) {
        delete[] table->data;
        delete table;
    }
}
// 检查排序表里的数据，是否是从小到大排序
static enum sortStatus checkData(SortTable *table) {
    for (int i = 0; i < table->length - 1; ++i) {
        if (table->data[i].key > table->data[i + 1].key) {
            printf("Check Sort Data Failed: %d : %d\n", table->data[i].key, table->data[i + 1].key);
            return failed;
        }
        else
            return success;
    }
}
/* 测试sortName的排序算法，算法通过sort传递函数名，数据以table传入 */
void testSort(const char *sortName, sortHandler sort, SortTable *table) {
    clock_t start = clock();
    sort(table);
    clock_t end = clock();
    if (checkData(table) == failed) {
        printf("%s failed!\n", sortName);
        return;
    }
    printf("%s cost time: %fs.\n", sortName, (double) (end - start) / CLOCKS_PER_SEC);
}
