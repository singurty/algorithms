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

void freeTree(tree *t) {
	if (t->left != NULL) {
		freeTree(t->left);
	}
	if (t->right != NULL) {
		freeTree(t->right);
	}
	free(t);
}

void printTree(tree *t, int space) {
	// Base case
	if (t == NULL)
		return;

	// Increase distance between levels
	space += 4;

	// Process right child first
	printTree(t->right, space);

	// Print current node after space
	// count
	printf("\n");
	for (int i = 4; i < space; i++)
		printf(" ");
	printf("%d\n", t->item);

	// Process left child
	printTree(t->left, space);
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

int size(tree *t) {
	int count = 1;
	int leftCount = 0;
	int rightCount = 0;;
	if (t->left != NULL) {
		leftCount = size(t->left);
	}
	if (t->right != NULL) {
		rightCount += size(t->right);
	}
	count += leftCount;
	count += rightCount;
	return count;
}

void bstToArray(tree *t, int *array, int *index) {
	if (t->left != NULL) {
		bstToArray(t->left, array, index);
	}
	array[*index] = t->item;
	*index += 1;
	if (t->right != NULL) {
		bstToArray(t->right, array, index);
	}
}

void arrayToBst(int *array, tree **t, int length) {
	printf("start: %d length: %d\n", array[0], length);
	if (length < 1) {
		return;
	}
	if (length == 1) {
		insert(t, array[0], *t);
		return;
	}

	int mid;
	if (length % 2 == 0) {
		mid = length / 2;
	} else {
		mid = (length + 1) / 2;
	}
	insert(t, array[mid - 1], *t);
	arrayToBst(array, t, mid - 1);
	if (length % 2 == 0) {
		arrayToBst(array + mid, t, mid);
	} else {
		arrayToBst(array + mid, t, mid - 1);
	}
}

void balanceTree() {
	// create a sorted array out of BST
	int arraySize = size(root);
	int bstArray[arraySize];
	int index = 0;
	bstToArray(root, bstArray, &index);
	printf("array out of bst:\n");
	for (int i = 0; i < arraySize; i++) {
		printf("%d ", bstArray[i]);
	}
	printf("\n");

	tree *newTree = NULL;
	arrayToBst(bstArray, &newTree, arraySize);
	freeTree(root);
	root = newTree;
}

int main() {
	insert(&root, 4, root);
	insert(&root, 1, root);
	insert(&root, 3, root);
	insert(&root, 2, root);
	insert(&root, 8, root);
	insert(&root, 5, root);
	insert(&root, 6, root);
	insert(&root, 11, root);
	insert(&root, 15, root);
	insert(&root, 12, root);
	insert(&root, 13, root);
	insert(&root, 21, root);
	insert(&root, 24, root);
	insert(&root, 16, root);
	insert(&root, 17, root);
	insert(&root, 7, root);
	printf("left-hand depth: %d\n", depth(root->left));
	printf("right-hand depth: %d\n", depth(root->right));
	printTree(root, 4);

	printf("banancing tree...\n");
	balanceTree();
	printf("left-hand depth: %d\n", depth(root->left));
	printf("right-hand depth: %d\n", depth(root->right));
	printTree(root, 4);
}
