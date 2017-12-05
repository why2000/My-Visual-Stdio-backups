#include <stdio.h>
#include<malloc.h>
int main(void)
{
    int i, j, t, n;
    scanf("%d", &n);
    while (n != 0)
    {
        int *a;
        a = (int*)malloc(sizeof(int)*n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - 1; j++)
            {
                if (a[n - 1 - i] >= a[n - 2 - j - i]);
                else {
                    t = a[n - 1 - i];
                    a[n - 1 - i] = a[n - 2 - j - i];
                    a[n - 2 - j - i] = t;
                }
            }

        }
        for (i = 0; i < n; i++)
        {
            if (i < n - 1)
                printf("%d ", a[i]);
            else
                printf("%d\n", a[i]);
        }
        scanf("%d", &n);
    }
    return 0;
}