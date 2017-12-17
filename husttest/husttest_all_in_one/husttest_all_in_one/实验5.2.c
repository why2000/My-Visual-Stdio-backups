//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void) {
    int i;
    int num;
    unsigned int mask = 0x01 << (sizeof(int) * 8 - 1);
    int bitarray[sizeof(int) * 8] = { 0 };
    printf("Please input the number:\n");
    scanf("%d", &num);
    for (i = sizeof(int) * 8 - 1; i >= 0; i--) {
        bitarray[i] = ((unsigned int)num & mask) >> (sizeof(int) * 8 - 1);
        num <<= 1;
    }
    printf("The bit type of this number is:\n");
    for (i = sizeof(int) * 8 - 1; i >=0; i--) {
        printf("%d", bitarray[i]);
    }
    printf("\n");
    return 0;
}

#endif
