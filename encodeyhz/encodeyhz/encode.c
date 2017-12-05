#include <stdio.h>
#include <string.h>
#define MAXSIZE 50

//先执行-e，对letter文件加密，输出至lol，再执行-o，解密并输出至222
int main(void)
{
	FILE *file1, *file2;
	int i;
	int paslen;
	char a;
	char b[MAXSIZE];
	char c[] = "-e";
	char d[] = "-o";
	char key[50];
	scanf("%s",b);
	getchar();
	if (strcmp(b, c) == 0)
	{
		gets(key);
		paslen = strlen(key);//获取密码长度
		file1 = fopen("letter.txt", "rb");
		file2 = fopen("lol.txt", "wb+");
		a = fgetc(file1);
		i = 0;
		while (a != EOF)
		{
			a = a ^ (key[i++]); //利用密码进行加密
			fputc(a, file2);
			a = fgetc(file1);
			if (i >= paslen) {
				i = 0;
			}
		}
		fclose(file1);
		fclose(file2);
	}
	if (strcmp(b, d) == 0)
	{
		gets(key);
		paslen = strlen(key);//获取密码长度
		file1 = fopen("lol.txt", "rb");
		file2 = fopen("222.txt", "wb+");
		a = fgetc(file1);
		i = 0;
		while (a != EOF)
		{
			a = a ^ (key[i++]); //利用密码进行解密，结果输出至222
			fputc(a, file2);
			a = fgetc(file1);
		}
		fclose(file1);
		fclose(file2);
	}
	return 0;
}