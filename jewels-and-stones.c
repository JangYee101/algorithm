//title num:771

#include <stdio.h>


int numJewelsInStones(char *J, char *S)
{
    int i, j, num=0;
    char *p_j;
    while(*S)
    {
        p_j = J;
        while(*p_j)
        {
            if(*p_j == *S)
            {
                num++;
                break;
            }
            p_j++;
        }
        S++;
    }
    return num;
}

int main()
{
    char jewels[100]="aA", stones[100]="aAbAbbb";
    printf("%d\n", numJewelsInStones(jewels, stones));
    return 0;
}
