#ifndef _MAIN_H
#define _MAIN_H
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define MAX_LINE 1024
#define MAX_PATH 1024
struct evening_struct {

};
int read_file_list(char *path);
void read_a_single_file(char *f_path, evening_struct file_struct);


#endif
