#include<stdio.h>
#define SIZE 100

int adjmatric[SIZE][SIZE], adjmatricB[SIZE][SIZE], num;
int stack[SIZE], queue[SIZE], count = 0, front = -1, rear = 0;

void dfs(int matric)
{
	for (int i = 0; i < num; i++) {
		if (adjmatric[matric][i] == 1) {

			adjmatric[matric][i] = 0;
			for (int k = 0; k < count; k++)
				if (stack[k] == i)
					return;
			
			adjmatric[i][matric] = 0;
			stack[count++] = i;
			dfs(i);
		}
	}
}
void queueFull(int key)
{
	printf("Queue is Full, cannot push element %d\n", key);
}

void bfs(int matric)
{
	for(int i = 0; i<num; i++)
		if (adjmatricB[matric][i] == 1) {
			if (rear == SIZE)
				queueFull(i);
			else
				queue[rear++] = i;

			for (int k = 0; k < num; k++)
				adjmatricB[k][i] = 0;
			adjmatricB[i][matric] = 0;

			stack[count++] = i;
		}
	if (front != num)
		bfs(queue[++front]);
}

int main()
{
	scanf_s("%d", &num);

	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++) {
			scanf_s("%d", &adjmatric[i][j]);
			adjmatricB[i][j] = adjmatric[i][j];
		}
	
	stack[count++] = 0;
	dfs(0);

	//dfs출력
	for (int i = 0; i < num; i++) {
		printf("%d ", stack[i]);
		stack[i] = NULL;
	}

	printf("\n");

	count = 0;
	stack[count++] = 0;
	bfs(0);

	//bfs출력
	for (int i = 0; i < num; i++)
		printf("%d ", stack[i]);

	return 0;
}