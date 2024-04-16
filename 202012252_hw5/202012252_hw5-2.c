#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 100
#define MALLOC(p, s) \
    if (!((p) = malloc(s))) { \
        fprintf(stderr, "Insufficient memory"); \
        exit(EXIT_FAILURE);\
    }

typedef struct node* nodePointer;
typedef struct node {
	int vertex;
	nodePointer link;
}node;

nodePointer adjLists[SIZE];
int num, rear, front, visited[SIZE], queue[SIZE];

void dfs(int v)
{
	nodePointer w;
	visited[v] = 1;
	printf("%d ", v);
	for (w = adjLists[v]; w; w = w->link) {
		if (!visited[w->vertex])
			dfs(w->vertex);
	}
}

void add(int v, int i)
{
	nodePointer k,prev,cur;
	MALLOC(k, sizeof(*k));
	
	k->vertex = v;
	cur = adjLists[i], prev = NULL;
	if (cur) {
		while (cur != NULL) {
			prev = cur;
			cur = cur->link;
		}
		k->link = NULL;
		prev->link = k;
	}
	else {
		k->link = NULL;
		adjLists[i] = k;
	}
}

bool isEmpty()
{
	for(int i =0; i<num; i++)
		if(visited[i] == 0)
			return 0;
	return 1;
}

int pop()
{
	return queue[++front];
}

void push(int v)
{
	rear += 1;
	queue[rear] = v;
}

void bfs(int v)
{
	nodePointer w;
	front = rear = 0;
	printf("%d ", v);
	visited[v] = 1;
	push(v);
	while (!isEmpty()) {
		v = pop();
		for (w = adjLists[v]->link; w; w = w->link) {
			if (visited[w->vertex] == 0) {
				printf("%d ", w->vertex);
				push(w->vertex);
				visited[w->vertex] = 1;
			}
		}
	}
}

int main()
{
	int input;
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++)
	{
		visited[i] = 0;
		while (1)
		{
			scanf_s("%d", &input);
			if (input == -1)
				break;
			add(input, i);
		}		
	}
	dfs(0);

	for (int i = 0; i < num; i++)
		visited[i] = 0;
	printf("\n");

	bfs(0);
	return 0;
}