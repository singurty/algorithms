#include <stdbool.h>

#define STACKSIZE 1000

typedef struct {
    int s[STACKSIZE+1];
    int top;
    int count;
} stack;

void init_stack(stack *s);
void push(stack *s, int x);
int pop(stack *s);
bool empty_stack(stack *s);
void print_stack(stack *s);