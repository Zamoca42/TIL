#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int var_name = 3;		// creates an object call 'var_name'

	int* pt = &var_name;	// pt is an identifier.
	*pt = 1;				// *pt is not an identifier. *pt designates an object.

	int arr[100];			// arr is an identifier. Is arr an object?
	arr[0] = 7;				// arr[0] is an object.

	var_name = 3;			// modifiable lvalue

	pt = &var_name;
	int* ptr = arr;
	*pt = 7;				// *pt is not an identifier but an modifiable lvalue expression

	int* ptr2 = arr + 2 * var_name; // address rvalue
	*(arr + 2 * var_name) = 456;	// lvalue expression

	const char* str = "Constant string";	// str is a modifiable lvalue.
	str = "Second string"; // "Constant string" = "Second string" // impossible
	//str[0] = 'A'; // Error
	//puts(str);

	char str2[] = "String in an array";
	str2[0] = 'A';	//OK
	//puts(str2);

	return 0;
}