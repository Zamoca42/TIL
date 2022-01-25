#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



void temp()
{
	extern int g_int;

	g_int += 1000;
}

void fun_sec()
{
	temp();

	extern int g_int;

	g_int += 7;
	printf("g_int is fun() %d %p\n", g_int, &g_int);
}

