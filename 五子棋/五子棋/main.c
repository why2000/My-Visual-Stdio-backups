#include<windows.h>//COORD结构包含在其中 
#include<stdlib.h>//调用system函数 
#include<stdio.h>
#include<conio.h>//用于存放getch()这个函数 读取键盘信息 
#include<time.h>//生成随机数会用到 
#include<conio.h>  //_kbhit()
#include<mmsystem.h>  //音频库                                              
#pragma comment(lib,"winmm.lib")
#define L 15


int cm[L][L];//存储该点的信息 
int hue = 2;//棋子信息 1为黑子 2为白子 白子先下 
int count = 0;//棋盘上的总棋子数 
int mode;//游戏模式 

//函数总体申明 之后嵌套会很多 所以一起先申明 
void star_print();  //打印游戏开始函数
void board_print();  //打印棋盘数据
void mode_print(int mode);//打印模式 
void movegb(char key); //键盘控制光标 
void gotoxy(int x, int y);//计算机移动光标 
void initial();    //初始化棋盘数据
void PC_game();   //人机博弈
void TP_game(); //双人博弈
int chessjudge(int x, int y); //判断能否下子
int chessjudgewin(int x, int y, int hue);  //判断输赢
int chesscomputer(); //电脑下棋
int chessscore(int x, int y, int hue); //棋盘权值函数



struct coordinate
{
    int x;
    int y;
}location = { 7, 9 };//坐标初始化 


int main()
{
    int choice = 0;
    system("title  [五子棋]");//磁盘操作系统 
    system("color f3");//用 system("color 0A"); 其中color后面的0是背景色代号，A是前景色代号。各颜色代码如下：0=黑色 1=蓝色 2=绿色 3=湖蓝色 4=红色 5=紫色 6=黄色 7=白色 8=灰色 9=淡蓝色 A=淡绿色 B=淡浅绿色 C=淡红色 D=淡紫色 E=淡黄色 F=亮白色 
    system("mode con cols=83 lines=35");//窗口宽度高度
    while (1)
    {
        star_print();
        printf("\n\n\n              请输入你的选择 :");
        while (1)
        {
            choice = _getch();
            if(choice==27)
                {
                    exit(0);
                }
            else if (choice == 49)  //人机博弈
                {
                	
                    PC_game();
                    break;
                }
            else if (choice == 50)  //双人博弈
                {
                    TP_game();
                    break;
                }
        }
        system("cls");
    }
    return 0;
}


void gotoxy(int x, int y) //计算机移动光标 
{
    COORD c; //c是一个结构  
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//获取窗口句柄 设置光标位置  
}
/*COORD是Windows API中定义的一种结构，表示一个字符在控制台屏幕上的坐标。其定义为：
typedef struct _COORD {
SHORT X; // horizontal coordinate
SHORT Y; // vertical coordinate
} COORD;*/ 

void star_print()
{
printf("\n\n\n\n\n");
printf("                                     五子棋                     \n\n\n");
printf("                                    游戏说明                      \n");
printf("                                                               \n");
printf("                       1: 黑子由机器使用                       \n");
printf("\n");
printf("                       2: 白子由人使用                         \n");
printf("                                                               \n");
printf("\n");
printf("\n\n              人机博弈按：1   双人博弈按：2   退出按：Esc ");
}


