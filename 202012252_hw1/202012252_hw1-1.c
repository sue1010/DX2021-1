#include<stdio.h>
#include <stdlib.h> 
#define MAX_TERMS 100

typedef struct {
	float coef; //계수
	int expon; //지수
} polynomial;
polynomial terms[MAX_TERMS];
int avail, availC, a, b;
int startA, startB, finishA, finishB;

int COMPARE(int x, int y)
{
	if (x < y)
		return -1;
	else if (x > y)
		return 1;
	else if(x = y)
		return 0;
}

void attach(float coefficient, int exponent)
{
	if (avail >= MAX_TERMS) {
		fprintf(stderr, "다항식에 항이 너무 많다.");
		exit(1);
	}
	terms[avail].coef = coefficient;
	terms[avail++].expon = exponent;
}

void padd(int startA, int finishA, int startB, int finishB, int* startC, int* finishC)
{
	float coefficient;
	startC = &availC;

	while (startA <= finishA && startB <= finishB)
		switch (COMPARE(terms[startA].expon, terms[startB].expon))
		{
		case -1: // a의 지수가 b의 지수보다 작은 경우
			attach(terms[startB].coef, terms[startB].expon);
			startB++;
			break;
		case 0: // 지수가 같은 경우
			coefficient = terms[startA].coef + terms[startB].coef;
			if (coefficient)
				attach(coefficient, terms[startA].expon);
			startA++;
			startB++;
			break;
		case 1: //a의 지수가 b의 지수보다 큰 경우
			attach(terms[startA].coef, terms[startA].expon);
			startA++;
			break;
		}

	for (; startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	for (; startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);

	finishC = &avail;
	*finishC -= 1;

	printf("%d %d\n", *startC, *finishC);

	for (int i = *startC; i <= *finishC; i++)
		printf("%.f %d ", terms[i].coef, terms[i].expon);

}

int main(void)
{
	scanf_s("%d %d", &a, &b);
	startA = 0;
	finishA = a - 1;
	startB = a;
	finishB = a + b - 1;
	availC = a + b;
	avail = a + b;

	for (int i = 0; i < a; i++) 
	{
		scanf_s("%f %d", &terms[i].coef, &terms[i].expon);
	}
	for (int i = a; i < avail; i++)
	{
		scanf_s("%f %d", &terms[i].coef, &terms[i].expon);
	}
	
	padd(startA, finishA, startB, finishB, &availC, &avail);

	return 0;
}

