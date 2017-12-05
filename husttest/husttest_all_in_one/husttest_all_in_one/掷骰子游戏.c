//#define NOW
#ifdef NOW

#include<stdio.h>


int findnum(int steps);
int iscontinue(int j, int sum, int prev);

int main(void) {
    int n;
    scanf("%d", &n);
    int i = 0;
    int prev=-1;
    for (i = 0; i < n; i++) {
        int a, b;
        int flag=0;
        scanf("%d %d", &a, &b);
        int j = 1,prev = -2;
        int sum = findnum(a) + findnum(b);
        while (iscontinue(j, sum, prev) !=-1) {
            if (j == 1) {
                prev = iscontinue(j, sum, prev);
            }
            sum = findnum(a + j) + findnum(b + j);
            ++j;
        }

    }
    return 0;
}

int findnum(int steps) {
    int sum = 0;
    while (steps != 0) {
        sum += steps % 10;
        steps /= 10;
    }
    return (sum % 6 + 1);

}


int iscontinue(int j, int sum, int prev) {
    if (j == 1) {
        if (sum == 7 || sum == 11) {
            printf("success!\n");
            return -1;
        }
        else if (sum == 2 || sum == 3 || sum == 12) {
            printf("fail!\n");
            return -1;
        }
        else {
            return sum;
        }
    }
    else {
        if (sum == 7) {
            printf("fail!\n");
            return -1;
        }
        else if (sum == prev) {
            printf("success!\n");
            return -1;
        }
        else {
            return sum;
        }
    }
}


#endif