void board_print()
{ 
int i, j, k; 
mode_print(mode);//在图形界面上的打印  是人机还是双人 
for (j = 0; j<L; j++)
{
for (i = 0; i<L; i++)
{
if (cm[j][i] == 1)
{printf("●");fflush(stdout);}
else if (cm[j][i] == 2)
{printf("○");fflush(stdout);}
else if (j == 0 && i == 0)
{printf("┏");fflush(stdout);}
else if (j == 0 && i == L - 1)
{printf("┓");fflush(stdout);}
else if (j == L - 1 && i == 0)
{printf("┗");fflush(stdout);}
else if (j == L - 1 && i == L - 1)
{printf("┛");fflush(stdout);}
else if (j == 0 && i != 0 && i != L - 1)
{printf("┯");fflush(stdout);}
else if (j != 0 && j != L - 1 && i == 0)
{printf("┠");fflush(stdout);}
else if (j != 0 && j != L - 1 && i == L - 1)
{printf("┨");fflush(stdout);}
else if (j == L - 1 && i != 0 && i != L - 1)
{printf("┷");fflush(stdout);}
else if (j != 0 && j != L - 1 && i != 0 && i != L - 1)
{printf("┼");fflush(stdout);}
if (j>0 && j<L - 1 && i<L - 1)
{printf("—");fflush(stdout);}
if (j == 0 && i != L - 1)
{printf("━");fflush(stdout);}
else if (j == L - 1 && i != L - 1)
{printf("━");fflush(stdout);}
}
printf("\n");
if (j >= 0 && j<L - 1)
{
for (k = 0; k<L; k++)
{
if (k == 0 || k == L - 1)
{printf("┃  ");fflush(stdout);}
else {printf("│  ");fflush(stdout);}
}
if (j == 2)
printf("  操作 - PS ");
if (j == 4)
printf("  重玩按：n ");
if (j == 5)
printf(" 返回按：Backspace");
if (j == 6)
printf(" 退出按：Esc");
if(j == 7)
printf("  空格下子  ");
if(j == 8)
printf(" 上 下 左 右");
if(j == 9)
printf("   移动光标 ");
if(j==10&&mode==2)
{
	if(count%2==0) printf("白子");
	else printf("黑子");
}
}
printf("\n");
}
}	


void mode_print(int x)
{
if (x == 1)
printf("\n\n                   五子棋--人机博弈 \n\n\n");
else printf("\n\n                   五子棋--双人博弈 \n\n\n");
}

void movegb(char key)/*光标的移动*///0x48 0x50 0x4B 0x4D是键盘的扫描码 
{
switch (key)
{
case 0x48:if (location.y>1)location.y--; if (location.y<2)location.y = L + 1; break;/*光标向上移动*/
case 0x50:if (location.y<L + 2)location.y++; if (location.y>L + 1)location.y = 2; break;/*光标向下移动*/
case 0x4B:if (location.x>-1)location.x--; if (location.x<0)location.x = L - 1; break;/*光标向左移动*/
case 0x4D:if (location.x<L)location.x++; if (location.x>L - 1)location.x = 0; break;/*光标向右移动*/
}
gotoxy(4 * location.x, 2 * location.y);
}

void initial()//注意到二次游戏可能会带来的影响 
{
int i, j;
for (j = 0; j<L; j++) for (i = 0; i<L; i++) cm[i][j] = 0;//将棋子信息初始化为零（如果没有 第二次游戏时便不会初始化） 
hue = 2;//白子先走 
count = 0;
system("cls");//清除屏幕 
board_print();//打印棋盘 
location.x = 50;//光标最初的位置 
location.y = 50;
gotoxy(location.x, location.y);
}


int chessjudge(int x, int y)
{
if (cm[x][y] != 0)
return 1;
return 0;
}

int chessjudgewin(int x, int y, int hue)
{
int row, col, count;
row = x, col = y; count = 0;
while (cm[row][col] == hue && col < L)
{
    count++;
    col++;
}
col = y - 1;
while (cm[row][col] == hue && col >= 0)
{
count++;
col--;
}
if (count >= 5)
return 1;

row = x, col = y; count = 0;
while (cm[row][col] == hue && row < L)
{
count++;
row++;
}
row = x - 1;
while (cm[row][col] == hue && row >= 0)
{
count++;
row--;
}
if (count >= 5)
return 1;

row = x, col = y; count = 0;
while (cm[row][col] == hue && col < L && row < L)
{
count++;
col++;
row++;
}
col = y - 1, row = x - 1;
while (cm[row][col] == hue && col >= 0 && row >= 0)
{
count++;
col--;
row--;
}
if (count >= 5)
return 1;


row = x, col = y; count = 0;
while (cm[row][col] == hue && col < L && row >= 0)
{
count++;
col++;
row--;
}
col = y - 1, row = x + 1;
while (cm[row][col] == hue && col >= 0 && row < L)
{
count++;
col--;
row++;
}
if (count >= 5)
return 1;

return 0;
}


