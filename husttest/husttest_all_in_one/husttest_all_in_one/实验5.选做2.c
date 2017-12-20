//#define NOW
#ifdef NOW
#include <stdio.h>
void execute(int* sum);

int main(void)
{
    int count = 0;
    execute(&count);
    printf("There are %d possible ways\n", count);
    return 0;
}

void execute(int* sum)
{
    int i, j, flag;
    int pos[9] = { 0 };
    while (pos[8] != 1)
    {
        ++pos[0];
        //穷举,j表示第i行的棋子放在哪一个位置
        for (i = 0; i < 8; ++i)
        {
            if (pos[i] == 8)
            {
                pos[i] = 0;
                ++pos[i + 1];
            }
        }
        flag = 1;
        //判断
        for (i = 0; i < 8; ++i)
        {
            for (j = 0; j < 8; ++j)
            {
                if (i != j)
                {
                    if (pos[i] == pos[j]) {
                        flag = 0;
                        break;
                    }
                    else if ((pos[i] - pos[j]) == (i - j) || (pos[i] - pos[j]) == (j - i)) {
                        flag = 0;
                        break;
                    }
                }
                
            }
            if (!flag)break;
        }
        //输出
        if (flag)
        {
            for (i = 0; i < 8; ++i)
            {
                for (j = 0; j < 8; ++j)
                {
                    if (pos[i] == j)
                        printf("1  ");
                    else
                        printf("0  ");
                }
                printf("\n");
            }
            printf("\n");
        }
        *sum += flag;
    }
}

#endif
