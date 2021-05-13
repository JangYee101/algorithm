/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：shellSort.c
*   创 建 者：JangYee
*   创建日期：2021年05月14日
*   描    述：希尔排序，就是一个高级的插入排序
*
================================================================*/


#include "tools.h"

void shellSort(int arr[], int size) {
    int i, j, gap=1;
    while(gap < size/3)
        gap = 3*gap + 1;
    for(; gap>0; gap=gap/3) {
        for(i=gap; i<size; i++) {
            for(j=i-gap; j>=0 && arr[j] > arr[j+gap] ;j-=gap) {
                swap(&arr[j], &arr[j+gap]);
            }
        }
    }
}

int main() {
    int array[SIZE];
    commonTest(array, SIZE, shellSort);
    return 0;
}
