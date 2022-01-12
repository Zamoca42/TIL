#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	const int password = 337;
	int i = 0;

	/*
	
	printf("Enter the password : ");
	scanf("%d", &i);

	
	while (i != password)
	{
		printf("Enter the password : ");
		scanf("%d", &i);
	}

	*/

	do
	{
		printf("Enter secret code : ");
		scanf("%d", &i);
	} 
	while (i != password);

	printf("Good!\n");

	return 0;
}