#include<stdio.h>

#define MAX_ROW 100
#define MAX_COL 100
#define MAX_STACK 100
#define False 0
#define True 1

typedef struct {
	short int vert;
	short int horiz;
}offsets;		

typedef struct {
	short int row;
	short int col;
	short int dir;
}element;		

int maze[MAX_ROW][MAX_COL];		// ¹Ì·Î
int mark[MAX_ROW][MAX_COL];		// Áö³ª°£ ±æ
int n, m, EXIT_ROW, EXIT_COL;		// n = row, m = col, EXIT_ROW = µµÂø, EXIT_COL = µµÂø

element stack[MAX_STACK];	
element position;

offsets move[8] = { {-1,0}, {-1,1},{0,1}, {1,1},{1,0},{1,-1},{0,-1},{-1,-1} };

element push(int *top )
{
	(*top)++;
	stack[*top].row = position.row;
	stack[*top].col = position.col;
	stack[*top].dir = position.dir;
}

element pop(int* top)
{
	element result;
	if (*top >= 0) {
		result = stack[*top];
		(*top)--;
	}
	return result;
}

void path(void)
{
	int i, row, col, nextRow, dir, nextCol, top, found = False;

	mark[1][1] = 1;
	top = 0;

	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 1;

	while (top > -1 && !found){

		position = pop(&top);

		row = position.row;
		col = position.col;
		dir = position.dir;

		while (dir < 8 && !found) {
			nextRow = row + move[dir].vert;
			nextCol = col + move[dir].horiz;

			if (nextRow == EXIT_ROW && nextCol == EXIT_COL)
				found = True;

			else if (!maze[nextRow][nextCol] && !mark[nextRow][nextCol]) {
				mark[nextRow][nextCol] = 1;

				position.row = row;
				position.col = col;
				position.dir = ++dir;

				push(&top);

				row = nextRow;
				col = nextCol;
				dir = 0;
			}

			else dir++;
		}
	}

	if (found) {
		printf("%d %d\n", EXIT_ROW, EXIT_COL);
		printf("%d %d\n", row, col);
		for (i = top; i >= 0; i--)
			printf("%d %d\n", stack[i].row, stack[i].col);	
	}
	else printf("No path in maze\n");
}

int main(void)
{
	scanf_s("%d %d", &n, &m);

	EXIT_COL = n;
	EXIT_ROW = m;

	maze[n+2][m+2];
	mark[n+2][m+2];

	for(int i = 0; i < n+2; i++)
		for (int j = 0; j < m + 2; j++)
		{
			if (i == 0 || j == 0 || i == n+1 || j == m+1)
				maze[i][j] = 1;
			else
				scanf_s("%d", &maze[i][j]);
		}

	path();

	return 0;
}