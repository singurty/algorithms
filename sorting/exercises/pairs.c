// The algorithm design manual exercise 4-3

#include <stdio.h>
#include <stdlib.h>

int main() {
	int length;
	printf("How many numbers? ");
	scanf("%d", &length);
	int *numbers = malloc(sizeof(int) * length);
	int *current = numbers;

	for (int i = 0; i < length; i++) {
		printf("Input number: ");
		scanf("%d", current);
		current++;
	}

	for (int i = 0; i < length; i++) {
		printf("%d ", numbers[i]);
		printf("\n");
	}
}