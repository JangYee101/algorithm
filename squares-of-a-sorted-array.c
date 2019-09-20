//title num: 977

//not pass

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int* sortedSquares(int* A, int ASize, int* returnSize)
{
    int * ret_A = malloc(ASize*sizeof(int));
    *returnSize = ASize;
    int tail, head, i, index_for_ret=0;
    for(i=0;i<ASize;i++)
    {
        if(A[i]>=0)
        {
            head = i;
            tail = i - 1;
            break;
        }
    }
    while(true)
    {
        if(tail>=0 && head<ASize)
        {
            if(A[head] > abs(A[tail]))
            {
                ret_A[index_for_ret] = A[tail--];
            }
            else
            {
                ret_A[index_for_ret] = A[head++];
            }
        }
        else if(tail<0 && head >=ASize)
        {
            break;
        }
        else
        {
            if(tail>=0)
            {
                ret_A[index_for_ret] = A[tail--];
            }
            else
            {
                ret_A[index_for_ret] = A[head++];
            }
        }
        ret_A[index_for_ret] = ret_A[index_for_ret] * ret_A[index_for_ret];
        index_for_ret++;
    }
    return ret_A;
}


int main()
{
    int data[100] = {-4,-1,0,3,10};
    /*int ii=0,aaa=data[ii++];
    printf("%d\n", aaa);
    exit(0);*/
    int i, *ptr, ptrSize;
    ptr = sortedSquares(data, 5, &ptrSize);
    for(i=0;i<ptrSize;i++)
    {
        printf("%d\n", ptr[i]);
    }
    return 0;
}








