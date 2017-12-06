//#define NOW
#ifdef NOW
#include<stdio.h>
#define MAXLINE 1024
#define MAXNUM 100
int main(void) {
    int N;
    char x[MAXNUM][MAXLINE], newone[MAXLINE];
    int i = 0;
    while ((scanf("%d", &N), N) != 0) {
        getchar();
        int i = 0, j = 0, k = 0;
        for (i = 0; i < N; i++) {
            j = 0;
            while ((x[i][j++] = fgetc(stdin)) != '\n');
        }
        for (i = 0; i < N; i++) {
            for (j = 0;; j++) {
                if (x[i][j] == '\n') {
                    break;
                }
                else {
                    newone[k++] = x[i][j];
                }
            }
        }
        newone[k] = '\0';
        printf("%s\n", newone);
    }
    return 0;
}
#endif
