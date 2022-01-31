#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> // strlen(),strcmp()
#include <stdlib.h> // malloc(),free()
#define SLEN 81

struct namect {
	char* fname;	// Use malloc()
	char* lname;	// Use malloc()
	int letters;
};

void getinfo(struct namect*);			// allocate memory
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);			// free memory when done
char* s_gets(char* st, int n);


int main()
{
	/*
	char buffer[SLEN] = { 0, };
	int f2 = scanf("%[^\n]%*c", buffer);
	p.fname = (char*)malloc(strlen(buffer) + 1);
	if (p.fname != NULL)
		strcpy(p.fname, buffer);
	printf("%s %s\n", p.fname, p.lname);
	*/

	/* Problem */
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);	// vs. scanf()
	if (ret_val)
	{
		find = strchr(st, '\n');	// look for newline
		if (find)					// if the address is not NULL
			*find = '\0';			// place a null character there
		else
			while (getchar() != '\n')
				continue;			// dispose of rest of line
	}

	return ret_val;
}

void getinfo(struct namect* person)
{
	char buffer[SLEN] = { 0, };
	int f2;

	printf("Input your first name:\n>> ");
	f2 = scanf("%[^\n]%*c", buffer);
	if (f2 != 1)
		printf("Worng input");
	else
	{
		person->fname = (char*)malloc(strlen(buffer) + 1);
		if (person->fname != NULL)
			strcpy(person->fname, buffer);
		else
			printf("Malloc() failed");
	}

	printf("Input your last name:\n>> ");
	f2 = scanf("%[^\n]%*c", buffer);
	if (f2 != 1)
		printf("Worng input");
	else
	{
		person->lname = (char*)malloc(strlen(buffer) + 1);
		if (person->lname != NULL)
			strcpy(person->lname, buffer);
		else
			printf("Malloc() failed");
	}
	printf("%s %s\n", person->fname, person->lname);
}

void makeinfo(struct namect* person)
{
	person->letters = strlen(person->fname) + strlen(person->lname);
}
void showinfo(const struct namect* person)
{
	printf("Hi, %s %s. Your name has %d characters.\n", person->fname, person->lname, person->letters);
}

void cleanup(struct namect* person)
{
	free(person->fname);
	free(person->lname);
}