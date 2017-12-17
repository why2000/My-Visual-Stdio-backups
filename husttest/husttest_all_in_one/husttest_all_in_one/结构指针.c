//#define NOW
#ifdef NOW
#include<stdio.h>
struct Student {
    int num;
    char name[19];
    double score;
};
int main(void) {
    struct Student s[3];
    struct Student *p = &s[0];
    int i, j;
    int time;
    scanf("%d", &time);
    for (time = 0; time < 2; time++) {
        for (i = 0; i < 3; i++) {
            scanf("%d", &s[i].num);
            getchar();
            for (j = 0; (s[i].name[j] = getchar()) != ' '; j++);
            s[i].name[j] = '\0';
            scanf("%lf", &s[i].score);
        }
        for (i = 0; i < 3; i++) {
            printf("%d\t", s[i].num);
            printf("%-20s", s[i].name);
            printf("%lf", s[i].score);
            printf("\n");
        }
        for (p = &s[0]; p < &s[0] + 3; p++) {
            printf("%d\t", p->num);
            printf("%-20s", p->name);
            printf("%lf", p->score);
            printf("\n");
        }
    }
    return 0;
}
#endif
