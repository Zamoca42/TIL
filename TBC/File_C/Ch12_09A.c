#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

extern int g_int;

void fun_second()
{
	g_int += 10;

	printf("g_int is fun() %d %p\n", g_int, &g_int);

}