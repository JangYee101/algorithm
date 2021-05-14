/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：insert_sort.c
*   创 建 者：JangYee
*   创建日期：2021年05月14日
*   描    述：
*
================================================================*/

//先将[:2]变成有序，再将[:3]变成有序。。。。。
//再每次排序时，如果i 和 i-1时有序的，就可以break改成循环了

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
