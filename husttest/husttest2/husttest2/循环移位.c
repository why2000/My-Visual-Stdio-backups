//#define NOW
#ifdef NOW
#include<stdio.h>

int main(void) {

	int num = 0, n = 0, len = 0;
	int buf[1000];
	int size = sizeof(int);
	scanf("%d %d", &num, &n);
	num = (num >> n) | (num << (size*8 - n));
	printf("%d\n", num);
	return 0;

}
#endif
