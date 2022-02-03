#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	// pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()
#include <stdbool.h>

unsigned char to_decimal(const char bi[]);
void print_binary(const unsigned char num);

int main()
{
	unsigned char i = to_decimal("01000110");
	unsigned char mask = to_decimal("00000101");

	print_binary(i);
	print_binary(mask);
	print_binary(i & mask);


	return 0;
}

unsigned char to_decimal(const char bi[])
{
	const size_t bit = strlen(bi);
	unsigned char sum = 0;
	for (size_t i = 0; i < bit; ++i)
	{
		if (bi[i] == '1')
			sum += (int)pow(2, bit - 1 - i);
	}

	return sum;
	//printf("Binary %s == Decimal %d\n", bi, sum);
}


/* my code
void print_binary(const unsigned char num)
{
	printf("Decimal  %d", num);
	printf("\t == Binary ");

	const size_t bit = sizeof(num) * 8;

	for (int i = 0; i < bit; ++i)
	{
		size_t mask = pow(2, bit - 1 - i);
		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}
*/


void print_binary(const unsigned char num)
{
	printf("Decimal %3d \t== Binary ", num);

	const size_t bits = sizeof(num) * 8;
	for (size_t i = 0; i < bits; ++i)
	{
		const unsigned char mask = (unsigned char)pow((double)2, (double)(bits - 1 - i));

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}
