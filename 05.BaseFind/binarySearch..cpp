//
// Created by 25328 on 23/4/3.
//
#include <cstdlib>
#include <cstdio>
#include <ctime>
typedef int Element;
/* 二分查找
 * 空间有序，在闭区间搜索，就是不断地确定区间的范围 [0...n-1]
 * 确定left和right的区间，定位中间值，根据中间值来更新left和right
 * */
int binarySearch(const Element *arr, int n, Element target) {
    int l = -1;
    int r = n;
    while (l + 1 != r) {
        int mid = (l + r) >> 1;
        if (arr[mid] < target) l = mid;
        else r = mid;
    }
    if (arr[r] == target) return r;
    else return -1;
}
int binarySearch2(const Element *arr, int n, Element target) {
    int left = 0;
    int right = n -1;
    int mid;
    while (left <= right) {
        mid = (left + right) >> 1;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
int normalSearch(const Element *arr, int n, Element target) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            return 0;
        }
    }
    return -1;
}
int main() {
    int arr[] = {1,2,3,4,5,6};
    printf("%d",binarySearch(arr,6,-1));
    return 0;
}