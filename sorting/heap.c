#include <stdio.h>

#define PQ_SIZE 100

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
	if (n == 0) {
		return 1;
	}
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
		q->n++;
		bubble_up(q, q->n - 1);
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

void pq_init(priority_queue *q) {
	q->n = 0;
}

void make_heap(priority_queue *q, int s[], int n) {
	pq_init(q);
	for (int i = 0; i < n; i++) {
		pq_insert(q, s[i]);
	}
}

void make_heap_fast(priority_queue *q, int s[], int n) {
	q->n = n;
	for (int i = 0; i < n; i++ ) {
		q->q[i] = s[i];
	}
	for (int i = q->n/2; i >= 0; i--) {
		bubble_down(q, i);
	}
}

void heapsort_(int s[], int n) {
	priority_queue q;
	make_heap_fast(&q, s, n);
	for (int i = 0; i < n; i++) {
		s[i] = extract_min(&q);
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
	int n = sizeof(s) / sizeof(s[0]);
	print_array(s, n);
	heapsort_(s, n);
	print_array(s, n);
}
