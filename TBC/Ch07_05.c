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

	//indenting�� �򰥸� �� block�������� ��Ȯ��
	//compilers ignore indenting

	return 0;
}