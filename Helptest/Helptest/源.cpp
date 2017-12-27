#include<iostream>
using std::cout; using std::endl;
int main() {
	static int n[2], i, j, k;
	for (i = 0; i < 2; i++) {
		n[j++] = n[i] + i + 1;
	}
	cout << n[k] << 'a' << '\t' <<'b'<< n[k++] << endl;
	return 0;
}