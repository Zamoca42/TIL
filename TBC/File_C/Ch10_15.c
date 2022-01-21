#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n = 5;
	double x;
	x = n;		// no error
	int* p1 = &n;
	double* pd = &x;
	pd = p1;	// Warning

	int* pt;
	int(*pa)[3];
	int ar1[2][3] = { 3, };
	int ar2[3][2] = { 7, };
	int** p2;	// a pointer to a pointer

	pt = &ar1[0][0];	// pointer-to-int

	for (int i = 0; i < 6; ++i)
		printf("%d ", *(pt + i));

	pt = ar1[0];		// pointer-to-int
	//pt = ar1;			// Warning (Error)
	pa = ar1;			// pointer-to-int[3]

	p2 = &pt;			// pointer-to-int *
	*p2 = ar2[0];		// pointer-to-int
	//p2 = ar2;			// Warning (Error)
	//Notes
	// - p2: pointer to pointer to int
	// - ar2: a pointer to array-of-2-ints

	/* Pointer and comst */

	int x = 20;
	const int y = 23;
	int* p1 = &x;
	const int* p2 = &y;
	const int** pp2 = &p1;
	p1 = p2;		// Warning (Error)

	*p2 = 123;		// Error
	p2 = p1;

	int x2 = 30;
	int* p3 = &x2;
	*pp2 = p3;
	pp2 = &p1;



	return 0;
}