#include<stdio.h>
#include<malloc.h>
void execute();
int length();
int rever();
int main(void) {
	printf("please input the first element:\n");
	unsigned long long input;
	scanf("%lld", &input);
	input = rever(input);
	execute(input);
	system("pause");
	return 0;

}
int change();
void execute(unsigned long long input) {
	unsigned long long last = 0;
	float rate = 1;
	float lengthrate = 1;
	int i = 0;
	for (i = 0; last != input&&i <= 10; i++) {
		last = rever(input);
		input = change(input);
		printf("%lld\n", input);
		
		rate = (input*1.0) / last;
		lengthrate = (length(input)*1.0) / length(last);
		if (rate == 1)
			printf("loop\n");
		else {
			printf("rate:%f\n", rate);
			printf("lengthrate:%f\n", lengthrate);
		}
		input=rever(input);
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
int change(unsigned long long input) {
	int* single;
	int newone = 0;
	int i;
	int leng = length(input);
	single = (int*)malloc((leng+2) * sizeof(int));
	for (i = 0; i <= leng; i++) {
		single[i] = input % 10;
		input = input / 10;
	}
	i = 0;
	int sametime = 0;
	int total;
	for (; i<=leng; i++) {
		
		//total= sametime;
		
		if ((single[i] != single[i - 1] && i != 0) ) {
			sametime++;
			newone = newone * 100;
			//newone=newone+(sametime*10+single[i])*(10^(length(newone)));
			newone = newone + (sametime * 10 + single[i - 1]);
			sametime = 0;
		}
		else if(i!=0) {
			sametime++;

		}
		
	}
	//newone = newone * 100;
	//newone = newone + (total * 10 + single[i - 1]);
	return newone;
}

int rever(int n) {
	int i, r;
	r = 0;
	while (n != 0)
	{
		i = n % 10;
		r = r * 10 + i;
		n = n / 10;
	}

	return r;
}







