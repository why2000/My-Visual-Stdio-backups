//#define NOW
#ifdef NOW
#include<stdio.h>
#define MAXLINE 1024
int main(void) {
    int N, x[MAXLINE];
    int i = 0;
    scanf("%d", &N);
    
    for (i = 0; i < N; ++i) {
        int n;
        scanf("%d", &n);
        int j = 0;
        for (j = 0; j < n; j++) scanf("%d", &x[j]);
        for (j = 0; j < n / 2; j++) {
            x[j] ^= x[n - 1 - j];
            x[n - 1 - j] ^= x[j];
            x[j] ^= x[n - 1 - j];
        }
        for (j = 0; j < n; j++) {
            printf("%d", x[j]);
            if (j != n - 1) printf(" ");
            else printf("\n");
        }
        
    }
    return 0;
}
#endif
