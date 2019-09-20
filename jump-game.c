#include <stdio.h>
#include <stdbool.h>

bool canJump(int *nums, int numSize){
    int i, cur_len, cur_site=0, next_jump_len, next_size;
    if(numSize <= 1) return true;
    while(1){
        printf("%d\t%d\n", cur_site, nums[cur_site]);
        if(nums[cur_site] <= 0) return false;
        next_jump_len = 0;
        for(i=cur_site+1; i<=nums[cur_site]+cur_site;i++){
            if(i >= numSize - 1) return true;
            cur_len = i + nums[i];
            if(cur_len >= next_jump_len){
                next_jump_len = cur_len;
                next_size = i;
            }
        }
        cur_site = next_size;
    }
}

int main(){
    int a[] = {2,0};
    if(canJump(a, 2))
        printf("true\n");
    else
        printf("false\n");
    return 0;

}
