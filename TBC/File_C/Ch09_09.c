#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
	10
	10 / 2 = 5, remainder = 0
	5 / 2 = 2, remainder = 1
	2 / 2 = 1, remainder = 0
	1 / 2 = 0, remainder = 1
*/

void print_binary(unsigned long n);
void print_binary_loop(unsigned long n);

int main()
{
	unsigned long num = 10;

	print_binary_loop(num);
	print_binary(num);

	printf("\n");

	return 0;
}

void print_binary_loop(unsigned long n)
{
	//my code
	/*
	long ans;

	for (ans = 1; n >= 1; n = n/2)
	{
		if (n != 1)
		{
			ans = n % 2;
			printf("%d ", ans);
		}
		else
			printf("%d", n);
	}
	*/
	//recommand code
	while (1)
	{
		int quotient = n / 2;
		int remainder = n % 2;

		printf("%d", remainder); // remainder is 0 or 1

		n = quotient;

		if (n == 0) break;
	}

	printf("\n");

}

void print_binary(unsigned long n)
{
	int remainder = n % 2;

	if (n >= 2)
		print_binary(n / 2);

	printf("%d", remainder);

	return;
}