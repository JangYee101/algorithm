/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：bubble_sort.c
*   创 建 者：JangYee
*   创建日期：2021年05月13日
*   描    述：
*
================================================================*/

//每次都将最值放在tail，tail--
#include "tools.h"


void bubbleSort(int arr[], int size) {
    printf("---------bubble sort-----------\n");
    int i, j;
    for (i=0;i<size-1;i++) {
        for (j=0;j<size-i-1;j++) {
            if(arr[j]>arr[j+1])
                swap(arr+j, arr+j+1);
        }
    }
}



int main() {
    int array[SIZE];
    commonTest(array, SIZE, bubbleSort);
    return 0;
}
