//#define NOW
#ifdef NOW
#include<stdio.h>

int main(void) {
    int index[12] = { 0 };
    char c;
    int i = 0;
    while ((c = fgetc(stdin)) != '#') {
        if (c >= '0'&&c <= '9') {
            ++index[c - '0'];
        }
        else if ((c >= 'A'&&c <= 'Z') || (c >= 'a'&&c <= 'z')) {
            ++index[10];
        }
        else {
            ++index[11];
        }
    }
    for (i = 0; i <= 9; i++) {
        printf("Number %d: %d\n", i, index[i]);
    }
    printf("characters: %d\n", index[10]);
    printf("other: %d\n", index[11]);
    return 0;
}

#endif
