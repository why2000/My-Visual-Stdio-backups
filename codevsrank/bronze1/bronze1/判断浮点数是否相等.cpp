//#define NOW
#ifdef NOW
#include<iostream>
#include<malloc.h>

using std::cin;
using std::cout; using std::endl;

int main() {
	double in1 = 0.0, in2 = 0.0;
	cin >> in1 >> in2;
	double dif = 0.0;
	if (in1 == in2) {
		cout << "yes" << endl;
	}
	else
	{
		if (in1 > in2) {
			dif = in1 - in2;
		}
		else if (in1 < in2) {
			dif = in2 - in1;
		}
		if (dif <= 1e-8) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}

	return 0;
}
#endif
