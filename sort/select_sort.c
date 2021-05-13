/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：select_sort.c
*   创 建 者：JangYee
*   创建日期：2021年05月14日
*   描    述：
*
================================================================*/


#include "tools.h"


void selectSort(int arr[], int size) {
    int i, j, min_index;
    for(i=0;i<size;i++) {
        min_index = i;
        for(j=i+1;j<size;j++) {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        if (min_index != i)
            swap(arr+i, arr+min_index);
    }
}



int main() {
    int array[SIZE];
    commonTest(array, SIZE, selectSort);
    return 0;
}
