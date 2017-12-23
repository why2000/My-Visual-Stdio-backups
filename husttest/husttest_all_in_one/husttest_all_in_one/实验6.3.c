//#define NOW
#ifdef NOW
#include<stdio.h>
#include<malloc.h>
#include<string.h>
void upper(int* raw, int n);
void lower(int* raw, int n);
int main(int argc, char** argv) {
    int n;
    int i;
    printf("Please the number of inputs:\n");
    scanf("%d", &n);
    printf("Start inputing:\n");
    int* num = (int*)malloc(sizeof(int)*n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    void (*p)(int*, int);
    if (argc == 1) {
        p = upper;
    }
    else {
        if (strcmp(argv[1], "-d") == 0){ //这不是Py！！！不能直接用等号比较字符串
            p = lower;
        }
    }
    p(num, n);
    for (i = 0; i < n; i++) {
        printf("%4d", num[i]);   
    }
    printf("\n");
    return 0;
}
void upper(int* raw, int n) {
    int i = 0, j = 0;
    int buf = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (raw[j] > raw[j + 1]) {
                buf = raw[j + 1];
                raw[j + 1] = raw[j];
                raw[j] = buf;
            }
        }
    }
}
void lower(int* raw, int n) {
    int i = 0, j = 0;
    int buf = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (raw[j] < raw[j + 1]) {
                buf = raw[j + 1];
                raw[j + 1] = raw[j];
                raw[j] = buf;
            }
        }
    }
}
#endif
