//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void) {
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		short num = 0;
		scanf("%hd", &num);
		unsigned int mask1 = 0xff;

		unsigned int mask2 = 0xff00;
		unsigned int buf1 = num&mask1;
		unsigned int buf2 = num&mask2;
		printf("%c,%c\n",  buf2 >> 8,buf1);
	}



	return 0;
}
#endif