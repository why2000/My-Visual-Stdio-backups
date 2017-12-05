//#define NOW
#ifdef NOW
#include <stdio.h>
double sum_fac(int n);
int main(void)
{
    int k;
    for (k = 1; k<6; k++)
        printf("k=%d\tthe sum is %lf\n", k, sum_fac(k));
    return 0;
}
double sum_fac(int n){
    double s = 0;
    int i;
    double fac = 1;
    for (i = 1; i <= n; i++) {
        fac /= i;
        s += fac;
    }//要把s+=fac放在循环内部
    return s;
}

#endif
