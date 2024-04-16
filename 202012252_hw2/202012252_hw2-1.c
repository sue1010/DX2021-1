#include<stdio.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
	int key;
}element;

element queue[MAX_QUEUE_SIZE];

int rear = 0;
int front = 0;
int n;	//원형 큐 배열 크기

void queueFull(int item)
{
	printf("Queue is Full, cannot push element %d\n", item);
}

void queueEmpty()
{
	printf("Queue is Empty, cannot pop element\n");
}

void push(int item)		//배열 추가
{
	int o_rear = rear;
	rear = (rear + 1) % n;
	if (front == rear)
	{
		queueFull(item);
		rear = o_rear;
	}
	else
		queue[rear].key = item;
}

element pop()		//큐 지우고 프론트 앞으로
{
	if (front == rear)
		queueEmpty();
	else
		front = (front + 1) % n;
}

void check_item(int item)
{
	if (item == -1)
	{
		pop();
	}
	else if (item == 0)
	{
		for (int j = front + 1; j < rear + 1; j++)
			printf("%d ", queue[j].key);
		printf("\n");
	}
	else
		push(item);
}

int main(void)
{
	int m;	// 숫자 입력 횟수(m)
	int item;
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i< m ; i++)
	{
		scanf_s("%d", &item);
		check_item(item);
	}
	return 0;
}

