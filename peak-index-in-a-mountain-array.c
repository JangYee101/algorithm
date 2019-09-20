//title num : 852


#include <stdio.h>

int peakIndexInMountainArray(int* A, int ASize)
{
    int head=0, tail=ASize-1, middle;
    while(1)
    {
        middle = (head + tail) / 2;
        if(A[middle] > A[middle+1] && A[middle] > A[middle-1])
        {
            return middle;
        }
        else if(A[middle-1] < A[middle])
        {
            head = middle;
        }
        else
        {
            tail = middle;
        }
    }
}

int main()
{
    int data[1000]={0,2,1,0}, data_size=4;
    printf("%d\n", peakIndexInMountainArray(data, data_size));
    return 0;
}
