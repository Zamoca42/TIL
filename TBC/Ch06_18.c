#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// prototype
int compute_pow(int base, int exp);

int main()
{
	// my code
	
	/*
	int i, sqr, j, result;

	scanf("%d %d", &i, &sqr);

	for (j = 0; j < sqr; j++)
		result *= i;

	printf("Result is : %d\n", result);
	*/
	
	// recommand code

	int base, exp, result;
	
	while (scanf("%d %d", &base, &exp) == 2)
	{
		/*
		result = 1;
		for (i = 0; i < exp; ++i)
			result *= base;
		*/
		result = compute_pow(base, exp);

		printf("Result = %d\n", result);
	}

	return 0;
}

// function (scope)
int compute_pow(int base, int exp)
{
	int i, result;

	result = 1;
	for (i = 0; i < exp; ++i)
		result *= base;

	return result;
}
