// Given two binary search trees, merge ethem into a
// doubly linked list in sorted order

#include <stdlib.h>

typedef struct tree {
	int item;
	struct tree *parent;
	struct tree *left;
	struct tree *right;
} tree;

typedef struct list {
	int item;
	struct list *previous;
	struct list *next;
} list;

tree *root1 = NULL;
tree *root2 = NULL;

list *head = NULL;

void insert(tree **t, int item, tree *parent) {
	tree *p;
	if (*t == NULL) {
		p = malloc(sizeof(tree));
		p->item = item;
		p->left = p->right = NULL;
		p->parent = parent;
		*t = p;
		return;
	}
	if (item < (*t)->item) {
		insert(&((*t)->left), item, *t);
	} else {
		insert(&((*t)->right), item, *t);
	}
}

void mergeTrees() {

}

void initTrees() {
	insert(&root1, 4, root1);
	insert(&root1, 1, root1);
	insert(&root1, 3, root1);
	insert(&root1, 2, root1);
	insert(&root1, 8, root1);
	insert(&root1, 5, root1);
	insert(&root1, 6, root1);
	insert(&root1, 11, root1);
	insert(&root1, 15, root1);
	insert(&root1, 12, root1);
	insert(&root1, 21, root1);

	insert(&root2, 7, root2);
	insert(&root2, 3, root2);
	insert(&root2, 1, root2);
	insert(&root2, 5, root2);
	insert(&root2, 9, root2);
	insert(&root2, 8, root2);
	insert(&root2, 10, root2);
	insert(&root2, 13, root2);
	insert(&root2, 11, root2);
	insert(&root2, 22, root2);
}

int main() {
	initTrees();
}
