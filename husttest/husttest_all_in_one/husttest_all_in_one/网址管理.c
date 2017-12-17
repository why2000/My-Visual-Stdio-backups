//#define NOW
#ifdef NOW
#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct _web {
    char abbr[21];
    char name[41];
    char url[101];
}web;
int main(void) {
    int num;
    int i = 0, j = 0;
    scanf("%d", &num);
    getchar();
    web *webs = (web*)malloc(sizeof(web)*num);
    for (i = 0; i < num; i++) {
        
        for (j = 0; (webs[i].abbr[j] = getchar()) != ' '; j++);
        webs[i].abbr[j] = '\0';
        for (j = 0; (webs[i].name[j] = getchar()) != ' '; j++);
        webs[i].name[j] = '\0';
        for (j = 0; ((webs[i].url[j] = getchar()) != '/' || (webs[i].url[j - 1]) == ':' || (webs[i].url[j - 1]) == '/'); j++);
        webs[i].url[j++] = '/';
        webs[i].url [j] = '\0';//这是我做过的第一个输入不以\n结束的题目
        getchar();
    }
    for (i = 0; i < num; i++) {
        printf("%-20s", webs[i].abbr);
        printf("%-40s", webs[i].name);
        printf("%s", webs[i].url);
        printf("\n");
    }
    printf("\n");
    web buf;
    for (i = 0; i < num - 1; i++) {
        for (j = 0; j < num - 1 - i; j++) {
            if (strcmp(webs[j].abbr, webs[j + 1].abbr) == 1) {
                buf = webs[j + 1];
                webs[j + 1] = webs[j];
                webs[j] = buf;
            }
        }
    }
    for (i = 0; i < num; i++) {
        printf("%-20s", webs[i].abbr);
        printf("%-40s", webs[i].name);
        printf("%s", webs[i].url);
        printf("\n");
    }
    return 0;
}
#endif
