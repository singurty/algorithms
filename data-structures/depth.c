#include <stdlib.h>
#include <stdio.h>

typedef struct tree {
	int item;
	struct tree *parent;
	struct tree *left;
	struct tree *right;
} tree;

tree *root = NULL;

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

int depth(tree *t) {
	int count = 1;
	int leftCount = 0;
	int rightCount = 0;;
	if (t->left != NULL) {
		leftCount = depth(t->left);
	}
	if (t->right != NULL) {
		rightCount += depth(t->right);
	}
	if (leftCount > rightCount) {
		count += leftCount;
	} else {
		count += rightCount;
	}
	return count;
}

int main() {
	insert(&root, 2, root);
	insert(&root, 1, root);
	insert(&root, 7, root);
	insert(&root, 4, root);
	insert(&root, 8, root);
	insert(&root, 6, root);
	insert(&root, 5, root);
	printf("depth of tree is %d\n", depth(root));
}
