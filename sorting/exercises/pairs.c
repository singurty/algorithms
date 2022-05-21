// The algorithm design manual exercise 4-3

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int *numbers;
int length;

void printNumbers() {
	for (int i = 0; i < length; i++) {
		printf("%d ", numbers[i]);
		printf("\n");
	}
}

int main() {
	printf("How many numbers? (should be even) ");
	scanf("%d", &length);
	if (length % 2 != 0) {
		printf("Length should be divisible by two\n");
		return 1;
	}
	numbers = malloc(sizeof(int) * length);
	int *current = numbers;

	for (int i = 0; i < length; i++) {
		printf("Input number: ");
		scanf("%d", current);
		current++;
	}
	sort(numbers, length);
	printNumbers();
}