//
// Created by 25328 on 23/4/1.
//

#ifndef DATASTRUCTURE_MINIHEAP_H
#define DATASTRUCTURE_MINIHEAP_H
#include "../sortHelper.h"
// 最小堆的结构，vector
typedef struct {
    keyType *data;      //用顺序存储动态保存堆的数据
    int len;            //约束堆data域的长度, 待插入的位置
    int capacity;       //最大容量
}MiniHeap;

// 产生n个元素的堆空间
MiniHeap *createMiniHeap(int n);

// 释放
void releaseMiniHeap(MiniHeap *heap);
// 插入元素
void insertMiniHeap(MiniHeap *heap, keyType e);
// 提取元素
keyType extractMiniHeap(MiniHeap *heap);
#endif //DATASTRUCTURE_MINIHEAP_H
