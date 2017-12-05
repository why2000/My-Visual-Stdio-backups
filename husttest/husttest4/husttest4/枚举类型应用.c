//#define NOW
#ifdef NOW
#include<stdio.h>
void output(int a,int d);
int febday(int y);
int main(void) {
	
	int day = 0;
	int year = 0;
	scanf("%d", &year);
	day=febday(year);
	for (int i = 1; i <= 12; i++) {
		output(i,day);

	}
	return 0;
}
void output(int a,int d) {
	enum month{jan=1,feb,mar,apr,may,jun,jul,aug,sept,oct,nov,dec}mon;
	mon = (enum month)a;
	switch (mon) {
	case jan:
		printf("January,31\n");
		break;
	case feb:
		printf("February,%d\n",d);
		break;
	case mar:
		printf("March,31\n");
		break;
	case apr:
		printf("April,30\n");
		break;
	case may:
		printf("May,31\n");
		break;
	case jun:
		printf("June,30\n");
		break;
	case jul:
		printf("July,31\n");
		break;
	case aug:
		printf("August,31\n");
		break;
	case sept:
		printf("September,30\n");
		break;
	case oct:
		printf("October,31\n");
		break;
	case nov:
		printf("November,30\n");
		break;
	case dec:
		printf("December,31\n");
		break;

	}


}
int febday(int y) {
	if ((y % 100) != 0) {
		if (y % 4 == 0) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else if (y % 400 == 0) {
		return 29;
	}
	else {
		return 28;
	}
}
#endif
