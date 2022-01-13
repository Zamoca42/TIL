# TBC

>## 목차
>[따라 배우는 C언어 강의를 선택하게 된 이유](#따라-배우는-C언어-강의를-선택하게-된-이유)  
>[Chapter 0~1. C언어 강의 시작](#chapter-01-C언어-강의-시작)  
>[Chapter 2. C의 해부학](#chapter-2-C의-해부학)  
>[Chapter 3. scanf() & 데이터와 자료형](#chapter-3-scanf--데이터와-자료형)  
>[Chapter 4. 문자열과 형식 맞춘 입출력](#chapter-4-문자열과-형식-맞춘-입출력)  
>[Chapter 5. 반복문 & 연산자](#chapter-5-반복문--연산자)  
>[Chapter 6. 반복문](#chapter-6-반복문)  
  
---
### 따라 배우는 C언어 강의를 선택하게 된 이유
---
  
이번에 컴공 복수전공을 계획하고 있는데,

개학 전에 C언어, 자료구조정도는 학습 해보고 싶어서

유튜브에 여러 강의를 맛보기로 들어보던 중

홍정모의 따라하며 배우는 C언어에 끌려서 유료강의를 결제하게 되었다.

강의 소개 및 목록

[홍정모 연구소 : 네이버 블로그](https://blog.naver.com/atelierjpro/221459363501)

기본기를 제대로 배울 수 있을거같다는 느낌을받았다.

[https://youtu.be/PDM_w2b4UA0](https://youtu.be/PDM_w2b4UA0)

컴퓨터의 작동 원리까지 상세하게 설명해주신다. 

지금 올라온 링크로 들어가면 Chapter 0~1에 대한 강의 내용을 볼 수 있다.

Chapter 0~1 부분은 반드시 이해한다는 느낌보다는 

원리 정도만 이해하고 넘어가면 좋다고 한다.

챕터가 끝날때마다 공부한 내용을 업로드할 예정이다.
  
---
### Chapter 0~1. C언어 강의 시작
---
  


- [0.6] random access를 하기위해서는 address bus가 필요하다
    
    → C언어에 포인터가 있는 이유  
      
    
- [1.3] The Spirit of C
    
    → 프로그래머를 믿어라
    
    → 프로그래머가 필요한 일을 하는 것을 방해하지마라
    
    → 언어를 작고 단순하게 유지하라
    
    →  한 연산을 할 때 단 한가지 방법만 제공해라.
    
    → 호환을 보장할 수 없다 하더라도 속도를 빠르게 해라.
    
- [1.4] 소프트웨어 개발의 7가지 단계
    
    → 목적을 정의한다
    
    → 프로그램을 설계한다
    
    → 코드를 작성한다
    
    → 컴파일 한다
    
    → 실행시켜본다
    
    → 시험해보고 오류가 있다면 수정한다
    
    → 프로그램을 유지하고 개선해 나간다
    
---
### Chapter 2. C의 해부학
---

```c
#include <stdio.h>

int main(void)
{

	int a; //변수 선언

	int b;

	int c;

	a=1; // 변수에 값 대입

	b=2;

	c = a + b; // 연산 결과 대입

	printf(”Result is %i”, c); //함수 호출

	return 0; 

}
```

C언어를 코딩할때 제일먼저 입력하는 전처리기(preprocessor)인

#include <stdio.h> 의 stdio는 무슨 줄임말일까 고민했는데 standard in&out이라고 한다. 

함수를 사용할 수 있는 stdio 라이브러리를 가져온다 정도의 뜻이다.

int main(void) 는 함수 정의 시작부분이고 나머지 중괄호 안은 영역을 의미한다.

---
### Chapter 3. scanf() & 데이터와 자료형
---

- [3.1] 자료형
    
    ![9904.png](TBC%20a4270fdf4845483ca1e256608b8816d2/9904.png)
    
    [출처]<[https://opentutorials.org/module/3921/23515](https://opentutorials.org/module/3921/23515)>
    

- [3.2] 변수와 상수
    
    ```c
    const int angel = 1004;
    // 변수이지만 const가 붙으면 값을 바꿀 수 없음
    // 기호적 상수
    ```
    

- [3.3~4] 간단한 입출력 프로그램만들기
    
    ```c
    #include<stdio.h>
    
    int main()
    {
    	int i = 0, j = 0;
    	int sum = 0;
    
    	printf("Input two integers\n");
    
    	scanf("%d %d", &i, &j); //& : ampersand
    	//메모리 주소를 직접 접근하기때문에 보안 위험
    	//microsoft에서는 scanf_s 권장
    
    	sum = i + j;
    
    	printf("%d Plus %d = %d\n", i, j, sum);
    
    	return 0;
    }
    ```
    

- [3.5] 정수와 실수
    
    Two’s Complement
    
    부호를 갖는 정수를 2의 보수로 표현한다
    
    [2의 보수 - 위키백과, 우리 모두의 백과사전](https://ko.wikipedia.org/wiki/2%EC%9D%98_%EB%B3%B4%EC%88%98)
    
- [3.7]  다양한 자료형
    
    ```c
    //다양한 자료형과 형식지정자
    
    #include <stdio.h>
    #include <limits.h>
    #include <stdlib.h>
    
    int main()
    {
    	char c = 65;
    	short s = 200;
    	unsigned int ui = 3000000000U; // 3'000'000'000U <- U는 생략가능
    	long l = 65537L;
    	long long ll = 12345678908642LL; // 12'345'678'908'642ll
    
    	printf("char = %hhd, %d, %c\n", c, c, c);
    	printf("short = %hhd, %hd, %d\n", s, s, s);
    	printf("unsigned int = %u, %d\n", ui, ui); //%d에서 오버플로우
    	printf("long = %ld, %hd\n", l, l);
    	printf("long long = %lld, %ld\n", ll, ll);
    
    	return 0;
    }
    ```
    

- [3.8] 8진수와 16진수
    
    ```c
    #include <stdio.h>
    
    int main()
    {
    	unsigned int decimal = 4294967295;
    	unsigned int binary = 0b11111111111111111111111111111111;
    	unsigned int oct = 037777777777;
    	unsigned int hex = 0xffffffff;
    
    	printf("%u\n", decimal);
    	printf("%u\n", binary);
    	printf("%u\n", oct);
    	printf("%u\n", hex);
    
    	printf("%o %x %#o %#x %#X", decimal, decimal, decimal, decimal, decimal);
    
    	return 0;
    }
    ```
    
    - 8진수와 16진수가 2진수보다 간결하게 표현 가능하기 때문에 사용할 일이 많다.

- [3.10] 문자형
    
    [https://ko.wikipedia.org/wiki/ASCII](https://ko.wikipedia.org/wiki/ASCII)
    
    C언어도 char 자료형을 사용했을 때 아스키코드로 출력이 가능하고 visual studio로 봤을 때
    
    정수형 숫자가 출력 되는 것을 확인 할 수 있다
    
    ```c
    char C = 'A'; // ASCII = int(65)
    ```
    
---
### Chapter 4. 문자열과 형식 맞춘 입출력
---

- [4.1]  scanf()에서 주소를 가져오기 위해서  변수 앞에 &을 붙인다.
    
    하지만 변수를 선언하고 나서 뒤에 배열을 넣어주면 주소 자체가 되기 때문에
    
    scanf() 함수에서 &을 빼주어야 한다.
    
- [4.2] sizeof 연산자
    
    ```c
    #include <stdio.h>
    #include <stdlib.h> // malloc()
    
    struct MyStruct
    {
    	int i;
    	float f;
    };
    
    int main()
    {
    	/* 1. sizeof basic types */
    	
    	int a = 0;
    	unsigned int int_size1 = sizeof a;
    	unsigned int int_size2 = sizeof(int);
    	unsigned int int_size3 = sizeof(a);
    
    	size_t int_size4 = sizeof(a);
    	size_t float_size = sizeof(float);
    
    	printf("Size of int type is %u bytes. \n", int_size1);
    	printf("Size of int type is %zu bytes. \n", int_size4);
    	printf("Size of float type is %zu bytes. \n", float_size);
    
    	/* 2. sizeof arrays */ 
    
    	int int_arr[30]; // int_arr[0] = 1024; ...
    	int* int_ptr = NULL;
    	int_ptr = (int*)malloc(sizeof(int) * 30); // int_prt[0] = 1024; ...
    
    	printf("Size of array = %zu bytes \n", sizeof(int_arr));
    	printf("Size of pointer = %zu bytes\n", sizeof(int_ptr));
    
    	/* 3. sizeof character array */
    
    	char c = 'a';
    	char string[10]; // maximally 9 character + '/0' (null character)
    
    	size_t char_size = sizeof(char);
    	size_t str_size = sizeof(string);
    
    	printf("Size of char type is %zu bytes.\n", char_size);
    	printf("Size of string type is %zu bytes.\n", str_size);
    
    	/* 4. sizeof structure */
    
    	printf("%zu\n", sizeof(struct MyStruct));
    
    	return 0;
    
    }
    ```
    
- [4.3] 문자열이 메모리에 저장되는 구조
    
    ```c
    #include <stdio.h>
    
    int main()
    {
    	/*
    	int a = 1;
    	int int_arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    	printf("%i %i %i\n", int_arr[0], int_arr[1], int_arr[9]);
    	*/
    
    	printf("%i\n", int_arr[10000]);
    
    	char c = 'a';
    	char str1[10] = "Hello"; // null character
    	// H,e,l,l,o,/0 까지 6글자인 것 처럼 출력
    	char str2[10] = { 'H', 'i' };
    
    	printf("%c\n", c);
    	printf("%s\n", str1);
    	printf("%s\n", str2);
    
    	printf("%hhi %hhi %hhi %hhi %hhi\n",
    		str2[0], str2[1], str2[2], str2[3], str2[4]);
    
    	char str3[10] = "Hello, World"; // array size is not enough
    	char str3[20] = "Hello, \0World";
    	printf("%s\n", str3);
    	printf("%c\n", str3[10]);
    	printf("%c\n", str3[11]);
    
    	return 0;
    }
    ```
    

- [4.7] 변환 지정자
    
    ![11904.png](TBC%20a4270fdf4845483ca1e256608b8816d2/11904.png)
    
    추가로 %%를 입력하면 퍼센트 기호를 출력할 수 있다.
    
    [출처] <[https://opentutorials.org/module/3921/23515](https://opentutorials.org/module/3921/23515)>
    
- [4.8] 변환 지정자의 수식어들
    
    %[flags][width][.precision][length]specifier
    
    [https://cplusplus.com/reference/cstdio/printf/](https://cplusplus.com/reference/cstdio/printf/)
    
    - flags - 출력하고 싶은 형식
        
        → ( - ) : 왼쪽 줄 맞춤, 없으면 오른쪽 줄 맞춤
        
        → ( + ) : 양수일 경우 항상 + 기호 출력
        
        → ( # ) : o, x , X 같은 진수 표현식 형식 지정자의 0, 0x, 0X 출력
        
        → ( 0 ) : 빈칸자리를 0으로 채운다
        
    - width - 입력하는 숫자만큼의 자리수가 생긴다
        
        ex) 상수로 1234 입력 → width에 7을 적을경우 → 앞에서 3자리는 빈칸
        
    - .precision - .number : number에 입력 값 만큼 정확도(?)
        
        %f일 경우 소수 자리 수
        
        %d일 경우 자리 수 출력
        
        %s일 경우도 자리 수 만큼 출력
        
    - length
        
        ![length.png](TBC%20a4270fdf4845483ca1e256608b8816d2/length.png)
        
---
### Chapter 5. 반복문 & 연산자
---

- [5.1] 반복 루프의 첫 만남
    
    ```c
    #include <stdio.h>
    
    int main()
    {
    	int n = 1;
    
    	while (n < 3)
    	{
    		printf("%d\n", n);
    		n = n + 1;
    	}
    
    	return 0;
    }
    ```
    

- [5.2] 대입 연산자
    
    ```c
    int i;
    
    i = 1024;
    
    // 1024 = I;
    
    i = i + 1;
    ```
    
    수학적으로 보면 i = i + 1; 은 잘못된 것 이지만,
    
    C언어에서는 대입 연산자이기 때문에 오른쪽에서 i + 1을 한 후 왼쪽 i에 대입하라는 뜻이다
    
    → L-value : 메모리를 차지하고 있는 특정 데이터 객체(개체)
    
    → R-value : 수정 가능한 L-value에게 대입될 수는 있지만, 자기 자신은 L-value가 될 수 없는 것
    
    ```c
    const int TWO = 2; // 수정 불가능한 L-value
    
    int a, b, c; // 수정 가능한 L-value
    
    a = 42; //42는 R-value
    
    b = a;
    
    c = TWO * (a+b); //(a+b)는 R-value (프로그램이 계산하는 임시값, 끝나면 사라짐)
    ```
    
- [5.7] 나머지 연산자
    
    ```c
    //TODO: seconds -> hours, minutes, seconds
    		minutes = seconds / 60;
    		seconds %= 60;
    
    		hours = minutes / 60;
    		minutes %= 60;
    
    		//print result
    		printf("%d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
    
    		printf("Input seconds : ");
    		scanf("%d", &seconds);
    ```
    
    나머지 연산자는 나눈 나머지를 변수에 저장한다
    

- [5.8] 증가, 감소 연산자
    
    ```c
    a++; // a = a + 1 or a += 1;
    ```
    
    후위 (postfix) 연산자라고 부르고 연산을 한번 실행한 뒤에 1을 더해주는 식으로 작동한다.
    
    ```c
    ++a; // a = a + 1 or a += 1;
    ```
    
    전위 (prefix) 연산자라고 부르고 연산을 실행하기 전에 
    
    1을 더하고 난 뒤 대입하고 실행하는 식으로 작동한다.
    
    ```c
    int i = 1, j = 1;
    	int i_post, pre_j;
    
    	i_post = i++;
    	pre_j = ++j;
    
    	printf("%d %d\n", i, j); // 출력값 2 2
    	printf("%d %d\n", i_post, pre_j); // 출력값 1 2
    ```
    
---
### Chapter 6. 반복문
---

- [6.2] Pseudo Code
    
    의사 코드 라고 부르며
    
    프로그래밍 언어보다 논리 자체에 집중하기 위해 인간의 언어로 표현해보는 것
    
    알고리즘을 공부할 때, 가장 많이 보게됨
    
    ![의사코드.png](TBC%20a4270fdf4845483ca1e256608b8816d2/%EC%9D%98%EC%82%AC%EC%BD%94%EB%93%9C.png)
    
    [출처] edwith - 컴퓨터 과학 교양 강좌 : CS50 
    
- [6.3] 진입조건 루프 While
    - while문은 진입조건 루프라고 하여 조건값이 참 일 때, 루프를 반복한다.
        
        ```c
        /*
        while (expression)
        		statement
        */
        
        int i;
        
        	i = 1;
        	while (i < 5)		   // infinite loop
        		printf("Hi!\n"); // iteration
        ```
        
    - while문을 작성할 때 일반적인 실수로는
        
        ```c
        /* common mistake */
        
        	i = 0;
        	while (i < 3)
        		printf("%i\n", i);
        		i++; // indenting
        
        	i = 0;
        		while (i++ < 3);		// null statement
        		printf("%i\n", i);
        
        	while (scanf("%d, &i") == 1)
        		; // null statement
        			// do something (?)
        ```
        
        블럭을 표시하지 않거나, 조건 끝에 세미콜론 (;) 을 작성하거나, statement를 작성하지 않는 
        
        실수가 일반적이다
        
- [6.4~5] 관계 연산자
    
    ```c
    /*		
    			Relational Operators
    			<	is less than
    			<=	is less than or equal to
    			==	is equal to
    			>=	is greater than or equal to
    			>	is greater than
    			!=	is not equal to
    	*/
    
    	/*
    	int n = 0;
    	while (n++ < 5)
    		printf("%d ", n);
    	printf("\n");
    	char c = 'A';
    	while (c != 'Z')
    		printf("%c ", c++);
    	*/
    
    	const double PI = 3.141592;
    	double guess = 0.0;
    
    	printf("Input PI : ");
    	scanf("%lf", &guess);
    	//while (guess != PI)
    	while (fabs(guess - PI) > 0.001)
    	{
    		printf("Fool! Try again.\n");
    		printf("Input PI again : ");
    		scanf("%lf", &guess);
    	}
    
    	printf("Good!");
    ```
    
    관계 연산자는 참, 거짓을 출력하는데 사용한다.
    
- [6.8~9] for 루프
    
    for문은 while문과 같이 진입 조건 루프에 해당하지만, 좀 더 유연하게 사용할 수 있다.
    
    for문과 while문의 차이를 알아보면
    
    ```c
    int i;
    
    i = 1;
    
    while (i <= 10)
    	{
    		printf("%d ", i);
    		i++;
    	}
    ```
    
    while 문은 initialize, test, update 까지 나눠진 것 처럼 보인다.
    
    ```c
    for (int i = 1; i <= 10; i++) // init, test, update
    	{
    		printf("dummy ");
    		printf("%d ", i);
    	}
    ```
    
    for 문은 initialize, test, update 까지 for문 옆에 한줄로 유연하게 작성 가능하다.
    
    ```c
    for (int i = 0; i < 100; i = i + 8)
    	printf("%d ", i);
    
    for (char c = 'A'; c < 'Z'; c++)
    	printf("%c ", c);
    
    for (int i = 0; i * i < 10; i++)
    	printf("%d ", i);
    
    for (;;)
    		printf("I love you!");
    ```
    
    여러가지 방식으로 사용 가능하다.
    
- [6.13]  탈출 조건 루프 do while
    
    while문에서는 조건이 참일 때, 진입 할지, 말지를 결정한다면,
    
    do while문은 한번은 입력을 해야하고, 빠져 나올지 말지를 조건으로 확인한다.
    
    비밀번호를 입력하는 예시를 보면
    
    ```c
    const int password = 337;
    int i = 0;
    
    	printf("Enter the password : ");
    	scanf("%d", &i);
    	
    	while (i != password)
    	{
    		printf("Enter the password : ");
    		scanf("%d", &i);
    	}
    ```
    
    while문을 사용할 때에 먼저 입력을 받고  while문을 작성하기 때문에 
    
    루프에서도 한번 더 입력해야한다.
    
    ```c
    do
    	{
    		printf("Enter secret code : ");
    		scanf("%d", &i);
    	} 
    	while (i != password);
    
    	printf("Good!\n");
    ```
    
    do while문 에서는 한번만 입력을 하면 루프로 들어가고
    
    탈출이 가능하기 때문에 효율적으로 보일 수 있다.
    
- [6.14] 어떤 루프를 사용할까?
    
    진입조건 : [while], [for] 
    
    vs 탈출조건 : [do while]
    
    → [do while] : 앞서 한번은 실행을 해야 할 경우
    
    → [while] , [for] : 그 외의 경우 
    
- [6.15] 중첩된 루프들
    - 예시1
        
        ```c
        for (int j = 0; j < 5; j++)		// outer row loop
        	{
        		for (char i = 'A'; i < 'L'; i++)// inner character loop
        		{
        			printf("%c ", i);
        		}
        
        		printf("\n");
        	}
        
        /* 출력 예 */
        
        // A B C D E F G H I J K
        // A B C D E F G H I J K
        // A B C D E F G H I J K
        // A B C D E F G H I J K
        // A B C D E F G H I J K
        ```
        
    
    - 예시 2
        
        ```c
        	for (int r = 0; r < 10; ++r)
        	{
        		for (char c = 'A'; c <= 'A' + r; ++c)
        		{
        			printf("%c ", c);
        		}
        		printf("\n");
        	}
        	
        /* 출력 예 */
        
        // A
        // A B 
        // A B C
        // A B C D
        // ...
        // A B C D E F G H I J
        ```
        
    - 예시 3
        
        ```c
        for (int r = 0; r < 12; ++r)
        	{
        		for (char c = 'A' + r; c < 'A' + 12; ++c)
        		{
        			printf("%c ", c);
        		}
        		printf("\n");
        	}
        
        /* 출력 예 */
        
        // A B C D E F G H I J K L
        // B C D E F G H I J K L
        // C D E F G H I J K L
        // ...
        // L
        ```
        

- [6.16] 배열과 런타임에러
    
    ```c
    #define NUM_DAYS 365
    
    char my_chars[] = "Hello, World!";
    	int daily_temperature[NUM_DAYS];
    	double stock_prices_history[NUM_DAYS];
    	printf("%zd\n", sizeof(stock_prices_history));
    	printf("%zd\n", sizeof(double) * NUM_DAYS);
    	printf("%zd\n", sizeof(stock_prices_history[0]));
    
    	int my_numbers[5];
    
    	my_numbers[0] = 1; //subscripts, indices, offsets
    	my_numbers[1] = 3;
    	my_numbers[2] = 4;
    	my_numbers[3] = 2;
    	my_numbers[4] = 1024;
    
    	// scanf("%d", &my_numbers[0]);
    	// scanf("%d", my_numbers); 
    	// 변수에는 &을 붙이지만 array는 주소 자체라서 붙이지 않음
    
    	printf("%d\n", my_numbers[0]);
    	printf("%d\n", my_numbers[1]);
    	printf("%d\n", my_numbers[2]);
    	printf("%d\n", my_numbers[3]);
    	printf("%d\n", my_numbers[4]);
    
    	/* Runtime Error */
    	 compile not error
    	my_numbers[5] = 123; // out of bound
    
    	my_numbers = 7; // compile error
    ```
    
    배열을 선언하게 되면 변수를 여러번 선언하지 않고 stock_prices_history [NUM] 형식으로 
    
    stock_prices_history는 주소, [NUM]안에 정수를 입력하여 정수 값 만큼의 
    
    double 자료형인 8byte * NUM 의 값 만큼의 블록을 불러올 수 있다.
    
    sizeof 연산자로 출력해보면 stock_prices_history[0] 는 8을 출력하고
    
    stock_prices_history[365] 는 8 * 365가 되어 2920을 출력하는 것을 알 수 있다.
    
    한 가지 주의해야 할 것은 my_numbers[5]의 예시처럼 배열을 선언하면
    
    컴퓨터는 0부터 숫자를 세기 때문에 [0]~[4]까지 배열이 선언되는 것을 알 수있다.
    
    여기서 my_numbers[5] = 123; 을 입력하면 컴파일러는 문제가 없다고 하지만
    
    실행을 시킬 때 문제가 발생한다. 이 것을 런타임 에러라고 부른다.
    
- [6.17] for 루프를 배열과 함께 사용하기
    
    앞에서 배운 배열과 for루프를 응용할 수 있는데
    
    많은 양의 데이터를 다루고자 할 때, 배열과 for루프를 사용하면 유용하다.
    
    ```c
    #define SIZE 5
    
    int num[SIZE];
    	int sum = 0;
    
    	for (int i = 0; i < SIZE; ++i)
    	{
    		printf("Enter %d numbers : ", SIZE);
    		scanf("%d", &num[i]);
    		sum += num[i];
    	}
    
    	
    	printf("Sum = %d\n", sum);
    ```
    
    나는 이처럼 입력을 해보았는데 적은 양의 데이터는 문제가 없지만, 
    
    데이터가 클 수록 문제가 발생할 수 있다고 한다.
    
    ```c
    // recommand code
    // 많은 데이터에서는 for문을 쪼개는게 더 좋을 수 있다
    
    	
    	int numbers[SIZE];
    	int sum = 0;
    	int i;
    
    	printf("Enter %d numbers : ", SIZE);
    
    	for (i = 0; i < SIZE; ++i)
    		scanf("%d", &numbers[i]);
    
    	for (i = 0; i < SIZE; ++i)
    		sum += numbers[i];
    
    	printf("Sum = %d\n", sum);
    	
    ```
    
    이렇게 for문을 나누는 것이 데이터가 많을 땐 좋을 수 있다.
    
- [6.18] 루프 안에서 함수의 반환 값 사용하기
    
    이 때까지 배운 것을 예제로 제곱구하는 함수를 작성 해보았다.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    // prototype
    int compute_pow(int base, int exp);
    
    int main()
    {
    	// my code
    	/*
    	int i, sqr, j, result;
    
    	scanf("%d %d", &i, &sqr);
    
    	for (j = 0; j < sqr; j++)
    		result *= i;
    
    	printf("Result is : %d\n", result);
    	*/
    
    	// recommand code
    
    	int base, exp, result;
    	
    	while (scanf("%d %d", &base, &exp) == 2)
    	{
    		/*
    		result = 1;
    		for (i = 0; i < exp; ++i)
    			result *= base;
    		*/
    		result = compute_pow(base, exp);
    
    		printf("Result = %d\n", result);
    	}
    
    	return 0;
    }
    
    // function (scope)
    int compute_pow(int base, int exp)
    {
    	int i, result;
    
    	result = 1;
    	for (i = 0; i < exp; ++i)
    		result *= base;
    
    	return result;
    }
    ```
    
    따로 함수를 밑에서 작성하면 main에서 함수를 입력해도 작동을 하지 않는다.
    
    그래서 main 함수 위에 밑에서 작성한 int compute_pow(int base, int exp); 
    
    프로토타입을 작성하여 main에서 사용할 수 있게 해준다.
