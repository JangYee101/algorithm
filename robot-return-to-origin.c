//title num: 657

#include <stdio.h>
#include <stdbool.h>


bool judgeCircle(char *moves)
{
    int ud=0, lr=0;
    while(*moves)
    {
        switch(*moves)
        {
            case 'U':
                ud++;
                break;
            case 'D':
                ud--;
                break;
            case 'L':
                lr--;
                break;
            case 'R':
                lr++;
                break;
            default :
                printf("'%d' is a bad char!\n", *moves);
                break;
        }
        moves++;
    }
    if(ud==0 && lr==0)
        return true;
    return false;
}

int main()
{
    if(judgeCircle("UDRL"))
        printf("true\n");
    else
        printf("false");
    return 0;
}
