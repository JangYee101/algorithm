//title num: 1021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *removeOuterParentheses(char *S)
{
    char *temp = calloc(10000, sizeof(char));
    char *old_temp = temp;
    int depth=0;
    while(*S++)
    {
        depth=1;
        while(depth != 0)
        {
            if(*S == '(')
            {
                depth++;
            }
            else if (*S == ')')
            {
                depth--;
            }
            *temp++ = *S++;
        }
        temp--;
    }
    *temp = 0;
    return old_temp;
}

int main()
{
    printf("%s\n", removeOuterParentheses("(()())(())(()(()))"));
    return 0;
}
