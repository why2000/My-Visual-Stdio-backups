//#define NOW
#ifdef NOW
#include<iostream>
#include<string>
#include<malloc.h>
using std::string;
using std::cin;
using std::cout; using std::endl;


int sum = 0;

void number(int n) {
	for (int i = 1; i <= n / 2; i++) {
		sum++;
		number(i);
	}
}

int main() {

	int n;
	cin >> n;
	number(n);
	cout << sum + 1;


	return 0;
}
#endif
