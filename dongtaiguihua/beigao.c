
#include <stdio.h>
#include <string.h>

int tmp[10][10];

int bigestValue(int *w, int *v, int lw, int num){
    int i,j,t;
    memset(tmp, 0 , 100);
    for(i=0;i<num;i++){
        for(j=0;j<lw;j++){
            if(j + 1 - w[i] >= 0){
                t = v[i] + tmp[i][j+1-w[i]];
                tmp[i+1][j+1] = tmp[i][j+1] > t ? tmp[i][j+1] : t;
            }
            else{
                tmp[i+1][j+1] = tmp[i][j+1];
            }
            printf("%d ", tmp[i+1][j+1]);

        }
        printf("\n");
    }
    printf("\n\n");
    for(i=1;i<=num;i++){
        for(j=1;j<=lw;j++){
            printf("%d ", tmp[i][j]);
        }
        printf("\n");
    }
    return tmp[i][j];
}



int main(){
    int w[5] = {2, 4, 5, 1, 4};
    int v[5] = {1, 2, 3, 1, 3};
    int limit_w=4;
    printf("\n%d\n", bigestValue(w, v, limit_w, 5));
    return 0;

}
