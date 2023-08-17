#include <stdio.h>
#include <conio.h>
// #include <math.h>
// #include <string.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void addAtBegin(struct node **head_reference, int d)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        perror("Memory Full");
        return;
    }

    p->data = d;
    p->next = *head_reference;
    *head_reference = p;
}

int DeleteAtBeg(struct node **head_reference)
{
    struct node *previous = *head_reference;
    *head_reference = (*head_reference)->next;
    int collected_Data = previous->data;
    free(previous);
    return collected_Data;
}

void AddatEnd(struct node **head_reference, int d)
{

    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        perror("Memory Full");
        return;
    }

    p->data = d;
    p->next = NULL;

    if (*head_reference == NULL)
    {
        *head_reference = p;
        return;
    }

    else
    {
        struct node *last = *head_reference;

        while (last->next != NULL)
            last = last->next;

        last->next = p;
        return;
    }
}

void DisplayLinkedlist(struct node *head)
{
    struct node *curr = head;
    while (curr)
    {
        printf("%d---->", curr->data);
        curr = curr->next;
    }
    printf("NULL");
    printf("\n\n");
}

int deleteAtEnd(struct node **head_reference)
{
    struct node *current_ptr = *head_reference;
    struct node *previous_ptr = NULL;

    while (current_ptr->next != NULL)
    {
        previous_ptr = current_ptr;
        current_ptr = current_ptr->next;
    }

    int e = current_ptr->data;

    if (previous_ptr == NULL)
    {
        *head_reference = NULL;
    }

    else
    {
        previous_ptr->next = NULL;
    }

    free(current_ptr);
    return e;
}

void addAtPosition(struct node **head_reference, int d, int pos)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        perror("Memory Full");
        return;
    }

    p->data = d;
    p->next = NULL;

    if (pos <= 0 || *head_reference == NULL)
    {
        p->next = *head_reference;
        *head_reference = p;
    }

    else
    {
        struct node *currnet = *head_reference;
        struct node *previous = NULL;

        for (int i = 0; i < pos && currnet != NULL; i++)
        {
            previous = currnet;
            currnet = currnet = currnet->next;
        }

        previous->next = p;
        p->next = currnet;

    }
}

int delAtPosition(struct node **head_reference, int pos)
{
    struct node *currnet = *head_reference;
    struct node *previous = NULL;
    int e;

    if (pos <= 0 || (*head_reference)->next == NULL)
    {
        e = currnet->data;
        (*head_reference) = (*head_reference)->next;
        free(currnet);
        return e;
    }

    else
    {
        for (int i = 0; i < pos && currnet->next != NULL; i++)
        {
            previous = currnet;
            currnet = currnet = currnet->next;
        }

        e = currnet->data;
        previous->next = currnet->next;
        free(currnet);
        return (e);
    }
}

int SearchKey(struct node *head, int key)
{
    struct node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == key)
            return 1;

        curr = curr->next;
    }

    return 0;
}

int frequencyofThekey(struct node *head, int key)
{
    struct node *curr = head;
    int count = 0;

    while (curr != NULL)
    {
        if (curr->data == key)
            count++;

        curr = curr->next;
    }

    return count;
}

