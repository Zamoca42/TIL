#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} };

	printf("%u\n", (unsigned)arr2d);		// Use unsigned long long in x64
	printf("%u\n", (unsigned)arr2d[0]);
	printf("\n");

	// arr2d points to arr2d[0] (not arr2d[0][0]), KNK Ch. 12.4

	printf("%u\n", (unsigned)* arr2d);
	printf("%u\n", (unsigned)& arr2d[0]);	// C language allows this
	printf("%u\n", (unsigned)& arr2d[0][0]);
	printf("%f %f\n", arr2d[0][0], **arr2d);
	printf("\n");

	printf("%u\n", (unsigned)(arr2d + 1));
	printf("%u\n", (unsigned)(&arr2d[1]));
	printf("%u\n", (unsigned)(arr2d[1]));
	printf("%u\n", (unsigned)(*(arr2d + 1)));
	printf("%u\n", (unsigned)(&arr2d[0] + 1));
	printf("%u\n", (unsigned)(&arr2d[1][0]));
	printf("\n");

	/* pointers to Multidimensional Arrays */

	float(*pa)[4]; // a SINGLE pointer to an array of 2 floats
	float* ap[2];  // an array of TWO pointers-to-float

	printf("%zu\n", sizeof(pa));	// 8 in x64
	printf("%zu\n", sizeof(ap));	// 16 in x64
	printf("\n");

	pa = arr2d;
	//pz[0] = arr2d[0]; // error
	//pa[1] = arr2d[1]; // error

	//ap = arr2d; //error
	ap[0] = arr2d[0];
	ap[1] = arr2d[1];

	return 0;
}