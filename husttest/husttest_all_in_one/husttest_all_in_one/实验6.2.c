//#define NOW
#ifdef NOW
#include<stdio.h>
#include<malloc.h>
void execute(char *ori);
int main(void) {
    int n;
    int i;
    printf("Please input the number of lines:\n");
    scanf("%d", &n);
    getchar();
    printf("Start inputing:\n");
    char **buf = (char**)malloc(sizeof(char*)*n);
    for (i = 0; i < n; i++) {
        buf[i]=(char*)malloc(sizeof(char) * 80);
    }
    for (i = 0; i < n; i++) {
        gets(buf[i]);
    }
    for (i = 0; i < n; i++) {
        execute(buf[i]);
    }
    return 0;
}

void execute(char *ori) {
    int i = 0, j = 0, t = 0;
    int dec = 0;
    int flag = 0;
    char* buf = ori;
    while (ori[i++] != '\0');
    for (j = 0; buf[j] != '\0'; j++) {
        if (buf[j] == ' ') {
            if (j == 0);
            else if (buf[j - 1] == ' ') {
                for (t = j; t < i - dec; t++) {
                    buf[t] = buf[t + 1];  
                }
                ++dec;
                --j;
            }
        }
        else {
            flag = 1;
        }
    }
    if (flag) {
        for (t = 0; t < j; t++) {
            printf("%c", buf[t]);
        }
        printf("\n");
    }
}

#endif
