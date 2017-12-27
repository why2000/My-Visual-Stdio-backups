//#define NOW
#ifdef NOW
#include<stdio.h>
#include<string.h>
#define MAXSIZE 1024
int main(int argc, char** argv) {
    char *(*p[2])(const char *, const char *);
    char str1[MAXSIZE], str2[MAXSIZE];
    p[0] = strstr;
    p[1] = strpbrk;
	if (argc == 2) {
		printf("Please enter the two strings you want to compare:\n");
		scanf("%s%s", str1, str2);
		if (strcmp(argv[1], "-c") == 0) {
			char *bufc;
			printf("You are in \"has_same_char\" mode\n");
			if ((bufc = p[1](str1, str2)) != NULL) {
				printf("These two strings has at least one common char '%c'\n", *bufc);
			}
			else {
				printf("These two strings are different\n");
			}
		}
		else if (strcmp(argv[1], "-s") == 0) {
			char *bufs;
			printf("You are in \"is_sub_string\" mode\n");
			if ((bufs = p[0](str1, str2)) != NULL) {
				printf("The second string is a sub_string of the first one\n");
			}
			else {
				printf("The second string isn't a sub_string of the first one\n");
			}
		}
		else {
			printf("Usage:实验6.选做2.exe [-s(sub_string)] [-c(common_char)] str1 str2\n");
		}
	}
    else {
        printf("Usage:实验6.选做2.exe [-s(sub_string)] [-c(common_char)] str1 str2\n");
    }
    return 0;
}
#endif
