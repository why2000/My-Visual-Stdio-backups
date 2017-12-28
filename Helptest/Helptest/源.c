#include <stdio.h>
#include <stdlib.h>
#define N 2
#define M 1
int* change(int* aa, char na[][10])
{
	int **as = &aa;
	int i = 0, j = 0, sum[6] = { 0,0,0,0,0,0 };
	printf("以下是各科平均成绩\n");
	for (i = 0; i<M; i++)
	{
		for (j = 0; j<N; j++)
		{
			*(sum + i) += *(*(as + i) + j);
			printf("%d\n", *(*(as + i) + j));
			printf("%d\n", *(sum + i));

		}
		printf("%s:%f\n", *(na + i), (float)(*(sum + i)) / N);
	}
	return sum;
}
int main()
{
	int i = 0, j = 0;
	char name[M][10];
	int ar[M][N];
	for (i = 0; i<M; i++)
	{
		gets(name + i);
	}
	printf("请输入三门成绩\n");
	for (j = 0; j<N; j++)
	{
		for (i = 0; i<M; i++)
		{
			scanf("%d", (*(ar + i) + j));
		}
	}
	int *p = change(ar[0], name);
	return 0;
}
