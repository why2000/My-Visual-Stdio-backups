//#define NOW
#ifdef NOW
#include<stdio.h>

#define PI 3.14159//去掉最后的分号
void main(void)//加个空格，void是main的类型
{
    int f, newint;//下面的newint未定义，在这里补上
    short p, k;
    double c, r, s;
    
    /* for task 1 */
    printf("Input  Fahrenheit : ");//改为英文引号
    scanf("%d", &f);//1.改为英文引号2.scanf函数需传递要写入的变量的地址，应给f加上地址运算符
    c = 1.0*5 / 9 * (f - 32);//采用浮点除法而非整数除法
    printf(" \n %d(F) = %.2f(C)\n\n ", f, c);//改为英文引号

    /* for task 2 */
    printf("input the radius r:");
    scanf("%lf", &r);//用%lf获取double类型的输入
    s = PI * r * r;
    printf("\nThe acreage is %.2f\n\n", s);//输出s的值而非其地址

    /* for task 3 */
    printf("input hex int k, p :");
    scanf("%hx %hx", &k, &p);//输入短整形而非十六进制数
    newint = (p & 0xff00) | (k & 0xff00) >> 8;//1.newint在上面补了定义2.k的高字节需右移而非左移
    printf("new int = %x\n\n", newint);//用整形输出而非16进制输出
    return 0;
}


#endif
