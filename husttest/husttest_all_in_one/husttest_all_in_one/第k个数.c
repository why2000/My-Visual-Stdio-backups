//#define NOW
#ifdef NOW
#include<stdio.h>
int find(int num, int n) {
    int i;
    int buf;
    for (i = 1; i <= n; ++i) {
        buf = num % 10;
        if (num == 0) {
            return -1;
        }
        num /= 10;
    }
    return buf;

}

int main(void) {
    int num, place;
    while (scanf("%d %d", &num, &place)!=EOF) {
        printf("%d\n", find(num, place));
    }
    return 0;

}

#endif
