//#define NOW
#ifdef NOW
#include<stdio.h>
int isspeci(const int year) {
	if (year % 4 == 0) {
		if (year % 100 == 0) {
			if (year % 400 == 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 1;
		}
	}
	else {
		return 0;
	}
}
int main(void) {
	int year, month, day;
	
	while (scanf("%d %d %d", &year, &month, &day)!=EOF) {
		int all = 1;
		int days = 1;
		int months = 1;
		if (isspeci(year)) {
			while (!(months == month && days == day)) {
				++days;
				++all;
				if (months == 1 || months == 3 || months == 5 || months == 7 || months == 8 || months == 10 || months == 12) {
					
					if (days == 32) {
						++months;
						days = 1;
					}
				}
				else if (months == 2) {
					if (days == 30) {
						++months;
						days = 1;
					}
				}
				else {
					if (days == 31) {
						++months;
						days = 1;
					}
				}
			}
		}
		else {
			while (!(months == month && days == day)) {
				++days;
				++all;
				if (months == 1 || months == 3 || months == 5 || months == 7 || months == 8 || months == 10 || months == 12) {

					if (days == 32) {
						++months;
						days = 1;
					}
				}
				else if (months == 2) {
					if (days == 29) {
						++months;
						days = 1;
					}
				}
				else {
					if (days == 31) {
						++months;
						days = 1;
					}
				}
			}

		}
		printf("该日期是这一年中的第%d天\n", all);

	}



	return 0;
}
#endif