#include <stdlib.h>
#include <stdio.h>
#include <sys/queue.h>
#include "sort.h"

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