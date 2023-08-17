 #include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 20

typedef struct Stack
{
    int top;
    char array[SIZE];
} Stack;

void toPostfix(char infix[], char postfix[]);
int isOperator(char ch);
int precedence(char s);

void initStack(Stack *s)
{
    s->top = -1;
}

int isFull(struct Stack *stack)
{
    return stack->top == SIZE - 1;
}

int isEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, char item)
{
    if (isFull(stack))
    {
        printf("Stack overFlow \n");
        return;
    }
    stack->array[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    char m = stack->array[stack->top];
    stack->top--;
    return m;
}

char peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

int main()
{

    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";
    char postfix[50];
    // printf("Enter Your Infix Expresion :  ");
    // scanf("%s", infix);
    toPostfix(infix, postfix);
    printf("%s", postfix);

    return 0;
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
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

void toPostfix(char infix[], char postfix[])
{
    Stack op;
    initStack(&op);
    int len = strlen(infix);
    int j = 0;
    
    for (int i = 0; infix[i]; i++)
    {

        if (isalnum(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
        }

        else if (isOperator(infix[i]))
        {
            while (!isEmpty(&op) && (precedence(infix[i]) <= precedence(peek(&op))))
            {
                postfix[j] = pop(&op);
                j++;
            }
            push(&op, infix[i]);
        }

        else if (infix[i] == '(')
            push(&op, infix[i]);

        else if (infix[i] == ')')
        {
            while (!isEmpty(&op) && peek(&op) != '(')
            {
                postfix[j] = pop(&op);
                j++;
            }
            pop(&op);
        }
    } // end for

    while (!isEmpty(&op))
    {
        postfix[j] = pop(&op);
        j++;
    }

    postfix[j] = '\0';
}
