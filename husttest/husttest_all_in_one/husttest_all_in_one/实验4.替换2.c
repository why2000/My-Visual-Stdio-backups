//#define NOW
#ifdef NOW
#include<stdio.h>
#define max(x, y, z)    ((x>y)?((x>z)?x:((z>y)?z:y)):(y>z)?y:((z>x)?z:x))
float sum(float x, float y);//ÉùÃ÷sumº¯Êı
int main(void)
{
    int a, b, c;
    float d, e;
    printf("Enter three integers:");
    scanf("%d,%d,%d", &a, &b, &c);
    printf("\nthe maximum of them is %d\n", max(a, b, c));

    printf("Enter two floating point numbers:");
    scanf("%f,%f", &d, &e);
    printf("\nthe sum of them is  %f\n", sum(d, e));
    return 0;
}

float sum(float x, float y)
{
    return x + y;
}



#endif