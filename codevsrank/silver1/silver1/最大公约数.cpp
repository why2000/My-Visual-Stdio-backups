//#define NOW
#ifdef NOW
#include<iostream>
#include<string>
#include<malloc.h>
#include<vector>
using std::vector;
using std::string;
using std::cin;
using std::cout; using std::endl;
vector<long long> buf1;
vector<long long> buf2;
int gcd(long long num1, long long num2);
int main() {
	long long num1 = 0;
	long long num2 = 0;
	int res = 0;
	cin >> num1 >> num2;
	res = gcd(num1, num2);
	cout << res;
	return 0;
}


int gcd(long long num1, long long num2) {
	long long res = 1;
	long long sing1 = 0;
	long long sing2 = 0;
	long long dex1 = 0, dex2 = 0;
	if (num1%num2 == 0&&num1>=num2) {
		res = num2;
		goto out;
	}
	else if (num2%num1 == 0 && num2 >= num1) {
		res = num1;
		goto out;
	}
	for (int i = 2; i <= num1; ++i) {
		if (!(num1%i)) {
			sing1 = 0;
			buf1.push_back(i);
			++dex1;
		}
	}
	buf1.push_back(num1);
	for (long long i = 2; i <= num2; ++i) {
		if (!(num2%i)) {
			sing2 = 0;
			buf2.push_back(i);
			++dex2;
		}
	}
	buf2.push_back(num2);
	if (sing1 = 1 && sing2 == 1) {
		res = 1;
	}
	else {
		for (long long i = dex1;i>=0; --i) {
			for (long long j = dex2; j >= 0; --j) {
				if (buf1[i] == buf2[j]) {
					res = buf1[i];
					goto out;
				}
			}
		}
	}
	out:;
	return res;
}
#endif
/*这题可以这样：
int gcd(int x,int y)

{
	return y?gcd(y,x%y):x;//辗转相除法求gcd
}

*/