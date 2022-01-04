#include <stdio.h>

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int s[], int l, int h) {
	int p = h; // select the last element as pivot
	int firsthigh = l; // divider position for pivot element

	for (int i = l; i < h; i++) {
		if (s[i] < s[p]) {
			swap(&s[i], &s[firsthigh]);
			firsthigh++;
		}
	}
	swap(&s[p], &s[firsthigh]);
	return firsthigh;
}

void quicksort(int s[], int l, int h) {
	if (l < h) {
		int p = partition(s, l, h);
		quicksort(s, l, p - 1);
		quicksort(s, p + 1, h);
	}
}

void print_array(int s[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", s[i]);
	}
	printf("\n");
}

int main() {
	int s[] = {4,3,62,3,2,3,1,6,7,34,76,2,6,24,43,65,78,61,86,23,63,81,37,97,15,19,37,13,55,89,54,21,92,19,76,21,46};
	print_array(s, sizeof(s) / sizeof(int));
	quicksort(s, 0, sizeof(s) / sizeof(int) - 1);
	print_array(s, sizeof(s) / sizeof(int));
}
