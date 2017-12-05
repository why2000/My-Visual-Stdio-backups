//#define NOW
#ifdef NOW
#include<iostream>
#include<string>
#include<malloc.h>
#include<vector>
using std::string;
using std::cin;
using std::cout; using std::endl;
using std::vector;
int main() {
	vector<int> buf;
	int num;
	int m = 0;
	cin >> num >> m;
	int idx=0;
	for (int i = 0; num != 0;i++) {
		buf.push_back(num%m);
		num = num / m;
		idx = i;
	}
	for (int i = idx; i >= 0; i--) {
		if (buf[i] < 10) {
			cout << buf[i];
		}
		else
		{
			char foo = buf[i] + 55;
			cout << foo;
		}
	}




	return 0;
}
#endif

