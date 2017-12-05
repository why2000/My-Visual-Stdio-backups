#include<iostream>
using namespace std;
int main()
{
	int n, a(0), g(0), b, x, y;
	cin >> n;
	int *num=(int*)malloc(n*sizeof(int));
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	/*
	for (int i = 1; i <= (n - 1); i++)
	{
		if (p[i] == p[i + 1])
			g = g + 1;
	}
	if (g == (n - 1)) cout << "NO";
	else
	{
		x = p[1], y = p[2];
		for (int i = 1; i <= (n - 2); i++)
		{
			if (p[i + 1]>p[i]) x = p[i + 1], y = p[i];
			else if (p[i + 1] == p[i]) x = x;
			else if (p[i + 2]>x) y = x, x = p[i + 2];
			else if (p[i + 2] == x) x = x;
			else if (p[i + 2]>y) y = p[i + 2];
		}
		for (int i = 1; i <= n; i++)
		{
			if (y == p[i])
			{
				b = i;
				break;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (y == p[i])
			{
				a = a + 1;
			}
		}
		cout << a << " " << b << " " << y << endl;
		*/		
	int index = 0;;//次大值位置
	int times = 1;//次大值次数
	int max = num[0];
	int max2=0;
	int still = 0;
	for (int i = 0; i < n; i++) {
		if (num[i] >= max) {
			max = num[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (num[i] < max) {
			max2 = num[i];
			++still;
			index = i + 1;
		}

	}
	if (still) {
		for (int i = 0; i < n; i++) {
			if (num[i] > max2&&num[i] < max) {
				max2 = num[i];
				index = i + 1;		
			}
			else if (num[i] == max2) {
				++times;
			}
		}
		
		cout << index << " " << times << " " << max2 << endl;

		

	}
	else {
			cout << "NO" << endl;
		}
	return 0;
}