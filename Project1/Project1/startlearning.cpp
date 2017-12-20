#include<stdio.h>
union testunion
{
    char c;
    int a;
};

int main(void) {
    union testunion why;
    why.a = 0xCCCC;
    printf("%c\n%x", why.c, why.a);
    return 0;
}