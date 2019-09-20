//title num: 1051

#include <stdio.h>
#include <stdlib.h>

int heightChecker(int * heights, int heightsSize)
{
    int i,j,t,count=0;
    int *p_data = calloc(heightsSize, sizeof(int));
    for(i=0;i<heightsSize;i++)
    {
        p_data[i] = heights[i];
    }
    for(i=0;i<heightsSize;i++)
    {
        for(j=i+1;j<heightsSize;j++)
        {
            if(heights[i]>heights[j])
            {
                t=heights[i];
                heights[i]=heights[j];
                heights[j]=t;
            }
        }
    }
    for(i=0;i<heightsSize;i++)
    {
        //printf("%d  %d\n", heights[i], p_data[i]);
        if(p_data[i] != heights[i])
        {
            count++;
        }
    }
    return count;
}

int heightCheckerOptimize(int *heights, int heightsSize)
{
    int data[101], index_for_data=0;
    int i,count=0;
    memset(data, 0, 100*sizeof(int));
    for(i=0;i<heightsSize;i++)
    {
        data[heights[i]]++;
    }
    for(i=0;i<heightsSize;i++)
    {
        while(data[index_for_data]==0)
        {
            index_for_data++;
        }
        if(index_for_data != heights[i])
        {
            count++;
        }
        data[index_for_data]--;
    }
    return count;
}

int main()
{
    int data[10]={4,1,1,2,1,3};
    printf("%d\n", heightCheckerOptimize(data, 6));
    return 0;
}















