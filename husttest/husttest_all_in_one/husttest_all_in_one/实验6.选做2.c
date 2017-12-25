//#define NOW
#ifdef NOW
#include<stdio.h>
#include<string.h>
#define MAXSIZE 1024
int main(int argc, char** argv) {
    argv[1] = "-i";
    char *(*p[2])(const char *, const char *);
    char str1[MAXSIZE], str2[MAXSIZE];
    p[0] = strstr;
    p[1] = strcmp;
    printf("Please enter the two strings you want to compare");
    scanf("%s%s", str1, str2);
    if (strcmp(argv[1], "-c") == 0) {
        printf("You are in \"is_same\" mode\n");
        if (p[1](str1, str2) == 0) {
            printf("These two strings are the same\n");
        }
        else {
            printf("These two strings are different\n");
        }
    }
    else if (strcmp(argv[1], "-i") == 0) {
        prinf("You are in \"is_sub\" mode\n");
        if (p[0](str1, str2)) {
            printf("The second string is a sub_string of the first one\n");
        }
        else {
            printf("The second string isn't a sub_string of the first one\n");
        }
    }
    else {
        printf("Usage:实验6.选做2.exe [-c(compare)] [-f(find)] str1 str2\n");
    }
    return 0;
}
#endif
