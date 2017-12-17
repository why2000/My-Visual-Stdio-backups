//#define NOW
#ifdef NOW
#include<stdio.h>
typedef struct _date{
    int year;
    int month;
    int day;
}date;
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
    int times;
    int i = 0;
    scanf("%d", &times);
    date *now = (date*)malloc(sizeof(date)*times);
    for (i = 0; i < times; i++)
    {
        scanf("%d %d %d", &now[i].year, &now[i].month, &now[i].day);
        int days = now[i].day;
        switch (now[i].month - 1) {//月份-1后所得月份就是上一个月，要加上其天数
        case 11:
            days += 30;
        case 10:
            days += 31;
        case 9:
            days += 30;
        case 8:
            days += 31;
        case 7:
            days += 31;
        case 6:
            days += 30;
        case 5:
            days += 31;
        case 4:
            days += 30;
        case 3:
            days += 31;
        case 2:
            days += 28;
        case 1:
            days += 31;
        default:
            break;
        }
        if (isspeci(now[i].year)&&now[i].month>2) {
            days += 1;
        }
        printf("%d\n", days);

    }
    return 0;
}
#endif
