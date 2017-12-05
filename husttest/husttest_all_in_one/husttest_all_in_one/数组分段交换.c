//#define NOW
#ifdef NOW
#include<stdio.h>
#include<malloc.h>
int main(void) {
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        int i = 0;
        int *num = (int*)malloc(sizeof(int)*n);
        for (i = n - k; i < n; i++) {
            scanf("%d", &num[i]);
        }
        for (i = 0; i < n - k; i++) {
            scanf("%d", &num[i]);
        }
        for (i = 0; i < n; i++) {
            printf("%d", num[i]);
            if (i != n - 1) {
                printf(" ");
            }
            else {
                printf("\n");
            }
        }
    }
    return 0;
}

#endif
