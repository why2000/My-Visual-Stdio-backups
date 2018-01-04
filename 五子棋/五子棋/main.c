#include<windows.h>//COORD�ṹ���������� 
#include<stdlib.h>//����system���� 
#include<stdio.h>
#include<conio.h>//���ڴ��getch()������� ��ȡ������Ϣ 
#include<time.h>//������������õ� 
#include<conio.h>  //_kbhit()
#include<mmsystem.h>  //��Ƶ��                                              
#pragma comment(lib,"winmm.lib")
#define L 15


int cm[L][L];//�洢�õ����Ϣ 
int hue = 2;//������Ϣ 1Ϊ���� 2Ϊ���� �������� 
int count = 0;//�����ϵ��������� 
int mode;//��Ϸģʽ 

//������������ ֮��Ƕ�׻�ܶ� ����һ�������� 
void star_print();  //��ӡ��Ϸ��ʼ����
void board_print();  //��ӡ��������
void mode_print(int mode);//��ӡģʽ 
void movegb(char key); //���̿��ƹ�� 
void gotoxy(int x, int y);//������ƶ���� 
void initial();    //��ʼ����������
void PC_game();   //�˻�����
void TP_game(); //˫�˲���
int chessjudge(int x, int y); //�ж��ܷ�����
int chessjudgewin(int x, int y, int hue);  //�ж���Ӯ
int chesscomputer(); //��������
int chessscore(int x, int y, int hue); //����Ȩֵ����



struct coordinate
{
    int x;
    int y;
}location = { 7, 9 };//�����ʼ�� 


int main()
{
    int choice = 0;
    system("title  [������]");//���̲���ϵͳ 
    system("color f3");//�� system("color 0A"); ����color�����0�Ǳ���ɫ���ţ�A��ǰ��ɫ���š�����ɫ�������£�0=��ɫ 1=��ɫ 2=��ɫ 3=����ɫ 4=��ɫ 5=��ɫ 6=��ɫ 7=��ɫ 8=��ɫ 9=����ɫ A=����ɫ B=��ǳ��ɫ C=����ɫ D=����ɫ E=����ɫ F=����ɫ 
    system("mode con cols=83 lines=35");//���ڿ�ȸ߶�
    while (1)
    {
        star_print();
        printf("\n\n\n              ���������ѡ�� :");
        while (1)
        {
            choice = _getch();
            if(choice==27)
                {
                    exit(0);
                }
            else if (choice == 49)  //�˻�����
                {
                	
                    PC_game();
                    break;
                }
            else if (choice == 50)  //˫�˲���
                {
                    TP_game();
                    break;
                }
        }
        system("cls");
    }
    return 0;
}


void gotoxy(int x, int y) //������ƶ���� 
{
    COORD c; //c��һ���ṹ  
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);//��ȡ���ھ�� ���ù��λ��  
}
/*COORD��Windows API�ж����һ�ֽṹ����ʾһ���ַ��ڿ���̨��Ļ�ϵ����ꡣ�䶨��Ϊ��
typedef struct _COORD {
SHORT X; // horizontal coordinate
SHORT Y; // vertical coordinate
} COORD;*/ 

void star_print()
{
printf("\n\n\n\n\n");
printf("                                     ������                     \n\n\n");
printf("                                    ��Ϸ˵��                      \n");
printf("                                                               \n");
printf("                       1: �����ɻ���ʹ��                       \n");
printf("\n");
printf("                       2: ��������ʹ��                         \n");
printf("                                                               \n");
printf("\n");
printf("\n\n              �˻����İ���1   ˫�˲��İ���2   �˳�����Esc ");
}


