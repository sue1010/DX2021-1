#include<stdio.h>
#include<string.h>

#define MAX_STACK 100
#define STACK_SIZE 100

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand } precedence;
typedef int element;

int isp[] = { 0,19,12,12,13,13,13,0 };
int icp[] = { 20,19,12,12,13,13,13,0 };
int n;
int top = -1;
char stack[MAX_STACK];
char expr[MAX_STACK];

int pop() {
	if (top == -1) {
		return top;
	}
	return stack[top--];
}

char push(char token)
{
	if (MAX_STACK - 1 == top)
	{
		return 0;
	}
	stack[++top] = token;
}


precedence getToken(char* symbol, int* n)
{
	*symbol = expr[(*n)++];
	switch (*symbol) {
	case'(':return lparen;
	case')': return rparen;
	case'+': return plus;
	case'-': return minus;
	case'/': return divide;
	case'*': return times;
	case'%': return mod;
	case' ': return eos;
	default: return operand;
	}
}


void postfix(char *expr)		//중위표기 후위 표기로  변환
{
	int i = 0;
	char symbol;
	precedence token;
	int n = 0;
	int top = 0;
	stack[0] = eos;

	for (token == getToken(&symbol, &n); token != eos; token == getToken(&symbol, &n)) {
		token = expr[i];
		if (token == operand)
			printf("%c", symbol);
		else if (token == rparen)
		{
			while (stack[top] != lparen)
				printToken(pop());
			pop();
		}
		else {
			while (isp[stack[top]] >= icp[token])
				printToken(pop());
			push(token);
		}
		i++;
	}
	while ((token = pop()) != eos)
		printf("%s",Token(token));
	printf("\n");
}

int eval(void)
{
	precedence token;
	char symbol;
	int op1, op2;
	int n = 0;
	int top = -1;
	token = getToken(&symbol, &n);
	while (token != eos) {
		if (token == operand)
			push(symbol = '0');
		else {
			op2 = pop();
			op1 = pop();
			switch (token) {
			case plus: push(op1 + op2);
				break;
			case minus: push(op1 - op2);
				break;
			case times: push(op1 * op2);
				break;
			case divide: push(op1 / op2);
				break;
			case mod: push(op1 % op2);
			}
		}
		token = getToken(&symbol, &n);
	}
	return pop();
}

int main(void) {
	int len;
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf_s("%s", &expr);
		len = strlen(expr);
		postfix(expr);
		eval();
	}
	return 0;
}