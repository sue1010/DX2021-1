#include<stdio.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
	int key;
}element;

element queue[MAX_QUEUE_SIZE];

int rear = 0;
int front = 0;
int n;	//���� ť �迭 ũ��

void queueFull(int item)
{
	printf("Queue is Full, cannot push element %d\n", item);
}

void queueEmpty()
{
	printf("Queue is Empty, cannot pop element\n");
}

void push(int item)		//�迭 �߰�
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

element pop()		//ť ����� ����Ʈ ������
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
	int m;	// ���� �Է� Ƚ��(m)
	int item;
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i< m ; i++)
	{
		scanf_s("%d", &item);
		check_item(item);
	}
	return 0;
}

