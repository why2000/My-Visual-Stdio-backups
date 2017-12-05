#ifndef _MAIN_H
#define _MAIN_H
/*
* =====================================================================================
*       Filename:	why_calculator.h
*    Description:	including library
*        Version:	1.1.2
*        Created:	2017.10.26 16:03:50
*      Time Used:	10h
*  Last Modified:	2017.10.26 16:22
*   Last Changed:	New functions added
*         Author:	伍瀚缘(Tree Wu), why2000@hust.edu.cn
*        Company:	Huazhong University of Science and Technology
* =====================================================================================
*/

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define MAXSIZE 500//输入表达式的最大长度

int readinput(char *input, char *buf);//"reading.c"
int translate(const char *input, char *repol);//"reading.c"
int errorfound(const int index);//"output.c"
int preciquest(void);//"output.c"
void baseoutput(void);//"output.c"
void endingoutput(void);//"output.c"
void outputhelp(void);//"output.c"
void outputresult(double result);//"output.c"
void exectute(void);//"why_calculator.c"
double calculate(char *repol);//"calculating.c"
double numbertrans(const char *dnum);//"calculating.c"
int isint(double n);//"calculating.c"
#endif //_MAIN_H
