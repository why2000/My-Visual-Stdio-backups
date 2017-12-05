#ifndef _MAIN_C
#define _MAIN_C

#include<main.h>
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<Windows.h>
#define MAX_LINE 1024
#define MAX_PATH 1024

//struct evening_struct {
//
//};
int read_file_list(char *path);
int main(void) {
    char *path;
    path = (char*)malloc(sizeof(char)*MAX_PATH);
    int i = 0;
    while ((path[i] = fgetc(stdin)) != '\n');
    path[i] = '\0';
    read_file_list(path);

    return 0;
}


int read_file_list(char *path) {
    int nums = 0;
    char buf[MAX_LINE];
    FILE* list;
    int len;
    system("%c:", path[0]);
    system("cd %s", path);
    system("DIR *.* /s > filenamelist.txt");
    list = fopen("filenamelist.txt", "r+");
    while (fgets(buf, MAX_LINE, list) != NULL)
    {
        char aim[MAX_PATH];
        char path[MAX_PATH];
        char finalpath[MAX_PATH];
        len = strlen(buf);
        buf[len - 1] = '\0';
        if (buf[0] == 32 && buf[2] == ':' && (buf[1] == 'C' || buf[1] == 'D' || buf[1] == 'E' || buf[1] == 'F') && buf[4] != 36) {
            int ori;
            for (ori = 1; buf[ori] != 32 || buf[ori + 1] != -75 || buf[ori + 2] != -60; ori++) {
                path[ori - 1] = buf[ori];
            }
            path[ori - 1] = '\0';
            char help[] = "0";
            help[0] = 92;
            strcat(path, help);

        }
        if (buf[0] == '2'&&buf[1] == '0'&&buf[4] == '/'&&buf[21] != '<'&&buf[36] != 36) {


            if (buf[36] != 'f' || buf[37] != 'i' || buf[40] != 'n' || buf[43] != 'e' || buf[44] != 'l') {


                strcpy(aim, &buf[36]);
                strcpy(finalpath, path);
                strcat(finalpath, aim);
                printf("%s\n",finalpath);
            }

        }
        ++nums;
    }
    return nums;
}

#endif
