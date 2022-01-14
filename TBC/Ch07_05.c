#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int number;
	scanf("%d", &number);

	/*
	if (number > 5)
		if (number < 10)
			printf("Lager than 5 smaller than 10\n");
	else
		printf("Less than or equal to 5");
	*/

	if (number > 5)
	{
		if (number < 10)
			printf("Lager than 5 smaller than 10\n");
		else
			printf("Lager than 10\n");
	}
	else
		printf("Less than or equal to 5");

	//indenting이 헷갈릴 땐 block설정으로 명확히
	//compilers ignore indenting

	return 0;
}