void board_print()
{ 
int i, j, k; 
mode_print(mode);//��ͼ�ν����ϵĴ�ӡ  ���˻�����˫�� 
for (j = 0; j<L; j++)
{
for (i = 0; i<L; i++)
{
if (cm[j][i] == 1)
{printf("��");fflush(stdout);}
else if (cm[j][i] == 2)
{printf("��");fflush(stdout);}
else if (j == 0 && i == 0)
{printf("��");fflush(stdout);}
else if (j == 0 && i == L - 1)
{printf("��");fflush(stdout);}
else if (j == L - 1 && i == 0)
{printf("��");fflush(stdout);}
else if (j == L - 1 && i == L - 1)
{printf("��");fflush(stdout);}
else if (j == 0 && i != 0 && i != L - 1)
{printf("��");fflush(stdout);}
else if (j != 0 && j != L - 1 && i == 0)
{printf("��");fflush(stdout);}
else if (j != 0 && j != L - 1 && i == L - 1)
{printf("��");fflush(stdout);}
else if (j == L - 1 && i != 0 && i != L - 1)
{printf("��");fflush(stdout);}
else if (j != 0 && j != L - 1 && i != 0 && i != L - 1)
{printf("��");fflush(stdout);}
if (j>0 && j<L - 1 && i<L - 1)
{printf("��");fflush(stdout);}
if (j == 0 && i != L - 1)
{printf("��");fflush(stdout);}
else if (j == L - 1 && i != L - 1)
{printf("��");fflush(stdout);}
}
printf("\n");
if (j >= 0 && j<L - 1)
{
for (k = 0; k<L; k++)
{
if (k == 0 || k == L - 1)
{printf("��  ");fflush(stdout);}
else {printf("��  ");fflush(stdout);}
}
if (j == 2)
printf("  ���� - PS ");
if (j == 4)
printf("  ���水��n ");
if (j == 5)
printf(" ���ذ���Backspace");
if (j == 6)
printf(" �˳�����Esc");
if(j == 7)
printf("  �ո�����  ");
if(j == 8)
printf(" �� �� �� ��");
if(j == 9)
printf("   �ƶ���� ");
if(j==10&&mode==2)
{
	if(count%2==0) printf("����");
	else printf("����");
}
}
printf("\n");
}
}	


void mode_print(int x)
{
if (x == 1)
printf("\n\n                   ������--�˻����� \n\n\n");
else printf("\n\n                   ������--˫�˲��� \n\n\n");
}

void movegb(char key)/*�����ƶ�*///0x48 0x50 0x4B 0x4D�Ǽ��̵�ɨ���� 
{
switch (key)
{
case 0x48:if (location.y>1)location.y--; if (location.y<2)location.y = L + 1; break;/*��������ƶ�*/
case 0x50:if (location.y<L + 2)location.y++; if (location.y>L + 1)location.y = 2; break;/*��������ƶ�*/
case 0x4B:if (location.x>-1)location.x--; if (location.x<0)location.x = L - 1; break;/*��������ƶ�*/
case 0x4D:if (location.x<L)location.x++; if (location.x>L - 1)location.x = 0; break;/*��������ƶ�*/
}
gotoxy(4 * location.x, 2 * location.y);
}

void initial()//ע�⵽������Ϸ���ܻ������Ӱ�� 
{
int i, j;
for (j = 0; j<L; j++) for (i = 0; i<L; i++) cm[i][j] = 0;//��������Ϣ��ʼ��Ϊ�㣨���û�� �ڶ�����Ϸʱ�㲻���ʼ���� 
hue = 2;//�������� 
count = 0;
system("cls");//�����Ļ 
board_print();//��ӡ���� 
location.x = 50;//��������λ�� 
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
        count++;//�������һ��λ�� ��������һ 
/*rand�����ڲ��������ǰ����Ҫϵͳ�ṩ������α��������е����ӣ�rand����������ӵ�ֵ����һϵ������������ϵͳ�ṩ������û��
�仯��ÿ�ε���rand�������ɵ�α��������ж���һ���ġ�srand(unsigned seed)ͨ������seed�ı�ϵͳ�ṩ������ֵ���Ӷ�����ʹ��ÿ�ε�
��rand�������ɵ�α��������в�ͬ���Ӷ�ʵ�����������ϵġ��������ͨ����������ϵͳʱ�����ı�ϵͳ������ֵ����srand(time(NULL))��
����Ϊrand�����ṩ��ͬ������ֵ������������ͬ�����������*/
        while (chessjudge(row1, col1))
        {
            row1 = rand() % 15;
            col1 = rand() % 15;
        }//��λ�ò�Ϊ0 �����������һ��λ�� ֱ����������
        cm[row1][col1] = 1;//���˵�ĳ��Ѿ��к��ӵ���Ϣ
        hue = 3 - hue;//���Ӹ�Ϊ���ӣ�2��
        system("cls");
        board_print();
        /*x = abs(location.x - col1);//x y ���ڴ������ 
        y = abs(location.y - 2 - row1);

       if (location.x - col1>0) for (i = 0; i < x; i++) movegb(0x4B);
       else for (i = 0; i < x; i++) movegb(0x4D);

       if (location.y - 2 - row1>0) for (i = 0; i < y; i++) movegb(0x48);
       else for (i = 0; i < y; i++) movegb(0x50);

       printf("��"); */
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

            printf("��");*/ 
        }
        else//���������������� 
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

                printf("��");*/ 
                if (chessjudgewin(row1, col1, 1))
                {
                    gotoxy(22, 17);
                    printf("�� ����ʤ�� ��");
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
                printf("��");*/ 

                if (chessjudgewin(row2, col2, 1))
                {
                    gotoxy(22, 17);
                    printf("�� ����ʤ�� ��");
                    return 1;
                }
            }
        }
    }
