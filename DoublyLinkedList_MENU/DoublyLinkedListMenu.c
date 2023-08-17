#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    struct node *next;
    int data;
} Node;

void Add_at_End(Node **head, int d)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = d;
    newNode->next = newNode;
    newNode->prev = newNode;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    else
    {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
}

void Add_at_Begin(Node **head, int d)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = d;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL)
    {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    else
    {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        *head = newNode;
    }
}

void DisplayList(Node *head)
{
    Node *curr = head;

    if (head == NULL)
    {
        printf("The List is Empty XD \n");
        return;
    }

    do
    {
        printf("%d<--->", curr->data);
        curr = curr->next;
    } while (curr != head);

    printf("HEAD");
    printf("\n");
    printf("\n\n");
}

int LengthList(Node *head)
{
    Node *curr = head;
    int count = 0;

    if (head == NULL)
    {

        printf("The List is Empty XD \n");
        return count;
    }

    do
    {
        count++;
        curr = curr->next;

    } while (curr != head);

    printf("\n");
    return count;
}

void Add_at_pos(Node **head, int d, int pos)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = d;
    newNode->next = newNode;
    newNode->prev = newNode;

    Node *curr = *head;
    Node *back = NULL;

    if (pos <= 0 || *head == NULL)
    {
        *head = newNode;
        return;
    }

    for (int i = 1; i < pos && curr->next != *head; i++)
    {
        back = curr;
        curr = curr->next;
    }

    if (curr->next == *head)
    {
        Add_at_End(head, d);
    }

    else
    {
        newNode->prev = back;
        newNode->next = curr;
        back->next = newNode;
        curr->prev = newNode;
    }
}

void AddAfterKey(Node **head, int d, int key)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = d;
    newNode->next = newNode;
    newNode->prev = newNode;
    Node *curr = *head;

    if (*head == NULL)
    {
        printf("Empty List\n\n");
    }

    if (key == (*head)->data)
    {
        newNode->next = (*head)->next;
        newNode->prev = (*head);
        (*head)->next = newNode;
        return;
    }

    do
    {
        curr = curr->next;

    } while (curr != *head && curr->data != key);

    if (curr == *head)
    {
        printf("\nKey not found in the list\n");
    }

    // if (curr->next == *head)
    // {

    // }

    else
    {
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next = newNode;
    }
}

int deleteAtBeg(Node **head)
{
    Node *curr = *head;
    int e = curr->data;

    if (curr->next == curr)
    {
        (*head) = NULL;
        free(curr);
        return e;
    }

    *head = (*head)->next;
    (*head)->prev = curr->prev;
    curr->prev->next = *head;
    free(curr);
    return e;
}

int deleteAtEnd(Node **head)
{
    Node *curr = *head;
    int e = curr->data;

    if (curr->next == curr)
    {

        (*head) = NULL;
        free(curr);
        return e;
    }

    else
    {
        curr = (*head)->prev;
        (*head)->prev = curr->prev;
        e = curr->data;
        curr->prev->next = (*head);
        free(curr);
        return (e);
    }
}

int deleteAtpos(Node **head, int pos)
{

    Node *curr = *head;
    int e;

    if (pos == 1)
    {
        e = (*head)->data;
        *head = (*head)->next;
        (*head)->prev = curr->prev;
        curr->prev->next = *head;
        free(curr);
        return e;
    }

    for (int i = 1; i < pos; i++)
    {
        curr = curr->next;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    e = curr->data;
    free(curr);
    return e;
}

void deleteKey(Node **head, int key)
{

    Node *curr = *head;

    if (key == (*head)->data)
    {
        *head = (*head)->next;
        (*head)->prev = curr->prev;
        curr->prev->next = *head;
        free(curr);
        return;
    }

    else
    {
        do
        {
            curr = curr->next;

        } while (curr != *head && curr->data != key);
    }

    if (curr == *head)
    {
        printf("KEY NOT FOUND\n\n\n");
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
}

int main()
{
    int n;
    int ch;

    int d;
    int pos;
    int l, h;

    Node *head = NULL;

    // DisplayList(head);

    while (1)
    {
        printf("-----------------------------------------------------------------------------------MENU--------------------------------------------------------------------------\n");

        printf("(-1) CREATE PERSONALIZED LINKED LIST \n");
        printf("(0) CREATE TEST CASE LIST \n");
        printf("(1) DISPLAY THE LINKED LIST\n");
        printf("(2) INSERT AT BEGINING\n");
        printf("(3) INSERT AT END\n");
        printf("(4) INSERT AT POSITION\n");
        printf("(5) DELETE AT BEGINING\n");
        printf("(6) DELETE AT END\n");
        printf("(7) DELETE AT POSITION\n");
        printf("(8) LENGTH OF THE LINKED LIST\n");
        printf("(9) INSERT AFTER THE GIVEN KEY\n");
        printf("(10) DELETE THE GIVEN KEY\n");

        printf("\n\n");

        printf("ENTER THE CHOICE THAT YOU WANT : ");
        scanf("%d", &ch);

        printf("\n\n");

        switch (ch)
        {

        case -1:
            printf("Enter Till where Numbers You want :  ");
            scanf("%d", &n);
            int m;
            for (int i = 1; i <= n; i++)
            {
                printf(" |  ");
                scanf("%d", &m);
                Add_at_End(&head, m);
            }
            printf("\n");
            break;

        case 0:
            printf("Enter Till where Numbers You want :  ");
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                Add_at_End(&head, i);
            }
            printf("\n");

            break;

        case 1:
            DisplayList(head);
            break;

        case 2:
            printf("Enter data to be Added : ");
            scanf("%d", &d);
            Add_at_Begin(&head, d);
            printf("\n");

            break;

        case 3:
            printf("Enter data to be Added : ");
            scanf("%d", &d);
            Add_at_End(&head, d);
            printf("\n");

            break;

        case 4:
            printf("Enter data to be Added : ");
            scanf("%d", &d);
            printf("Enter position to be Added : ");
            scanf("%d", &pos);
            Add_at_pos(&head, d, pos);
            printf("\n");
            break;

        case 5:
            if (head == NULL)
            {
                printf("\nThe Linked list is empty\n\n");
                break;
            }

            h = deleteAtBeg(&head);
            printf("The deleted Data is :  %d \n\n", h);
            break;

        case 6:
            if (head == NULL)
            {
                printf("\nThe Linked list is empty\n\n");
                break;
            }

            h = deleteAtEnd(&head);
            printf("The deleted Data is :  %d \n\n", h);
            break;

        case 7:

            if (head == NULL)
            {
                printf("\nThe Linked list is empty\n\n");
            }

            else
            {
                printf("Enter position to be deleted : ");
                scanf("%d", &pos);
                h = deleteAtpos(&head, pos);
                printf("The deleted Data is :  %d \n\n", h);
                printf("\n");
            }
            break;

        case 8:
            l = LengthList(head);
            printf("The length of the list is : %d ", l);
            printf("\n\n");
            break;

        case 9:
            printf("Enter data to be Added : ");
            scanf("%d", &d);
            printf("Enter Key after which to be Added : ");
            scanf("%d", &pos);
            AddAfterKey(&head, d, pos);
            printf("\n");
            break;

        case 10:
            printf("Enter data to be Deleted : ");
            scanf("%d", &d);
            deleteKey(&head, d);
            printf("\n");
            break;

        default:
            break;
        }
    }

    getch();
    return 0;
}



///