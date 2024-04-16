#include<stdio.h>
#include<stdlib.h>

#define MALLOC(p, s) \
    if (!((p) = malloc(s))) { \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);\
    }

typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer rightChild, leftChild;
}node;

treePointer root;

treePointer createNode(int key)
{
	treePointer ptr;
	MALLOC(ptr, sizeof(*ptr));
	ptr->data = key;
	ptr->leftChild = ptr->rightChild = NULL;
	root = ptr;
	return root;
}

treePointer insert(treePointer ptr, int key)
{
	if (!ptr) {
		return createNode(key);
	}
	if (key < ptr->data) {
		ptr->leftChild = insert(ptr->leftChild, key);
	}
	else {
		ptr->rightChild = insert(ptr->rightChild, key);
	}
	return ptr;
}
treePointer maxNode(treePointer ptr)
{
	if (ptr) {
		ptr = ptr->rightChild;
		maxNode(ptr);
	}
	return ptr;
}

treePointer delete(treePointer ptr, int key)
{
	if (!ptr) {
		return ptr;
	}
	if (key < ptr->data) {
		ptr->leftChild = delete(ptr->leftChild, key);
	}
	else if (key > ptr->data) {
		ptr->rightChild = delete(ptr->rightChild, key);
	}
	else {
		if (!ptr->leftChild) {
			treePointer temp = ptr->rightChild;
			free(ptr);
			return temp;
		}
		else if (!ptr->rightChild) {
			treePointer temp = ptr->leftChild;
			free(ptr);
			return temp;
		}
		treePointer temp = maxNode(ptr->leftChild);
		ptr->data = temp->data;
		ptr->leftChild = delete(ptr->leftChild, temp->data);
	}
	return ptr;
}

void preorder(treePointer ptr)
{
	if (ptr)
	{
		if (ptr->data != 0)
			printf("%d ", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

int main()
{
	int t = 0, count = 0;

	while (t != -1)
	{
		scanf_s("%d", &t);
		if (t == -1)
			break;
		root = insert(root, t);
	}
	t = 0;
	while (t != -1)
	{
		scanf_s("%d", &t);
		if (t == -1)
			break;
		if (count % 2 == 0)
			delete(root, t);
		else if (count % 2 == 1)
			root = insert(root, t);
		preorder(root);
		printf("\n");
		count++;
	}
	return 0;
}