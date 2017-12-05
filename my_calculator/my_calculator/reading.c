#define _READ_C
#ifdef _READ_C
/*
* =====================================================================================
*       Filename:	reading.c
*    Description:	read input and change it into a reverse polish style
*        Version:	1.1.2
*        Created:	2017.10.26 16:04:47
*      Time Used:	10h
*  Last Modified:	2017.10.27 23:58
*    Last Change:	deal with dots
*         Author:	伍瀚缘(Tree Wu), why2000@hust.edu.cn
*        Company:	Huazhong University of Science and Technology
* =====================================================================================
*/
#include<why_calculator.h>
//#define NOW 1
#ifdef NOW//调试用

int main(void) {


	return 0;
}

#endif
extern int execstatus;//"why_calculator.c"

//函数功能：储存输入的表达式(buf)用于格式化输出，并建立一个处理了负号的版本(input)以进行后续计算，同时处理特殊输入指令
int readinput(char *input, char *buf) {//input进行后续计算,buf用于格式化输出
	int i = 0,j=0;
	int minus = 0;

	while (((input[i] = fgetc(stdin))) != '\n')
	{
		buf[j] = input[i];
		if (input[i] == '-') {//非常神秘的没有验证正确性的自己脑子一抽想出来的负数的暴力处理办法
			if (i == 0) {//负号在首位时直接添0
				input[i++] = '0';
				input[i] = '-';
			}
			else if (input[i - 1] == '(') {//负号在左括号后时直接添0
			/*******这个不能和上面的合并，否则读取input[-1]会导致内存错误******/
				input[i++] = '0';
				input[i] = '-';
			}
			
			else{//负号在数字的后面时添置括号
				input[i++] = '+';
				input[i++] = '(';
				input[i++] = '0';
				input[i] = '-';
				++minus;
			}
		}
		if (input[i] == '+') {//顺便把正号一起处理了
			if (i == 0) {//首位添0
				input[i++] = '0';
				input[i] = '+';
			}
			else if (input[i - 1] == '(') {//左括号后添0
				input[i++] = '0';
				input[i] = '+';
			}	
		}if (input[i] == '.'&&!(input[i-1]>='0'&&input[i-1]<='9')) {//当然还有小数点
				input[i++] = '0';
				input[i] = '.';//任何情况下没接在数字后面的小数点只要直接变成0.就行了
			
		}
		if (input[i] == ' ')
		{
			i--;
			j--;
		}
		i++;
		j++;
	}
	buf[j] = '\0';
	for (int k = 1; k <= minus; k++) {//补全由于处理负数产生的括号
		input[i++] = ')';
	}
	//**********************错误8：无输入******************************
	if (input[0]=='\n') {
		return errorfound(8);
	}
	//************************ERROR8*********************************

	input[i] = '\0';
	
	
	//特殊命令：
	//1.exit（或quit）退出程序
	//2.help 打开帮助界面
	//3.change 修改精度
	if (strcmp(input, "quit")==0 || strcmp(input, "exit")==0) {
		strcpy(input, "");
		return 0;
	}
	else if (strcmp(input, "help") == 0) {
		outputhelp();
		return 2;
	}
	else if (strcmp(input, "change") == 0) {
		preciquest();
		return 2;
	}
	else {
		return 1;
	}


}

//将中缀输入串转换并压入逆波兰栈
int translate(const char *input, char *repol) {//input为经部分后处理的输入，repol为逆波兰栈，用于后续运算
	char stack[MAXSIZE];//in栈用于存符号
	int	now = 0;//input读取符
	int top = -1;//in栈顶符,读取top为负时表示出现错误
	int pol = 0;//repol栈写入符
	while (input[now]!='\0') {
		//1.括号处理
		if (input[now] == '(') {//左括号无视优先级直接入栈
			stack[++top] = input[now++];
		}
		else if (input[now] == ')') {//注意右括号本身永远不会存在于入栈中，后续不用判断其存在
			//左括号上方符号出栈
			while (stack[top] != '('&&top >= 0) {
				repol[pol++] = stack[top--];
			}
			//*************************错误1：右括号多于左括号********************************
			if (top < 0) {
				repol[pol] = '\0';//结束逆波兰栈的写入，并返回0以请求继续输入
				return errorfound(1);
			}
			//********************************ERROR1**************************************
			--top;//舍弃左括号
			++now;//舍弃右括号
		}
		//2.读取运算符
		else if (input[now]=='@'||input[now]=='^') {//最高级运算符@与^（开方/乘方）同级运算符及其上方的全部运算符出栈压入repol，再将本身压入入栈
			while (top >= 0 && (stack[top] == '@' || stack[top] == '^')) {
				repol[pol++] = stack[top--];
			}
			stack[++top] = input[now++];
		}
		else if (input[now] == '*' || input[now] == '/') {//次高级运算符*与/将同级或高级运算符出栈压入repol,再将本身压入入栈
			while (top >= 0 && (stack[top] == '@' || stack[top] == '^' || stack[top] == '*' || stack[top] == '/')) {
				repol[pol++] = stack[top--];
			}
			stack[++top] = input[now++];
		}
		else if (input[now] == '+' || input[now] == '-') {//低级运算符+与-将左括号上方的全部运算符出栈压入repol,再将本身压入入栈
			while (top >= 0 && stack[top] != '(') {
				repol[pol++] = stack[top--];

			}
			stack[++top] = input[now++];
		}
		else if((input[now] >= '0'&&input[now] <= '9') || (input[now] == '.')) {//数字（含浮点）直接写入逆波兰栈
			//此处可考虑用项目 \\codevstest\\sliver1 里写的函数进行功能拓展：其他进制读入
			//初步想法：读取0x为十六进制，1x~fx对应1~15进制
			while ((input[now] >= '0'&&input[now] <= '9')||input[now]=='.') {
				repol[pol++] = input[now++];
			}
			repol[pol++] = ' ';//数字读入结束标识，防止repol中压入连续数字产生混淆
		}
		//**************************错误6：无法识别的输入**************************************
		else {
			return errorfound(6);
		}
		//**********************************ERROR6*****************************************
	}
	while (top >= 0) {//符号压入repol
			//***********************错误2：左括号多于右括号************************************
			if (stack[top] == '(') {
				repol[pol++]='\0';//结束逆波兰栈的写入，并返回0以请求继续输入
				return errorfound(2);
			}
			//******************************ERROR2******************************************
			repol[pol++] = stack[top--];
		}
	repol[pol++] = '\0';//逆波兰栈写入完成


}

#endif //_READ_C