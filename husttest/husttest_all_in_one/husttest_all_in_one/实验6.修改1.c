//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void)
{
    float f;//������һ���������
    float *p = &f;//��������pָ��һ���ѱ������ַ�ĸ�������ĵ�ַ
    scanf("%f", p);
    printf("%f\n", *p);
    return 0;
}


#endif
