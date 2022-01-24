#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f1(int hello, double world); // to the end of the prototype declaration
// void vla_param(int n, int m, double ar[n][m]; // gcc only

double func_block(double d)
{
	double p = 0.0;

	int i;
	for (i = 0; i < 10; i++)
	//for (i = 0; i < 10; I++)	// C99
	{
		double q = d * i;
		p *= q;
		if (i == 5)
			goto hello;

	}

hello:
	printf("Hello, World");

	return p;
}


int main()
{

	return 0;
}