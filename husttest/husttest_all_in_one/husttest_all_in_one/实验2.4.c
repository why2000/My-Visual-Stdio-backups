//#define NOW
#ifdef NOW
#include<stdio.h>

int main(void) {
    int num = 0, sum = 0;
    int i = 0;
    int place;
    scanf("%d", &num);
    for (i = 0; num != 0; i++) {
        place = num % 10;
        num /= 10;
        sum += place;
        sum *= 10;
    }
    sum /= 10;
    printf("%d\n", sum);
    return 0;
}

#endif
