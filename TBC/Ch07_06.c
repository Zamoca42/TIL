#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

int main()
{
	unsigned num, i;
	bool isPrime = 0; // flag, try bool type

	scanf("%u", &num);

	/*
		TODO : Check if num is a prime number
		ex) num is 4, try num % 2, num % 3
		ex) num is 5, try num % 2, num % 3, num % 4
	*/

	// my code
	
	/*
	isPrime = 1;

	for (i = 1; num > i; ++i)
	{
		if (num % i == 0)
		{
			isPrime = 0;
		}
	}
	*/

	// true
	
	isPrime = true;

	for (i = 2; num > i; ++i)
	{
		if (num % i == 0)
		{
			isPrime = false;
		}
	}

	if (isPrime)
		printf("%u is a prime number.\n", num);
	else
		printf("%u is not a prime number.\n", num);


	return 0;
}