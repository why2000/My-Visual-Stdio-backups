//#define NOW
#ifdef NOW
#include<stdio.h>
#include<math.h>
#define cals(a,b,c) ((a+b+c)/2)
#define calarea(a,b,c) (sqrt(name*(name-a)*(name-b)*(name-c)))
int main(void) {
    double a, b, c, name;
    double area;
    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        name = cals(a, b, c);
        area = calarea(a, b, c);
        printf("%lf %lf\n", name, area);
    }
    return 0;
}
#endif
