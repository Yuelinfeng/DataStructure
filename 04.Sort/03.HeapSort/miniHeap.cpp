//
// Created by 25328 on 23/4/1.
//
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "miniHeap.h"
/* 满足节点的访问行为[i/2, i, 2i, 2i+1] 根节点从1号索引进行存储 */
MiniHeap *createMiniHeap(int n) {
    MiniHeap *heap = new MiniHeap;
    heap->data = new keyType[n+1](); //从1开始算，0空着
    heap->capacity = n;
    heap->len = 0;
    return heap;
}

void releaseMiniHeap(MiniHeap *heap) {
    if (heap) {
        delete[] heap->data;
        delete heap;
    }
}

// -------------------- 二叉堆的插入操作 ---------------------//
// 上移
static void shiftUp(MiniHeap *heap, int k) {
    keyType tmp;
    while (k > 1 && heap->data[k/2] > heap->data[k]) {
        tmp = heap->data[k];
        heap->data[k] = heap->data[k/2];
        heap->data[k/2] = tmp;
        k /= 2;
    }
}
/* 先在最后位置插入元素，
 * 然后通过上移操作，确定这个新元素的位置，保证每个根节点是子节点的最小值 */
void insertMiniHeap(MiniHeap *heap, keyType e) {
    if (heap->len + 1 > heap->capacity) {
        printf("MiniHeap space full!\n");
        return;
    }
    heap->data[++heap->len] = e;
    // 上移操作
    shiftUp(heap, heap->len);
}

static void shiftDown(MiniHeap *heap, int k) {
    keyType tmp;
    while (2 * k <= heap->len) {    // 保证有左孩子
        int index = 2 * k; // 假设最小值（左孩子）
        // 如果右孩子存在，右孩子小于左孩子（右孩子应该大于左孩子）, 说明index要更新
        if (index + 1 <= heap->len && heap->data[index + 1] < heap->data[index]) {
            index++;
        }
        if (heap->data[k] <= heap->data[index])
            break;
        // 发现当前值比左右孩子最小的值还要大
        tmp = heap->data[k];
        heap->data[k] = heap->data[index];
        heap->data[index] = tmp;
        k = index;
    }
}
/* 取出堆顶元素，把堆中的最后一个元素放到堆顶，根据原则下沉 */
keyType extractMiniHeap(MiniHeap *heap) {
    if (heap->len <= 0) {
        printf("No data!\n");
        return 0;
    }
    keyType ret = heap->data[1]; //取出最小堆
    heap->data[1] = heap->data[heap->len]; //把最大值给第一个
    heap->len--;
    shiftDown(heap, 1);
    return ret;
}
