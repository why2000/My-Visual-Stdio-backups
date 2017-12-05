//#define NOW
#ifdef NOW
#include<iostream>
#include<stdio.h>
#include<vector>
#include<cctype>

using std::string;
using std::cin;
using std::cout; using std::endl;
using std::vector;

int powwhy(int a, int m);

int main() {
	int n;
	
	char single;
	vector<int> buf;
	int num = 0;
	int dex = 0;
	while (((single = getchar()) != ' ')) {
		if (isdigit((int)single)) {
			single -= 48;
		}
		else if (isupper((int)single)) {
			single -= 55;
		}
		else if (islower((int)single)) {
			single -= 87;
		}
		buf.push_back(single);
		++dex;
	}
	scanf("%d", &n);
	for (int i = 0; i < dex; i++) {
		num += buf[i] * powwhy(n, dex - i - 1);
	}
	cout << num;




	return 0;
}


int powwhy(int a, int m) {
	int res = 1;
	if (m == 0) {
		res = 1;
	}
	else {
		for (int i = 1; i <= m; i++) {
			res *= a;
		}
	}
	return res;

}
#endif
