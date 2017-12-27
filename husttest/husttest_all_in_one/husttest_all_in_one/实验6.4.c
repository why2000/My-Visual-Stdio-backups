//#define NOW
#ifdef NOW
#include<stdio.h>
#define M 3
#define N 3
#define CLALEN 50
#define STULEN 50
void averstu(char* stu, double* gra);
void avercla(char* cla, double* gra);
void lower(char* cla, double* gra);
void failed(char* cla, double* gra);
void great(char* cla, double* gra);
int main(void)
{
    char classes[M][CLALEN], students[N][STULEN];
    double grades[N][M];
    int c, s;
    char * cla = &classes[0][0];
    char * stu = &students[0][0];
    double * gra = &grades[0][0];
    for (c = 0; c < M; c++)
    {
        printf("Please the name of class %d:\n", c + 1);
        gets(classes[c]);
    }
    for (s = 0; s < N; s++)
    {
        printf("Please the name of student %d:\n", s + 1);
		gets(students[s]);
    }
    for (s = 0; s < N; s++)
    {
        for (c = 0; c < M; c++)
        {
            printf("Please enter %s's grade of class \"%s\":\n", students[s], classes[c]);
            scanf("%lf", &grades[s][c]);
        }
    }
    averstu(stu, gra);
    avercla(cla, gra);
    lower(cla, gra);
    failed(cla, gra);
    great(cla, gra);
    return 0;
}

void averstu(char* stu, double* gra) {
    double sum = 0;
    int s_counter, c_counter;
    for (s_counter = 0; s_counter < N; s_counter++)
    {
        sum = 0;
        for (c_counter = 0; c_counter < M; c_counter++) {
            sum += *(gra + s_counter * M + c_counter);
        }
        double avr = sum / M;
        printf("The average grade of student %s is: %lf\n", stu + s_counter * STULEN, avr);
    }
    printf("\n");
}

void avercla(char* cla, double* gra) {
    double sum = 0;
    int c_counter, s_counter;
    for (c_counter = 0; c_counter < M; c_counter++)
    {
        sum = 0;
        for (s_counter = 0; s_counter < N; s_counter++) {
            sum += *(gra + s_counter * M + c_counter);
        }
        double avr = sum / N;
        printf("The average grade of class \"%s\" is: %lf\n", cla + c_counter * CLALEN, avr);
    }
    printf("\n");
}

void lower(char* cla, double* gra) {
    int s_counter, c_counter;
    for (c_counter = 0; c_counter < M; c_counter++)
    {
        double sum = 0;
        int num = 0;
        for (s_counter = 0; s_counter < N; s_counter++) {
            sum += *(gra + s_counter * M + c_counter);
        }
        double avr = sum / N;
        for (s_counter = 0; s_counter < N; s_counter++)
        {
            if (*(gra + s_counter * M + c_counter) < avr)num++;
        }
        printf("There are %d students who were lower than average in class \"%s\"\n", num, cla + c_counter * CLALEN);
        num = 0;
    }
    printf("\n");
}

void failed(char* cla, double* gra) {
    int c_counter, s_counter;
    for (c_counter = 0; c_counter < M; c_counter++)
    {
        int num = 0;
        for (s_counter = 0; s_counter < N; s_counter++)
        {
            if (*(gra + s_counter * M + c_counter) < 60)num++;
        }
        printf("There are %d students who failed class \"%s\"\n", num, cla + c_counter * CLALEN);
        num = 0;
    }
    printf("\n");
}

void great(char* cla, double* gra) {
    int c_counter, s_counter;
    for (c_counter = 0; c_counter < M; c_counter++) {
        int num = 0;
        for (s_counter = 0; s_counter < N; s_counter++)
        {
            if (*(gra + s_counter * M + c_counter) >= 90) num++;
        }
        printf("There are %d students get 90 or higher in class \"%s\"\n", num, cla + c_counter * CLALEN);
    }
    printf("\n");
}

#endif
