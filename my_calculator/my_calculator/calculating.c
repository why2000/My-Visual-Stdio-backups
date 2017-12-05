#define _CALCU_C
#ifdef _CALCU_C
/*
* =====================================================================================
*       Filename:	calculating.c
*    Description:	funs about calculating
*        Version:	1.1.2
*        Created:	2017.10.26 16:05:58
*      Time Used:	10h
*  Last Modified:	2017.10.28 00:05
*    Last Change:	One error judgement deleted
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

#endif //NOW
extern int execstatus;//"why_calculator.c"

//函数功能：计算结果
double calculate(char *repol) {//repol为填充完毕的逆波兰栈
	double stack[MAXSIZE];//计算栈
	char dnum[MAXSIZE];//读取浮点数
	int pol = 0;//repol读取符
	int top = -1;//栈顶符
	while (repol[pol] != '\0') {
		if ((repol[pol] >= '0'&&repol[pol] <= '9')||repol[pol]=='.') {//读取数字字符串
			int now = 0;
			while (repol[pol] != ' ') {
				dnum[now++] = repol[pol++];
			}
			dnum[now++] = '\0';
			stack[++top] = numbertrans(dnum);//数字字符串的转换
			pol++;
		}
		else {
			//************************错误7：运算符过多***************************
			if (top == 0) {
				return errorfound(7);
			}
			//**************************ERROR7*********************************
			switch (repol[pol++]) {
			case '@'://开方运算，中缀中后读取的（stack[top]）为开方的次数，先读取的为被开方的数,目前不支持对负数开方
				if (stack[top-1]>=0) {//被开方数为负时要求开方次数为奇整数
					stack[top - 1] = pow(stack[top - 1], 1.0 / stack[top]);
					--top;
					break;
				}
				else if ((isint(stack[top])&&(int)stack[top]%2&&stack[top-1]<0)) {
					stack[top - 1] = -pow(-stack[top - 1], 1.0 / stack[top]);
					--top;
					break;
				}

				//***********************错误3：开非奇整数次方时底数小于零*****************************
				else {
					return errorfound(3);
				}
				//********************************ERROR3*****************************************

			case '^'://幂运算，后读取的为指数，先读取的为底数
				if (stack[top-1]>=0) {
					stack[top - 1] = pow(stack[top - 1], stack[top]);
					--top;
					break;
				}
				else if (isint(1.0 / stack[top]) && ((int)(1.0 / stack[top]) % 2) && stack[top - 1] < 0) {
					stack[top - 1] = pow(stack[top - 1], stack[top]);
					--top;
					break;
				}
				//***********************错误4：结果为虚数的幂运算****************************
				else {
					return errorfound(4);
				}
				//*****************************ERROR4************************************

			case '*'://乘法运算
				stack[top - 1] *= stack[top];
				--top;
				break;
			case '/'://除法运算，后读取的为除数，先读取的为被除数
				if (stack[top]) {
					stack[top - 1] /= stack[top];
					--top;
					break;
				}
				//***********************错误5：分母为0*************************************
				else {
					return errorfound(5);
				}
				//*****************************ERROR5*************************************
			case '+'://加法运算
				stack[top - 1] += stack[top];
				--top;
				break;
			case '-'://减法运算
				stack[top - 1] -= stack[top];
				--top;
				break;
			}
			
		}
		
	}
	return stack[top];
}

//函数功能：整数判断
int isint(double n) {//
	if (n >= 0)
		if ((n - (int)n) < 1e-15 || (n - (int)n) < -0.999999999999999) return 1;
		else return 0;
	else
		if (-(n - (int)n) < 1e-15 || -(n - (int)n) < -0.999999999999999) return 1;
		else return 0;

}

//函数功能：将字符串形式的浮点数转换成double类型
double numbertrans(const char *dnum) {//dunm为字符串形式的浮点数
	double intpart = 0, floatpart = 0, flo = 1;//整数部分，小数部分，浮点位
	int now = 0;
	double result = 0;
	while (dnum[now] >= '0' && dnum[now] <= '9')
	{
		intpart = intpart * 10 + dnum[now++] - '0';//整数部分读取：乘十加n
	}

	if (dnum[now] == '.') //小数部分读取
	{
		while (dnum[++now] != '\0')
		{	
			//*****************************错误9：多重小数点**************************
			if (dnum[now] == '.') {
				return errorfound(9);
			}
			//********************************ERROR9*******************************
			floatpart = floatpart * 10 + dnum[now] - '0';
			flo *= 10;
		}
	}
	

	result = intpart + floatpart / flo;
	return result;
}
#endif //_CALCU_C
