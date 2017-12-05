//#define NOW
#ifdef NOW
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 50
int powwhy(int a, int m);
int main(void) {
    int n = 0;
    int i = 0, j = 0, k = 0;//全是计数器
    scanf("%d%*c", &n);

    for (j = 0; j < n; j++) {
        char str[MAXSIZE];
        int sum = 0;
        for (i = 0; (str[i] = getchar()) != '\n'; i++);
        for (k = 2; k < i; k++) {
            if (isdigit((int)str[k])) {
                str[k] -= 48;
            }
            else if (isupper((int)str[k])) {
                str[k] -= 55;
            }
            else if (islower((int)str[k])) {
                str[k] -= 87;
            }
            sum += str[k] * powwhy(16,i-1-k);
        }
        printf("%d\n", sum);
    }
    return 0;
}
int powwhy(int a, int m) {
    int res = 1;
    if (m == 0) {
        res = 1;
    }
    else {
        int i = 1;
        for (i = 1; i <= m; i++) {
            res *= a;
        }
    }
    return res;

}

#endif
