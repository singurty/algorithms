// The algorithm design manual exercise 4-1

#include <stdlib.h>
#include <stdio.h>
#include <sys/queue.h>

#define BUF_SIZE 100

struct entry {
	double data;
	STAILQ_ENTRY(entry) entries;
};

STAILQ_HEAD(stailhead, entry);

void merge(double s[], int low, int middle, int high) {
	struct stailhead buffer1, buffer2;
	STAILQ_INIT(&buffer1);
	STAILQ_INIT(&buffer2);

	for (int i = low; i <= middle; i++) {
		struct entry *n1 = malloc(sizeof(struct entry));
		n1->data = s[i];
		STAILQ_INSERT_TAIL(&buffer1, n1, entries);
	}
	for (int i = middle + 1; i <= high; i++) {
		struct entry *n1 = malloc(sizeof(struct entry));
		n1->data = s[i];
		STAILQ_INSERT_TAIL(&buffer2, n1, entries);
	}

	int i = low;
	while (!(STAILQ_EMPTY(&buffer1) || STAILQ_EMPTY(&buffer2))) {
		if (STAILQ_FIRST(&buffer1)->data <= STAILQ_FIRST(&buffer2)->data) {
			s[i++] = STAILQ_FIRST(&buffer1)->data;
			STAILQ_REMOVE_HEAD(&buffer1, entries);
		} else {
			s[i++] = STAILQ_FIRST(&buffer2)->data;
			STAILQ_REMOVE_HEAD(&buffer2, entries);
		}
	}

	while (!STAILQ_EMPTY(&buffer1)) {
		s[i++] = STAILQ_FIRST(&buffer1)->data;
		STAILQ_REMOVE_HEAD(&buffer1, entries);
	}

	while (!STAILQ_EMPTY(&buffer2)) {
		s[i++] = STAILQ_FIRST(&buffer2)->data;
		STAILQ_REMOVE_HEAD(&buffer2, entries);
	}
}

void merge_sort(double s[], int low, int high) {
	if (low < high) {
		int middle = (low + high) / 2;
		merge_sort(s, low, middle);
		merge_sort(s, middle + 1, high);
		merge(s, low, middle, high);
	}
}

void print_array(double s[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%.1f ", s[i]);
	}
	printf("\n");
}

int main() {
	double players[] = {2.2, 1, 4.3, 7.1, 9, 9.9, 3, 3.3, 3.8, 5.5, 5, 6.9, 7, 4.7};
	int n = sizeof(players) / sizeof(double);
	print_array(players, n);
	merge_sort(players, 0, n - 1);
	printf("Team 1:\n");
	print_array(players, n/2);
	printf("Team 2:\n");
	print_array(players + (n/2), n/2);
}
