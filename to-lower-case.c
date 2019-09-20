//title num: 709

#include <stdio.h>

int STEP = 'a' - 'A';

char * toLowerCase(char *str)
{
    char *old_str = str;
    while(*str)
    {
        if('A'<=*str && 'Z'>=*str)
        {
            (*str) += STEP;
        }
        str++;
    }
    return old_str;
}

int main()
{
    char a[100] = "heLLo World!";
    printf("%s\n", toLowerCase(a));
    return 0;
}
