//title num: 461


#include <stdio.h>

int hammingDistance(int x, int y)
{
    int re = x^y;
    int count=0;
    while(re)
    {
        if(re%2)
        {
            count++;
        }
        re=re>>1;
    }
    return count;
}


int main()
{
    printf("%d\n", hammingDistance(1, 4));
    return 0;
}
