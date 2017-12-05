//#define NOW
#ifdef NOW
#include<stdio.h>
void way0(void) {//continue
	int num[10];
	int sum = 0;
	int times = 0;
	for (int i = 0; i < 10;i++) {
		scanf("%d", &num[i]);
		if (num[i] <= 0) {
			continue;
		}
		else
		{
			sum += num[i];
			++times;
		}
	}
	if (times > 0) {
		double average = (1.0*sum) / times;
		printf("In \"continue\" way,numbers=%d,average=%.6f\n", times, average);
	}
}
void way1(void) {//nocontinue
	int num[10];
	int sum = 0;
	int times = 0;
	for (int i = 0; i < 10; i++) {
		scanf("%d", &num[times]);
		if (num[times] > 0) {
			sum += num[times];
			++times;
		}
	}
	if (times > 0) {
		double average = (1.0*sum) / times;
		printf("In \"no continue\" way,numbers=%d,average=%.6f\n", times, average);
	}
}
int main(void) {
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int way;
		scanf("%d", &way);
		if (way == 0) {
			way0();
		}
		else if (way == 1) {
			way1();
		}
	}
	return 0;
}
#endif
 