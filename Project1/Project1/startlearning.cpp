#include<stdio.h>
int main(void) {
    double x, a, b, c, d, e;
    x = 1;
    while (x != 0) {
        scanf("%lf", &x);
        if (x != 0) {
            if (x<1000) printf("%lf\n", 0);
            else if (x<2000) {
                a = (x - 1000)*0.05;
                printf("%lf\n", a);
            }
            else if (x<3000) {
                b = (x - 2000)*0.10;
                b = 50 + b;
                printf("%lf\n", b);
            }
            else if (x<4000) {
                c = (x - 3000)*0.15;
                printf("%lf\n", 150 + c);
            }
            else if (x<5000) {
                d = (x - 4000)*0.20;
                printf("%f\n", 300 + d);
            }
            else {
                e = (x - 5000)*0.25;
                printf("%lf\n", 500 + e);
            }
        }
    }
    return 0;
}