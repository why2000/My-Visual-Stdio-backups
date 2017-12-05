//#define NOW
#ifdef NOW
#include<iostream>
#include<string>
#include<malloc.h>
using std::string;
using std::cin;
using std::cout; using std::endl;

int main() {
	int n = 0;
	cin >> n;
	int *buttom = (int*)malloc(sizeof(int)*1001);
	for (int i = 0; i < 1001; i++)buttom[i] = 0;
	for (int i = 0; i < n; i++) {
		int buf = 0;
		cin >> buf;
		buttom[buf] += 1;
	}
	int sum = 0;
	int idex = 0;
	for (int i = 0; i < 1001; i++) {
		if (buttom[i]) idex += 1;
	}
	cout << idex << endl;
	int idex2 = 0;
	for (int i = 0; i < 1001; i++) {
		
		if (buttom[i]) {
			cout << i;
			idex2 += 1;
			if (idex2 != n) {
				cout << " ";
			}
		}
		
	}
	cout << endl;

	free(buttom);
	return 0;
}

#endif
