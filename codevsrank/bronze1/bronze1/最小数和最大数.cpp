//#define NOW
#ifdef NOW
#include<iostream>
#include<malloc.h>

using std::cin;
using std::cout; using std::endl;

int main() {
	int n = 0;
	cin >> n;
	int *buf;
	buf = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		cin >> buf[i];
	}
	int max = buf[0];
	int min = buf[0];
	for (int i = 0; i < n; i++) {
		if (buf[i] > max)max = buf[i];
		if (buf[i] < min)min = buf[i];
	}
	cout << min << " " << max << endl;
	free(buf);


	return 0;
}
#endif