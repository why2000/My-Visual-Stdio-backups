#define NOW
#ifdef NOW
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1024
int main(void)
{
	FILE *fp;
	char sent[MAXLINE];
	int i = 1;
	if ((fp = fopen("test", "w+")) == NULL) {
		printf("Error!");
		return;
	}
	gets(sent);
	if (sent[0] <= 'z' &&  sent[0] >= 'a')sent[0] -= 32;
	while (*(sent + i) != '\0') {
		if (*(sent + i) <= 'z' && *(sent + i) >= 'a' && *(sent + i - 1) == ' ')*(sent + i) -= 32;
		i++;
	}
	fputs(sent, fp);
	fclose(fp);
	return 0;
}

#endif
