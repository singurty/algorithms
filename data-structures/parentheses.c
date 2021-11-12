#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
	int* stack;
	int* top;
} stack;

void push(int value) {
	*stack.top = value;
	stack.top++;
}

void pop() {
	stack.top--;
}

int main(int argc, const char* argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <string>\n", argv[0]);
		exit(1);
	}
	// init stack
	stack.stack = malloc(strlen(argv[1]));
	stack.top = stack.stack;
	// iterate though the string
	for (int i = 0; i < strlen(argv[1]); i++) {
		if (argv[1][i] == '(') {
			push(i);
		} else if (argv[1][i] == ')') {
			// no matching opening parenthesis
			if (stack.top == stack.stack) {
				printf("false\n");
				printf("offending parenthesis at %d\n", i);
				exit(0);
			}
			pop();
		}
	}
	// all opening parentheses terminatd
	if (stack.top == stack.stack) {
		printf("true\n");
	} else {
		printf("false\n");
		printf("offending parenthesis at %d\n", stack.top[-1]);
	}
}
