#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* while (expression) // true or false
		statement
	*/

	int i;

	//i = 1;
	//while (i < 5)		// infinite loop
	//	printf("Hi!\n");// iteration

	/*i = 1;
	while (i < 5)
	{
		printf("i before = %d\n", i);
		i++;
		printf("i after = %d\n", i);
	}*/

	//i = 10;
	//while (i++ < 5)		// cannot enter
	//	printf("Hi\n");

	/* common mistake */

	//i = 0;
	//while (i < 3)
	//	printf("%i\n", i);
	//	i++; // indenting

	//i = 0;
	//while (i++ < 3);		// null statement
	//printf("%i\n", i);

	//while (scanf("%d, &i") == 1)
	//	; // null statement
	//// do something (?)

	return 0;
}