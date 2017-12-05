//#define NOW
#ifdef NOW
#include<stdio.h>
#define fun(x) (((3*x-4)*x-5)*x+13)
#define dfun(x) ((9*x-8)*x-5)
double newtown(double x);
int main(void) {
    int x = 1;
    double res = newtown(x);
    printf("%lf\n", res);
    return 0;
}
double newtown(double x) {
    double newx = x - fun(x) / dfun(x);
    double dec = newx - x;
    while (!(dec < 1e-6&&dec>(-1e-6))) {
        x = newx;
        newx = x - fun(x) / dfun(x);
        dec = newx - x;
    }
    return newx;
}
#endif
