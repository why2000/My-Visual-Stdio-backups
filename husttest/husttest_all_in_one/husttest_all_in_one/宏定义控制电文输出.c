#define NOW
#ifdef NOW
#include<stdio.h>
#define MAXLINE 1024
#define CHANGE (c%2)

int main(void) {
    int n;
    char c, ch[MAXLINE];
    int i = 0;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; ++i) {
        int p = 0;
        for (p = 0; (scanf("%c", &ch[p]), ch[p]) != '\n'; p++);
        int j = 0;
        c = ch[0];
        for (j = 0; ch[j] != '\n'; j++) {
            if (CHANGE) {
                if ((ch[j] >= 'a') && (ch[j] <= 'z')) {
                    ch[j] -= 32;
                }
                else if ((ch[j] >= 'A') && (ch[j] <= 'Z'))
                {
                    ch[j] += 32;
                }
            }

            printf("%c", ch[j]);
        }
        printf("%c", ch[j]);
    }
    return 0;
}
#endif
