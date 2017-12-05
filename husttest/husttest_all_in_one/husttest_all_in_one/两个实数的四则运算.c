//#define NOW
#ifdef NOW
#include<stdio.h>
void way0(const double num1, const double num2, const char syn) {//if
	double res;
	if (syn == '+') {
		res = num1 + num2;
	}
	else if (syn == '-') {
		res = num1 - num2;
	}
	else if (syn == '/') {
		res = (1.0*num1) / num2;
	}
	else if (syn == '*') {
		res = num1*num2;
	}
	printf("After if-else processing,the result is : %.2f\n", res);
}
void way1(double num1, double num2, char syn) {//switch
	double res;
	switch (syn) {
	case '+':
		res = num1 + num2;
		break;
	case '-':
		res = num1 - num2;
		break;
	case '*':
		res = num1*num2;
		break;
	case '/':
		res = (1.0*num1) / num2;
		break;
	default:
		break;
	}
	
	printf("After switch processing,the result is : %.2f\n", res);
}
int main(void) {
	double num1, num2;
	char syn;
	int type;
	while (scanf("%d %lf %lf%*c%c", &type, &num1, &num2, &syn)!=EOF){
		if (type == 0) {
			way0(num1,num2,syn);
			printf("\n");
		}
		else if (type == 1) {
			way1(num1, num2, syn);
			printf("\n");
		}
		else if (type == 2) {
			way0(num1, num2, syn);
			way1(num1, num2, syn);
			printf("\n");
		}
	}
	return 0;
}
#endif
