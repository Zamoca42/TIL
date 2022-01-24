#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int el;

void testLinkage()
{
	printf("DoSomething called\n");
	printf("%d\n", el);

	el++;

}