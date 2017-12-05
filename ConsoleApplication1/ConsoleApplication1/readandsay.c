#include<stdio.h>
#include<malloc.h>
#include"stdafx.h"
void execute();
int length();
int main(void) {
	printf("please input the first element:\n");
	unsigned long input;
	scanf("%ld", &input);
	execute(input);
	system("pause");
	return 0;

}
int change();
void execute(unsigned long input) {
	unsigned long last = 0;
	float rate = 1;
	float lengthrate = 1;
	int i = 0;
	for (i = 0; last != input&&i <= 10; i++) {
		last = input;
		input = change(input);
		printf("%ld\n", input);
		rate = (input*1.0) / last;
		lengthrate = (length(input)*1.0) / length(last);
		if (rate == 1)
			printf("loop\n");
		else {
			printf("rate:%f\n", rate);
			printf("lengthrate:%f\n", lengthrate);
		}
	}

}


int length(int x) {
	int i;
	if (x != 0) {
		for (i = 0; x != 0; i++)
			x = x / 10;
	}
	else {
		i = 1;
	}
	return i;

}
int change(int input) {
	int* single;
	int newone = 0;
	int i;
	int leng = length(input);
	single = (int*)malloc(leng * sizeof(int));
	for (i = 0; i <= leng; i++) {
		single[i] = input % 10;
		input = input / 10;
	}
	i = 0;
	int sametime = 1;
	for (; i<leng; i++) {

		if ((single[i] != single[i - 1] && i != 0) || i == leng - 1) {
			newone = newone * 100;
			//newone=newone+(sametime*10+single[i])*(10^(length(newone)));
			newone = newone + (sametime * 10 + single[i - 1]);
			sametime = 1;
		}
		else {
			sametime++;

		}
	}
	return newone;
}









