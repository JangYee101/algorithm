#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
    int i, sum_profit=0, single_profit;
    for(i=1;i<pricesSize;i++){
        single_profit = prices[i]-prices[i-1];
        if(single_profit > 0)
            sum_profit += single_profit;
    }
    return sum_profit;
}

int main(){
    int a[] = {7, 1, 5, 3, 6, 4};
    printf("%d\n", maxProfit(a, 6));
    return 0;
}
