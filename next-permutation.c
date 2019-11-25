
#include <stdio.h>




void nextPermutation(int* nums, int numsSize){
    if(numsSize == 1) return ;
    int i,j=numsSize-1;
    int t;
    while(j){
    for(i=numsSize-2;i>0;i--){
        if(nums[j] > nums[i]){
            break;
        }
    }
    j--;
    }
    i = j;
    if(i == 0){
        for(i=0;i<numsSize/2;i+=2){
            t = nums[i];
            nums[i] = nums[numsSize - 1 - i];
            nums[numsSize-1-i] = t;
        }
    }
    else{
        t = nums[i];
        nums[i] = nums[numsSize - 1];
        nums[numsSize-1] = t;
        i++;
        for(;i<numsSize;i++){
            for(j=i+1;j<numsSize;j++){
               // printf("%d:%d\t%d:%d\n",i, nums[i], j,nums[j]);
                if(nums[i] > nums[j]){
                    t = nums[i];
                    nums[i] = nums[j];
                    nums[j] = t;
                }
            }
        }
    }
}


int main(){
    int nums[] = {2,3,1}, i;
    nextPermutation(nums, 3);
    for(i=0;i<3;i++){
        printf("%d\n", nums[i]) ;
    }
    return 0;
}
