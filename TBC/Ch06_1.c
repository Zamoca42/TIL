#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num, sum = 0;
	int status;

	printf("Enter an integer (q to quit) : ");

	status = scanf("%d", &num); // return value of scanf()

	while (status == 1)			// equality operater
	{
		sum = sum + num;

		printf("Enter next integer (q to quit) : ");
		status = scanf("%d", &num);
	}

	printf("Sum = %d\n", sum);

	//TODO: C-style shortcut

	return 0;
}