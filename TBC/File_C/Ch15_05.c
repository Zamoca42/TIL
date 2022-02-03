#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>	// pow()
#include <string.h> // strlen()
#include <stdlib.h> // exit()
#include <stdbool.h>

void print_binary(const char num)
{
	printf("Decimal  %3d \t== Binary", num);
	
	const size_t bit = sizeof(num) * 8;

	for (size_t i = 0; i < bit; ++i)
	{
		const char mask = (char)pow((double)2, (double)(bit - 1 - i));

		if ((num & mask) == mask)
			printf("%d", 1);
		else
			printf("%d", 0);
	}
	printf("\n");
}

int main()
{
	print_binary(127);
	print_binary(-127);
	print_binary(~127 + 1);

	print_binary(12);
	print_binary(-12);
	print_binary(~12 + 1);

	print_binary(7);
	print_binary(-7);
	print_binary(~-7+1);
	
	return 0;
}