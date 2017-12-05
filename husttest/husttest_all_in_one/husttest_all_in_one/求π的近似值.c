//#define NOW
#ifdef NOW
#include<stdio.h>

int main(void) {
	int a;
	int flag = 2;
	double pai = 1.0;
	for (a = 3;; a=a+2)
	{
		if (flag % 2) {
			pai += 1.0 / a;
		}
		else {
			pai -= 1.0 / a;
		}
		flag++;
		
		if ((1.0 / a) < 1e-5)
		{
			break;
		}
	}
	pai *= 4;
	printf("%0.9f\n", pai);
	return 0;

}
#endif