return 0;
}


int chessscore(int x, int y, int hue)   //����Ȩֵ����
{
    int count3,count4,row,col,count1,count2,sumscore = 0;//1��ʾ���� 2��ʾ���� 3��ʾб�Ϸ��� 4��ʾб�·���
    char u,d,l,r,lu,ld,ru,rd;//u�� d�� l�� r�� lu��б�� ld��б�� ru��б�� rd��б��

    count1=count2=count3=count4=1;//�������Ӻ�÷����Ȼ��һ�� 
    l=r=u=d=lu=ld=ru=rd=0;

    cm[x][y]=hue;//��������ĳһ��λ�� 
/*---------------------------------------���жϺ������Ӳ���¼�ո���---------------------------*/
    row = x, col = y + 1;
    while (cm[row][col] == hue && col < L)
    {
        count1++;
        col++;
    }
    while (col < L && cm[row][col] == 0)//�������м����ո� 
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

/*-------------------------------------���ж��������Ӳ���¼�ո���---------------------------*/
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


/*------------------------------------���ж�б�������Ӳ���¼�ո���--------------------------*/
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

/*-----------------------------------���ж�б�������Ӳ���¼�ո���---------------------------*/
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
/*---------------------------------------------����Ӯ��---------------------------------------------*/

    cm[x][y] = 0;//ͳ����� ����ȡ�� ����Ӯ�� 

    if (count1 >= 5 || count2 >= 5 || count3 >= 5 || count4 >= 5) return sumscore = 5000;

    if ((count1 == 4 && count2 == 4 && l >= 1 && r >= 1 && u >= 1 && d >= 1) ||
       (count1 == 4 && count3 == 4 && l >= 1 && r >= 1 && ru >= 1 && ld >= 1) ||
       (count1 == 4 && count4 == 4 && l >= 1 && r >= 1 && rd >= 1 && lu >= 1) ||
       (count2 == 4 && count3 == 4 && u >= 1 && d >= 1 && ru >= 1 && ld >= 1) ||
       (count2 == 4 && count4 == 4 && u >= 1 && d >= 1 && lu >= 1 && rd >= 1) ||
       (count3 == 4 && count4 == 4 && ru >= 1 && ld >= 1 && lu >= 1 && rd >= 1))   //�ж�˫����
       return sumscore = 4000;

    if ((count1 == 4 && l >= 1 && r >= 1) || (count2 == 4 && u >= 1 && d >= 1) ||
       (count3 == 4 && ru >= 1 && ld >= 1) || (count4 == 4 && lu >= 1 && rd >= 1))   //�жϻ���
        return sumscore = 800;
      
    if ((count1 == 4 && ((l == 0 && r >= 1) || (l >= 1 && r == 0))) ||
       (count2 == 4 && ((u == 0 && d >= 1) || (u >= 1 && d == 0))) ||
       (count3 == 4 && ((ld == 0 && ru >= 1) || (ld >= 1 && ru == 0))) || 
	   (count4 == 4 && ((lu == 0 && rd >= 1) || (lu >= 1 && rd == 0))))
       sumscore = sumscore + 35;  //����
       
    if((((count1==3&&count2==4)||(count1==4&&count2==3))&&l>=1&&r>=1&&u>=1&&d>=1)||
	   (((count1==3&&count3==4)||(count1==4&&count3==3))&&l>=1&&r>=1&&ru>=1&&ld>=1)||
	   (((count1==3&&count4==4)||(count1==4&&count4==3))&&l>=1&&r>=1&&lu>=1&&rd>=1)||
	   (((count2==3&&count3==4)||(count2==4&&count3==3))&&u>=1&&d>=1&&ru>=1&&ld>=1)||
	   (((count2==3&&count4==4)||(count2==4&&count4==3))&&u>=1&&d>=1&&lu>=1&&rd>=1)||
	   (((count3==3&&count4==4)||(count3==4&&count4==3))&&lu>=1&&rd>=1&&ru>=1&&ld>=1)) //�Ļ������� 
	   return sumscore+600;                                                              
	   
    if((count1==3&&count2==3&&l>=1&&r>=1&&u>=1&&d>=1)||
      (count1==3&&count3==3&&l>=1&&r>=1&&ru>=1&&ld>=1)||
      (count1==3&&count4==3&&l>=1&&r>=1&&rd>=1&&lu>=1)||
      (count2==3&&count3==3&&u >=1 && d >=1 && ru >=1 && ld >=1 ) ||
      (count2 == 3 && count4 == 3 && u >=1 && d >=1 && lu >=1 && rd >=1 ) ||
      (count3 == 3 && count4 == 3 && ru >=1 && ld >=1 && lu >=1 && rd >=1))   //�ж�˫����
      return sumscore + 400;


    if((count1 == 3 && l >= 1 && r >= 1) || (count2 == 3 && u >= 1 && d >= 1) ||
      (count3 == 3 && ru >= 1 && ld >= 1) || (count4 == 3 && lu >= 1 && rd >= 1))
    { 
        sumscore = sumscore + 60;
        return sumscore;
    }     //�жϻ���

    if ((count1 == 2 && count2 == 2 && l >= 1 && r >= 1 && u >= 1 && d >= 1) ||
       (count1 == 2 && count3 == 2 && l >= 1 && r >= 1 && ru >= 1 && ld >= 1) ||
       (count1 == 2 && count4 == 2 && l >= 1 && r >= 1 && rd >= 1 && lu >= 1) ||
       (count2 == 2 && count3 == 2 && u >= 1 && d >= 1 && ru >= 1 && ld >= 1) ||
       (count2 == 2 && count4 == 2 && u >= 1 && d >= 1 && lu >= 1 && rd >= 1) ||
       (count3 == 2 && count4 == 2 && ru >= 1 && ld >= 1 && lu >= 1 && rd >= 1))
       sumscore = sumscore + 20;   //�ж�˫���

    if ((count1 == 2 && l >= 1 && r >= 1) || (count2 == 2 && u >= 1 && d >= 1) ||
       (count3 == 2 && ru >= 1 && ld >= 1) || (count4 == 2 && lu >= 1 && rd >= 1))
       sumscore = sumscore + 10;     //�����
       
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
        printf("���������ʼ"); 
        while (1)
        { 
            key = _getch();/*���»���_�ĺ���һ���Ǻ������ڲ��ĺ������������»��ߵ�һ�����ṩ���û�ʹ�õĺ��������»��ߵ�Ŀ����Ϊ�˷�ֹ��
            ������ĺ����ͺ�����ĺ���������ͻ������ֱ��ʹ��Ҳ�ǿ��Եġ�*/ 
            if(w == 0)
            {
                location.x = 7;
                location.y = 9;
                gotoxy(location.x, location.y);//�ƶ���� ����ʼλ�� 
                w++;
            }
    
           if (key == 27) exit(0);
           else if (key == 8) break;//����������
           else if (key == 110) break; //������
           else if (key == 32)//���� 
           {
                if (count == L * L)
                { 
                    gotoxy(22, 13);
                    printf("�� ƽ�� ��");
                    count = 0;
                    break;
                }
                else if (hue == 2)//���� 
                {
                if(!chessjudge(location.y - 2, location.x))
                {
                    printf("��");
                    cm[location.y - 2][location.x] = hue;
                    count++;
                    //system("cls");
					//board_print(); 
                    if (chessjudgewin(location.y - 2, location.x, hue))//ÿ��һ���ж�һ�� 
                    {
                        gotoxy(22, 15);
                        printf("�� ����ʤ�� ��");
                        key = _getch();
                        while(key != 27 && key != 110 && key != 8) key = _getch();
                        if(key == 8 || key == 110) break;
                        else exit(0);//�˳���Ϸ 
                    }
                    else 
                    {   
                        hue=3-hue;
                        c=chesscomputer();//��������  �ú����������ж���Ӯ 
                        if(c)//����ʤ�� 
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
            else  //����ƶ�
            {
                key = _getch();
                movegb(key);//ÿgetchһ�ζ�Ҫ����һ�� 
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
if (key == 27)   //�˳���Ϸ
{
exit(0);
}
else if (key == 8)   //����������
{
break;
}
else if (key == 110)  //������
{
break;
}
else if(key == 32)//�ո� 
{
if(hue == 2)
{
if(chessjudge(location.y-2,location.x) == 0)
{
cm[location.y-2][location.x] = 2;
//printf("��");
count++;
system("cls");
board_print();
if(chessjudgewin(location.y-2,location.x,hue))
{
gotoxy(22, 15);
printf("�� ����ʤ�� ��");
key = _getch();
while(key != 27 && key != 110 && key != 8)
key = _getch();
if(key == 8 || key == 110)
break;
else exit(0);
}
hue = 3 - hue;//���� 
}
}
else
{

if(chessjudge(location.y-2,location.x) == 0)
{
cm[location.y-2][location.x] = 1;
//printf("��");
count++;
system("cls");
board_print();
if(chessjudgewin(location.y-2,location.x,hue))
{
gotoxy(22, 15);
printf("�� ����ʤ�� ��");
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



