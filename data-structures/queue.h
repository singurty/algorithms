#define QUEUESIZE 1000

typedef int item_type;

typedef struct {
  item_type q[QUEUESIZE+1];
  int first;
  int last;
  int count;
} queue;

void init_queue(queue *q);
void enqueue(queue *q, item_type x);
item_type dequeue(queue *q);
item_type headq(queue *q);
int empty_queue(queue *q);