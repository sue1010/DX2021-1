#include<stdio.h>
#include<stdlib.h>

typedef struct listNode* listPointer;
typedef struct {
	int data;
	listPointer link;
}listNode;

listNode* first = NULL;

void printList()
{
	for (; first; first = first->link)
		printf("%d ", first->data);
}

void delete(int del)
{
	listNode* x = first;

	if (first == NULL)
		return;

	if (x->data == del)
	{
		first = x->link;
		free(x);
		x = NULL;
		return;
	}

	while (x->link != NULL)
	{
		listNode* trail = x->link;
		if (trail->data == del)
		{
			if (trail->link != NULL)
				x->link = trail->link;
			else
				x->link = NULL;

			free(trail);
			trail = NULL;
		}
		x = x->link;
	}
}

int main()
{
	int input, del;

	listNode* new = NULL;
	listNode* last = NULL;

	while (1)
	{
		scanf_s("%d", &input);
		if (input == -1)
			break;

		new = (listNode*)malloc(sizeof(listNode));
		new->data = input;
		new->link = NULL;

		if (last == NULL)
			first = new;
		else
			last->link = new;
		last = new;
	}

	while (1)
	{
		scanf_s("%d", &del);
		if (del == -1)
			break;
		else
			delete(del);
	}
	printList();
	return 0;
}