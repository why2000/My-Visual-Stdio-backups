//#define NOW
#ifdef NOW
#include<iostream>
#include<malloc.h>

using std::cin;
using std::cout; using std::endl;
void sort(int num[], int i, int j);
int main() {
	int n = 0;
	cin >> n;
	int *num = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, 0, n-1);
	for (int i = 0; i < n; i++) {
		cout << num[i];
		if (i != n - 1) {
			cout << " ";
		}
	}
	free(num);
	return 0;
}
void sort(int num[], int start, int end) {
	if (start < end)
	{
		int i = start, j = end, x = num[start];
		while (i < j)
		{
			while (i < j && num[j] >= x) // 从右向左找小
				j--;
			if (i < j)
				num[i++] = num[j];
			while (i < j && num[i] < x) // 从左向右找大  
				i++;
			if (i < j)
				num[j--] = num[i];
		}
		num[i] = x;
		sort(num, start, i - 1); //左区间排序  
		sort(num, i + 1, end); //右区间排序
	}
}
#endif