int chesscomputer()
{
    int i, j, cscore, cscorel, pscore, pscorel, row1, col1, row2, col2, x, y;
    cscore = pscore = 0; row1 = row2 = col1 = col2 = 0;
    if (count == 1)
    {
        srand((unsigned)time(NULL));
        row1 = rand() % 15;
        col1 = rand() % 15;
        count++;//随机生成一个位置 棋子数加一 
/*rand函数在产生随机数前，需要系统提供的生成伪随机数序列的种子，rand根据这个种子的值产生一系列随机数。如果系统提供的种子没有
变化，每次调用rand函数生成的伪随机数序列都是一样的。srand(unsigned seed)通过参数seed改变系统提供的种子值，从而可以使得每次调
用rand函数生成的伪随机数序列不同，从而实现真正意义上的“随机”。通常可以利用系统时间来改变系统的种子值，即srand(time(NULL))，
可以为rand函数提供不同的种子值，进而产生不同的随机数序列*/
        while (chessjudge(row1, col1))
        {
            row1 = rand() % 15;
            col1 = rand() % 15;
        }//该位置不为0 则随机生成另一个位置 直到可以下子
        cm[row1][col1] = 1;//将此点改成已经有黑子的信息
        hue = 3 - hue;//棋子改为白子（2）
        system("cls");
        board_print();
        /*x = abs(location.x - col1);//x y 用于储存距离 
        y = abs(location.y - 2 - row1);

       if (location.x - col1>0) for (i = 0; i < x; i++) movegb(0x4B);
       else for (i = 0; i < x; i++) movegb(0x4D);

       if (location.y - 2 - row1>0) for (i = 0; i < y; i++) movegb(0x48);
       else for (i = 0; i < y; i++) movegb(0x50);

       printf("●"); */
    }
    else
    {
        for (i = 0; i < L; i++) for (j = 0; j < L; j++)if (!chessjudge(i, j))
        {
            cscorel = chessscore(i, j, 1);
            if (cscorel > cscore)
            {
                cscore = cscorel;
                row1 = i;
                col1 = j;
            }
           
		    pscorel = chessscore(i, j, 2);
            if (pscorel > pscore)
            {
                pscore = pscorel;
                row2 = i;
                col2 = j;
            }
        }
        if (count == 3)
        {
            cm[row1][col1] = 1;
            hue = 3 - hue;
            count++;
            system("cls"); 
            board_print();
            /*x = abs(location.x - col1);
            y = abs(location.y - 2 - row1);

            if (location.x - col1>0) for (i = 0; i < x; i++) movegb(0x4B);
            else for (i = 0; i < x; i++) movegb(0x4D);

            if (location.y - 2 - row1>0) for (i = 0; i < y; i++) movegb(0x48);
            else for (i = 0; i < y; i++) movegb(0x50);

            printf("●");*/ 
        }
        else//下了三个棋子以上 
     	{
            if (cscore >= pscore)
            {
                cm[row1][col1] = 1;
                hue = 3 - hue;
                count++;
                system("cls");
                board_print();
                /*x = abs(location.x - col1);
                y = abs(location.y - 2 - row1);

                if (location.x - col1>0) for (i = 0; i < x; i++) movegb(0x4B);
                else for (i = 0; i < x; i++) movegb(0x4D);

                if (location.y - 2 - row1>0) for (i = 0; i < y; i++) movegb(0x48);
                else for (i = 0; i < y; i++) movegb(0x50);

                printf("●");*/ 
                if (chessjudgewin(row1, col1, 1))
                {
                    gotoxy(22, 17);
                    printf("【 黑子胜利 】");
                    return 1;
                }
            }
            else
            {
                cm[row2][col2] = 1;
                hue = 3 - hue;
                count++;
                system("cls");
                board_print();
                /*x = abs(location.x - col2);
                y = abs(location.y - 2 - row2);

                if (location.x - col2>0) for (i = 0; i < x; i++) movegb(0x4B);
                else for (i = 0; i < x; i++) movegb(0x4D);

                if (location.y - 2 - row2>0)for (i = 0; i < y; i++) movegb(0x48);
                else for (i = 0; i < y; i++) movegb(0x50);
                printf("●");*/ 

                if (chessjudgewin(row2, col2, 1))
                {
                    gotoxy(22, 17);
                    printf("【 黑子胜利 】");
                    return 1;
                }
            }
        }
    }
return 0;
}


