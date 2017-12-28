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
	while (1) {
		int mode;
		printf("Please choose what to do(Enter a number)\n");
		printf("1.Show the list\n");
		printf("2.Do some change\n");
		printf("3.Show the average grade of each student\n");
		printf("4.Show all the infomation of each student\n");
		printf("5.Creat a new list(Caution: this will delete the old list)\n");
		printf("6.Sort with type: Change value\n");
		printf("7.Sort with type: Change address\n");
		scanf("%d", &mode);
		switch (mode) {
		case 1:
			outputlist(&head);
			break;
		case 2:
			changelist(&head);
			break;
		case 3:
			averstu(&head);
			break;
		case 4:
			infostu(&head);
			break;
		case 5:
			for (int i = 0; head->next != NULL; i++) {
				bufhead = head->next;
				free(head);
				head = bufhead;
			}
			free(head);
			creatlist(&head);
			break;
		case 6:
			sortbyvalue(&head);
			break;
		case 7:
			sortbyaddress(&head);
			break;
		default:
			printf("Please enter a number (1 - 7)\n");
			char*buf = (char *)malloc(BUFSIZ);
			free(buf);
			buf = (char *)malloc(BUFSIZ);
			setbuf(stdin, buf);
			break;
		}
	}
	return 0;
}
void sortbyaddress(stu **headp) {
	stu *p = *headp;
	int n;
	for (n = 0; p->next != NULL; n++, (p = p->next));
	p = *headp;
	stu *foo = (stu *)malloc(sizeof(stu));
	foo->next = *headp;
	p = foo;
	while (n > 1) {
		while (p->next->next->next != NULL) {
			if (p->next->aver > p->next->next->aver) {
				stu *bufnext1;
				stu *bufnext2;
				bufnext2 = p->next->next;
				bufnext1 = p->next;
				bufnext1->next = p->next->next->next;
				p->next = bufnext2;
				p->next->next = bufnext1;
			}
			p = p->next;
		}
		n--;
		p = foo;
	}
	*headp = foo->next;
	free(foo);
	p = *headp;
	for (; p->next != NULL; p = p->next) {
		printf("ID        Name        Average\n");
		printf("%-10ld%-12s%-10.2lf\n", p->ID, p->name, p->aver);
	}
	p = (*headp);
}

void sortbyvalue(stu **headp) {
	stu *p = *headp;
	int n;
	for (n = 0; p->next != NULL; n++, (p = p->next));
	p = *headp;
	while (n > 1) {
		while (p->next->next != NULL) {
			if (p->aver > p->next->aver) {
				stu temp;
				stu *bufnext;
				temp = (*p);
				bufnext = p->next;
				(*p) = *(p->next);
				p->next = bufnext;
				bufnext = p->next->next;
				*(p->next) = temp;
				p->next->next = bufnext;
			}
			p = p->next;
		}
		n--;
		p = (*headp);
	}
	for (; p->next != NULL; p = p->next) {
		printf("ID        Name        Average\n");
		printf("%-10ld%-12s%-10.2lf\n", p->ID, p->name, p->aver);
	}
	p = (*headp);
}

