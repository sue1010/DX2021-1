#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n) (n == MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct{
	int key;
}element;
element heap[MAX_ELEMENTS];
int n = 0;

void push(element item, int* n)
{
	int i;
	if (HEAP_FULL(*n)) {
		fprintf(stderr, "The heap is full. \n");
		exit(EXIT_FAILURE);
	}
	i = ++(*n);
	while ((i != 1) && (item.key > heap[i / 2].key)) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = item;
}

element pop(int* n)
{
	int parent, child;
	element item, temp;
	if (HEAP_EMPTY(*n)) {
		fprintf(stderr, "The heap is empty. \n");
		exit(EXIT_FAILURE);
	}
	item = heap[1];
	temp = heap[(*n)--];
	parent = 1;
	child = 2;
	while (child <= *n) {
		if ((child < *n) && (heap[child].key < heap[child + 1].key))
			child++;
		if (temp.key >= heap[child].key)
			break;
		heap[parent] = heap[child];
		heap[child] = temp;
		child *= 2;
	}
	return item;
}
int main()
{
	int count, num, j = 1;
	element item;
	scanf_s("%d", &count);
	while (count!=0)
	{
		scanf_s("%d", &num);	
		if (num == 0){
			while ( j <= n)
			{
				printf("%d ", heap[j].key);
				j++;
			}
			printf("%d\n", -1);
			j = 1;
		}
		else if (num == -1)
			pop(&n);
		else{
			item.key = num;
			push(item, &n);
		}
		count--;
	}
	return 0;
}