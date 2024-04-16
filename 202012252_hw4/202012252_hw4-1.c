#include<stdio.h>
#include<stdlib.h>
#define MAX_NODE_SIZE 1000
#define MAX_QUEUE_SIZE 1000

#define MALLOC(p, s) \
    if (!((p) = malloc(s))) { \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);\
    }

typedef struct node* treePointer;
typedef struct node{
	int data, key;
	treePointer rightChild, leftChild;
}node;

treePointer root, child, queue[MAX_QUEUE_SIZE];
int count, rear=0, front=0;

void create(int t)
{
	MALLOC(root, sizeof(*root));
	root->leftChild = NULL;
	root->rightChild = NULL;
	root->data = t;
	root->key = 1;
}
treePointer search(treePointer ptr, int count, treePointer child)
{
	if(ptr)
	{
		if (ptr -> key == count / 2)
		{
			if (count % 2 == 0)
				ptr->leftChild = child;
			else if (count % 2 == 1)
				ptr->rightChild = child;
		}
		search(ptr->leftChild, count, child);
		search(ptr->rightChild, count, child);
	}
}

void insert(int t, int count)
{
	if (t == 1)
		create(t);
	else
	{
		MALLOC(child, sizeof(*child));
		child->data = t;
		child->key = count;
		child->rightChild = NULL;
		child->leftChild = NULL;
		search(root, count, child);
	}
}

void inorder(treePointer ptr)		// 중위 순회
{
	if (ptr)
	{
		inorder(ptr->leftChild);
		if (ptr->data != 0)
			printf("%d ", ptr->data);
		inorder(ptr->rightChild);
	}
}
void preorder(treePointer ptr)		// 전위 순회
{	
	if (ptr)
	{
		if (ptr->data != 0)
			printf("%d ", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
void postorder(treePointer ptr)		//후위 순회
{
	if (ptr)
	{
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		if (ptr->data != 0)
			printf("%d ", ptr->data);
	}
}

void IsFull()
{
	fprintf(stderr, "Node is Full, cannot push element");
	exit(EXIT_FAILURE);
}

void queueFull()
{
	fprintf(stderr, "Queue is Full, cannot push element");
	exit(EXIT_FAILURE);
}

void addq(treePointer ptr)
{
	rear = (rear + 1) % MAX_QUEUE_SIZE;
	if (rear == front)
		queueFull();
	queue[rear] = ptr;
}

treePointer deleteq()
{
	if (front == rear)
		return NULL;
	front = (front + 1) % MAX_QUEUE_SIZE;
	return queue[front];
}

void levelOrder(treePointer ptr)		// 레벨 순회
{
	if (!ptr)
		return;
	addq(ptr);
	for (;;)
	{
		ptr = deleteq();
		if (ptr)
		{
			if(ptr->data != 0)
				printf("%d ", ptr->data);
			if (ptr->leftChild)
				addq(ptr->leftChild);
			if (ptr->rightChild)
				addq(ptr->rightChild);
		}
		else break;
	}
}
int main()
{
	int n, t, i=0;
	scanf_s("%d", &n);

	while(i<n)
	{
		scanf_s("%d", &t);
		create(t);
		count = 1;
		while(t!=-1)
		{
			if (count == MAX_NODE_SIZE) {
				IsFull();
				break;
			}
			scanf_s("%d", &t);
			if (t == -1)
				break;
			count += 1;
			insert(t, count);
		}
		inorder(root);
		printf("\n");
		preorder(root);
		printf("\n");
		postorder(root);
		printf("\n");
		levelOrder(root);
		printf("\n");		
		i++;
	}
	return 0;
}