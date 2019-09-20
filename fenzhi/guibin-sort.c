
#include <stdio.h>

int nums_temp[100];

void guibin_sort(int *nums,int head, int tail){
    printf("%d\t%d\n", head, tail);
    int mid;
    int tmp;
    int i;
    mid = (tail + head) / 2;
    printf("mid is %d\n", mid);
    if(tail != head){
        guibin_sort(nums, head, mid);
        guibin_sort(nums, mid+1, tail);
    }
    int t_p = mid+1, h_p = head;
    int j=0;
    while(1){
        //printf("\n%d\n", t_p);
        if(t_p>tail && h_p>mid) break;
        else if(t_p>tail){
            nums_temp[j++] = nums[h_p++];
        }
        else if(h_p > mid){
            nums_temp[j++] = nums[t_p++];
        }
        else{
        if(nums[h_p] > nums[t_p]){
            nums_temp[j++] = nums[h_p++];
        }
        else{
            nums_temp[j++] = nums[t_p++];
        }}
    }
    for(i=head,j=0;i<=tail;i++,j++){
        nums[i] = nums_temp[j];
    }
    return ;
}


int main(){
    int a[]={2,5,3,9,6,0,1,3,4,2,1,6,7};
    int i;
    guibin_sort(a, 0, 12);
    for(i=0;i<=12;i++){
        printf("%d\n", a[i]);
    }
}
