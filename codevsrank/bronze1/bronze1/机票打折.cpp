//#define NOW
#ifdef NOW
#include<iostream>
#include<malloc.h>

using std::cin;
using std::cout; using std::endl;

int main() {
	float ori = 0;
	float rate = 0.0;
	cin >> ori >> rate;
	float now = ori*rate*0.01;
	int output = ((int)(now + 0.5))*10;
	cout << output << endl;




	return 0;
}
#endif