void creatlist(stu **headp)
{
	*headp = (stu *)malloc(sizeof(stu));
	stu *tail = *headp, *p = *headp;
	printf("Please enter the infomation needed:\n");
	printf("Ends with the ID 0\n");
	printf("ID\tName\tEnglish\tMath\tPhysics\tCProgramming\n");

	for (;;) {
		scanf("%ld", &p->ID);
		if (p->ID == 0)break;
		scanf("%s%d%d%d%d", p->name, &p->eng, &p->math, &p->phy, &p->cpro);
		p->aver = (p->eng + p->math + p->phy + p->cpro) / 4.0;
		p = (stu *)malloc(sizeof(stu));
		tail->next = p;
		tail = p;
	}
	tail->next = NULL;
}
void outputlist(stu **headp)
{
	stu *p = *headp;
	printf("This is the list you created:\n");
	while (p->next != NULL) {
		printf("ID        Name        English   Math      Physics   CProgramming\n");
		printf("%-10ld%-12s%-10d%-10d%-10d%d\n", p->ID, p->name, p->eng, p->math, p->phy, p->cpro);
		p = p->next;
	}
}
void listadd(stu **headp) {
	stu *p = *headp;
	for (; p->next != NULL; p = p->next);
	while (1) {

		printf("Please enter the infomation needed:\n");
		printf("Enter the ID 0 to quit\n");
		printf("ID\tName\tEnglish\tMath\tPhysics\tCProgramming\n");
		scanf("%ld", &p->ID);
		if (p->ID == 0)break;
		scanf("%s%d%d%d%d", p->name, &p->eng, &p->math, &p->phy, &p->cpro);
		p->aver = (p->eng + p->math + p->phy + p->cpro) / 4.0;
		p->next = (stu *)malloc(sizeof(stu));
		p = p->next;
	}
	p->next = NULL;
}

void changelist(stu **headp)
{
	char c;
	stu *p;
	p = *headp;
	printf("1.Search by name\n");
	printf("2.Search by ID\n");
	printf("3.Add a student\n");
	c = getchar();
	c = getchar();
	switch (c) {
	case '1':
		printf("Please input the name\n");
		char t[10];
		scanf("%s", t);
		for (; p->next != NULL && strcmp(p->name, t); p = p->next)
			;
		if (!strcmp(p->name, t)) {
			printf("Student found:\n");
			printf("ID        Name        English   Math      Physics   CProgramming\n");
			printf("%-10ld%-12s%-10d%-10d%-10d%d\n", p->ID, p->name, p->eng, p->math, p->phy, p->cpro);
		}
		else if (p->next == NULL) {
			printf("Student not found\n");
			return;
		}
		break;
	case '2':
		printf("Please input the ID\n");
		long tmp;
		scanf("%ld", &tmp);
		for (; p->next != NULL && tmp != p->ID; p = p->next);
		if (tmp == p->ID) {
			printf("Student found:\n");
			printf("ID        Name        English   Math      Physics   CProgramming\n");
			printf("%-10ld%-12s%-10d%-10d%-10d%d\n", p->ID, p->name, p->eng, p->math, p->phy, p->cpro);
		}
		else if (p->next == NULL) {
			printf("Student not found\n");
			return;
		}
		break;
	case '3':
		listadd(headp);
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
	char*buf = (char *)malloc(BUFSIZ);
	free(buf);
	buf = (char *)malloc(BUFSIZ);
	setbuf(stdin, buf);
	//by why
	c = getchar();
	printf("please reinput\n");
	switch (c) {
	case '1':
		scanf("%ld", &p->ID);
		break;
	case '2':
		scanf("%s", p->name);
		break;
	case '3':
		scanf("%d", &p->eng);
		break;
	case '4':
		scanf("%d", &p->math);
		break;
	case '5':
		scanf("%d", &p->phy);
		break;
	case '6':
		scanf("%d", &p->cpro);
		break;
	default:
		printf("No change is done");
		break;
	}
	p->aver = (p->eng + p->math + p->phy + p->cpro) / 4.0;
}
void averstu(stu **headp)
{
	stu *p = *headp;
	for (; p->next != NULL; p = p->next) {
		p->aver = (p->eng + p->math + p->phy + p->cpro) / 4.0;
		printf("ID        Name        Average\n");
		printf("%-10ld%-12s%-10.2lf\n", p->ID, p->name, p->aver);
	}
}
void infostu(stu **headp)
{
	stu *p;
	p = *headp;
	for (; p->next != NULL; p = p->next) {
		p->sum = p->eng + p->math + p->phy + p->cpro;
		p->aver = p->sum / 4.0;
		printf("ID        Name        Sum       Average\n");
		printf("%-10ld%-12s%-10d%-10.2lf\n", p->ID, p->name, p->sum, p->aver);
	}
}
#endif
