#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* バブルソート */
void bubble(int a[], int n){
    int k, i;
    int tmp = 0;
    for(k = 1; k <= (n-1); k++){
        for(i = 0; i <= (n-k-1); i++){
            if(a[i] > a[i+1]){
                tmp = a[i];
                a[i] = a[i+1];
                a[i+1] = tmp;
            }
        }
    }
}

/* シェルソート */
void shell(int a[], int n){
    int gap, i, j;
    int tmp = 0;
    for(gap = n/2; gap > 0; gap /= 2){
        for(i = gap; i < n; i++){
            for(j = i-gap; j >= 0 && a[j] > a[j+gap]; j -= gap){
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        }
    }
    
}

/* クイックソート */
void quick(int a[], int left, int right){
    int pl = left;
    int pr = right;
    int x = a[(left + right) / 2];
    int tmp = 0;
    
	do {
		while (a[pl] < x) pl++;
		while (a[pr] > x) pr--;
		if (pl <= pr) {
			tmp = a[pl];
			a[pl] = a[pr];
			a[pr] = tmp;
			pl++;
			pr--;
		}
	} while (pl <= pr);
	
	if (pr > left){
	    quick(a, left, pr);
	}
	
	if (pl < right){
	    quick(a, pl, right);
	}
}




int main(void)
{
    
    /*2桁の正の整数をランダムにnx個生成*/
    int i, nx;
    int *x;
    x = calloc(nx, sizeof(int));
    srand((unsigned int)time(NULL));
    for(i=0; i < nx; i++){
        x[i]=rand()%100 + 1;
    }
  
    long start, end;
    double times;
  
    /* 配列xをバブルソート */
    start = clock();
    bubble(x, nx);
    end = clock();
    times = (double)(end - start) / CLOCKS_PER_SEC;
    printf("バブルソート　：%f秒\n", times);
    
  
    /* 配列xをシェルソート */
    start = clock();
    shell(x, nx);
    end = clock();
    times = (double)(end - start) / CLOCKS_PER_SEC;
    printf("シェルソート　：%f秒\n", times);
  
    /* 配列xをクイックソート */
    start = clock();
    quick(x, 0, nx - 1);
    end = clock();
    times = (double)(end - start) / CLOCKS_PER_SEC;
    printf("クイックソート：%f秒\n", times);
   
    
    return 0;
}
