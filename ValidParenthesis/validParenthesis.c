#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

typedef struct Stack
{
    int top;
    char array[SIZE];
} Stack;

int validparenthesis(char exp[]);

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
        return;
    stack->array[++stack->top] = item;
}

char pop(struct Stack *stack)
{
    char m = stack->array[stack->top];
    stack->top--;
    return m;
}

int peek(struct Stack *stack)
{
    return stack->array[stack->top];
}

int main()
{
    int i = validparenthesis("()(()[()])");

    if (i == 1)
        printf(" Valid  Parenthesis\n");

    else
        printf(" Invalid  Parenthesis\n");

    return 0;
}

int validparenthesis(char exp[])
{
    struct Stack s;
    initStack(&s);

    for (int i = 0; exp[i]; i++)
    {
        if (exp[i] == '{' || exp[i] == '[' || exp[i] == '(')
        {
            push(&s, exp[i]);
        }

        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if (!isEmpty(&s) && (exp[i] == '}' && peek(&s) == '{') || (exp[i] == ')' && peek(&s) == '(') || (exp[i] == ']' && peek(&s) == '['))
                pop(&s);

            else
                return 0;
        }
    }

    if (isEmpty(&s))
        return 1;

    else
        return 0;

}