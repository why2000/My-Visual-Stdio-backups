//#define NOW
#ifdef NOW
#include<iostream>
#include<string>
#include<malloc.h>
using std::string;
using std::cin;
using std::cout; using std::endl;

int spec(int n);
int main() {
	int upper=1, lower=1;
	int place = 1;
	cin >> place;
	if (place == 1)cout << 1 << "/" << 1;
	else {
		int spepla = 1;
		for (int i = 1; 1; i++) {
			if ((spec(i) < place&&spec(i + 1) > place) || spec(i + 1) == place) {
				spepla = i + 1;
				break;
			}
		}
		if (spepla % 2 == 0) {//Å¼Êý
			upper = spepla - (spec(spepla) - place);
			lower = 1 + spec(spepla) - place;
		}
		else {//ÆæÊý
			lower = spepla - (spec(spepla) - place);
			upper = 1 + spec(spepla) - place;
		}
		cout << upper << "/" << lower;
	}
	return 0;
}
int spec(int n) {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		res += i;
	}
	return res;
}
#endif