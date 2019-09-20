
#include <stdio.h>



int maxSubArray(int* nums, int numsSize){
    int i;
    int max=0;
    int sum=0;
    for(i=0;i<numsSize;i++){
        if(max < sum) max = sum;
        sum += nums[i];
        if(sum < 0)
            sum = 0;
    }
    max = max>sum?max:sum;
    return max;
}



int main(){
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    printf("%d\n", maxSubArray(a, 9));
    return 0;
}
