//#define NOW
#ifdef NOW
#include<stdio.h>
#define MAXSIZE 1000
int main(void) {

    int times = 0;
    
    int n = 0;
    int i = 0, j = 0, k = 0;//还是全是计数器
    scanf("%d%*c", &times);
    for (j = 0; j < times; j++) {
        char t[MAXSIZE];
        char s[MAXSIZE];
        int place = 0;
        for (i = 0; (t[i] = getchar()) != '\n'; i++);
        scanf("%d%*c", &n);
        for (k = 0; k < i; k++) {
            if (k < n) {
                s[place++] = t[k];
            }
        }
        s[place] = '\0';
        printf("%s\n", s);
    }
    return 0;
}

#endif
