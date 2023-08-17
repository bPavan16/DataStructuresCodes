#include <stdio.h>
#include <ctype.h>

#include <math.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 30

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

/// prototypes
int isOperator(char ch);
int precedence(char s);
void reverseString(char str[]);
void ConvertInfix_To_prefix(char infix[], char prefix[]);

int main()
{

    char infix[50];
    char prefix[50];
    printf("Enter the value of the infix that is to be converted to prefix : ");
    // scanf("%s", infix);

    ConvertInfix_To_prefix("(A-B/C)*(A/K-L)", prefix);

    printf("The prefix String is %s", prefix);
}

int isOperator(char ch)
{
    if (ch == '-' || ch == '+' || ch == '*' || ch == '/' || ch == '^')
        return 1;

    else
        return 0;
}

int precedence(char s)
{
    switch (s)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;

    default:
        return 0;
    }
}

void reverseString(char str[])
{
    char key;
    Stack s;
    initStack(&s);

    for (int i = 0; str[i]; i++)
    {
        push(&s, str[i]);
    }

    int j = 0;

    while (!IsEmpty(&s))
    {
        str[j] = pop(&s);
        j++;
    }
}

void ConvertInfix_To_prefix(char infix[], char prefix[])
{

    Stack s;
    initStack(&s);

    int j = 0;
    int L = strlen(infix);

    for (int i = L - 1; i >= 0; i--)
    {
        if (isalnum(infix[i]))
        {
            prefix[j] = infix[i];
            j++;
        }

        else if (isOperator(infix[i]))
        {
            while (!IsEmpty(&s) && precedence(infix[i]) < precedence(TopStack(&s)))
            {
                prefix[j] = pop(&s);
                j++;
            }

            push(&s, infix[i]);
        }

        else if (infix[i] == ')')
            push(&s, infix[i]);

        else if (infix[i] == '(')
        {
            while (!IsEmpty(&s) && TopStack(&s)!= '(')
            {
                prefix[j] = pop(&s);
                j++;
            }
            pop(&s);
        }
    }

    while (!IsEmpty(&s))
    {
        prefix[j] = pop(&s);
        j++;
    }
    prefix[j] = '\0';

    reverseString(prefix);
}
