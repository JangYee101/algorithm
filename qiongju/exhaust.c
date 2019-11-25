/*
three cup is 8, 5, 3, and have 8 water in 8 cup, want to let 8 and 5 cup all have 4 water
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CUP_NUM 3
#define CUP_WATER_INIT {8, 0, 0}
#define CUP_VOLUME {8, 5, 3}
#define VICTORY_STATU {3, 2, 3}
#define LIMIT_DEEPING 100*2

int cup_water_init[CUP_NUM] = CUP_WATER_INIT;
int victory_statu[CUP_NUM] = VICTORY_STATU;
int cup_volume[CUP_NUM] = CUP_VOLUME;

typedef struct cup_status{
    int statu[CUP_NUM];
    struct cup_status *ft_p, *sn_p;
    char history_deed[LIMIT_DEEPING];
}cupStatus;

cupStatus *connectPoint(cupStatus *ft_p){
    cupStatus *son_point = calloc(sizeof(cupStatus),1);
    son_point->ft_p = ft_p;
    son_point->sn_p = NULL;
    strcpy(son_point->history_deed, ft_p->history_deed);
    return son_point;
}


cupStatus *isNextDeed(cupStatus *point, int i, int j){
    if(point->statu[i] > 0 && point->statu[j] < cup_volume[j]){//can deed
        cupStatus *son_point = connectPoint(point);
        int change_val = point->statu[i]<(cup_volume[j]-point->statu[j])?point->statu[i]:(cup_volume[j]-point->statu[j]);
        //printf("%d give %d water %dL\n", i, j, change_val);
        son_point->statu[j] = point->statu[j] + change_val;
        son_point->statu[i] = point->statu[i] - change_val;
        if(i+j == 1)
            son_point->statu[2] = point->statu[2];
        else if(i+j == 2)
            son_point->statu[1] = point->statu[1];
        else
            son_point->statu[0] = point->statu[0];

        //printf("now %d\t%d\t%d\n", son_point->statu[0],son_point->statu[1],son_point->statu[2]);
        int len = strlen(son_point->history_deed);
        son_point->history_deed[len] = i + '0';
        son_point->history_deed[len + 1] = j + '0';
        son_point->history_deed[len + 2] = 0;
        //printf("deed is :%s\n", son_point->history_deed);
        return son_point;
    }
    return NULL;
}

void exhaustForFindCup(cupStatus *point){
    int j,i;

    //printf("%d\t%d\t%d\n", point->statu[0],point->statu[1],point->statu[2]);
    //满足跳过
    for(i=0;i<CUP_NUM;i++){
        if(point->statu[i] != victory_statu[i])
            break;
    }
    if(i == CUP_NUM){//目标达成
        char *p = point->history_deed;
        printf("\nvictory!\n");
        while(*p){//打印过程
            //printf("%d to %d\n", *p-'0',*p);
            //printf("%s\n",p);
            printf("%d --> %d\n",cup_volume[*p - '0'], cup_volume[*(p+1) - '0']);
            p += 2;
        }

        //跳过
        free(point);
        return ;

    }

    //重复跳过
    cupStatus *temp_p = point;
    while(temp_p = temp_p->ft_p){
        for(i=0;i<CUP_NUM;i++){
            if(point->statu[i] != temp_p->statu[i])
                break;
        }
        if(i == CUP_NUM){//重复，跳过
            free(point);
            //printf("repeated\n");
            return ;
        }
    }
    //不跳过
    for(i=0;i<CUP_NUM;i++){
        for(j=i+1;j<CUP_NUM;j++){
            if(temp_p = isNextDeed(point, i, j))
                exhaustForFindCup(temp_p);
            if(temp_p = isNextDeed(point, j, i))
                exhaustForFindCup(temp_p);
        }
    }
    return ;
}


cupStatus * cupInit(){
    int i;
    cupStatus *root;
    root = calloc(sizeof(cupStatus),1);
    for(i=0;i<CUP_NUM;i++){
        root->statu[i] = cup_water_init[i];
    }
    root->ft_p = NULL;
    root->sn_p = NULL;
    memset(root->history_deed, 0, LIMIT_DEEPING);
    return root;
}

int main(){
    cupStatus *root_cup_s;
    root_cup_s = cupInit();
    exhaustForFindCup(root_cup_s);
    return 0;
}


