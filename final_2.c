#include <stdio.h>
#include <math.h>


double f(double x){
    double y = 0.0;
    y = 2*pow(x, 5) - 8*pow(x, 4) + 20*pow(x, 3) + 50*pow(x, 2) + 150*x - 400;
    return y;
}


double Solution(double limit) {
    double left = 0.0;
    double right = 0.0;
    double mid = 0.0;
    
    if(f(0.0) == 0.0){
        mid = 0.0;
    }
    else if(f(0.0) > 0.0){
        while(f(left) * f(right) > 0.0){
            left -= 10.0;
            if(left < -pow(10.0, 7.0)){break;}
        }
    }
    else{
        while(f(left) * f(right) > 0.0){
            right += 10.0;
            if(right > pow(10.0, 7.0)){break;}
        }
    }
    
    mid = (left + right) / 2.0;
    
    while(f(mid) < -limit || limit < f(mid)){
        if(f(mid) < 0.0){
            left = mid;
        }
        else if(f(mid) > 0.0){
            right = mid;
        }
        mid = (left + right) / 2.0;
    }
    
    return mid;
}


int main(void)
{
    printf("|f(mid)| < 0.1 で打ち切りにしたとき\n");
    printf("x = %.18f\n", Solution(0.1));                            /* x = 1.553039550781250000 */
    printf("f(x) = %.18f\n\n", f(Solution(0.1)));                    /* f(x) = -0.000934021324042078 */
    printf("|f(mid)| < 0.0000000000001 で打ち切りにしたとき\n");
    printf("x = %.18f\n", Solution(0.0000000000001));                /* x = 1.553041956020359438 */
    printf("f(x) = %.18f\n", f(Solution(0.0000000000001)));          /* f(x) = 0.000000000000056843 */
    
    return 0;
}
