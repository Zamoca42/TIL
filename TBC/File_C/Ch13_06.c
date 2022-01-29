#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

/*
	ABCDEF ...
	Current position 0 and read -> A
	Current position 1 and read -> B
	...
*/

int main()
{
	int ch;
	long cur;

	FILE* fp = fopen("test.txt", "r");

	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);	//Runtime error

	fseek(fp, 2L, SEEK_SET);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);

	fseek(fp, -2L, SEEK_CUR);
	cur = ftell(fp);
	printf("ftell() = %ld\n", cur);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	/* SEEK_END */

	fseek(fp, 0L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	fseek(fp, -1L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	fseek(fp, -2L, SEEK_END);
	ch = fgetc(fp);
	printf("%d %c\n", ch, ch);

	return 0;
}