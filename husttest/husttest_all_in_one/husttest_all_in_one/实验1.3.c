//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void) {
    unsigned long num;
    unsigned short place1, place2, place3, place4;
    scanf("%lu", &num);
    place1 = (num & 0xFF000000) >> (6 * 4);
    place2 = (num & 0x00FF0000) >> (4 * 4);
    place3 = (num & 0x0000FF00) >> (2 * 4);
    place4 = (num & 0x000000FF) >> (0 * 4);
    printf("%hu.%hu.%hu.%hu\n", place4, place3, place2, place1);//4¸ö×Ö¶Îµ¹ÐòÊä³ö
    return 0;
}

#endif
