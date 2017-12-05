//#define NOW
#ifdef NOW
#include <stdio.h>
long sum_fac(int n);
int main(void)
{
    int k;
    for (k = 1; k<6; k++)
        printf("k=%d\tthe sum is %ld\n", k, sum_fac(k));
    return 0;
}


long sum_fac(int n)
{
    static int s = 0, fac = 1, i = 1;//static
    fac *= i;
    s += fac;
    i++;
    return s;
}

#endif
