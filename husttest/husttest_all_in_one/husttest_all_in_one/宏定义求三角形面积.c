//#define NOW
#ifdef NOW
#include<stdio.h>
#include<math.h>
#define cals(a,b,c) ((a+b+c)/2)
#define calarea(a,b,c) (sqrt(s*(s-a)*(s-b)*(s-c)))
int main(void) {
    double a, b, c, s;
    double area;
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        s = cals(a, b, c);
        area = calarea(a, b, c);
        printf("%.0f %lf\n", s, area);
    }
    return 0;
}
#endif
