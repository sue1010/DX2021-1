#include<stdio.h>
#define MAX_TERMS 101

typedef struct {
	int col;		//����(��)
	int row;		//����(��)
	int value;		//��
}term;

term a[MAX_TERMS];	//��� ����
int num[1000][1000];	//�ʱⰪ ����
int countarr[MAX_TERMS];	//����� �� ��ȣ ����
int col_num, row_num, k;	//�Է¹��� ��� ��, ����� �迭 ���� �������� ����

void matrix(k)
{
	for (int i = 0; i < k; i++)
		scanf_s("%d", &countarr[i]);
	for (int i = 0; i < k; i++)
		printf("%d %d %d\n", a[countarr[i]].row,a[countarr[i]].col,a[countarr[i]].value);
}

int main(void)
{
	int count = 0;
	scanf_s("%d %d %d\n", &col_num, &row_num, &k);
	
	for (int j = 0; j < row_num; j++)
		for (int i = 0; i < col_num; i++)
		{
			scanf_s("%d", &num[j][i]);

			if (num[j][i] != 0)
			{
				a[count + 1].row = j;	
				a[count + 1].col = i;
				a[count + 1].value = num[j][i];
				count++;
			}
		}
	a[0].col = col_num;
	a[0].row = row_num;
	a[0].value = count;

	matrix(k);

	return 0;
	
}