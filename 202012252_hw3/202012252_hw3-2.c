#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) ((x) < (y) ? -1: ((x) == (y)) ? 0 : 1)

typedef struct polyNode* polyPointer;
typedef struct {
	int coef;
	int expon;
	polyPointer link;
}polyNode;

void attach(float coefficient, int exponent, polyNode** ptr)
{
	polyNode* p = *ptr;
	polyNode* temp;
	temp = (polyPointer)malloc(sizeof(temp));
	temp->coef = coefficient;
	temp->expon = exponent;
	temp->link = NULL;
	if (*ptr == NULL)
	{
		*ptr = temp;
		return;
	}
	while (p->link)
		p = p->link;
	p->link = temp;
}

polyPointer* padd(polyNode* a, polyNode* b)
{
	polyNode* c = NULL;
	
	int sum;

	while (a && b)
		switch (COMPARE(a->expon, b->expon))
		{
		case -1:
			attach(b->coef, b->expon, &c);
			b = b->link;
			break;
		case 0:
			sum = a->coef + b->coef;
			if (sum)
				attach(sum, a->expon, &c);
			a = a->link;
			b = b->link;
			break;
		case 1:
			attach(a->coef, a->expon, &c);
			a = a->link;
		}

	for (; a; a = a->link)
		attach(a->coef, a->expon, &c);
	for (; b; b->link)
		attach(b->coef, b->expon, &c);

	return c;
}

void printpoly(polyNode* c)
{
	polyNode* Node = c;
	while (Node)
	{
		printf("%d %d ", Node->coef, Node->expon);
		Node = Node->link;
	}
}

int main(void)
{
	int n, m;
	int co = 0;
	int ex = 0;

	polyNode* a = NULL;
	polyNode* b = NULL;
	polyNode* c = NULL;

	scanf_s("%d %d", &n,&m);

	while(n !=0)
	{
		scanf_s("%d %d", &co,&ex);
		attach(co, ex, &a);
		n--;
	}

	while(m!=0)
	{
		scanf_s("%d %d", &co,&ex);
		attach(co, ex, &b);
		m--;
	}
	c = padd(a, b);
	printpoly(c);

	return 0;
}