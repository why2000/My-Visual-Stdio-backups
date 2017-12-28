//#define NOW
#ifdef NOW
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _stu {
	long ID;
	char name[10];
	int eng;
	int math;
	int phy;
	int cpro;
	int sum;
	double aver;
	struct _stu *next;
	struct _stu *last;
}stu;
void creatlist(stu **headp);
void outputlist(stu **headp);
void changelist(stu **headp);
void averstu(stu **headp);
void infostu(stu **headp);
void sortbyvalue(stu **headp);
void sortbyaddress(stu **headp);
int main(void)
{
	stu *head = NULL;
	stu *bufhead = head;
	creatlist(&head);
	stu *remhead = head;
	char* buf;
	while (1) {
		char mode;
		//自制超强精简版清缓冲神器
		buf = (char *)malloc(BUFSIZ);
		free(buf);
		buf = (char *)malloc(BUFSIZ);
		setbuf(stdin, buf);
		//by why
		system("cls");
		printf("Please choose what to do(Enter a number)\n");
		printf("1.Show the list\n");
		printf("2.Do some change\n");
		printf("3.Show the average grade of each student\n");
		printf("4.Show all the infomation of each student\n");
		printf("5.Creat a new list(Caution: this will delete the old list)\n");
		printf("6.Sort with type: Change value\n");
		printf("7.Sort with type: Change address\n");
		printf("8.Exit\n");
		mode = getchar();
		switch (mode) {
		case '1':
			outputlist(&head);
			break;
		case '2':
			changelist(&head);
			break;
		case '3':
			averstu(&head);
			break;
		case '4':
			infostu(&head);
			break;
		case '5':
			for (int i = 0; head != remhead; i++) {
				bufhead = head->next;
				free(head);
				head = bufhead;
			}
			free(head);
			creatlist(&head);
			break;
		case '6':
			sortbyvalue(&head);
			break;
		case '7':
			sortbyaddress(&head);
			break;
		case '8':
			return 0;
			break;
		default:
			//自制超强精简版清缓冲神器
			buf = (char *)malloc(BUFSIZ);
			free(buf);
			buf = (char *)malloc(BUFSIZ);
			setbuf(stdin, buf);
			//by why
			printf("This is not a number(1-7).\nPress any key to continue\n");
			getchar();
			break;
		}
		//自制超强精简版清缓冲神器
		buf = (char *)malloc(BUFSIZ);
		free(buf);
		buf = (char *)malloc(BUFSIZ);
		setbuf(stdin, buf);
		//by why
	}
	return 0;
}

void sortbyaddress(stu **headp) {
	stu *p = *headp;
	int n = 0;
	do {
		n++;
		p = p->next;
	} while (p != *headp);
	p = *headp;
	while (n > 1) {
		while (p->next != *headp) {
			if (p->aver > p->next->aver) {
				stu temp;
				stu *buf1 = p->last;
				stu *buf2 = p;
				stu *buf3 = p->next;
				stu *buf4 = p->next->next;
				if (p == *headp) {
					*headp = (*headp)->next;
				}
				buf1->next = buf3;
				buf3->next = buf2;
				buf2->next = buf4;
				buf4->last = buf2;
				buf2->last = buf3;
				buf3->last = buf1;
			}
			p = p->next;
		}
		n--;
		p = *headp;
	}
	p = *headp;
	system("cls");
	do {
		printf("ID        Name        Average\n");
		printf("%-10ld%-12s%-10.2lf\n", p->ID, p->name, p->aver);
		p = p->next;
	} while (p != *headp);
	p = *headp;
	//自制超强精简版清缓冲神器
	char* buf = (char *)malloc(BUFSIZ);
	free(buf);
	buf = (char *)malloc(BUFSIZ);
	setbuf(stdin, buf);
	//by why
	printf("Press any key to continue");
	getchar();
}


void sortbyvalue(stu **headp) {
	stu *p = *headp;
	int n = 0;
	char* buf;
	do {
		n++;
		p = p->next;
	} while (p != *headp);
	p = *headp;
	while (n > 1) {
		while (p->next != *headp) {
			if (p->aver > p->next->aver) {
				stu temp;
				stu *buf1 = p->last;
				stu *buf2 = p;
				stu *buf3 = p->next;
				stu *buf4 = p->next->next;
				temp = *buf2;
				*buf2 = *(p->next);
				*buf3 = temp;
				buf2->next = buf3;
				buf3->next = buf4;
				buf3->last = buf2;
				buf2->last = buf1;
			}
			p = p->next;
		}
		n--;
		p = *headp;
	}
	p = *headp;
	system("cls");
	do {
		printf("ID        Name        Average\n");
		printf("%-10ld%-12s%-10.2lf\n", p->ID, p->name, p->aver);
		p = p->next;
	} while (p != *headp);
	p = *headp;
	//自制超强精简版清缓冲神器
	buf = (char *)malloc(BUFSIZ);
	free(buf);
	buf = (char *)malloc(BUFSIZ);
	setbuf(stdin, buf);
	//by why
	printf("Press any key to continue");
	getchar();
}

