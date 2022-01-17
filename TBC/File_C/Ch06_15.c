#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* Example 1 */
	
	//for (int j = 0; j < 5; j++)		// outer row loop
	//{
	//	for (char i = 'A'; i < 'L'; i++)// inner character loop
	//	{
	//		printf("%c ", i);
	//	}

	//	printf("\n");
	//}

	/* Example 2 */
	
	/*
	for (int r = 0; r < 10; ++r)
	{
		for (char c = 'A'; c <= 'A' + r; ++c)
		{
			printf("%c ", c);
		}
		printf("\n");
	}
	*/

	/* Example 3 */

	for (int r = 0; r < 12; ++r)
	{
		for (char c = 'A' + r; c < 'A' + 12; ++c)
		{
			printf("%c ", c);
		}
		printf("\n");
	}

return 0;

}
