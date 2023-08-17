#include <stdio.h>
#include <conio.h>
// #include<math.h>
// #include<string.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} Node;

void AddAtBeg(Node **tail, int d)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = d;

    if (*tail == NULL)
    {
        *tail = newNode;
        (*tail)->next = (*tail);
        return;
    }

    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
}

void DisplayTheList(Node *tail)
{
    Node *curr = tail->next;

    do
    {
        printf("%d--->", curr->data);
        curr = curr->next;

    } while (curr != tail->next);

    printf("[]");
    printf("\n");
    printf("\n\n");
}

void Add_at_End(Node **tail, int d)
{

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = d;

    if (*tail == NULL)
    {
        *tail = newNode;
        (*tail)->next = (*tail);
        return;
    }

    newNode->next = (*tail)->next;
    (*tail)->next = newNode;
    (*tail) = newNode;
}

void Add_at_pos(Node **tail, int d,int pos)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = d;

    if (*tail == NULL)
    {
        *tail = newNode;
        (*tail)->next = (*tail);
        return;
    }

    if(pos<=0)
    {


    }



}

int main()
{

    int n;
    int ch;

    int d;
    int pos;
    int l;

    Node *tail = NULL;

    while (1)
    {
        printf("///////////////////////////////////////////////////////////////////\n");
        printf("(0) CREATE TEST CASE LIST \n");
        printf("(1) DISPLAY THE LINKED LIST\n");
        printf("(2) INSERT AT BEGINING\n");
        printf("(3) INSERT AT END\n");
        printf("(4) INSERT AT POSITION\n");
        // printf("(4) DELETE AT BEGINING\n");
        // printf("(5) DELETE AT END\n");
        // printf("(5) DELETE AT POSITION\n");
        printf("(7) LENGTH OF THE LINKED LIST\n");

        printf("\n\n");

        printf("ENTER THE CHOICE THAT YOU WANT : ");
        scanf("%d", &ch);

        printf("\n\n");

        switch (ch)
        {

        case 0:
            printf("Enter Till where Numbers You want :  ");
            scanf("%d", &n);

            for (int i = 1; i <= n; i++)
            {
                Add_at_End(&tail, i);
            }
            printf("\n");

            break;

        case 1:
            DisplayTheList(tail);
            break;

        case 2:
            printf("Enter data to be Added : ");
            scanf("%d", &d);
            AddAtBeg(&tail, d);
            printf("\n");

            break;

        case 3:
            printf("Enter data to be Added : ");
            scanf("%d", &d);
            Add_at_End(&tail, d);
            printf("\n");

            break;

        case 4:
            printf("Enter data to be Added : ");
            scanf("%d", &d);
            printf("Enter position to be Added : ");
            scanf("%d", &pos);
            // Add_at_pos(&tail, d, pos);
            printf("\n");
            break;

        case 7:
            // l = LengthList(tail);
            printf("The length of the list is : %d ", l);
            printf("\n\n");
            break;

        default:
            exit(0);
        }
    }

    getch();
    return 0;
}