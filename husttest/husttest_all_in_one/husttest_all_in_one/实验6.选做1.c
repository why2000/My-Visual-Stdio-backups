//#define NOW
#ifdef NOW
#include<stdio.h>
#define N 20
#define M 10
int main(void) {
    int inter[3][N] = { 0 };
    int flo[3][M] = { 0 };
    int i, f;
    printf("Please enter the first number:\n");
    for (i = 0; i < N; i++)inter[0][i] = getchar() - '0';
    getchar();
    for (f = 0; f < M; f++)flo[0][f] = getchar() - '0';
    getchar();
    printf("Please enter the second number:\n");
    for (i = 0; i < N; i++)inter[1][i] = getchar() - '0';
    getchar();
    for (f = 0; f < M; f++)flo[1][f] = getchar() - '0';
    getchar();
    int flag = 0;
    for (f = M - 1; f >= 0; f--) {
        flo[2][f] += flo[0][f] + flo[1][f];
        while (flo[2][f] >= 10) {
            flo[2][f] -= 10;
            if (f != 0) {
                flo[2][f - 1] += 1;
            }
            else {
                inter[2][N - 1] += 1;
            }
        }
    }
    for (i = N - 1; i >= 0; i--) {
        inter[2][i] += inter[0][i] + inter[1][i];
        while (inter[2][i] >= 10) {
            inter[2][i] -= 10;
            if (i != 0) {
                inter[2][i - 1] += 1;
            }
            else {
                flag = 1;
            }
        }
    }
    printf("The result is:\n");
    if (flag) {
        printf("%d", flag);
    }
    for (i = 0; i < N; i++) {
        printf("%d", inter[2][i]);
    }
    printf(".");
    for (f = 0; f < M; f++) {
        printf("%d", flo[2][f]);
    }
    printf("\n");
    return 0;
}
#endif
