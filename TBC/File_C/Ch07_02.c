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

	//ch = getchar();	// �ѱ��� ��������
	//putchar(ch);	// ������ ���� ����ϱ�

	/* Example 2 */
	
	/*
	while (ch != '\n') // Use '\n' to find the end of a sentence
	{
		putchar(ch);

		ch = getchar();
	}

	// �� ���ھ� ����ϴ� ���������� �������ڸ� �Է��ص� ����ϴ� ����
	// buffer���� �ӽ÷� �޾Ƴ��ٰ� while ������ �� ���ھ� �ݺ��ؼ� �������� �ֱ� ����
	// �ڿ� ������ buffer���� �ڼ��� ����

	putchar(ch);
	*/

	/* Example 3 */

	/*
	while ((ch = getchar()) != '\n') // �̷� ������ ���̴� �͵� ����
		putchar(ch);

	putchar(ch);
	*/

	/* Example 4 */

	//for ���� ����ϴ� �Ͱ� ��� ���ϴ� �� �߿� ���� ������
	//for ���� ���������� ��� �ݺ��ǰ� �ֱ⶧���� �������� �ľ��ؼ�
	//if�� ����ϴ� ���� �� ��ȣ

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