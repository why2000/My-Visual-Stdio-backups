//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void) {
    char c;
    scanf("%c%*c", &c); 
    if (c >= 'A'&&c <= 'Z') {
        c += 32;
    }
    printf("%c\n",c);
    return 0;
}
#endif
