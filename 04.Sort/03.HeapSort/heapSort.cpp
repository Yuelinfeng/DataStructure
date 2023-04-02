//
// Created by 25328 on 23/4/1.
//

#include "heapSort.h"

void miniHeapSort(SortTable *table) {
    MiniHeap *miniHeap = createMiniHeap(table->length);
    for (int i = 0; i < table->length; ++i) {
        insertMiniHeap(miniHeap,table->data[i].key);
    }
    for (int i = 0; i < table->length; ++i) {
        table->data[i].key = extractMiniHeap(miniHeap);
    }
    releaseMiniHeap(miniHeap);
}
