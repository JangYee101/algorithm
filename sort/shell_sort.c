/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：shellSort.c
*   创 建 者：JangYee
*   创建日期：2021年05月14日
*   描    述：希尔排序，就是一个高级的插入排序
*
================================================================*/

/*
1. 选择一个增量序列 t1，t2，……，tk，其中 ti > tj, tk = 1；
2 .按增量序列个数 k，对序列进行 k 趟排序；
3. 每趟排序，根据对应的增量 ti，将待排序列分割成若干长度为 m 的子序列，分别对各子表进行直接插入排序。仅增量因子为 1 时，整个序列作为一个表来处理，表长度即为整个序列的长度。
*/

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
