#include<stdio.h>
#define MAX_TERMS 101

typedef struct {
	int row;
	int col;
	int value;
}term;
term a[MAX_TERMS];
term b[MAX_TERMS];

int main(void)
{
	int count=1;
	scanf_s("%d %d %d", &a[0].row, &a[0].col, &a[0].value);
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;
	
	for (int i = 1; i <= a[0].value; i++)
	{
		scanf_s("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
	}
	for (int i = 1; i <= a[0].value; i++)		
		for (int j = 1; j <= a[0].value; j++)
		{
			if (a[j].col == i - 1)
			{
				b[count].row = a[j].col;
				b[count].col = a[j].row;
				b[count].value = a[j].value;
				count++;
			}
		}	

	for(int i = 0; i<= b[0].value; i++)
		printf("%d %d %d\n", b[i].row, b[i].col, b[i].value);
	
	return 0;
}