//#define NOW
#ifdef NOW
#include <stdio.h>
int main(void)
{
    int i = 1, n, s = 1;
    printf("Please enter n:");
    scanf("%d", &n);
    do {
        s = s*i;
        i++;
    } while (i <= n);
    printf("%d!=%d", n, s);
    return 0;
}

#endif