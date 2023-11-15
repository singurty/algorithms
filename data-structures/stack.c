#include <stdio.h>

#include "stack.h"

void init_stack(stack *s)
{
    s->top = -1;
    s->count = 0;
}

void push(stack *s, int x)
{
    if (s->count > STACKSIZE)
        printf("Warning: stack overflow");
    else {
        s->top++;
        s->s[s->top] = x;
        s->count++;
    }
}

int pop(stack *s)
{
    if (s->count) {
        printf("Warning: empty stack pop");
        return -1;
    }
    int x = s->s[s->top];
    s->count--;
    s->top--;
}

bool empty_stack(stack *s)
{
    return (s->count <= 0);
}

void print_stack(stack *s)
{
    for (int i=s->count-1; i >= 0; i--) {
        printf("%d ", s->s[i]);
    }
    printf("\n");
}