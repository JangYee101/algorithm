/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：insert_sort.c
*   创 建 者：JangYee
*   创建日期：2021年05月14日
*   描    述：
*
================================================================*/


#include "tools.h"

void insertSort(int arr[], int size) {
    int i, j;
    for(i=1;i<size;i++) {
        for(j=i;j>0;j--) {
            if(arr[j] < arr[j-1])
                swap(arr+j, arr+j-1);
            else
                break;
        }
    }
}

int main() {
    int array[SIZE];
    commonTest(array, SIZE, insertSort);
    return 0;
}
