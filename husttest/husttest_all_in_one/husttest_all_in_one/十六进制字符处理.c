//#define NOW
#ifdef NOW
#include<stdio.h>
int main(void) {
	int n = 0;
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++) {
		
		char s[2];
		int c;
		scanf("%1s", s);
		c = s[0];
		if (c <=57&&c>=48) {
			printf("%d\n", c - 48);
		}
		else if (c <= 70 && c >= 65) {
			printf("%d\n", c - 55);
		}
		else if (c <= 102 && c >= 97) {
			printf("%d\n", c - 87);
		}
		else {
			printf("%d\n",c);
		}
	}


	return 0;
}
#endif