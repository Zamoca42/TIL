#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

#define WIDTH 30
#define NAME "YEON KYU CHU"
#define ADDRESS "Yong-In, Korea"

void print_multiple_chars(char c, int n_stars, bool end1); // prototype
void print_centered_str(char str[]);

int main()
{
	print_multiple_chars('*', WIDTH, true); // argument

	print_centered_str(NAME);
	print_centered_str(ADDRESS);

	print_multiple_chars('*', WIDTH, false);

	return 0;
}

void print_multiple_chars(char c, int n_stars, bool end1)
{
	for (int i = 0; i < n_stars; ++i)
		printf("%c", c); // puthcar(c)

	if (end1 == true)
		printf("\n");
}

void print_centered_str(char str[])
{
	int n_blanks = 0;

	n_blanks = (WIDTH - strlen(str)) / 2;
	print_multiple_chars(' ', n_blanks, false);
	printf("%s\n", str);
}