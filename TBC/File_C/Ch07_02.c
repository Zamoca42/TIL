#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	/* 
		1. Introduce getchar(), putchar()
		2. Use while loop to process character sequences
		3. Filter a specific character
		4. Convert numbers to asterisks
		5. Lower characters to Upper characters
	*/
	
	/* Example 1 */

	char ch;

	//ch = getchar();	// 한글자 가져오기
	//putchar(ch);	// 가져온 글자 출력하기

	/* Example 2 */
	
	/*
	while (ch != '\n') // Use '\n' to find the end of a sentence
	{
		putchar(ch);

		ch = getchar();
	}

	// 한 글자씩 출력하는 원리이지만 여러글자를 입력해도 출력하는 이유
	// buffer에서 임시로 받아놨다가 while 문에서 한 글자씩 반복해서 빼내오고 있기 때문
	// 뒤에 나오는 buffer에서 자세히 설명

	putchar(ch);
	*/

	/* Example 3 */

	/*
	while ((ch = getchar()) != '\n') // 이런 식으로 줄이는 것도 가능
		putchar(ch);

	putchar(ch);
	*/

	/* Example 4 */

	//for 문을 사용하는 것과 사용 안하는 것 중에 뭐가 좋을까
	//for 문은 내부적으로 계속 반복되고 있기때문에 논리구조를 파악해서
	//if를 사용하는 것을 더 선호

	/*
	while ((ch = getchar()) != '\n')
	{
		//for (int i = '0'; i <= '9'; ++i)
			//if (ch == i)
				//ch = '*';
		if (ch >= '0' && ch <= '9')
			ch = '*';

		putchar(ch);
	}

	putchar(ch);
	*/

	/* Example 5 */

	/*
	while ((ch = getchar()) != '\n')
	{
		if (ch >= 'a' && ch <= 'z') // 'A' = 65, 'a' = 97
			ch -= 'a' - 'A';
		else if(ch >= 'A' && ch <= 'Z')
			ch += 'a' - 'A';


		putchar(ch);
	}

	putchar(ch);
	*/

	return 0;
}