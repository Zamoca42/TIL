#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void f1()
{
	return;
}

int f2(char i)
{
	return i + 1;
}

int main()
{
	void (*pf1)() = f1;
	//void (*pf1)() = &f1;

	int (*pf2)(char) = f2;

	(*pf1)();//call f1 via pf1;
	//pf1();

	int a = pf2('A');
	//int a = (*pf2)('A');

	printf("%d\n", a);//66

	return 0;
}