void creatlist(stu **headp)
{
	char* buf;
	*headp = (stu *)malloc(sizeof(stu));
	stu *buflast = *headp, *p = *headp;
	system("cls");
	printf("Please enter the infomation needed:\n");
	printf("Ends with the ID 0\n");
	printf("ID\tName\tEnglish\tMath\tPhysics\tCProgramming\n");

	for (;;) {
		scanf("%ld", &p->ID);
		if (p->ID == 0)break;
		scanf("%s%d%d%d%d", p->name, &p->eng, &p->math, &p->phy, &p->cpro);
		p->aver = (p->eng + p->math + p->phy + p->cpro) / 4.0;
		p = (stu *)malloc(sizeof(stu));
		buflast->next = p;
		p->last = buflast;
		buflast = p;
	}
	p->last->next = *headp;
	(*headp)->last = p->last;
	free(p);
}
void outputlist(stu **headp)
{
	char* buf;
	stu *p = *headp;
	system("cls");
	printf("This is the list you created:\n");
	do {
		printf("ID        Name        English   Math      Physics   CProgramming\n");
		printf("%-10ld%-12s%-10d%-10d%-10d%d\n", p->ID, p->name, p->eng, p->math, p->phy, p->cpro);
		p = p->next;
	} while (p != *headp);
	//自制超强精简版清缓冲神器
	buf = (char *)malloc(BUFSIZ);
	free(buf);
	buf = (char *)malloc(BUFSIZ);
	setbuf(stdin, buf);
	//by why
	printf("Press any key to continue");
	getchar();
}
void listadd(stu **headp) {
	stu *p = (*headp)->last;
	system("cls");
	while (1) {
		printf("Please enter the infomation needed:\n");
		printf("Enter the ID 0 to quit\n");
		printf("ID\tName\tEnglish\tMath\tPhysics\tCProgramming\n");
		p->next = (stu *)malloc(sizeof(stu));
		p->next->last = p;
		p = p->next;
		scanf("%ld", &p->ID);
		if (p->ID == 0)break;
		scanf("%s%d%d%d%d", p->name, &p->eng, &p->math, &p->phy, &p->cpro);
		p->aver = (p->eng + p->math + p->phy + p->cpro) / 4.0;
		printf("Adding success\n");
	}
	p->last->next = *headp;
	(*headp)->last = p->last;
	free(p);
}

