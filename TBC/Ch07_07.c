#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>		// islower()
#include <stdbool.h>
#include <iso646.h>		// and, or, not

#define PERIOD '.'

int main()
{
	/*
		Logical operators

		&& : and
		|| : or
		!  : not
	*/

	//bool test1 = 3 > 2 || 5 > 6;	// true
	//bool test2 = 3 > 2 && 5 > 6;	// false
	//bool test3 = !(5 > 6);		// true, equivalnet to 5 <= 6

	/* iso646.h */

	//bool test1 = 3 > 2 or 5 > 6;	// true
	//bool test2 = 3 > 2 and 5 > 6;	// false
	//bool test3 = not(5 > 6);		// true, equivalnet to 5 <= 6

	//printf("%d %d %d\n", test1, test2, test3);

	/* Character counting example */

	/*
	char ch;
	int count = 0;
	while ((ch = getchar()) != PERIOD)
	{
		//TODO : make exeptions
		if (ch != '\n' && ch != ' ')
			count++;

	}

	printf("%d", count);
	*/

	// && and || are sequence poins

	/*
	int x = 1, y = 2;
	if (x++ > 0 && x + y == 4)
		printf("%d %d\n", x, y);
	*/

	// ranges

	for (char c = 0; c < 127; ++c)
		if (islower(c))
			printf("%c ", c);

	return 0;
}