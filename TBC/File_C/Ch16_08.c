#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#include "DifferentFile.h"

void different_function();

int main()
{
	printf("__FILE__ : %s\n", __FILE__);
	printf("__DATE__ : %s\n", __DATE__);
	printf("__TIME__ : %s\n", __TIME__);
	printf("__LINE__ : %d\n", __LINE__);
	printf("__func__ : %s\n", __func__);

	different_function();

	different_func_in_different_file();

//#if __LINE__ != 22
//#error Not line 22
//#endif

#if defined(_WIN64) != 1
#error Not WIN64 plaform
#endif

	return 0;
}

void different_function()
{
	printf("This function is %s\n", __func__);
	printf("This is line %d\n", __LINE__);
}