int lengthofList(struct node *head)
{
    struct node *curr = head;
    int count = 0;
    while (curr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

void reverseLinkedList(struct node **head)
{
    struct node *p;
    struct node *q = NULL;
    struct node *r = NULL;

    p = *head;
    if (p != NULL)
        q = p->next;
    if (q != NULL)
        r = q->next;

    while (q != NULL)
    {
        q->next = p;
        p = q;
        q = r;
        if (r != NULL)
            r = r->next;
    }

    if (*head != NULL)
    {
        (*head)->next = NULL;
    }

    *head = p;
}

void deletetheFirstOccourence(struct node **head, int key)
{
    struct node *current = *head;
    struct node *prev = NULL;

    while (current != NULL && current->data != key)
    {
        prev = current;
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Key Not found\n");
        return;
    }

    else if (current == *head)
    {
        *head = (*head)->next;
        free(current);
    }

    else
    {
        prev->next = current->next;
        free(current);
    }
}

void addAfterKey(struct node **head, int d, int key)
{

    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
    {
        perror("Memory Full");
        return;
    }

    p->data = d;
    p->next = NULL;

    if (*head == NULL)
    {
        *head = p;
        return;
    }

    struct node *curr = *head;
    struct node *prev = NULL;

    while (curr && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL)
    {
        printf("The key Not Found");
    }

    else
    {
        p->next = curr->next;
        curr->next = p;
    }
}

void deleteDuplicates(struct node **head)
{
    struct node *q = *head;
    struct node *curr = *head;
    struct node *prev = NULL;

    while (q)
    {
        prev = q;
        curr = q->next;

        while (curr)
        {
            if (q->data == curr->data)
            {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }

            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        q = q->next;
    }
}

void sortList(struct node *head)
{
    struct node *i, *j;
    struct node *min;
    int temp;

    for (i = head; i != NULL; i = i->next)
    {
        min = i;
        for (j = i->next; j != NULL; j = j->next)
        {
            if (j->data < i->data)
            {
                min = j;
            }
        }

        temp = i->data;
        i->data = min->data;
        min->data = temp;
    }
}

int main()
{

    struct node *head = NULL;

    int ch, n;
    int d, pos;
    int key;

    while (1)
    {
        printf("************************************************************\n");
        printf("(0) CREATE A TEST CASE LIST \n");
        printf("(1) DISPLAY THE LINKED LIST \n");
        printf("(2) ADD AT THE BEGINNING LIST \n");
        printf("(3) DELETE AT THE BEGINNING LIST \n");
        printf("(4) ADD AT THE END LIST \n");
        printf("(5) DELETE AT THE END LIST \n");
        printf("(6) ADD AT THE GIVEN POSITION IN THE LIST LIST \n");
        printf("(7) DELETE AT THE GIVEN POSITION IN THE LIST LIST \n");
        printf("(8) SEARCH A KEY IN THE LINKED LIST \n");
        printf("(9) FREQUENCY OF A KEY IN THE LINKED LIST \n");
        printf("(10) LENGTH OF THE LINKED LIST \n");
        printf("(11) REVERSE THE LINKED LIST \n");
        printf("(12) DELETE THE FIRST OCCOURENCE OF THE KEY IN THE LIST LIST \n");
        printf("(12) DELETE THE FIRST OCCOURENCE OF THE KEY IN THE LIST LIST \n");
        printf("(14) DELETE DUPLICATES IN THE LIST LIST \n");

        printf("\n\n\n");

        printf("ENTER CHOICE :  ");
        scanf("%d", &ch);

        printf("\n\n\n");

                                                                                
        switch (ch)
        {
        case 0:
            printf("Enter Till where you want to add the numbers :  ");
            scanf("%d", &n);
            for (int i = n; i >= 0; i--)
            {
                AddatEnd(&head, i);
            }
            break;

        case 1:
            DisplayLinkedlist(head);
            break;

        case 2:
            printf("Enter the data that is to be added : ");
            scanf("%d", &d);
            addAtBegin(&head, d);
            break;

        case 3:
            if (head == NULL)
            {
                printf("The Linked List is empty ");
            }
            else
            {
                d = DeleteAtBeg(&head);
                printf("%d = The deleted Data", d);
            }
            break;

        case 4:
            printf("Enter the data that is to be added : ");
            scanf("%d", &d);
            AddatEnd(&head, d);
            break;

        case 5:
            if (head == NULL)
            {
                printf("The Linked List is empty ");
            }
            else
            {
                d = deleteAtEnd(&head);
                printf("%d = The deleted Data", d);
            }
            break;

        case 6:
            printf("Enter the data that is to be added : ");
            scanf("%d", &d);
            printf("Enter the position where it is to be added : ");
            scanf("%d", &pos);
            addAtPosition(&head, d, pos);
            break;

        case 7:
            if (head == NULL)
            {
                printf("The Linked List is empty ");
            }
            else
            {
                printf("Enter the position where it is to be Deleted : ");
                scanf("%d", &pos);
                d = delAtPosition(&head, pos);
                printf("%d = The deleted Data", d);
            }
            break;

        case 8:
            printf("Enter the key that is to be Searched : ");
            scanf("%d", &key);
            d = SearchKey(head, key);
            if (d == 1)
                printf("The key is found");
            else
                printf("The key is not found");
            break;

        case 9:
            printf("Enter the key that is to be Searched : ");
            scanf("%d", &key);
            d = frequencyofThekey(head, key);
            printf("The frequency of the key is %d", d);
            break;

        case 10:
            d = lengthofList(head);
            printf("The length Of the list is %d", d);
            break;

        case 11:
            reverseLinkedList(&head);
            break;

        case 12:
            printf("Enter the key that is to be Deleted : ");
            scanf("%d", &key);
            deletetheFirstOccourence(&head, key);
            break;

        case 13:
            printf("Enter the data that is to be added : ");
            scanf("%d", &d);
            printf("Enter the key that is to be checked : ");
            scanf("%d", &key);
            addAfterKey(&head, d, key);
            break;

        case 14:
            deleteDuplicates(&head);
            break;

        case 15:
            sortList(head);
            break;

        case 16:
                ;
            break;

        default:
            exit(0);
            break;
        }

        printf("\n\n");
    }

    getch();
    return 0;
}
