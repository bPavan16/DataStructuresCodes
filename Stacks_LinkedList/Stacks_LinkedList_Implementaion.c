#include <stdio.h>
// #include<conio.h>
// #include<math.h>
// #include<string.h>
// #include<stdlib.h>

typedef struct content
{
    int num;
} content;

typedef struct node
{
    content data;
    struct node *next;
} Node;

typedef struct stack
{
    Node *head;
} Stack;

void initStack(Stack *s)
{
    s->head = NULL;
}

void Push(Stack *s, content d)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = d;
    newNode->next = s->head;
    s->head = newNode;
}

content pop(Stack *s)
{
    Node *curr = s->head;
    content d = s->head->data;
    s->head = s->head->next;
    free(curr);
    return d;
}

content peek(Stack *s)
{
    return s->head->data;
}


int main()
{

    // getch();
    return 0;
}