int chessscore(int x, int y, int hue)   //棋盘权值函数
{
    int count3,count4,row,col,count1,count2,sumscore = 0;//1表示横向 2表示竖向 3表示斜上方向 4表示斜下方向
    char u,d,l,r,lu,ld,ru,rd;//u上 d下 l左 r右 lu左斜上 ld左斜下 ru右斜上 rd右斜下

    count1=count2=count3=count4=1;//假设落子后该方向必然有一个 
    l=r=u=d=lu=ld=ru=rd=0;

    cm[x][y]=hue;//假设下在某一个位置 
/*---------------------------------------①判断横向棋子并记录空格子---------------------------*/
    row = x, col = y + 1;
    while (cm[row][col] == hue && col < L)
    {
        count1++;
        col++;
    }
    while (col < L && cm[row][col] == 0)//向上数有几个空格 
    {
        r++;
        col++;
    }
    row = x, col = y - 1;
    while (cm[row][col] == hue && col >= 0)
    {
        count1++;
        col--;
    }
    while (col >= 0 && cm[row][col] == 0)
    {
        l++;
        col--;
    }
/*------------------------------------------------------------------------------------------*/

/*-------------------------------------②判断竖向棋子并记录空格子---------------------------*/
    row = x + 1, col = y;
    while (cm[row][col] == hue && row < L)
    {
        count2++;
        row++;
    }
    while (row < L && cm[row][col] == 0)
    {
        d++;
        row++;
    }
    row = x - 1, col = y;
    while (cm[row][col] == hue && row >= 0)
    {
        count2++;
        row--;
    }
    while (row >= 0 && cm[row][col] == 0)
    {
        u++;
        row--;
    }
/*------------------------------------------------------------------------------------------*/


/*------------------------------------③判断斜上向棋子并记录空格子--------------------------*/
    row = x - 1, col = y + 1;
    while (cm[row][col] == hue && col < L && row >= 0)
    {
        count3++;
        col++;
        row--;
    }
    while (col < L && row >= 0 && cm[row][col] == 0)
    {
        ru++;
        col++;
        row--;
    }
    row = x + 1, col = y - 1;
    while (cm[row][col] == hue && col >= 0 && row < L)
    {
        count3++;
        col--;
        row++;
    }
    while (col >= 0 && row < L && cm[row][col] == 0)
    {
        ld++;
        col--;
        row++;
    }
/*------------------------------------------------------------------------------------------*/

/*-----------------------------------④判断斜下向棋子并记录空格子---------------------------*/
    row = x + 1, col = y + 1;
    while (cm[row][col] == hue && col < L && row < L)
    {
        count4++;
        col++;
        row++;
    }
    while (col < L && row < L && cm[row][col] == 0)
    {
        rd++;
        col++;
        row++;
    }
    row = x - 1, col = y - 1;
    while (cm[row][col] == hue && col >= 0 && row >= 0)
    {
        count4++;
        col--;
        row--;
    }
    while (col >= 0 && row >= 0 && cm[row][col] == 0)
    {
        lu++;
        col--;
        row--;
    }
/*---------------------------------------------计算赢面---------------------------------------------*/

    cm[x][y] = 0;//统计完毕 假设取消 计算赢面 

    if (count1 >= 5 || count2 >= 5 || count3 >= 5 || count4 >= 5) return sumscore = 5000;

    if ((count1 == 4 && count2 == 4 && l >= 1 && r >= 1 && u >= 1 && d >= 1) ||
       (count1 == 4 && count3 == 4 && l >= 1 && r >= 1 && ru >= 1 && ld >= 1) ||
       (count1 == 4 && count4 == 4 && l >= 1 && r >= 1 && rd >= 1 && lu >= 1) ||
       (count2 == 4 && count3 == 4 && u >= 1 && d >= 1 && ru >= 1 && ld >= 1) ||
       (count2 == 4 && count4 == 4 && u >= 1 && d >= 1 && lu >= 1 && rd >= 1) ||
       (count3 == 4 && count4 == 4 && ru >= 1 && ld >= 1 && lu >= 1 && rd >= 1))   //判断双活四
       return sumscore = 4000;

    if ((count1 == 4 && l >= 1 && r >= 1) || (count2 == 4 && u >= 1 && d >= 1) ||
       (count3 == 4 && ru >= 1 && ld >= 1) || (count4 == 4 && lu >= 1 && rd >= 1))   //判断活四
        return sumscore = 800;
      
    if ((count1 == 4 && ((l == 0 && r >= 1) || (l >= 1 && r == 0))) ||
       (count2 == 4 && ((u == 0 && d >= 1) || (u >= 1 && d == 0))) ||
       (count3 == 4 && ((ld == 0 && ru >= 1) || (ld >= 1 && ru == 0))) || 
	   (count4 == 4 && ((lu == 0 && rd >= 1) || (lu >= 1 && rd == 0))))
       sumscore = sumscore + 35;  //成四
       
    if((((count1==3&&count2==4)||(count1==4&&count2==3))&&l>=1&&r>=1&&u>=1&&d>=1)||
	   (((count1==3&&count3==4)||(count1==4&&count3==3))&&l>=1&&r>=1&&ru>=1&&ld>=1)||
	   (((count1==3&&count4==4)||(count1==4&&count4==3))&&l>=1&&r>=1&&lu>=1&&rd>=1)||
	   (((count2==3&&count3==4)||(count2==4&&count3==3))&&u>=1&&d>=1&&ru>=1&&ld>=1)||
	   (((count2==3&&count4==4)||(count2==4&&count4==3))&&u>=1&&d>=1&&lu>=1&&rd>=1)||
	   (((count3==3&&count4==4)||(count3==4&&count4==3))&&lu>=1&&rd>=1&&ru>=1&&ld>=1)) //四活且三活 
	   return sumscore+600;                                                              
	   
    if((count1==3&&count2==3&&l>=1&&r>=1&&u>=1&&d>=1)||
      (count1==3&&count3==3&&l>=1&&r>=1&&ru>=1&&ld>=1)||
      (count1==3&&count4==3&&l>=1&&r>=1&&rd>=1&&lu>=1)||
      (count2==3&&count3==3&&u >=1 && d >=1 && ru >=1 && ld >=1 ) ||
      (count2 == 3 && count4 == 3 && u >=1 && d >=1 && lu >=1 && rd >=1 ) ||
      (count3 == 3 && count4 == 3 && ru >=1 && ld >=1 && lu >=1 && rd >=1))   //判断双活三
      return sumscore + 400;


    if((count1 == 3 && l >= 1 && r >= 1) || (count2 == 3 && u >= 1 && d >= 1) ||
      (count3 == 3 && ru >= 1 && ld >= 1) || (count4 == 3 && lu >= 1 && rd >= 1))
    { 
        sumscore = sumscore + 60;
        return sumscore;
    }     //判断活三

    if ((count1 == 2 && count2 == 2 && l >= 1 && r >= 1 && u >= 1 && d >= 1) ||
       (count1 == 2 && count3 == 2 && l >= 1 && r >= 1 && ru >= 1 && ld >= 1) ||
       (count1 == 2 && count4 == 2 && l >= 1 && r >= 1 && rd >= 1 && lu >= 1) ||
       (count2 == 2 && count3 == 2 && u >= 1 && d >= 1 && ru >= 1 && ld >= 1) ||
       (count2 == 2 && count4 == 2 && u >= 1 && d >= 1 && lu >= 1 && rd >= 1) ||
       (count3 == 2 && count4 == 2 && ru >= 1 && ld >= 1 && lu >= 1 && rd >= 1))
       sumscore = sumscore + 20;   //判断双活二

    if ((count1 == 2 && l >= 1 && r >= 1) || (count2 == 2 && u >= 1 && d >= 1) ||
       (count3 == 2 && ru >= 1 && ld >= 1) || (count4 == 2 && lu >= 1 && rd >= 1))
       sumscore = sumscore + 10;     //单活二
       
    return sumscore;
}


