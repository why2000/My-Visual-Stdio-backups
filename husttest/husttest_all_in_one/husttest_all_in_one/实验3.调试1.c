//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void)
{
    int i, k;
    long sum = 0, *p = &sum;  /* 声明p为长整型指针，指向sum  */
    scanf("%d", &k);
    for (i = 1; i <= k; i++) {
        sum += fabonacci(i);
        printf("i=%d\tthe sum is %ld\n", i, *p);  /*  *p等价于sum  */
    }
    return 0;
}
long fabonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fabonacci(n - 1) + fabonacci(n - 2);
}


#endif
