#include <stdio.h>

#define NUMBER 6

int main(void)
{
    int start = 0;
    int goal = 0;
    int matrix[NUMBER][NUMBER]={
        { 0, 12, 28,  0,  0,  0},
        {12,  0, 10, 13,  0,  0},
        {28, 10,  0, 11,  7,  0},
        { 0, 13, 11,  0,  0,  9},
        { 0,  0,  7,  0,  0,  4},
        { 0,  0,  0,  9,  4,  0}
    }; 

    printf("０：横浜\n");
    printf("１：武蔵小杉\n");
    printf("２：品川\n");
    printf("３：渋谷\n");
    printf("４：新橋\n");
    printf("５：溜池山王\n\n");
      
    printf("出発駅の番号： ");
    scanf("%d",&start);
    printf("到着駅の番号： ");
    scanf("%d",&goal);
    
    
    /* 変数設定・初期化 */
    int i, j, newtimes;
    int fix[NUMBER];
    int times[NUMBER];
    int route[NUMBER];
    int Route[NUMBER];
    
    for(i = 0; i < NUMBER; i++){
        fix[i] = 0;
        times[i] = 99999;
        route[i] = -1;
        Route[i] = -1;
    }
    times[start] = 0;
    
    
    /* 最短経路探索処理 */
    while(1){ 
        i = 0;
        
        /* 未確定の駅を探す */
        while(i < NUMBER){
            if(fix[i] == 0){
                break;
            }
            i++;
        }
        /* すべての駅が確定したので終了 */
        if(i == NUMBER){
            break;
        }
        
        /* 最短距離がより短い駅を探す */
        for(j = i+1; j < NUMBER; j++){
            if((fix[j] == 0) && (times[j] < times[i])){
                i = j;
            }
        }
        
        /* 出発駅からの最短距離を確定する */
        fix[i] = 1;
        for(j = 0; j < NUMBER; j++){
            if((matrix[i][j] > 0) && (fix[j] == 0)){
                newtimes = times[i] + matrix[i][j];
                if(newtimes < times[j]){
                    times[j] = newtimes;
                    route[j] = i;
                }
            }
        }
    }
    
    
    /* 出力値表示 */
    j = 0;
    i = goal;
    while(i != start){
        Route[j] = i;
        i = route[i];
        j++;
    }
    Route[j] = start;
    
    printf("\n最短経路：");
    for(i = j; i >= 0; i--){
        printf("%d,",Route[i]);
    }
    printf("\n所要時間：%d分",times[goal]);
    
    
    return 0;
}