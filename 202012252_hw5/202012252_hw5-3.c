#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
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

typedef struct {
	int count;
	nodePointer link;
}hdnodes;

hdnodes graph[MAX_VERTICES];
int v1, v2 = 0, edge;

void insert(int v1, int v2)
{
	nodePointer p, cur = graph[v1].link, prev=NULL;
	MALLOC(p, sizeof(*p));
	p->vertex = v2;
	
	if (cur){
		while (cur != NULL) {
			prev = cur;
			cur = cur->link;
		}
		p->link = NULL;
		prev->link = p;	
	}
	else{
		p->link = NULL;
		graph[v1].link= p;
	}	
}

void topSort(hdnodes graph[MAX_VERTICES], int n)
{
	int j, k, top;
	nodePointer ptr;
	top = -1;

	for (int i = 0; i < n; i++) {
		if (!graph[i].count) {
			graph[i].count = top;
			top = i;
		}
	}
	for (int i = 0; i < n; i++) {
		if (top == -1) {
			fprintf(stderr, "\nNetwork has a cycle. Sort terminated. \n");
			exit(EXIT_FAILURE);
		}
		else {
			j = top;
			top = graph[top].count;
			printf("%d ", j);
			for (ptr = graph[j].link; ptr; ptr = ptr->link) {
				k = ptr->vertex;
				graph[k].count--;
				if (!graph[k].count) {
					graph[k].count = top;
					top = k;
				}
			}
		}
	}
}
int main()
{
	int max = v2;
	scanf_s("%d", &edge);

	for (int i = 0; i < edge; i++) {
		scanf_s("%d %d", &v1, &v2);
		if (v2 >= max)
			max = v2;
		insert(v1, v2);
		graph[v2].count++;
		
	}

	topSort(&graph[0], max+1);
	return 0;
}