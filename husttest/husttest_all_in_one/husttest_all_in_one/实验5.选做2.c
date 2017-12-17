//#define NOW
#ifdef NOW
#include <stdio.h>

#include <math.h>
void execute(int* count);

int main(void)
{
    int count = 0;
    execute(&count);
    printf("There are %d possible ways\n", count);
    return 0;
}

void execute(int* count)
{
    int i, j, flag;
    int position[9] = { 0 };
    while (position[8] != 1)
    {
        ++position[0];
        //Çî¾Ù
        for (i = 0; i < 8; ++i)
        {
            if (position[i] == 8)
            {
                position[i] = 0;
                ++position[i + 1];
            }
        }
        flag = 1;
        //ÅÐ¶Ï
        for (i = 0; i < 8; ++i)
        {
            for (j = 0; j < 8; ++j)
            {
                if (i != j)
                {
                    if (position[i] == position[j])
                        flag = 0;
                    else if (abs(position[i] - position[j]) == abs(i - j))
                        flag = 0;
                }
            }
        }
        //Êä³ö
        if (flag)
        {
            for (i = 0; i < 8; ++i)
            {
                for (j = 0; j < 8; ++j)
                {
                    if (position[i] == j)
                        printf("1  ");
                    else
                        printf("0  ");
                }
                printf("\n");
            }
            printf("\n");
        }
        *count += flag;
    }
}

#endif
