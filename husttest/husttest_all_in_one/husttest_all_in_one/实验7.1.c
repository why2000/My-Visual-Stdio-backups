//#define NOW
#ifdef NOW
#include<stdio.h>
typedef struct _bits {
	unsigned char bit0 : 1, bit1 : 1, bit2 : 1, bit3 : 1, bit4 : 1, bit5 : 1, bit6 : 1, bit7 : 1;
}bits;
typedef union _bun {
	unsigned char t;
	bits stru;
}bun;
void f0(bits b) {
	if (b.bit0)
		printf("the function 1 is called!\n");
}
void f1(bits b) {
	if (b.bit1)
		printf("the function 2 is called!\n");
}
void f2(bits b) {
	if (b.bit2)
		printf("the function 3 is called!\n");
}
void f3(bits b) {
	if (b.bit3)
		printf("the function 4 is called!\n");
}
void f4(bits b) {
	if (b.bit4)
		printf("the function 5 is called!\n");
}
void f5(bits b) {
	if (b.bit5)
		printf("the function 6 is called!\n");
}
void f6(bits b) {
	if (b.bit6)
		printf("the function 7 is called!\n");
}
void f7(bits b) {
	if (b.bit7)
		printf("the function 8 is called!\n");
}
int main(void)
{
	int i;
	bun myuni;
	void(*p[8])(bits b);
	printf("input a 8-bit unsigned int: ");
	scanf("%d",&myuni.t);
	myuni.stru.bit0 = 1;
	p[0] = f0;
	p[1] = f1;
	p[2] = f2;
	p[3] = f3;
	p[4] = f4;
	p[5] = f5;
	p[6] = f6;
	p[7] = f7;
	for (i = 0; i < 8; i++) {
		p[i](myuni.stru);
	}
	return 0;
}
#endif
