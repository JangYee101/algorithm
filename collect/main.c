
#include <stdio.h>

int main(){
    int i;
    char a[10]={0};
    a[0]='1';
    a[1]='2';
    char *p = a;
    while(*(p++))
    {
        printf("%c\n", *p);
    }
    return 0;
}
