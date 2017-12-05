//#define NOW
#ifdef NOW
#include<stdio.h>
void wayif(double x);
void waysw(double x);
int main(void) {
    double x;
    scanf("%lf", &x);
    wayif(x);
    waysw(x);
    return 0;
}

void wayif(double x) {
    double res = 0;
    if (x < 1000) {
        res = 1000 * 0;
    }
    else if (x < 2000) {
        res = 1000 * 0 + (x - 1000)*0.05;
    }
    else if (x < 3000) {
        res = 1000 * (0 + 0.05) + (x - 2000)*0.10;
    }
    else if (x < 4000) {
        res = 1000 * (0 + 0.05 + 0.10) + (x - 3000)*0.15;
    }
    else if (x < 5000) {
        res = 1000 * (0 + 0.05 + 0.10 + 0.15) + (x - 4000)*0.20;
    }
    else  {
        res = 1000 * (0 + 0.05 + 0.10 + 0.15 + 0.20) + (x - 5000)*0.25;
    }
    printf("In if way, tax is :%lf\n", res);
}

void waysw(double x) {
    double res = 0;
    switch ((int)x / 1000) {
    case 0:
        res = 1000 * 0;
        break;
    case 1:
        res = 1000 * 0 + (x - 1000)*0.05;
        break;
    case 2:
        res = 1000 * (0 + 0.05) + (x - 2000)*0.10;
        break;
    case 3:
        res = 1000 * (0 + 0.05 + 0.10) + (x - 3000)*0.15;
        break;
    case 4:
        res = 1000 * (0 + 0.05 + 0.10 + 0.15) + (x - 4000)*0.20;
        break;
    default:
        res = 1000 * (0 + 0.05 + 0.10 + 0.15 + 0.20) + (x - 5000)*0.25;
        break;
    }
    printf("In switch way, tax is :%lf\n", res);
}

#endif
