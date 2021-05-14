/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：heap_sort.c
*   创 建 者：JangYee
*   创建日期：2021年05月14日
*   描    述：
*
================================================================*/

/*
1. 构造大顶堆，父节点大于子节点
2. 遍历执行：swap(a[0], a[tail]), tail--；（每次将最大数放在tail上，再tail--）
*/

#include "tools.h"

void heapify(int arr[], int i, int size) {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int maxI = i;
    if(left < size && arr[maxI] < arr[left]) {
        maxI = left;
    }
    if(right < size && arr[maxI] < arr[right]) {
        maxI = right;
    }
    if(maxI != i) {
        swap(&arr[i], &arr[maxI]);
        heapify(arr, maxI, size);
    }
}

//构造大顶堆
void _createBigHeap(int arr[], int size) {
    int i=size/2;
    for(;i>=0;i--) {
        heapify(arr, i, size);
    }
}

void heapSort(int arr[], int size) {
    _createBigHeap(arr, size);
    int i;
    for(i=0;i<size;i++) {
        swap(&arr[size-i-1], &arr[0]);
        heapify(arr, 0, size-i-1);
    }
}

int main() {
    int array[SIZE];
    commonTest(array, SIZE, heapSort);
    return 0;
}
