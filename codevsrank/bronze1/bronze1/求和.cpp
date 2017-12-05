//#define NOW
#ifdef NOW
#include<iostream>
#include<malloc.h>

using std::cin;
using std::cout; using std::endl;

int main() {
	int n = 0;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;
		sum += input;

	}
	cout << sum << endl;


	return 0;
}

#endif
