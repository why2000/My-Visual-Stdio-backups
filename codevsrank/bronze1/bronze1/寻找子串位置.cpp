//#define NOW
#ifdef NOW
#include<iostream>
#include<malloc.h>
#include<string>

using std::cin;
using std::cout; using std::endl;
using std::string;

int main() {
	string a;
	string b;
	cin >> a >> b;
	int place;
	place = a.find(b);
	cout << place+1 << endl;

	return 0;
}
#endif
