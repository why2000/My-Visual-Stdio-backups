//#define NOW
#ifdef NOW
#include<stdio.h>
#include<assert.h>//加上这个头文件
#define  R
int integer_fraction(float x);
int main(void)
{
    float  r, s;
    int s_integer = 0;
    printf("input a number: ");
    scanf("%f", &r);
#ifdef  R
    name = 3.14159*r*r;
    printf("area of round is: %f\n", name);
    s_integer = integer_fraction(name);
    assert((name - s_integer) < 1.0);
    printf("the integer fraction of area is %d\n", s_integer);
#endif
    return 0;
}

int integer_fraction(float x)
{
    int i = x;
    return i;
}


#endif
