//#define NOW
#ifdef NOW
#include <stdio.h>
int main(void)
{
    int i = 1, n, s = 1;
    printf("Please enter n:");
    scanf("%d", &n);
    while (i <= n) {
        s = s*i;
        i++;
    }
    printf("%d!=%d", n, s);
    return 0;
}

#endif