void changelist(stu **headp)
{
	char c;
	stu *p;
	char* buf;
	p = *headp;
	system("cls");
	printf("1.Search by name\n");
	printf("2.Search by ID\n");
	printf("3.Add a student\n");
	printf("4.Quit\n");
	//自制超强精简版清缓冲神器
	buf = (char *)malloc(BUFSIZ);
	free(buf);
	buf = (char *)malloc(BUFSIZ);
	setbuf(stdin, buf);
	//by why
	c = getchar();
	switch (c) {
	case '1':
		system("cls");
		printf("Please input the name\n");
		char t[10];
		scanf("%s", t);
		do {
			p = p->next;
		} while (p != *headp && strcmp(p->name, t));
		if (!strcmp(p->name, t)) {
			printf("Student found:\n");
			printf("ID        Name        English   Math      Physics   CProgramming\n");
			printf("%-10ld%-12s%-10d%-10d%-10d%d\n", p->ID, p->name, p->eng, p->math, p->phy, p->cpro);
		}
		else if (p == *headp) {
			//自制超强精简版清缓冲神器
			buf = (char *)malloc(BUFSIZ);
			free(buf);
			buf = (char *)malloc(BUFSIZ);
			setbuf(stdin, buf);
			//by why
			printf("Student not found\n");
			printf("Press any key to continue");
			getchar();
			return;
		}
		break;
	case '2':
		printf("Please input the ID\n");
		long tmp;
		scanf("%ld", &tmp);
		do {
			p = p->next;
		} while (p != *headp && tmp != p->ID);
		if (tmp == p->ID) {
			printf("Student found:\n");
			printf("ID        Name        English   Math      Physics   CProgramming\n");
			printf("%-10ld%-12s%-10d%-10d%-10d%d\n", p->ID, p->name, p->eng, p->math, p->phy, p->cpro);
		}
		else if (p == *headp) {
			//自制超强精简版清缓冲神器
			buf = (char *)malloc(BUFSIZ);
			free(buf);
			buf = (char *)malloc(BUFSIZ);
			setbuf(stdin, buf);
			//by why
			printf("Student not found\n");
			printf("Press any key to continue");
			getchar();
			return;
		}
		break;
	case '3':
		listadd(headp);
		return;
	case '4':
		return;
	default:
		printf("This is not a number(1-4).Press any key to continue");
		getchar();
		return;
	}
	printf("What to change?\n");
	printf("1.ID\n");
	printf("2.name\n");
	printf("3.Grade of English\n");
	printf("4.Grade of Math\n");
	printf("5.Grade of Physics\n");
	printf("6.Grade of C Language\n");
	printf("7.Quit\n");
	//自制超强精简版清缓冲神器
	buf = (char *)malloc(BUFSIZ);
	free(buf);
	buf = (char *)malloc(BUFSIZ);
	setbuf(stdin, buf);
	//by why
	c = getchar();
	switch (c) {
	case '1':
		printf("Please input:\n");
		scanf("%ld", &p->ID);
		printf("Changing success.Press any key to continue\n");
		//自制超强精简版清缓冲神器
		buf = (char *)malloc(BUFSIZ);
		free(buf);
		buf = (char *)malloc(BUFSIZ);
		setbuf(stdin, buf);
		//by why
		getchar();
		break;
	case '2':
		printf("Please input:\n");
		scanf("%s", p->name);
		printf("Changing success.Press any key to continue\n");
		//自制超强精简版清缓冲神器
		buf = (char *)malloc(BUFSIZ);
		free(buf);
		buf = (char *)malloc(BUFSIZ);
		setbuf(stdin, buf);
		//by why
		getchar();
		break;
	case '3':
		printf("Please input:\n");
		scanf("%d", &p->eng);
		printf("Changing success.Press any key to continue\n");
		//自制超强精简版清缓冲神器
		buf = (char *)malloc(BUFSIZ);
		free(buf);
		buf = (char *)malloc(BUFSIZ);
		setbuf(stdin, buf);
		//by why
		getchar();
		break;
	case '4':
		printf("Please input:\n");
		scanf("%d", &p->math);
		printf("Changing success.Press any key to continue\n");
		//自制超强精简版清缓冲神器
		buf = (char *)malloc(BUFSIZ);
		free(buf);
		buf = (char *)malloc(BUFSIZ);
		setbuf(stdin, buf);
		//by why
		getchar();
		break;
	case '5':
		printf("Please input:\n");
		scanf("%d", &p->phy);
		printf("Changing success.Press any key to continue\n");
		//自制超强精简版清缓冲神器
		buf = (char *)malloc(BUFSIZ);
		free(buf);
		buf = (char *)malloc(BUFSIZ);
		setbuf(stdin, buf);
		//by why
		getchar();
		break;
	case '6':
		printf("Please input:\n");
		scanf("%d", &p->cpro);
		printf("Changing success.Press any key to continue\n");
		//自制超强精简版清缓冲神器
		buf = (char *)malloc(BUFSIZ);
		free(buf);
		buf = (char *)malloc(BUFSIZ);
		setbuf(stdin, buf);
		//by why
		getchar();
		break;
	case '7':
		break;
	default:
		printf("No change is done\n");
		printf("Press any key to continue");
		getchar();
		break;
	}
	p->aver = (p->eng + p->math + p->phy + p->cpro) / 4.0;
}
void averstu(stu **headp)
{
	stu *p = *headp;
	char* buf;
	system("cls");
	do {
		p->aver = (p->eng + p->math + p->phy + p->cpro) / 4.0;
		printf("ID        Name        Average\n");
		printf("%-10ld%-12s%-10.2lf\n", p->ID, p->name, p->aver);
		p = p->next;
	} while (p != *headp);
	//自制超强精简版清缓冲神器
	buf = (char *)malloc(BUFSIZ);
	free(buf);
	buf = (char *)malloc(BUFSIZ);
	setbuf(stdin, buf);
	//by why
	printf("Press any key to continue");
	getchar();
}
void infostu(stu **headp)
{
	stu *p;
	char* buf;
	p = *headp;
	system("cls");
	do {
		p->sum = p->eng + p->math + p->phy + p->cpro;
		p->aver = p->sum / 4.0;
		printf("ID        Name        Sum       Average\n");
		printf("%-10ld%-12s%-10d%-10.2lf\n", p->ID, p->name, p->sum, p->aver);
		p = p->next;
	} while (p != *headp);
	//自制超强精简版清缓冲神器
	buf = (char *)malloc(BUFSIZ);
	free(buf);
	buf = (char *)malloc(BUFSIZ);
	setbuf(stdin, buf);
	//by why
	printf("Press any key to continue");
	getchar();
}
#endif