void PC_game()
{
    int c = 0,w = 0;
    char key;
    mode = 1;
    while (1)
    {
        initial();
        w = 0;
        printf("按任意键开始"); 
        while (1)
        { 
            key = _getch();/*带下划线_的函数一般是函数库内部的函数，而不带下划线的一般是提供给用户使用的函数。带下划线的目的是为了防止用
            户定义的函数和函数库的函数重名冲突，所以直接使用也是可以的。*/ 
            if(w == 0)
            {
                location.x = 7;
                location.y = 9;
                gotoxy(location.x, location.y);//移动光标 到初始位置 
                w++;
            }
    
           if (key == 27) exit(0);
           else if (key == 8) break;//返回主界面
           else if (key == 110) break; //重新玩
           else if (key == 32)//下子 
           {
                if (count == L * L)
                { 
                    gotoxy(22, 13);
                    printf("【 平局 】");
                    count = 0;
                    break;
                }
                else if (hue == 2)//白子 
                {
                if(!chessjudge(location.y - 2, location.x))
                {
                    printf("○");
                    cm[location.y - 2][location.x] = hue;
                    count++;
                    //system("cls");
					//board_print(); 
                    if (chessjudgewin(location.y - 2, location.x, hue))//每下一子判断一次 
                    {
                        gotoxy(22, 15);
                        printf("【 白子胜利 】");
                        key = _getch();
                        while(key != 27 && key != 110 && key != 8) key = _getch();
                        if(key == 8 || key == 110) break;
                        else exit(0);//退出游戏 
                    }
                    else 
                    {   
                        hue=3-hue;
                        c=chesscomputer();//电脑下棋  该函数包括了判断输赢 
                        if(c)//黑子胜利 
                        {
                            key = _getch();
                            while(key != 27 && key != 110 && key != 8) key = _getch(); 
                            if(key == 8 || key == 110) break;
                            else exit(0);
                        }
                    }      
                    }
                }
            }
            else  //光标移动
            {
                key = _getch();
                movegb(key);//每getch一次都要调用一次 
            }
        }
        if (key == 8) break;
    }
}



