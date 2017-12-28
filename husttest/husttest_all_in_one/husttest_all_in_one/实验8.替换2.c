//#define NOW
#ifdef NOW
#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	char ch;
	FILE *fp;
	if (argc != 2) {
		printf("Arguments error!\n");
		exit(-1);
	}
	if ((fp = freopen(argv[1], "r", stdin)) == NULL) {        /* fp Ö¸Ïò filename */
		printf("Can't open %s file!\n", argv[1]);
		exit(-1);
	}
	int c;
	while ((c = getchar()) != EOF)putchar(c);
	fclose(fp);                      /* ¹Ø±Õfilename */
	return 0;
}
#endif
