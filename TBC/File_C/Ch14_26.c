#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);//TODO : add a new menu


int main()
{
	char options[] = { 'u', 'l' }; //TODO : add a new menu
	int n = sizeof(options) / sizeof(char);

	typedef void (*FUNC_TYPE)(char*);
	FUNC_TYPE operations[] = { ToUpper, ToLower }; //TODO : add a new menu

	printf("Enter a string\n>> ");

	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");

	while (1)
	{
		printf("Choose an option:\n");
		printf("u) to upper\n");
		printf("l) to lower\n");

		char choice;
		while (scanf("%c%*%[^\n]%*c", &choice) != 1)
			printf("Please try again.\n>> ");

		bool found = false;

		for (int i = 0; i < n; ++i)
			if (options[i] == choice)
			{
				(*(operations[i]))(input);
				found = true;
				break;
			}

		if (found)
			break;
		else
			printf("Wrong input, try again\n");

	}
	printf("%s\n", input);

	return 0;
}

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void update_string(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}

void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
		
		
}