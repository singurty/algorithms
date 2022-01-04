#include <stdlib.h>
#include <stdio.h>
#include <sys/queue.h>

#define BUF_SIZE 100

struct entry {
	int data;
	STAILQ_ENTRY(entry) entries;
};

STAILQ_HEAD(stailhead, entry);

void merge(int s[], int low, int middle, int high) {
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

void merge_sort(int s[], int low, int high) {
	if (low < high) {
		int middle = (low + high) / 2;
		merge_sort(s, low, middle);
		merge_sort(s, middle + 1, high);
		merge(s, low, middle, high);
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
	merge_sort(s, 0, sizeof(s) / sizeof(int) - 1);
	print_array(s, sizeof(s) / sizeof(int));
}
