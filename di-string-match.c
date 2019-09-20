//title num: 942

not pass

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int * diStringMatch(char * S, int* returnSize)
{
    *returnSize = strlen(S) + 1;
    int *p_data = malloc((*returnSize)*sizeof(int));
    memset(p_data, 0, (*returnSize)*sizeof(int));
    int current_val = 0;
    int i=1;
    p_data[0] = 0;
    while(*S)
    {
        if(*S == 'D')
            p_data[i++] = --current_val;
        else
            p_data[i++] = ++current_val;
        S++;
    }
    return p_data;
}


int main()
{
    int *data;
    int data_length;
    int i;
    char str[100] = "IDID";
    data = diStringMatch(str, &data_length);
    for(i=0;i<data_length;i++)
        printf("%d\n", data[i]);
    free(data);
    return 0;
}
