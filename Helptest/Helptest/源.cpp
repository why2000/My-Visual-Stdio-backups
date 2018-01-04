#include <stdio.h>
int main(void) {
	int a = 6;
	a += (a++);
	printf("%d", a);
	return 0;
}