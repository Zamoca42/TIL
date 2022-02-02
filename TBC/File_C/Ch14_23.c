#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>	// time()

int main()
{
	/*
		typedef specifier
		- Give symbolic names (or aliases) to types
		- Does not create new types
	*/

	typedef unsigned char BYTE;	//Note the scope of BYTE

	BYTE x, y[10] = { 0, }, * z = &x;

	{
		typedef unsigned char byte; // You can use lowercases as well.

		/* Portable data types */

		size_t s = sizeof(byte);	// unsigned int (x86), unsigned long long (x64)
		// unsigned int s = sizeof(byte); // x86
		// unsigned long long s = sizeof(byte);//x64
	}

	//byte b; // typedef definition has a scope

	/*
		This function returns the time since 00:00:00 UTC, January 1, 1970 (Unix timestamp)
		in seconds.
	*/

	time_t t = time(NULL);

	printf("%lld\n", t);

	/*
		typedef vs #define
	*/

	typedef char* STRING;

	STRING name = "John Wick", sign = "World";

	/*
	#define STRING char *
	
	STRING name, sign;
	char * name, sign;

	*/

	typedef struct complex {
		float real;
		float imag;
	} COMPLEX;	// typedef struct complex COMPLEX


	return 0;

}