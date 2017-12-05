//#define NOW
#ifdef NOW
#include<stdio.h>

int main(void) {
	int s1, s2, s3;
	while (scanf("%d %d %d", &s1, &s2, &s3)!=EOF) {
		int mid = s1;
		if (s1 == s2||s1==s3) {
			printf("A:%d\n", s1);
		}
		else if (s2 == s3) {
			printf("B:%d\n", s2);
		}
		else {
			if (s1 < s2) {
				if (s1 > s3) {
					printf("A:%d\n", s1);
				}
				else if (s3 > s2) {
					printf("B:%d\n", s2);
				}
				else {
					printf("C:%d\n", s3);
				}
			}
			else {
				if (s3 > s1) {
					printf("A:%d\n",s1);
				}
				else if (s2 > s3) {
					printf("B:%d\n", s2);
				}
				else {
					printf("C:%d\n", s3);
				}
			}


		}
	}
	return 0;
}

#endif