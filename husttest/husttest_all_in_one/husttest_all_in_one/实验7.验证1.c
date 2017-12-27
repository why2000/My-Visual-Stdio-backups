//#define NOW
#ifdef NOW
#include<stdio.h>
#include<process.h>
int main(void) {
	char u[] = "UVWXYZ";
	char v[] = "xyz";
	struct T {
		int x;
		char c;
		char *t;
	}a[] = { { 11,'A',u },{ 100, 'B',v } }, *p = a;
	
	return 0;
}

#endif