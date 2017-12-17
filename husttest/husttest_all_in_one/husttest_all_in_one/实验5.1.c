//#define NOW
#ifdef NOW
#include<stdio.h>
#define R 3
#define C 4
int main(void) {
    int row, col;
    int* outp;
    int ori[R][C], tar[C][R];
    printf("Please input the original matrix:\n");
    for (row = 0; row < R; row++) {
        for (col = 0; col < C; col++) {
            scanf("%d", &ori[row][col]);
            tar[col][row] = ori[row][col];
        }
    }
    printf("The original matrix is:\n")
    for (row = 0; row < R; row++) {
        for (col = 0; col < C; col++) {
            printf("%-8d", ori[row][col]);
        }
        printf("\n");
    }
    printf("The transpose matrix is:\n")
    for (col = 0; col < C; col ++) {
        for (row = 0; row < R; row++) {
            printf("%-8d ", tar[col][row]);
        }
        printf("\n");
    }
    return 0;
}

#endif
