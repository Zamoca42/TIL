#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int temp(int a)
{
	return 0;
}

int (*g(inta))(int)
{
	return temp;
}

int main()
{
	/*
		*	indicates a pointer
		()	indicates a function
		[]	indicates an array
	*/

	int* ap[10];	// Identifier ap is an array of pointers

	typedef int* pint;
	pint ap2[10];

	float* fp(float);	// fp is a function that returns a pointer

	typedef float* pfloat;
	pfloat fp2(float);

	void (*pf)(int);
	/*
			void (*pf)(int);
				   1			1. pointer to
						2		2. function with int argument
			 3					3. returning void
	*/

	int* (*x[10])(void);



	return 0;
}