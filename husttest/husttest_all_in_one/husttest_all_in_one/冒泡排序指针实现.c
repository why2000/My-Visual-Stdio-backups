//#define NOW
#ifdef NOW
#include<stdio.h>
#include<malloc.h>
void paixu(int*raw, int n);
int main(void) {
    int num[10];
    int i = 0;
    while (scanf("%d", &num[i++])!=EOF) {
        if (i == 10) {
            paixu(num, i);
            i = 0;
            int j = 0;
            for (j = 0; j < 10; j++) {
                printf("%d", num[j]);
                if (j == 9) printf("\n");
                else printf("->");
            }
        }
        
        
        
    }
    return 0;
}

void paixu(int* raw, int n) {
    int i = 0, j = 0;
    int buf = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (raw[j] > raw[j+1]) {
                buf = raw[j + 1];
                raw[j + 1] = raw[j];
                raw[j] = buf;
            }
        }
    }
}

#endif