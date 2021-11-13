#include <stdlib.h>
#include <stdio.h>

#define LENGTH 10

typedef struct list {
	int item;
	struct list *next;
} list;

list *head;

void insert(int item) {
	list *p;
	p = malloc(sizeof(list));
	p->item = item;
	p->next = head;
	head = p;
}

void delete(list* node) {
	// this is the END node
	if (node->next == NULL) {
		return;
	}
	// if this is the first node then slice off
	if (head == node) {
		list *prevHead = head;
		head = head->next;
		free(prevHead);
		return;
	}
	// if this is the last element then make this
	// the end marker element
	if (node->next->next == NULL) {
		free(node->next);
		node->next = NULL;
		return;
	}
	// over write the item of node with node.next
	list *successor = node->next;
	node->item = successor->item;
	node->next = successor->next;
	free(successor);
}

void printList() {
	list *l = head;
	while (l->next != NULL) {
		printf("%d\n", l->item);
		l = l->next;
	}
}

void deleteSome() {
deleteLoop:;
	list *l = head;
	while (l->next != NULL) {
		switch (l->item) {
			case 9:
			case 3:
			case 5:
			case 7:
			case 0:
				delete(l);
				goto deleteLoop;
		}
		l = l->next;
	}
}

int main() {
	// the node with NULL as next marks the end
	list* end = malloc(sizeof(list));
	end->next = NULL;
	head = end;
	for (int i = 0; i < LENGTH; i++) {
		insert(i);
	}
	printList();
	deleteSome();
	printf("After delete:\n");
	printList();
}
