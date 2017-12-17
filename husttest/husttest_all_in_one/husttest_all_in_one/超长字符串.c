//#define NOW
#ifdef NOW
#include<stdio.h>
#include<malloc.h>
typedef struct single{
    char sym;
    struct single *next;
}sing;

int main(void) {
    sing *now = (sing*)malloc(sizeof(sing));
    sing *head = now;
    int num = 0;
    while ((now->sym = getchar()) != '#') {
        now->next = (sing*)malloc(sizeof(sing));
        now = now->next;
        num++;
    }
    char *arr = (char*)malloc(sizeof(char)*num);
    now = head;
    int i = 0;
    while (now->sym != '#') {
        printf("%c", now->sym);
        arr[i] = now->sym;
        now = now->next;
        i++;
    }
    printf("\n");
    printf("\n");
    for (i = 0; i < num; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
    return 0;
}
#endif
