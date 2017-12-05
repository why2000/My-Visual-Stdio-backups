
#define _MAIN_C
#ifdef _MAIN_C

/*
* =====================================================================================
*       Filename:	why_calculator.c
*    Description:	a simple calculator
*        Version:	1.1.2
*        Created:	2017.10.26 16:04:15
*      Time Used:	10h
*  Last Modified:	2017.10.27 11:44
*    Last Change:	formated the main fun, making it more flexible
*         Author:	伍瀚缘(Tree Wu), why2000@hust.edu.cn
*        Company:	Huazhong University of Science and Technology
* =====================================================================================
*/
//更新方向：
//1.增加负数的识别与读取（-a=(0-a)）		fixed
//2.对于多余运算符的识别				fixed
//3.对于输入非特定字母命令的识别			fixed
//4.对于负数开奇整数次方的支持           fixed
#include<why_calculator.h>

//异常安全指示器
//0:正常结束，1:继续运行，2:跳过此次计算，其他:异常结束
int execstatus = 1;
//精度，表示保留的小数位数
int preci=15;

//真正的执行函数
void exectute(void) {
	char input[MAXSIZE];
	char repol[MAXSIZE];
	char buf[MAXSIZE];
	double result;
	baseoutput();
	while (execstatus) {//不为0时继续运行
		if (execstatus != 2 && execstatus != 1) {//遇到异常错误时
			printf("未知错误，请按任意键结束程序\n");
			system("pause");
			exit(-1);
		}
		execstatus = readinput(input,buf);//读取输入
		if (execstatus == 2) {//遇到跳过本次计算请求时输出结束语并请求下一次输入
			endingoutput();
			execstatus = 1;
			continue;
		}
		translate(input, repol);//转换为逆波兰表达式
		if (execstatus == 2) {//请求下一次输入
			endingoutput();
			execstatus = 1;
			continue;
		}
		//puts(repol);//检测逆波兰转换是否正确，非调试时注释
		
		result = calculate(repol);
		if (execstatus == 2) {//请求下一次输入
			endingoutput();
			execstatus = 1;
			continue;
		}
	
		printf("%s = ", buf);
		outputresult(result);
		endingoutput();
	}
	


}
#define NOW 1
#ifdef NOW//调试时停用
//表面主函数
int main(void) {
	exectute();
	return 0;
}

#endif //NOW

#endif //_MAIN_C


