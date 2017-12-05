#define NOW
#ifdef NOW
#include<stdio.h>

int gcd(int x, int y)
{
    return y ? gcd(y, x%y) : x;
}
int main(void) {
    int num1, num2;
    while ((scanf("%d %d", &num1, &num2), !(num1 == 0 && num2 == 0))) {
        int max = gcd(num1, num2);
        int min = num1*num2 / max;
        printf("%d %d\n", max, min);
    }
    return 0;
}
#endif
