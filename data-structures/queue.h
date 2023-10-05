#define QUEUESIZE 1000

typedef int item_type;

typedef struct {
  item_type q[QUEUESIZE+1]
  int first;
  int last;
  int count;
} queue;
