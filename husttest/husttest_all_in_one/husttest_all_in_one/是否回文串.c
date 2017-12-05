//#define NOW
#ifdef NOW
#include<stdio.h>
#define MAXSIZE 500
int check(char *str, int len);
int main(void) {
    char str[MAXSIZE];
    int beright = 0;
    int i = 0, j = 0;
    int n;
    scanf("%d%*c", &n);
    for (j = 0; j < n; j++) {
        for (i = 0; (str[i] = getchar()) != '\n'; i++);
        beright = check(str, i);
        if (beright == 1) {
            printf("Yes!\n");
        }
        else {
            printf("No!\n");
        }
    }
    return 0;
}
int check(char *str, int len) {
    if (len <= 1) {
        return 1;
    }
    if (str[0] != str[len-1]) {
        return 0;
    }
    return check(++str, len = len-2);
}
#endif
