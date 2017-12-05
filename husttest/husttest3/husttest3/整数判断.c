//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void) {
	int a=0;
	while (scanf("%d", &a)) {
		if ((a % 10) == 5 && (a % 3) == 0) {
			printf("1\n");
		}
		else {
			printf("0\n");
		}
	}

	return 0;

}
#endif
