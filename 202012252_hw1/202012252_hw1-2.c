#include<stdio.h>
#define MAX_TERMS 101

typedef struct {
	int col;		//가로(열)
	int row;		//세로(행)
	int value;		//값
}term;

term a[MAX_TERMS];	//결과 저장
int num[1000][1000];	//초기값 저장
int countarr[MAX_TERMS];	//출력할 행 번호 저장
int col_num, row_num, k;	//입력받을 행과 열, 출력할 배열 개수 전역변수 선언

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