//#define NOW
#ifdef NOW
#include<stdio.h>
#include<malloc.h>
typedef struct {
    char name[50];
    int score;
} student;
void bisearch(int tar, student* stu, int n);
int main(void) {
    int n;
    int tarscore;
    int i = 0, j = 0;
    printf("Please input the number of students:\n");
    scanf("%d", &n);
    student *stu = (student*)malloc(sizeof(student)*n), temp;
    printf("Please input the info of students:\n");
    for (i = 0; i < n; i++) {
        printf("Name %d:\n", i + 1);
        scanf("%s", &((stu + i)->name));
        printf("Score %d:\n", i + 1);
        scanf("%d", &((stu + i)->score));
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ((stu + j)->score < (stu + j + 1)->score) {
                temp = *(stu + j);
                *(stu + j) = *(stu + j + 1);
                *(stu + j + 1) = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("Name %d: %s\n", i + 1, ((stu + i)->name));
        printf("Score %d: %d\n", i + 1, ((stu + i)->score));
    }
    printf("Please input the score to search:\n");
    scanf("%d", &tarscore);
    bisearch(tarscore, stu, n);
    return 0;
}
void bisearch(int tar, student* stu, int n) {
    int left = 0, right = n - 1, mid = (0 + n) / 2;
    int i;

    while (left <= right) {
        mid = (left + right) / 2;
        if ((stu + mid)->score < tar)
        {
            right = mid - 1;
        }
        else if ((stu + mid)->score > tar)
        {
            left = mid + 1;
        }
        else
        {
            int now;
            int flag1 = 0, flag2 = 0;
            for (i = 0; ; i++) {
                now = mid + i;
                if ((stu + now)->score == tar && (!flag1)) {
                    printf("This is the students with the score of %d :\n", tar);
                    printf("Name: %s    Score: %d\n", (stu + now)->name, (stu + now)->score);
                }
                else {
                    flag1 = 1;
                }
                now = mid - i;
                if ((stu + now)->score == tar && (!flag2) && i != 0) {
                    printf("This is the students with the score of %d :\n", tar);
                    printf("Name: %s    Score: %d\n", (stu + now)->name, (stu + now)->score);
                }
                else {
                    flag2 = 1;
                }
                if (flag1&&flag2)break;
            }
            return;
            
        }
    }
    printf("not found\n");

}
#endif