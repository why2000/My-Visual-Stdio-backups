//#define NOW
#ifdef NOW
#include<stdio.h>
#define MAXSIZE 500
int main(void) {
    char input[MAXSIZE];
    int i = 0, j = 0;
    while ((input[i] = fgetc(stdin)) != '\n') {
        if (input[i] == ' '&&(i!=0)) {
            if (input[i-1] == ' ') {
                --i;
            }
        }
        ++i;
    }
    for (j = 0; j <= i; j++) {
        fputc(input[j], stdout);
    }
    return 0;
}
#endif
