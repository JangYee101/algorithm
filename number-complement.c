//title num : 476


#include <stdio.h>

int findComplement(int num)
{

    int tmp = 1;
    while(num > tmp)
    {
        tmp = tmp << 1;
        tmp++;
    }
    return num^tmp;
}



int main()
{
    printf("%d\n",findComplement(5));
    return 0;
}
