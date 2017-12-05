#include <stdio.h>
void fun_1(int *a)
{
	int avg;  //存储平均值变量
	int max=a[0];
	int markmax;
	int min=a[0];
	int markmin;
	int i = 0;
	int all = 0;
	for (i = 0; i <= 49; i++) {
		if (a[i] > max) {
			max = a[i];
			markmax = i;
		}
		if (a[i] < min) {
			min = a[i];
			markmin = i;
		}
	}
	for (i = 0; i <= 49; i++) {
		if (i != markmax&&i!=markmin) {
			all = all + a[i];
		}
	}
	avg = all / 48;

	//printf(“%d”, avg);
}
//void fun_2(int *a)
//{
//	int median;  //存储中位数值变量


//	printf(“%d”, median);
//}


