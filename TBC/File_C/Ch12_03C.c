#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int el;				// file scope with external linkage (global variable)
static int i1;;		// file scope with internal linkage

int main()
{
	el = 1024;

	testLinkage();

	printf("%d\n", el);

	return 0;
}