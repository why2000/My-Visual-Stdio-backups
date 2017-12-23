//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void) {
    long num;
    int i;
    unsigned long maskh = 0xf0, maskl = 0x0f;
    printf("Please input a number:\n");
    scanf("%ld", &num);
    for (i = sizeof(long) - 1; i >= 0; i--) {
        printf("The higher bits of byte %d is %x\t", i + 1, ((num >> i * 8) & maskh) >> 4);
        printf("The lower bits of byte %d is %x\n", i + 1, (num >> i * 8) & maskl);
    }
    return 0;
}

#endif
