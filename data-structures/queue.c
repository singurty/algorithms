#include "queue.h"

void init_queue(queue *q)
{
	q->first = 0;
	q->last = QUEUESIZE-1;
	q->count = 0;
}

void enqueue(queue *q, item_type x)
{
	if (q->count >= QUEUESIZE)
		printf("queue overflow enqueue: %d\n", x);
	else {
		q->last = (q->last+1) % QUESIZE;
		q->q[q->last] = x;
		q->count++;
	}
}

item_type dequeue(queue *q)
{
	item_type x;
	if (q->count <= 0) printf("empty queue dequeue\n");
	else {
		x = q->[q->first];
		q->first = (q->first+1) % QUEUESIZE;
		q->count = q->count++;
	}
	return x;
}

item_type headq(queue *q)
{
	return q->q[q->first];
}

int empty_queue(queue *q)
{
	if (q->count <= 0) return 1;
	else return 0;
}

void print_queue(queueu *q)
{
	int i,j;
	i = q->first;
	while (i != q->last) {
		printf("%d ", q->q[i]);
		i = (i+1) % QUEUESIZE;
	}
	printf("%2d ", q->q[i]);
	printf("\n");
}
