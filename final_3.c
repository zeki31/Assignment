#include <stdio.h>
#include <math.h>
#include <time.h>

/* i のべき乗の値を power[i] に格納する配列 */
unsigned long power[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};


/* 総当たり的に探す関数 */
void Nomal(void){
    
    unsigned long num = 0;
    unsigned long ans = 0;
    unsigned long x;
    for(x = 1; x < 100000000; x++){
        num = x;
        while(x > 0){
            ans += power[x % 10];
            x /= 10;
        }
        if(num == ans){
            printf("%lu\n", num);
        }
        x = num;
        ans = 0;
    }
    
    return;
}


/* 再帰関数を用いる場合 */

/* i が何個使われているかを kosuu[i] に格納する配列 */
int kosuu[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

/* x に d (= 0, 1,..., 9)が何文字あるか数える関数 */
int Count(unsigned long x, unsigned long d){
    int ret = 0;
    
    if(x == 0){
        return 0;
    }
    else if(x % 10 == d){
        ret = 1;
    }

    ret += Count(x / 10, d);

    return ret;
}

/* 開き直り数か判定する関数 */
void Judge(void) {
    unsigned long ans = 0;

    int i;
    for(i = 1; i < 10; i++) {
        ans += power[i] * kosuu[i];
    }

    for(i = 1; i < 10; i++) {
        if(Count(ans, i) != kosuu[i]) {
            return;
        }
    }

    printf("%lu\n", ans);
    return;
}

/* 実行関数 */
void Superior(int begin, int k) {
    
    if(k > 10){
        return;
    }
    
    int i, j;
    for(i = begin; i < 10; i++){
        kosuu[i] += 1;
        Judge();
        Superior(i, k + 1);
        kosuu[i] -= 1;
    }
}



int main(void)
{
    /* べき乗の値を用意 */
    int i;
    for(i = 1; i < 10; i++){
        power[i] = pow(i, i);
    }
    
    long start, stop;
    double times;
    
    /* 総当たり的に探す場合 */
    start = clock();
    printf("総当たり的に探す場合\n");
    Nomal();            /* 開き直り数は 1, 3435 */
    stop = clock();
    times = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("計算時間：%f秒\n", times);       /* 2.940894秒 */
    
    /* 再帰関数を用いて探す場合 */
    start = clock();
    printf("\n再帰関数を用いて探す場合\n");
    Superior(1, 1);     /* 開き直り数は 1, 3435, 438579088 */
    stop = clock();
    times = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("計算時間：%f秒\n", times);       /* 0.010400秒 */
    
    return 0;
}

