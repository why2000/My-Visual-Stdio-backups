#include<stdio.h>
#include<limits.h>
void PrintBit(int x)
{
	int i;
	int m = sizeof(int) * 8;
	int mask = 1 << (m - 1);
	for (i = 1; i <= m; ++i)
	{
		putchar(!(x&mask) ? '0' : '1');
		x <<= 1;
		if (!(i % 8) && i<m)
			putchar(' ');
	}

}

int main()
{
	int a = 32;
	int c = (~0) << a;
	int d = (~0) << 32;
	PrintBit(c);
	printf("%d\n");
	PrintBit(d);
	return 0;

}