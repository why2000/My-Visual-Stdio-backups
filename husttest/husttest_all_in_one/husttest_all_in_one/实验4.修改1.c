//#define NOW
#ifdef NOW
#include<stdio.h>

#define SUM  (a+b)
#define DIF  (a-b)//这两个宏的定义要打上括号，不然会导致计算时优先级错误
#define SWAP(a,b)  t=a, a=b, b=t//这个宏的定义有问题，改成这样能正确实现交换
int main(void)
{
    int a, b, t;//a未定义，在这里补上
    printf("Input two integers a, b:");
    scanf("%d,%d", &a, &b);
    printf("\nSUM=%d\n the difference between square of a and square of b is:%d", SUM, SUM*DIF);
    SWAP(a, b);
    printf("\nNow a=%d,b=%d\n", a, b);
    return 0;
}


#endif
