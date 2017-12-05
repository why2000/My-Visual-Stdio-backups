//#define NOW
#ifdef NOW
#include<iostream>
#include<malloc.h>

using std::cin;
using std::cout; using std::endl;

int main() {
	int n = 0;
	cin >> n;
	int *arch = (int *)malloc(sizeof(int)*n *n);//Ê¹ÓÃarch[i*n+j]´úÌæarch[i][j]
	int line = n - 1;
	int row = n - 1;
	int max = n*n;
	int rleft = 0;
	int lup = 0;
	int rright = n - 1;
	int ldown = n - 1;
	do {
		for (; row >= rleft; row--) {
			arch[line*n + row] = max;
			max -= 1;
			if (max == 0) {
				arch[line*n + row] = 1;
				goto out;
			}
		}
		row += 1;
		ldown -= 1;
		max += 1;
		for (; line >= lup; line--) {
			arch[line*n + row] = max;
			max -= 1;
			if (max == 0) {
				arch[line*n + row] = 1;
				goto out;
			}
		}
		line += 1;
		rleft += 1;
		max += 1;
		for (; row <= rright; row++) {
			arch[line*n + row] = max;
			max -= 1;
			if (max == 0) {
			arch[line*n + row] = 1;
			goto out;
		}
		}
		row -= 1;
		lup += 1;
		max += 1;
		for (; line <= ldown; line++) {
			arch[line*n + row] = max;
			max -= 1;
			if (max == 0) {
				arch[line*n + row] = 1;
				goto out;
			}
		}
		line -= 1;
		rright -= 1;
		max += 1;
		


	} while (1);
	out:;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arch[i*n + j];
			if (j != n - 1)cout << " ";
		}
		cout << endl;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arch[n*i + i];
		sum += arch[n*i + (n - 1 - i)];
		
	}
	sum -= 1;
	cout << sum;
	return 0;
}
#endif