void TP_game()
{
int w = 0;
char key;
mode = 2;
while(1)
{
initial();
w = 0;
while(1)
{
key = _getch();
if(w == 0)
{
location.x = 7;
location.y = 9;
gotoxy(location.x, location.y);
w++;
}
if (key == 27)   //退出游戏
{
exit(0);
}
else if (key == 8)   //返回主界面
{
break;
}
else if (key == 110)  //重新玩
{
break;
}
else if(key == 32)//空格 
{
if(hue == 2)
{
if(chessjudge(location.y-2,location.x) == 0)
{
cm[location.y-2][location.x] = 2;
//printf("○");
count++;
system("cls");
board_print();
if(chessjudgewin(location.y-2,location.x,hue))
{
gotoxy(22, 15);
printf("【 白子胜利 】");
key = _getch();
while(key != 27 && key != 110 && key != 8)
key = _getch();
if(key == 8 || key == 110)
break;
else exit(0);
}
hue = 3 - hue;//轮流 
}
}
else
{

if(chessjudge(location.y-2,location.x) == 0)
{
cm[location.y-2][location.x] = 1;
//printf("●");
count++;
system("cls");
board_print();
if(chessjudgewin(location.y-2,location.x,hue))
{
gotoxy(22, 15);
printf("【 黑子胜利 】");
key = _getch();
while(key != 27 && key != 110 && key != 8) key = _getch();
if(key == 8 || key == 110) break;
else exit(0);
}
hue = 3 - hue;
}
}
}
else
{
key = _getch();
movegb(key);
}
}
if (key == 8)
break;
}
}



