#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

inline int foo()
{
	return 5;
}

// Driver code
int main()
{
	int ret;

	// inline function call
	ret = foo();

	printf("Output is: %d\n", ret);
	return 0;
}