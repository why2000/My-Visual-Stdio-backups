//#define NOW
#ifdef NOW
#include<stdio.h>

int gcd(int x, int y)
{
    return y ? gcd(y, x%y) : x;
}
int main(void) {
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    int max = gcd(num1, num2);
    printf("%d\n", max);
    return 0;
}
#endif
