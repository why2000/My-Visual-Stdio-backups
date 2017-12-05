//#define NOW
#ifdef NOW
#include<iostream>
#include<string>
#include<malloc.h>
#include<math.h>
using std::string;
using std::cin;
using std::cout; using std::endl;

int main() {
	int num = 0;
	cin >> num;
	int issing = 1;
	int end = sqrt(num);
	for (int i = 2; i <= end; i++) {
		if (!(num%i)) {
			issing = 0;
			break;
		}
	}
	if (num == 1) {
		cout << "\\n";
	}else if (issing) {
		cout << "\\t";
	}else{
		cout << "\\n";
	}
	return 0;
}
#endif
