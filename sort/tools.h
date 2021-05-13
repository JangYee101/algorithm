/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：tool.h
*   创 建 者：JangYee
*   创建日期：2021年05月13日
*   描    述：
*
================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define RANGE_LIMIT 100
#define SIZE 10


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void initArray(int arr[], int size) {
    srandom(time(NULL));
    int i;
    for (i=0;i<size;i++) {
        arr[i] =random() % RANGE_LIMIT;
    }
}

void showArray(int arr[], int size, char sp) {
    int i;
    for (i=0;i<size;i++) {
        printf("%d%c", arr[i], sp);
    }
    printf("\n");
}

void commonTest(int arr[], int size, void (*sort_func) (int [], int)) {
    initArray(arr, size);
    sort_func(arr, size);
    showArray(arr, size, '\n');
}

//int array[SIZE] = {56, 93, 2, 94, 47, 18, 85, 6, 41, 68, 95, 58, 14, 95, 86, 69, 72, 91, 18, 41};
