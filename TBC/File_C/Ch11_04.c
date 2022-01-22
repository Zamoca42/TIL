#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define STRLEN 81

int main()
{
	/* Creating Space */

	//char* name = ""; // Error at RUN-TIME
	/*
	char name[128];
	int result = scanf("%s, name");
	*/


	/*
		scanf() vs gets()
		scanf() reads one word
		gets() reads one line and removes \n and add \0
	
	*/

	char words[STRLEN] = "";			// Warning without initialization
	gets(words);						// gets receives pointer. No idea when stringe ends.
	//gets_s(words, sizeof(words));		// C11
	//int result = scanf("%s", words);
	printf("START\n");
	printf("%s", words);				// no \n at the end
	puts(words);						// puts() adds \n at the end
	puts("END.");

	//TODO: try char words[5];
	//Runtime error words > 5

	/* fgets() and fputs() */

	char words[STRLEN] = "";
	fgets(words, STRLEN, stdin);		// does NOT remove \n

	// TODO: replace '\n' with '\0'
	int i = 0;
	while (words[i] != '\n' && words[i] != '\0')
		i++;
	if (words[i] == '\n')
		words[i] = '\0';

	fputs(words, stdout);				// does NOT remove \n
	fputs("END", stdout);

	/* Small array */

	char small_array[5];
	puts("Enter long strings:");
	fgets(small_array, 5, stdin);		// FILE *_Stream
	//printf("%p\n", small_buffer);
	//printf("%p\n", fgets(small_buffer, 5, stdin));	// Return value of fgets
	fputs(small_array, stdout);

	/* Repeating short reading */

	char small_array[5];
	puts("Enter long strings:");
	while (fgets(small_array, 5, stdin) != NULL && small_array[0] != '\n')
		fputs(small_array, stdout);
		//puts(small_array);		// what if we us puts()

	/* scanf() */

	char str1[6], str2[6];
	int count = scanf("%5s %5s", str1, str2);
	//int count = scanf("%6s %6s", str1, str2); // run-time error
	//int count = scanf_s("%5s %5s", str1, 6, str2, 6);
	printf("%s|%s \n", str1, str2);

	return 0;
}