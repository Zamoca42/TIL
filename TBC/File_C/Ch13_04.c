#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 31

int main(void)
{
	FILE* fp;
	char words[MAX] = { '\0', };

	const char* filename = "record.txt";

	if ((fp = fopen(filename, "w+")) == NULL) // Try r+, w+, a+
	{
		fprintf(stderr, "Can't open \"%s\" file.\n", filename);
		exit(EXIT_FAILURE);
	}

	while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.'))
		fprintf(fp, "%s\n", words);

	rewind(fp); /* go back to beginning of file */

	while (fscanf(fp, "%s", words) == 1)
		fprintf(stdout, "%s\n", words);

	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");

	return 0;
}