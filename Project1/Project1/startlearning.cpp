#include <stdio.h>
#include <stdlib.h>

typedef struct String String;

struct String
{
    char ch;
    String *next;
};

void SaveSring(String ** head);
void PrintString(String *head);
void SaveToArray(String *head);
void DeleteString(String **head);
void InsertString(String *head);

int main(void)
{
    String *head = NULL;

    SaveSring(&head);
    PrintString(head);
    SaveToArray(head);
    DeleteString(&head);
    PrintString(head);
    InsertString(head);
    PrintString(head);
    return 0;
}

void SaveSring(String ** head)
{
    String *current = NULL;
    String *previous = NULL;

    while (1)
    {
        current = (String*)malloc(sizeof(String));
        if (*head == NULL)
        {
            *head = current;
        }

        if (previous != NULL)
            previous->next = current;

        previous = current;
        current->next = NULL;

        scanf("%c", &current->ch);

        if (current->ch == '\n')
        {
            current->ch = '\0';
            current->next = NULL;
            break;
        }
    }
}

void PrintString(String *head)
{
    while (head != NULL)
    {
        printf("%c", head->ch);
        head = head->next;
    }
    printf("\n\n");
}

void SaveToArray(String *head)
{
    int cnt, i;
    String *temp = head;
    for (cnt = 1; temp->next != NULL; cnt++)
    {
        temp = temp->next;
    }

    char *string;
    string = (char*)malloc(cnt);

    for (i = 0; i < cnt; ++i)
    {
        string[i] = head->ch;
        head = head->next;
    }
    printf("%s\n\n", string);
}

void DeleteString(String **head)
{
    String *current = NULL;
    String *previous = NULL;
    String *Delete = NULL;
    char t;

    scanf("%c%*c", &t);

    if ((*head)->ch == t)
    {
        Delete = *head;
        *head = (*head)->next;
        free(Delete);
    }

    previous = *head;
    current = previous->next;
    do
    {
        if (current->ch == t)
        {
            Delete = current;
            previous->next = current->next;
            current = previous->next;
            free(Delete);
        }
        else
        {
            previous = current;
            current = current->next;
        }
    } while (current != NULL);
}

void InsertString(String *head)
{
    String *current = NULL;
    String *previous = NULL;
    String *insert = NULL;
    char t;
    int x, a;

    scanf("%c", &t);

    insert = head;
    x = head->ch - t;
    x = x>0 ? x : (-x);

    previous = head;
    current = previous->next;
    do
    {
        a = current->ch - t;
        a = a>0 ? a : (-a);
        if (a<x)
        {
            x = a;
            insert = current;
        }
        previous = current;
        current = current->next;
    } while (current != NULL);

    current = insert->next;
    insert->next = (String*)malloc(sizeof(String));
    insert->next->ch = t;
    insert->next->next = current;
}
