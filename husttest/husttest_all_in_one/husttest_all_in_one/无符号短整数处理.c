//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void) {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		unsigned short num = 0;
		scanf("%hu", &num);
		unsigned int mask1 = 0xf;
		unsigned int mask2 = 0xf000;
		unsigned int mask3 = 0xff0;
		unsigned int buf1 = num&mask1;
		unsigned int buf2 = num&mask2;
		unsigned int buf3 = num&mask3;
		unsigned short res = (buf1<<12)|(buf2>>12)|buf3;
		printf("%hu\n", res);
	}
	


	return 0;
}
#endif