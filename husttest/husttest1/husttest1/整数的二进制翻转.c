//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void)
{
	int ori = 0, start = 0, len = 0;
	int bufori[32];
	int i = 0;
	int j = 0;
	for (i = 0; i <= 31; i++) {
		bufori[i] = 0;
	}
	scanf("%d %d %d", &ori, &start, &len);
	start = 31 - start;
	for (i = 31; ori != 0; i--) {
		bufori[i] = ori % 2;
		ori = ori / 2;
	}

	for (i = 0; i <= 3; i++) {
		for (j = 1; j <= 8; j++) {
			printf("%d", bufori[i * 8 + j - 1]);
		}
		if (i != 3)printf(" ");
	}
	printf("\n");
	for (i = start; i >start - len; i--) {
		if (bufori[i] == 1) {
			bufori[i] = 0;
		}
		else {
			bufori[i] = 1;
		}
	}
	for (i = 0; i <= 3; i++) {
		for (j = 1; j <= 8; j++) {
			printf("%d", bufori[i * 8 + j - 1]);
		}
		if (i != 3)printf(" ");
	}
	printf("\n");

	return 0;
}
#endif
