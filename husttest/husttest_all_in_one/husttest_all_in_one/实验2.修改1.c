//#define NOW
#ifdef NOW
#include <stdio.h>
int   main(void)
{
    int i, n, s = 1;
    printf("Please enter n:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        s = s*i;
    printf("%d! = %d", n, s);
    return 0;
}

#endif
