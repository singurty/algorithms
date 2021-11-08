#include <stdio.h>
#include <unistd.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int* array, int length) {
	printf("[ ");
	for (int i=0; i<length; i++) {
		printf("%d, ", array[i]);
	}
	printf("]\n");
}

void insertion_sort(int* s, int n) {
	int i, j;
	for (i = 1; i < n; i++) {
		j = i;
		while ((j > 0) && (s[j] < s[j - 1])) {
			swap(&s[j], &s[j - 1]);
			printArray(s, n);
			sleep(1);
			j = j - 1;
		}
	}
}

int main() {
	int testArray[] = {5,6,3,8,6,4,2,455,3,43,54,75,1,3,436,543,41};
	int length = sizeof(testArray) / sizeof(testArray[0]);
	printArray(testArray, length);
	insertion_sort(testArray, length);
}
