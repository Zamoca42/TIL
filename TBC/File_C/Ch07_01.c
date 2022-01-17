#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int number;

	printf("Input a positive integer : ");
	scanf("%d", &number);

	
	//my code
	
	/*
	if (number % 2 == 0)
		printf("Even");
	printf("Odd");
	*/

	//recommand code

	/*
	if (number % 2 == 0)
		printf("Even");
	
	if (number % 2 != 0)
		printf("Odd");
	*/

	// if else +

	if (number % 2 == 0)
		printf("Even");
	else
		printf("Odd");

	//TODO : print even or odd

	return 0;
}