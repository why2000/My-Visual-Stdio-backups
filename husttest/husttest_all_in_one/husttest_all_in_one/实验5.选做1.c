//#define NOW
#ifdef NOW
#include<stdio.h>
#include<malloc.h>
void strnins(char[], char[], int);
int main(void)
{
    char a[60] = "The adopted symbol is ", b[27] = "abcdefghijklmnopqrstuvwxyz";
    strnins(a, b, 4);
    printf("%s\n", a);
    return 0;
}
void strnins(char s[], char t[], int n)
{
    int i = 0, j = 0;
    int lent, lens;
    while (t[++i]);
    lent = i;
    i = 0;
    while (s[++i]);
    lens = i;
    i = 0;
    char* buf = (char*)malloc(sizeof(char)*(lens - n));
    for (i = n, j = 0; i < lens; i++, j++) {
        buf[j] = s[i];
    }
    for (i = n, j = 0; i < lent + n; i++, j++) {
        s[i] = t[j];
    }
    for (i = lent + n, j = 0; i < lens + lent - 1; i++, j++) {
        s[i] = buf[j];
    }
    s[i] = '\0';
}

#endif
