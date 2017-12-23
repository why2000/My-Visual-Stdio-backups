//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void)
{
    float f;//先声明一个浮点变量
    float *p = &f;//必须先让p指向一个已被分配地址的浮点变量的地址
    scanf("%f", p);
    printf("%f\n", *p);
    return 0;
}


#endif
