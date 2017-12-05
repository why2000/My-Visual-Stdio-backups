//#define NOW
#ifdef NOW
#include <stdio.h>
void choose(i) {
    if (i == 0)
        ;
    else if (i<10)
        printf("   %d", i);
    else if (i<100)
        printf("  %d", i);
    else if (i<1000)
        printf(" %d", i);
}
int yanghui[12][50] = { { 0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 } };
void sanjiao(int i) {
    int line, raw, k, a;
    int flag = 1;
    for (a = 0; a < i - 1; a++)
        printf("  ");
    printf("1");
    for (line = 1; line <= (i - 1); line++) {
        flag = 1;
        for (raw = 1; raw <= 50; raw++) {
            
            yanghui[line][raw] = (yanghui[line - 1][raw - 2] + yanghui[line - 1][raw]);
            if (yanghui[line][raw] != 0 && flag) {
                flag = 0;
                printf("%d", yanghui[line][raw]);
            }
            else if (raw != line)
                choose(yanghui[line][raw]);
            else {
                printf("\n");
                for (k = 0; k < (i - 1) - line; k++)
                    printf("  ");
            }
        }
    }
    printf("\n");
}

int main(void) {
    int i;
    while ((scanf("%d", &i), i) != 0) {
        sanjiao(i);
        printf("\n");
    }
    return 0;
}


#endif
