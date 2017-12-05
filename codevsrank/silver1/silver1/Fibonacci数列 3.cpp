//#define NOW
#ifdef NOW
#include<iostream>

using std::cin;
using std::cout; using std::endl;
int fibo(int n);
int main() {
	int n = 0;
	cin >> n;
	int res=fibo(n);
	cout << res;




	return 0;
}
int fibo(int n) {
	return (n == 1 || n == 2) ? 1 : fibo(n - 1) + fibo(n - 2);


	
}
#endif
