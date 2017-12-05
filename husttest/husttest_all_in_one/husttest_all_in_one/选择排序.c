//#define NOW
#ifdef NOW
#include<stdio.h>
#include<malloc.h>
void paixu(int*raw, int n);
int main(void) {
    int n = 0;
    while (scanf("%d", &n)) {
        if (n == 0) { 
            break;
        }
        else {
            int* raw = (int*)malloc(sizeof(int)*n);
            int i = 0;
            for (i = 0; i < n; i++) {
                scanf("%d", &raw[i]);
            }    
            paixu(raw, n);
            for (i = 0; i < n; i++) {
                printf("%d", raw[i]);
                if (i != n - 1) {
                    printf(" ");
                }
                else {
                    printf("\n");
                } 
            }
            free(raw);
        }
    }
    return 0;
}

void paixu(int*raw, int n) {
    int i = 0, j = 0;
    int buf = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (raw[j] < raw[i]) {
                buf = raw[i];
                raw[i] = raw[j];
                raw[j] = buf;
            }
        }
    }
}

#endif
