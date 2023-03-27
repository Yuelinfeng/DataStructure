//
// Created by 25328 on 23/3/27.
//

#ifndef DATASTRUCTURE_SORTHELPER_H
#define DATASTRUCTURE_SORTHELPER_H

typedef int keyType;
typedef struct {
    keyType key;    // 查找表中每个数据元素的关键值
    void *data;     // 数据的其他区域
}Element;

typedef struct {
    Element *data;  // 存放查找表中数据元素的首地址
    int length;     // 查找表的元素个数
}SortTable;
enum sortStatus{success, failed};

void swapElement(Element *a, Element *b);                   // 交换元素a和元素b
SortTable *generateRandomArray(int n, int low, int high);   //
SortTable *generateLinearArray(int n, int swapTimes);
SortTable *copySortTable(SortTable *old);
void releaseSortTable(SortTable *table);
// 排序算法函数的别名
typedef void (*sortHandler)(SortTable *);
// 测试sortName的排序算法
void testSort(const char *sortName, sortHandler sort, SortTable *table);
#endif //DATASTRUCTURE_SORTHELPER_H
