#include <stdlib.h>
#include <stdio.h>

#define LENGTH 10

typedef struct {
	int item;
	struct list *next;
} list;

list *head;

void insert(int item) {
	list *p;
	p = malloc(sizeof(list));
	p->item = item;
	p->next = (struct list *) head;
	head = p;
}

void printList() {
	list *l = head;
	while (l != NULL) {
		printf("%d\n", l->item);
		l = (list *) l->next;
	}
}

void reverse() {
	list** pointers = malloc(LENGTH);
	list *l = head;
	// get pointers of all nodes
	pointers[0] = head;
	for (int i = 1; l->next != NULL; i++) {
		pointers[i] = (list *) l->next;
		l = (list *) l->next;
	}
	// put them back in reverse order
	head = pointers[LENGTH - 1];
	l = head;
	for (int i = LENGTH - 2; i >= 0; i--) {
		l->next = (struct list *) pointers[i];
		l = (list *) l->next;
	}
	// mark the end
	pointers[0]->next = NULL;
	free(pointers);
}

int main() {
	head = NULL;
	for (int i = 0; i < LENGTH; i++) {
		insert(i);
	}
	printList();
	reverse();
	printf("After reverse:\n");
	printList();
}
