/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：quick_sort.c
*   创 建 者：JangYee
*   创建日期：2021年05月14日
*   描    述：
*
================================================================*/

/*
1. 从数列中挑出一个元素，称为 “基准”（pivot）;
2. 重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；
3. 递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；
*/

#include "tools.h"

int rangePart(int arr[], int headI, int tailI) {
    int t;
    while(headI < tailI) {
        t = arr[headI];
        while(headI < tailI && arr[tailI]>t) {
            tailI--;
        }
        arr[headI] = arr[tailI];
        while(headI < tailI && arr[headI]<=t) {
            headI++;
        }
        arr[tailI] = arr[headI];
        arr[headI] = t;
    }
    return headI;
}

void _quickSort(int arr[], int headI, int tailI) {
    if (headI >= tailI)
        return ;
    int midI = rangePart(arr, headI, tailI);
    _quickSort(arr, headI, midI-1);
    _quickSort(arr, midI+1, tailI);
}

void quickSort(int arr[], int size) {
    _quickSort(arr, 0, size-1);
}

int main() {
    int array[SIZE];
    commonTest(array, SIZE, quickSort);
    return 0;
}
