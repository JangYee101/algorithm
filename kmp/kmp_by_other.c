/*================================================================
*   Copyright (C) 2021 LuoYe. All rights reserved.
*   
*   文件名称：kmp_by_other.c
*   创 建 者：JangYee
*   创建日期：2021年05月14日
*   描    述：
*
================================================================*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int* getNext(char* p) {
    int* next = malloc(sizeof(int)*strlen(p));
    next[0] = -1;
    int j = 0;
    int k = -1;
    while (j < strlen(p) - 1) {
       if (k == -1 || p[j] == p[k]) {
           if (p[++j] == p[++k]) { // 当两个字符相等时要跳过
              next[j] = next[k];
           } else {
              next[j] = k;
           }
       } else {
           k = next[k];
       }
    }
    return next;

}

int KMP(char * t, char* p) {
    int i = 0; // 主串的位置
    int j = 0; // 模式串的位置
    int len_t = strlen(t);
    int len_p = strlen(p);
    int* next = getNext(p);
    while (i < len_t && j < len_p) {
       if (j == -1 || t[i] == p[j]) { // 当j为-1时，要移动的是i，当然j也要归0
           i++;
           j++;
       } else {
           // i不需要回溯了
           // i = i - j + 1;
           j = next[j]; // j回到指定位置
       }
       //printf("i is %d < %d\nj is %d < %d\n",i, strlen(t), j, strlen(p));
    }
    free(next);
    if (j == strlen(p)) {
       return i - j;
    } else {
       return -1;
    }
}

int main() {
    char *t="jiangye is god, hahaha";
    char *p="is god";
    int res = KMP(t, p);
    int i;
    printf("pos is %d\n", res);
    printf("%s\n", t);
    for(i=0;i<res;i++) printf(" ");
    printf("%s\n", p);
    return 0;
}



