#include <stdio.h>

#include <math.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 5

typedef struct Stack
{
    char data[SIZE];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = -1;
}

int isFull(Stack *s)
{
    return s->top == SIZE - 1;
}

void push(Stack *s, int ele)
{
    s->top++;
    s->data[s->top] = ele;
}

int pop(Stack *s)
{
    int ele = s->data[s->top];
    s->top--;
    return ele;
}

int TopStack(Stack *s)
{
    return s->data[s->top];
}

int IsEmpty(Stack *s)
{
    return s->top == -1;
}

void DisplayStack(Stack *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%c\n", s->data[i]);
    }
    printf("\n\n");
}

int main()
{

    printf("\n\n");

    int ch;
    char ele;

    Stack s;
    initStack(&s);

    while (1)
    {
        printf("(0) Display all Element in the Stack\n");
        printf("(1) Push an Element in the Stack\n");
        printf("(2) Pop an Element from the Stack\n");
        printf("(3) Peek an Element in the Stack\n");
        printf("(4) Is the Stack Full\n");
        printf("(5) Is the Stack Empty\n");

        printf("\n\n\n");

        printf("Enter the Choive that you want to perform : ");
        scanf("%d", &ch);
        getchar();

        printf("\n\n\n");

        switch (ch)
        {
        case 0:
            printf("The Stack To be displayed is :\n");
            if (IsEmpty(&s))
            {
                printf("Stack UnderFlow\n");
                break;
            }

            DisplayStack(&s);
            break;

        case 1:
            if (isFull(&s))
            {
                printf("Stack OverFlow \n");
                printf("\n");
            }
            else
            {
                printf("Enter The Element to be pushed into the Stack :  ");
                do
                {

                    scanf("%c", &ele);
                } while (ele == '\n');

                push(&s, ele);
                printf("\n\n");
            }
            break;

        case 2:
            if (IsEmpty(&s))
            {
                printf("Stack UnderFlow \n");
                printf("\n");
            }
            else
            {
                ele = pop(&s);
                printf("The poped Element is : ");
                printf("%c", ele);
                printf("\n\n");
            }
            break;

        case 3:
            if (IsEmpty(&s))
            {
                printf("Stack UnderFlow \n");
                printf("\n");
            }
            else
            {
                ele = TopStack(&s);
                printf("The Top Element is : ");
                printf("%c", ele);
                printf("\n\n");
            }
            break;

        case 4:
            if (isFull(&s))
            {
                printf("Stack Full \n");
                printf("\n");
            }
            else
            {
                printf("Stack not Full \n");
                printf("\n");
            }
            break;

        case 5:
            if (IsEmpty(&s))
            {
                printf("Stack Empty \n");
                printf("\n");
            }

            else
            {
                printf("Stack not Empty \n");
                printf("\n");
            }

            break;

        default:
            break;
        }
    }

    
    return 0;
}