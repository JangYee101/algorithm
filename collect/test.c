
#include <stdio.h>


enum DAY{
    ONE,
    TWO
};
enum NUM{
    ONEE,
    TURE
};
int main(){
    enum DAY day = 11;
    enum NUM num = 1;
    printf("%d\n", day);
    if(num == TURE) printf("yess\n");
    return 0;
}
