#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>


int main()
{
	/*
	int temp;
	temp = true ? 1024 : 7; // ternary
	printf("%d\n", temp);

	temp = false ? 1024 : 7; // 7
	printf("%d\n", temp);
	*/

	int number;
	scanf("%d", &number);
	
	//if (number % 2 == 0)
	//	is_even = true;
	//else
	//	is_even = false;
	
	/*
	bool is_even;

	is_even = (number % 2 == 0) ? 1 : 0;
	*/

	//bool is_even = (number % 2 == 0) ? 1 : 0;

	/*
	if (is_even)
		printf("Even");
	else
		printf("Odd");
	*/

	(number % 2 == 0) ? printf("Even") : printf("Odd");

	return 0;
}