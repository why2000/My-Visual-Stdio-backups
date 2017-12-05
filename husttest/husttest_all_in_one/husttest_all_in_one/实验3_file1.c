#include "实验3_file.h"
#ifdef NOW
#include<stdio.h>
int x, y;               /* 外部变量的定义性说明 */
char ch;              /* 外部变量的定义性说明 */
int main(void)
{
    x = 10;
    y = 20;
    ch = getchar();
    printf("in file1 x=%d,y=%d,ch is %c\n", x, y, ch);
    func1();
    return 0;
}


#endif
