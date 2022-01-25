#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int g_int = 123;

void fun();
void fun_second();
void fun_third();


int main()
{
	fun();
	fun_second();
	fun_third();

	return 0;
}

void fun()
{
	extern int g_int;

	g_int += 10;

	printf("g_int is fun() %d %p\n", g_int, &g_int);
	
}