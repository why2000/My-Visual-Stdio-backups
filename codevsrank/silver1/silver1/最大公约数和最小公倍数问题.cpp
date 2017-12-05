#define NOW
#ifdef NOW
#include <cstdio>
#include <cmath>

int gcd(int x, int y)
{
	return y ? gcd(y, x%y) : x;
}

int main()
{	
	int n, j, res=0, a, b;
	scanf("%d %d", &a, &b);
	int z = a*b;
	for (int i = a; i <= sqrt(z); i += a)
	{
		j = z / i;
		if (j<i)break;
		int m = gcd(j, i);
		if (m == a&&i*j / m == b)res++;
	}
	res *= 2;
	printf("%d", res);
	return 0;
}
#endif
