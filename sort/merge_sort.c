/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：merge_sort.c
*   创 建 者：JangYee
*   创建日期：2021年05月14日
*   描    述：
*
================================================================*/

/*
1. 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；
2. 设定两个指针，最初位置分别为两个已经排序序列的起始位置；
3. 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；
4. 重复步骤 3 直到某一指针达到序列尾；
5. 将另一序列剩下的所有元素直接复制到合并序列尾。
*/

#include "tools.h"

typedef struct _HArray {
    int *p;
    int size;
} harray;

harray merge(harray left, harray right) {
    int size = left.size + right.size, i=0;
    int *start_p = left.p;
    int *tarr = malloc(sizeof(int)*size);
    while(left.size && right.size) {
        if (*left.p > *right.p) {
            tarr[i++] = *right.p;
            (right.p)++;
            right.size--;
        }
        else {
            tarr[i++] = *left.p;
            (left.p)++;
            left.size--;
        }
    }
    while(left.size) {
        tarr[i++] = *left.p;
        (left.p)++;
        left.size--;
    }
    while(right.size) {
        tarr[i++] = *right.p;
        (right.p)++;
        right.size--;
    }
    if(i!=size)
        printf("some error!\n");
    for(i=0;i<size;i++)
        *(start_p+i) = tarr[i];
    free(tarr);
    left.size = size;
    left.p = start_p;
    return left;
}

harray _mergeSort(harray harr) {
    if (harr.size < 2)
        return harr;
    harray left, right;
    int mid = harr.size/2;
    left.p = harr.p;
    left.size = mid;
    right.p = harr.p + mid;
    right.size = harr.size - mid;
    return merge(_mergeSort(left), _mergeSort(right));
}

void mergeSort(int arr[], int size) {
    harray harr;
    harr.p = arr;
    harr.size = size;
    _mergeSort(harr);
}

int main() {
    int array[SIZE];
    commonTest(array, SIZE, mergeSort);
    return 0;
}
