//#define NOW
#ifdef NOW
#include<stdio.h>
#include<malloc.h>

int main(void) {
	int num;
	for (; (scanf("%d", &num),num!=0);) {
		
		int *buf;
		if (num >= 3) {
			buf = (int*)malloc(sizeof(int)*num);
			buf[0] = 1;
			buf[1] = 1;
			for (int i = 2; i < num; i++) {
				buf[i] = buf[i - 1] + buf[i - 2];
			}
			for (int i = 0; i < num; i++) {
				if (!((i + 1) % 8)) {
					printf("%10d\n", buf[i]);
				}
				else {
					printf("%10d", buf[i]);
				}
			}
			if (num % 8) {
				printf("\n");
			}
			free(buf);
			printf("\n");
		}

		else {
			printf("Error!\n\n");
		}
	}
	return 0;
}

#endif
