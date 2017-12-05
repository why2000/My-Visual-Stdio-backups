//#define NOW
#ifdef NOW

#include<stdio.h>

int main(void){
    int a, b;
    printf("Input two integers : ");
    scanf("%d %d", &a, &b);
    //考虑到应该把a和b的值的信息合成后存储于同一变量（a或b）中，然后用b的值进行拆解得到a的值，再利用a的值进行拆解得到b的值，设计程序如下：
    //利用了某数与自己异或结果为0，可用异或运算式直接实现
    a ^= b;//a的值为a与b的不进位和(a^b)
    b ^= a;//b的值为a^b^b=b^b^a=0^a=a
    a ^= b;//a的值为a^b^a=a^a^b=0^b=b
    /*实际上用数值加减也可以实现
    a += b;//a的值为a+b
    b = a-b;//b的值为a+b-b=a
    a -= b;//a的值为a+b-a=b
    */
    printf("\na = %d, b = %d", a, b);
    return 0;
}


#endif
