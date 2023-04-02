#插入排序
add_executable(4-1InsertSort sortHelper.h sortHelper.cpp
        01.InsertSort/insertSort.h 01.InsertSort/insertSort.cpp 01.InsertSort/main.cpp)
#交换排序
add_executable(4-2SwapSort sortHelper.h sortHelper.cpp
        02.SwapSort/bubbleSort.h 02.SwapSort/bubbleSort.cpp 02.SwapSort/main.cpp 02.SwapSort/quickSort.h 02.SwapSort/quickSort.cpp)

#推排序
add_executable(4-3HeapSort sortHelper.cpp sortHelper.h
        03.HeapSort/miniHeap.cpp 03.HeapSort/miniHeap.h 03.HeapSort/main.cpp 03.HeapSort/heapSort.cpp 03.HeapSort/heapSort.h)

# 归并排序
add_executable(4-4MergeSort sortHelper.h sortHelper.cpp
        04.MergeSort/mergeSort.cpp 04.MergeSort/mergeSort.h 04.MergeSort/main.cpp)