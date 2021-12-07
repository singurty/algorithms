#include <stdio.h>

#define PQ_SIZE 20

typedef struct {
	int q[PQ_SIZE];
	int n;
} priority_queue;

int pq_parent(int n) {
	if (n == 0) {
		return -1;
	}
	return (int) n/2;
}

int pq_young_child(int n) {
	return 2 * n;
}

void pq_swap(priority_queue *q, int x, int y) {
	int temp = q->q[x];
	q->q[x] = q->q[y];
	q->q[y] = temp;
}

void bubble_up(priority_queue *q, int p) {
	if (pq_parent(p) == -1) {
		return; // root of heap
	}
	if (q->q[pq_parent(p)] > q->q[p]) {
		pq_swap(q, p, pq_parent(p));
		bubble_up(q, pq_parent(p));
	}
}

void pq_insert(priority_queue *q, int x) {
	if (q->n >= PQ_SIZE) {
		printf("Warning: priority queue overflow!\n");
	} else {
		q->q[q->n] = x;
		q->n = (q->n) + 1;
		bubble_up(q, q->n);
	}
}

void pq_init(priority_queue *q) {
	q->n = 0;
}

void make_heap(priority_queue *q, int s[], int n) {
	pq_init(q);
	for (int i = 0; i < n; i++) {
		pq_insert(q, s[i]);
	}
}

void bubble_down(priority_queue *q, int p) {
	int c;
	int min_index;
	c = pq_young_child(p);
	min_index = p;
	// run for both children
	for (int i = 0; i <=1; i++) {
		if ((c + i) < q->n) {
			if (q->q[min_index] > q->q[c + i]) {
				// also need to check whether this child dominates its sibling
				min_index = c + i;
			}
		}
	}
	if (min_index != p) {
		pq_swap(q, p, min_index);
		bubble_down(q, min_index);
	}
}

int extract_min(priority_queue *q) {
	int min = -1;
	if (q->n <= 0) {
		printf("Warning: empty priority queue.\n");
	} else {
		min = q->q[0];
		q->q[0] = q->q[q->n - 1];
		q->n = q->n - 1;
		bubble_down(q, 0);
	}
	return min;
}
