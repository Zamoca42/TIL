![C_lang](https://user-images.githubusercontent.com/96982072/149340879-6abd88d5-2fbc-4439-8d9b-20137922c6a2.png)

## 따라 배우는 C언어 강의를 선택하게 된 이유
  
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

</br>
  

## Chapter 0~1. C언어 강의 시작
  


- ### [0.6] random access를 하기위해서는 address bus가 필요하다  
	-  C언어에 포인터가 있는 이유  
      
- ### [1.3] The Spirit of C
	-  프로그래머를 믿어라
	-  프로그래머가 필요한 일을 하는 것을 방해하지마라
	-  언어를 작고 단순하게 유지하라
	-  한 연산을 할 때 단 한가지 방법만 제공해라
	-  호환을 보장할 수 없다 하더라도 속도를 빠르게 해라.  
		
- ### [1.4] 소프트웨어 개발의 7가지 단계
	- 목적을 정의한다
	- 프로그램을 설계한다
	- 코드를 작성한다
	- 컴파일 한다
	- 실행시켜본다
	- 시험해보고 오류가 있다면 수정한다
	- 프로그램을 유지하고 개선해 나간다

</br>    
    
## Chapter 2. C의 해부학

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

</br>

## Chapter 3. scanf() & 데이터와 자료형


- ### [3.1] 자료형
    
    ![9904](https://user-images.githubusercontent.com/96982072/149322799-5acc2358-df68-4563-a028-9a3549de7716.png)

    
    [출처]<[https://opentutorials.org/module/3921/23515](https://opentutorials.org/module/3921/23515)>
    

- ### [3.2] 변수와 상수
    
    ```c
    const int angel = 1004;
    // 변수이지만 const가 붙으면 값을 바꿀 수 없음
    // 기호적 상수
    ```
    

- ### [3.3~4] 간단한 입출력 프로그램만들기
    
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
    

- ### [3.5] 정수와 실수
    
    Two’s Complement
    
    부호를 갖는 정수를 2의 보수로 표현한다
    
    [2의 보수 - 위키백과, 우리 모두의 백과사전](https://ko.wikipedia.org/wiki/2%EC%9D%98_%EB%B3%B4%EC%88%98)
    
- ### [3.7]  다양한 자료형
    
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
    

- ### [3.8] 8진수와 16진수
    
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

- ### [3.10] 문자형
    
    [https://ko.wikipedia.org/wiki/ASCII](https://ko.wikipedia.org/wiki/ASCII)
    
    C언어도 char 자료형을 사용했을 때 아스키코드로 출력이 가능하고 visual studio로 봤을 때
    
    정수형 숫자가 출력 되는 것을 확인 할 수 있다
    
    ```c
    char C = 'A'; // ASCII = int(65)
    ```

</br>    

## Chapter 4. 문자열과 형식 맞춘 입출력


- ### [4.1]  scanf()에서 주소를 가져오기 위해서  변수 앞에 &을 붙인다
    
    하지만 변수를 선언하고 나서 뒤에 배열을 넣어주면 주소 자체가 되기 때문에
    
    scanf() 함수에서 &을 빼주어야 한다.
    
- ### [4.2] sizeof 연산자
    
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
    
- ### [4.3] 문자열이 메모리에 저장되는 구조
    
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
    

- ### [4.7] 변환 지정자
    
    ![11904](https://user-images.githubusercontent.com/96982072/149322881-bbe48380-d79e-4448-801f-e7748eea0721.png)

    
    추가로 %%를 입력하면 퍼센트 기호를 출력할 수 있다.
    
    [출처] <[https://opentutorials.org/module/3921/23515](https://opentutorials.org/module/3921/23515)>
    
- ### [4.8] 변환 지정자의 수식어들
    
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
        
        ![length](https://user-images.githubusercontent.com/96982072/149322944-3001cee5-1d59-4f4b-8320-7c37616777d8.png)


</br>        

## Chapter 5. 반복문 & 연산자


 - ### [5.1] 반복 루프의 첫 만남
    
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
    

- ### [5.2] 대입 연산자
    
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
    
- ### [5.7] 나머지 연산자
    
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
    

- ### [5.8] 증가, 감소 연산자
    
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
    
</br>

## Chapter 6. 반복문


- ### [6.2] Pseudo Code
    
    의사 코드 라고 부르며
    
    프로그래밍 언어보다 논리 자체에 집중하기 위해 인간의 언어로 표현해보는 것
    
    알고리즘을 공부할 때, 가장 많이 보게됨
    
    ![의사코드](https://user-images.githubusercontent.com/96982072/149322968-880bc355-85bd-4de9-972b-db5d9f75eb4d.png)

    
    [출처] edwith - 컴퓨터 과학 교양 강좌 : CS50 
    
- ### [6.3] 진입조건 루프 While
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
        
- ### [6.4~5] 관계 연산자
    
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
    
- ### [6.8~9] for 루프
    
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
    
- ### [6.13]  탈출 조건 루프 do while
    
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
    
- ### [6.14] 어떤 루프를 사용할까?
    
    진입조건 : [while], [for] 
    
    vs 탈출조건 : [do while]
    
    → [do while] : 앞서 한번은 실행을 해야 할 경우
    
    → [while] , [for] : 그 외의 경우 
    
- ### [6.15] 중첩된 루프들
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
        

- ### [6.16] 배열과 런타임에러
    
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
    
- ### [6.17] for 루프를 배열과 함께 사용하기
    
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
    
- ### [6.18] 루프 안에서 함수의 반환 값 사용하기
    
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
    
</br>

## Chapter 7. 분기문

- ### [7.1] 분기문 if
    
    분기문 if 를 배우면서 간단한 예시로 숫자를 입력 했을 때, 홀수 또는 짝수를 나타내는 함수를 연습 해보았다.
    
    ```c
    int number;
    
    	printf("Input a positive integer : ");
    	scanf("%d", &number);
    ```
    
    입력 받을 숫자의 변수를 선언 해주고
    
    ```c
    if (number % 2 == 0)
    	printf("Even");
    printf("Odd");
    ```
    
    나는 이런식으로 작성하였지만, else를 사용하지 않았기 때문에 홀수를 출력할 때 문제가 발생하였다.
    
    ```c
    if (number % 2 == 0)
    		printf("Even");
    	
    if (number % 2 != 0)
    		printf("Odd");
    ```
    
    정확한 방법은 이렇게 if문을 두 개 사용하여 확실히 기능을 나누어 주거나
    
    ```c
    if (number % 2 == 0)
    		printf("Even");
    	else
    		printf("Odd");
    ```
    
    if 와 else를 사용하여 나머지가 0이 아닐 때 홀수로 출력할 수 있게 한다.
    
- ### [7.2] 표준입출력 함수들
    
    한 글자씩 가져올 수 있는 getchar(), 
    
    가져온 글자를 출력하는 putchar()를 
    
    if문과 함께 알아보자
    
    - 예시 1
        
        ```c
        char ch;
        
        ch = getchar();	// 한글자 가져오기
        	putchar(ch);	// 가져온 글자 출력하기
        ```
        
        우선 함수의 소개이다. 글자를 가져오고, 가져온 글자를 출력할 수 있다.
        
    - 예시 2
        
        ```c
        while (ch != '\n') // Use '\n' to find the end of a sentence
        	{
        		putchar(ch);
        		ch = getchar();
        	}
        
        putchar(ch);
        
        	// 한 글자씩 출력하는 원리이지만 여러글자를 입력해도 출력하는 이유
        	// buffer에서 임시로 받아놨다가 while 문에서 한 글자씩 반복해서 빼내오고 있기 때문
        	// 뒤에 나오는 buffer에서 자세히 설명
        ```
        
        while문을 사용하면 입력한 만큼 받은 문자를 출력할 수 있다.
        
    - 예시 3
        
        ```c
        while ((ch = getchar()) != '\n')
        		putchar(ch);
        	putchar(ch);
        ```
        
        while문을 짧게 줄이는 것도 가능하다.
        
    - 예시 4
        
        ```c
        while ((ch = getchar()) != '\n')
        	{
        		if (ch >= '0' && ch <= '9')
        			ch = '*';
        		putchar(ch);
        	}
        ```
        
        이렇게 if문을 사용하여 조건 내에 글자를 치환 할 수 있다.
        
        if대신 for을 사용할 수 있는데
        
        ```c
        for (int i = '0'; i <= '9'; ++i)
        			if (ch == i)
        				ch = '*';
        ```
        
        이렇게 작성할 수도 있지만, 논리구조를 파악하여 if하나만 쓰는 것이 더 좋을 수 있다.
        
    - 예시 5
        
        ```c
        while ((ch = getchar()) != '\n')
        	{
        		if (ch >= 'a' && ch <= 'z') // 'A' = 65, 'a' = 97
        			ch -= 'a' - 'A';
        		else if(ch >= 'A' && ch <= 'Z')
        			ch += 'a' - 'A';
        		putchar(ch);
        	}
        ```
        
        마지막으로 문자는 ASCII코드를 사용하여 문자 대신 인수로 받을 수 있으므로
        
        연산을 사용하여 소문자를 대문자로 또는 대문자를 소문자로 치환 가능하다.
        
    
- ### [7.3] ctype.h 사용법
    
    새로운 헤더인 ctype.h를 사용하면 대소문자 치환이나 숫자치환, 공백같은 조건들을 쉽게 적용 가능하다.
    
    ctype.h 설명 [https://www.tutorialspoint.com/c_standard_library/ctype_h.htm](https://www.tutorialspoint.com/c_standard_library/ctype_h.htm)
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <ctype.h> //New header
    
    int main()
    {
    	char ch;
    	
    	while ((ch = getchar()) != '\n')
    	{
    		if (islower(ch))
    			ch = toupper(ch);
    		else if (isupper(ch))
    			ch = tolower(ch);
    
    		if (isdigit(ch) != 0)
    			ch = '*';
    
    		putchar(ch);
    	}
    
    	putchar(ch);
    
    	return 0;
    }
    ```
    
    if안의 조건으로 islower을 넣어서 소문자 타입을 찾고 toupper로 대문자로 치환이 가능하다.
    
    isdigit으로 10진수 숫자를 찾아서 *로 바꾸는 식으로도 가능하다.
    
- ### [7.4] 다중 선택 else if
    
    내가 버는 수입에서 세금을 제외하면 얼마나 될 지 계산하는 소득 계산기를 작성해보았다.
    
    else if를 사용 해보기 위한 예제인데 구간 별로 세율을 매겨서 공제 금액을 찾고 마지막 최종 적용되는 세금을 출력하면 된다.
    
    ```c
    // assessment standard tax base
    #define BASE1  12000000.0
    #define BASE2  46000000.0
    #define BASE3  88000000.0
    #define BASE4 150000000.0
    #define BASE5 300000000.0
    #define BASE6 500000000.0
    
    #define RATE1  (6.0 / 100.0)		// percent to rate
    #define RATE2 (15.0 / 100.0)
    #define RATE3 (24.0 / 100.0)
    #define RATE4 (35.0 / 100.0)
    #define RATE5 (38.0 / 100.0)
    #define RATE6 (40.0 / 100.0)
    #define RATE7 (42.0 / 100.0)
    
    #define BASIC_DEDUCTION 1500000.0
    ```
    
    처음에 이렇게 구간을 정의 해주고나서
    
    ```c
    income -= BASIC_DEDUCTION;
    
    	if (income <= BASE1)
    	{
    		tax = income * RATE1;
    	}
    	else if (income <= BASE2)
    	{
    		tax = BASE1 * RATE1 + (income - BASE1) * RATE2;
    	}
    	else if (income <= BASE3)
    	{
    		tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (income - BASE2) * RATE3;
    	}
    	else if (income <= BASE4)
    	{
    		tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3
    			+ (income - BASE3) * RATE4;
    	}
    	else if (income <= BASE5)
    	{
    		tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3
    			+ (BASE4 - BASE3) * RATE4 + (income - BASE4) * RATE5;
    	}
    	else if (income <= BASE6)
    	{
    		tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3
    			+ (BASE4 - BASE3) * RATE4 + (BASE5 - BASE4) * RATE5 + (income - BASE5) * RATE6;
    	}
    	else
    	{
    		tax = BASE1 * RATE1 + (BASE2 - BASE1) * RATE2 + (BASE3 - BASE2) * RATE3
    			+ (BASE4 - BASE3) * RATE4 + (BASE5 - BASE4) * RATE5 + (BASE6 - BASE5) * RATE6
    			+ (income - BASE6) * RATE7;
    	}
    ```
    
    이런식으로 구간별로 적용을 해주는데 참 헷갈린다. 
    
    구간 별로 조건 지정은 어렵지 않았지만 블록 안에 함수들이 점점 헷갈린다
    
- ### [7.5] else와 if 짝짓기
    
    if를 한번만 사용하면 else를 사용할 때 별로 문제가 될 일은 없다.
    
    하지만 if를 여러번 중복해서 사용하면 else를 어디붙이느냐에 따라 출력하는 값이 완전히 바뀔 수 있다.
    
    ```c
    if (number > 5)
    		if (number < 10)
    			printf("Lager than 5 smaller than 10\n");
    else
    		printf("Less than or equal to 5");
    ```
    
    이렇게 하면 else위치가 맨 앞의 if와 붙어서 출력하게 된다.
    
    만약에 헷갈린다면 명확하게 {블록}을 설정한다.
    
    ```c
    if (number > 5)
    	{
    		if (number < 10)
    			printf("Lager than 5 smaller than 10\n");
    		else
    			printf("Lager than 10\n");
    	}
    else
    		printf("Less than or equal to 5");
    ```
    
    이렇게 하면 입력하는 나도 보기 편하고 출력도 제대로 가능하다.
    
- ### [7.6] 소수 판단 예제
    
    숫자를 입력 받아서 입력 받은 숫자가 소수인지 아닌지를 판단하는 예제를 작성 해보았다.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <stdbool.h>
    
    int main()
    {
    	unsigned num, i;
    	bool isPrime = 0; // flag, try bool type
    
    	scanf("%u", &num);
    ```
    
    초기에 이렇게 설정해주고 숫자를 입력받는다
    
    ```c
    isPrime = 1;
    
    	for (i = 1; num > i; ++i)
    	{
    		if (num % i == 0)
    		{
    			isPrime = 0;
    		}
    	}
    
    if (isPrime)
    		printf("%u is a prime number.\n", num);
    	else
    		printf("%u is not a prime number.\n", num);
    ```
    
    if 와 for을 사용해서 소수인지 판단하는데 내가 입력한 코드는 오류가 난다.
    
    ```c
    isPrime = true;
    
    	for (i = 2; num > i; ++i)
    	{
    		if (num % i == 0)
    		{
    			isPrime = false;
    		}
    	}
    ```
    
    정답을 보고 비교해보니  i = 1인 것과 i = 2인 것의 차이가 있다. 초기에 설정하는 값도 중요하다. 
    
- ### [7.7] 논리 연산자
    
    논리 연산자에는 && , || , ! 가 있다.
    
    각각 and, or, not으로 사용할 수 있다.
    
    논리 연산자 and는 두 개의 조건 값이 true 이면 true를 출력하고, 한 쪽이라도 false이면 false을 출력 한다.
    
    or 연산자는 어느 한 쪽만 true면 true를 출력한다.
    
    not 연산자는 true면 반대로 false를 출력한다.
    
    ```c
    bool test1 = 3 > 2 || 5 > 6;	// true
    bool test2 = 3 > 2 && 5 > 6;	// false
    bool test3 = !(5 > 6);		    // true, equivalnet to 5 <= 6
    ```
    
    iso646 헤더를 사용하면 연산자를 and, or, not으로 바꿔 줄 수 있다.
    
    ```c
    #include <iso646.h>		// and, or, not
    
    bool test1 = 3 > 2 or 5 > 6;	// true
    bool test2 = 3 > 2 and 5 > 6;	// false
    bool test3 = not(5 > 6);		  // true, equivalnet to 5 <= 6
    ```
    
    if문 조건 안에 논리 연산자를 넣어줘서 여러 조건을 넣을 수 있다.
    
    ```c
    char ch;
    	int count = 0;
    	while ((ch = getchar()) != PERIOD)
    	{
    		//TODO : make exeptions
    		if (ch != '\n' && ch != ' ')
    			count++;
    	}
    printf("%d", count);
    ```
    
- ### [7.8] 단어 세기 예제
    
    이제까지 사용한 ctype.h, if문, bool을 사용해서 글자 수, 단어 개수, 문장 개수를 알아보는 예제이다.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <ctype.h>
    #include <stdbool.h>
    #define STOP '.'
    
    int main()
    {
    	char c;
    	int	 n_chars = 0; // number of non-space characters
    	int  n_lines = 0;
    	int	 n_words = 0;
    	bool word_flag = false;
    	bool line_flag = false;
    
    	printf("Enter test :\n");
    ```
    
    여기까지는 작성을 예시를 보여주었고, 나머지 부분만 작성해서
    
    ```c
    printf("Characters = %d, Words = %d, Lines = %d\n", n_chars, n_words, n_lines);
    ```
    
    이런식으로 출력을 한다. 힌트는 bool에 주어진 word_flag, line_flag를 활용하는 것이였다.
    
    내가 작성한 코드는
    
    ```c
    while ((c = getchar()) != STOP)
    	{
    		if (c != '\n' && c != ' ')
    		{
    			n_chars++;
    		}
    		
    		if (word_flag != (c == ' '))
    		{
    			n_words++;
    		}
    				
    		if (c != '\n' && !line_flag)
    		{
    			n_lines++;
    			line_flag = true;
    		}
    
    		if (c == '\n')
    			line_flag = false;
    	}
    ```
    
    이런 식으로 작성을 했다. 문장 개수를 찾는 부분에서 오류가 있었고, ctype.h를 활용하지 못해서 아쉬웠다.
    
    ```c
    if (!isspace(c))
    			n_chars++;
    				
    		if (!isspace(c) && !line_flag)
    		{
    			n_lines++;
    			line_flag = true;
    		}
    		if (c == '\n')
    		{
    			line_flag = false;
    		}
    		if (!isspace(c) && !word_flag)
    		{
    			n_words++;
    			word_flag = true;
    		}
    		if (isspace(c))
    			word_flag = false;
    ```
    
    이런식으로 구조 자체는 유사해보이지만, ctype.h 부분을 사용하면서 훨씬 간결해지고, 보기 쉽다.
    
    isspace는 공백 부분 뿐만 아니라 줄바꿈인 \n도 해당되기 때문에 조건값을 일일이 입력하는 것 보다 더 유용하다.
    
- ### [7.9] 조건 연산자
    
    삼항 연산자, 영어로는 ternary라고도 쓴다.
    
    ```c
    temp = true ? 1024 : 7;
    ```
    
    true 옆에 ?를 붙여서 true면 왼쪽에 있는 1024를 temp에 넣고, false가 왔다면 오른쪽에 있는 7을 temp에 넣는다.
    
    앞에서 입력해본 홀수 짝수를 찾는 예제를
    
    ```c
    int number;
    scanf("%d", &number);
    	
    	if (number % 2 == 0)
    		is_even = true;
    	else
    		is_even = false;
    
    if (is_even)
    		printf("Even");
    	else
    		printf("Odd");
    ```
    
    이렇게 사용 했다면
    
    ```c
    is_even = (number % 2 == 0) ? 1 : 0;
    ```
    
    홀/짝 판단을 한 줄로 바꿀 수 있고
    
    ```c
    (number % 2 == 0) ? printf("Even") : printf("Odd");
    ```
    
    최종적으로 한 줄로 바꿔서 홀/짝을 출력까지 하게 만들 수도 있다.
    
    다만 코드를 보았을때 직관적이진 않아서 잘 사용하지 않는다.
    
- ### [7.10] 루프 도우미 continue 와 break
    
    코드를 직관적으로 바꾸고 싶다면, continue 와 break을 사용한다
    
    continue는 조건 실행 중에 만난다면 제외하고 건너 뛰는 역할을 하고
    
    break는 조건을 탈출한다.
    
    ```c
    for (int i = 0; i < 10; ++i)
    	{
    		if (i == 5)
    			continue;
    
    		printf("%d ", i);
    
    		if (i != 5)
    			printf("%d ", i);
    	}
    ```
    
    여기서 사용된 continue를 출력하면  1 2 3 4 6 7 8 9 같이 5를 제외한 숫자가 출력 된다.
    
    ```c
    for (int i = 0; i < 10; ++i)
    	{
    		if (i == 5)
    			break;
    
    		printf("%d ", i);
    	}
    ```
    
    break를 사용하면 1~9까지 출력해야 되는 것을 1 2 3 4 까지만 출력 한다.
    
    ```c
    while (getchar() != '\n')
    		continue; //null statement
    ```
    
    이것과
    
    ```c
    while (getchar() != '\n')
    		; //null statement
    ```
    
    이것처럼 continue를 빼도 다른 것은 없으나 continue나 break를 넣어서 만드는 것이 직관적이라는 점에서 장점이다.
    
    마찬가지로 break 도
    
    ```c
    char c;
    	while ((c = getchar()) != '.')
    	{
    		putchar(c);
    	}
    ```
    
    이것을
    
    ```c
    while (1)
    	{
    		char c = getchar();
    
    		if (c == '.')
    			break;
    
    		putchar(c);
    	}
    ```
    
    이렇게 쓸 수 있다. 어떤 것을 사용해도 상관은 없으나 밑에 문장이 길어지긴 하지만 더 직관적으로 보이기도 한다.
    
- ### [7.11] 최대, 최소, 평균 구하기 예제
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <float.h>
    
    int main()
    {
    	float max = -FLT_MAX;
    	float min = FLT_MAX;
    	float sum = 0.0f;
    	float input;
    	int n = 0;
    
    	while (scanf("%f", &input) == 1)
    	{
    		if (input < 0.0f || input > 100.0f)
    			continue;
    
    		//TODO: ignore negative values
    
    		/*
    		if (input > max)
    			max = input;
    		if (input < min)
    			min = input;
    		*/
    
    		max = (input > max) ? input : max;
    		min = (input < min) ? input : min;
    		sum += input;
    		
    		n++; // Count number of inputs
    	}
    
    	if (n > 0)
    		printf("min = %f, max = %f, ave = %f\n", min, max, sum / n);
    	else
    		printf("No input\n");
    
    	return 0;
    }
    ```
    
    최대 최소 구하기 예제이다.
    
    ```c
    if (input > max)
    			max = input;
    if (input < min)
    			min = input;
    ```
    
    if 를 사용해서 최대,최소 값을 구성할 수도 있고
    
    ```c
    max = (input > max) ? input : max;
    min = (input < min) ? input : min;
    ```
    
    삼항 연산자를 사용할 수도 있다.
    

- ### [7.12] 다중 선택 switch 와 break
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
    	int c = 0;
    
    	while ((c = getchar()) != '.')
    	{
    		printf("You love ");
    
    		switch (c)	//Note: integer types only
    		{
    		case 'a':
    			printf("apple");
    			break;
    		case 'b':
    			printf("baseball");
    			break;
    		case 'c':
    			printf("cake");
    			break;
    		default:
    			printf("nothing");
    		}
    
    		printf(".\n");
    
    		while (getchar() != '\n')
    			continue;
    	}
    
    	return 0;
    }
    ```
    
    마지막으로 볼 것은 switch 인데 만약에 a를 입력했다면
    
    case 'a'; 밑에 입력해놓은 단어 "apple"이 You love 와 합쳐져 You love apple를 출력한다.  
    
    여기서 break가 없다면 입력한 단어들에 들어가는 모든 단어를 출력해버린다.

</br>
    
## Chapter 8. 문자 입출력과 입력 유효성 검증

- ### [8.1] 입출력 버퍼
    
    앞에서 배운 getchar(), putchar() 함수들은 버퍼에서 임시로 받아 놓은 값을
    
    출력하기 때문에 while문과 사용하면 여러 문자를 출력할 수 있었다.
    
    ![img_c_buffer_vs_nobuffer_(1)](https://user-images.githubusercontent.com/96982072/149668431-6181d04a-d2e4-4407-a460-f433407a7441.png)
    
    [출처] [http://www.tcpschool.com/c/c_io_console](http://www.tcpschool.com/c/c_io_console)
    
    버퍼는 버스와 같다고 생각하면 된다. 버퍼를 사용하지 않는 함수도 존재한다
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <conio.h> //Windows, _getch(), _getche()
    
    int main()
    {
    	char c;
    
    	while ((c = _getche()) != '.')//echo : no buffer
    		putchar(c);
    
    	return 0;
    }
    ```
    
    _getch(), _getche() 함수는 버퍼를 사용하지 않는다. 그래서 한 글자만 받는다고 할 수 있겠다.
    
    _getche()를 사용해서 a b c를 순서대로 입력하면 aabbcc처럼 출력된다.
    
- ### [8.2] 파일의 끝
    
    문자를 입력받을 때 
    
    ```c
    while ((c = getchar()) != '.') 
    	putchar(c);	   			  
    ```
    
    마침표를 사용하거나 엔터를 입력하면 함수가 종료되는 식으로 사용을 해왔었는데
    
    EOF를 이용하여 종료 시킬 수도 있다. 기본적으로 ASCII 코드도 인수를 받는데
    
    아스키 코드 표를 보면 음수가 없는 것을 알 수  있다.
    
    ```c
    while ((c = getchar()) != EOF) // End Of File
    		putchar(c);	   			  // EOF = (-1) ASCII END
    ```
    
    이렇게 사용해서 변수 c에 -1을 넣어서 종료 시키는 것과 같다
    
    실행을 시켜서 문자를 입력하다가 ctrl + Z키를 누르면 프로그램이 종료한다.
    
    ```c
    while (1)
    	{
    		c = getchar();
    		printf("%d\n", c);
    		if (c == EOF)
    			break;
    	}
    ```
    
    이런 식으로 사용하는 것을 스트림이라고 한다.
    

- ### [8.3] 입출력 방향 재지정
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
    	//printf("I love apple.\n");
    
    	char str[100];
    	scanf("%s", str);
    	printf("I love %s\n", str);
    
    	return 0;
    ```
    
    콘솔창을 통해서 자기가 직접 입력을 하는 방법도 있겠지만
    
    명령프롬프트에서 출력한 내용의 txt파일을 만들거나, 읽어오게 시킬 수도 있다.
    
    cmd창에서 프로그램을 작성한 .exe 실행 파일이 있는 곳으로 이동한다
    
    CH08_03.exe > output.txt 를 입력하면
    
    ```c
    printf("I love apple.\n")
    ```
    
    출력하라고 했던 I love apple를 txt파일로 만들 수 있다.
    
    ![이미지_047](https://user-images.githubusercontent.com/96982072/149668436-7d8abd5c-a0bf-4c54-a704-a23a32381fc5.png)
    
    반대로 해당폴더에서 Melon이라는 글자를 input.txt로 만들고
    
    ```c
    char str[100];
    
    scanf("%s", str);
    printf("I love %s\n", str);
    ```
    
    이렇게 작성한 프로그램에
    
    CH08_03.exe < input.txt 식으로 입력하면 
    
    ![이미지_049](https://user-images.githubusercontent.com/96982072/149668438-c3c000d6-61a0-4103-9472-02e783cf9db4.png)
    
    I love Melon이 출력되는 것을 알 수 있다.
    
    아까 입력한 Melon을 CH08_03.exe < input.txt > output.txt 로 입력하면?
    
    입력과 출력을 동시에 할 수 있다.
    
    ![이미지_050](https://user-images.githubusercontent.com/96982072/149668440-5c7010f5-21c3-4967-adde-87826821c028.png)
    
    추가로 CH08_03.exe >> output.txt로 >를 두 번 입력하면
    
    ![이미지_051](https://user-images.githubusercontent.com/96982072/149668443-3c314524-7290-4571-945e-84a594cdc39d.png)
    
    이렇게 txt파일에는 저번에 출력을 요청 했던 것과 추가로 한 줄이 출력된다.
    
- ### [8.4] 사용자 인터페이스는 친절하게
    
    프로그램을 작성할 때에는 사용자는 예측할 수 없는 방법으로 다양하게 사용할 수 있다.
    
    그래서 프로그램이 목표하는 것 이외의 입력이 있을 수 있다.
    
    모든 가능성을 생각하고 작성해 볼 필요가 있다.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
    	int count = 0;
    
    	while (1)
    	{
    		printf("Current count is %d. Continue? (y/n)\n", count);
    
    		int c = getchar();
    
    		if (c == 'n')
    			break;
    		else if (c == 'y')
    			count++;
    		else
    			printf("Please input y or n\n");
    		
    		while (getchar() != '\n')
    			continue;
    	
    	}
    	return 0;
    }
    ```
    
    간단하게 y를 입력하면 1을 올리고 n을 입력하면 종료하는 프로그램이 있다고 하자.
    
    여기 작성된 코드에는 y를 입력하던 yes를 입력하던 
    
    어쨌든 첫 문자로 y를 받기 때문에 문제가 없다. 
    
    그러나 막상 처음 보는 사용자는
    
    what이나 여러가지 문자를 입력할 수 있기 때문에 y나 n 이외의 것을 입력하면 
    
    다시 y나 n을 입력하라고 안내를 해주는 코드를 작성 하는 것이 좋다.
    
- ### [8.5] 숫자와 문자 섞어서 입력받기
    
    문자 한 개와 숫자 두 개를 입력 받아서  숫자 두 개가 행렬이 되어
    
    행렬만큼 문자를 출력하는 식을 만드는 예제이다.
    
    ```c
    while (1)
    	{
    		scanf("%c %d %d", &c, &rows, &cols);
    		while (getchar() != '\n') continue;
    		display(c, rows, cols);
    		if (c == '\n')
    			break;
    	}
    ```
    
    여기서 행렬 부분을 main파트에 작성하면 길어질 수 있으므로 
    
    따로 display라는 함수로 정의를 해주면
    
    ```c
    void display(char cr, int lines, int width)
    {
    	int row, col;
    
    	for (row = 1; row <= lines; row++)
    	{
    		for (col = 1; col <= width; col++)
    			putchar(cr);
    		putchar('\n');
    	}
    }
    ```
    
    이렇게 행렬 부분을 만들 수 있다.
    
    또 한 scanf에서 문자 숫자 숫자를 다 받다가 특수문자를 입력하면 오류가 발생한다.
    
    그리고 여러번 입출력을 하고 싶고,
    
    아무것도 입력하지 않고 엔터만 입력하면 종료를 시키고 싶을 때 
    
    ```c
    printf("Input one character and tow integers:\n");
    	while ((c = getchar()) != '\n')
    	{
    		scanf("%d %d", &rows, &cols);
    		while (getchar() != '\n') continue;
    
    		display(c, rows, cols);
    		printf("Input another character and two integers:\n");
    		printf("Press Enter to quit.\n");
    
    	}
    ```
    
    이런식으로 while문 getchar로 반복 입력할 수 있다.
    
- ### [8.6] 입력 확인하기
    
    조금 더 나아가서 정수를 입력하고 그 수가 유효하면 맞다고 
    
    출력하고 그 중에서도 범위를 설정해서 범위 안의 숫자가 아니면 다시 입력하게 하는
    
    예제를 보았다
    
    ```c
    int main()
    {
    	long number;
    
    	while (1)
    	{
    		printf("Please input an integer between 1 and 100.\n");
    		number = get_long();
    
    		if (number > 1 && number < 100)
    		{
    			printf("OK. Thank you.\n");
    			break;
    		}
    		else
    			printf("wrong input. Please try again\n");
    	}
    
    	printf("Your input %d is between 1 and 100. Thank you\n", number);
    
    	return 0;
    }
    ```
    
    먼저 main()안의 함수는 이렇다. 여기서 빠진 것은 정수를 입력하게 하는 방법인데
    
    main안에서 모두 입력하면 너무 길어지므로 새로 get_long을 만들어서 함수를 선언한다
    
    ```c
    long get_long(void)
    {
    	printf("Please input an integer and press enter.\n");
    
    	long input;
    	char c;
    
    	while (scanf("%ld", &input) != 1)
    	{
    		printf("Your input -");
    
    		while ((c = getchar()) != '\n')
    			putchar(c); // input left in buffer
    
    		printf(" - is not an integer. Please try again.\n");
    	}
    
    	printf("Your input %ld is an integer. Thank you.\n", input);
    
    	return input;
    }
    ```
    
    이렇게 입력하면 정수를 받는 함수파트가 만들어지고 위의 main함수에서는 
    
    정수 범위만 설정해 줄 수 있다.
    
    정수가 아닌 것을 입력하면
    
    ![이미지_052](https://user-images.githubusercontent.com/96982072/149668447-5bd4fb61-c26b-485c-bb86-9ee21758f9c9.png)
    
    다시 입력을 받는다.
    
- ### [8.7] 입력 스트림과 숫자
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    
    int main()
    {
    	/*
    		Assume that your input is :
    		Hello 123 3.14
    	*/
    
    	char str[255];
    	int i, i2;
    	double d;
    
    	scanf("%s %d %lf", str, &i, &d);
    	printf("%s %d %f\n", str, i, d);
    
    	// or (see the difference)
    
    	scanf("%s %d %d", str, &i, &i2);
    	printf("%s %d %d\n", str, i, i2);
    
    	// or (see the difference)
    
    	char c;
    	while ((c = getchar()) != '\n')
    		putchar(c);
    	printf("\n");
    
    	return 0;
    }
    ```
    
    각각 scanf에서 Hello 123 3.14를 입력하면 어떤 결과를 가져오는지 확인하는 예제이다.
    
    ```c
    scanf("%s %d %lf", str, &i, &d);
    printf("%s %d %f\n", str, i, d);
    ```
    
    첫 번째 scanf에서 Hello 123 3.14를 입력하면 같은 값이 출력된다
    
    ```c
    scanf("%s %d %d", str, &i, &i2);
    printf("%s %d %d\n", str, i, i2);
    ```
    
    두 번째 i2인 정수를 입력받는 scanf에서 Hello 123 3.14를 입력하면
    
    Hello 123 3까지만 출력하고 나머지 .14는 다음 줄로 출력한다
    
    여기서 i2에서 정수로 받은 3은 출력하지만 소수자리인 .14는 버려지는 것이 아니라
    
    버퍼에 남겨둔다.
    
    그리고 str에서는 문자를 스트림 하지만 컴퓨터에서는 결국 2진수로 된 데이터를 받게 된다
    
- ### [8.8] 메뉴 만들기 예제
    
    ![이미지_053](https://user-images.githubusercontent.com/96982072/149668449-e899acc5-3cfa-4e6e-985a-39221599a4f7.png)
    
    이렇게 메뉴를 만들고 메뉴에 맞는 단축키를 입력하면 반응하는 예제를 작성 해보았다
    
    ```c
    int user_choice;
    
    	while ((user_choice = get_choice()) != 'q')
    	{
    		switch (user_choice)
    		{
    		case 'a':
    			printf("Avengers assemble!\n");
    			break;
    		case 'b':
    			putchar("/a"); //Beep
    			break;
    		case 'c':
    			count();
    			break;
    		default :
    			printf("Error with %d.\n", user_choice);
    			exit(1);
    			break;
    		}
    	}
    ```
    
    메인 함수 부분은 이렇게 작성되었다. 조금 어렵고 헷갈려서 따라치는 수준에 그쳤다.
    
    조금만 시간을 들여서 고민했으면 어느정도 해볼 수 있었을 거란 생각도 해본다.
    
    따로 만들어야 하는 함수 블럭이 4개정도 되었는데 메뉴 선택하는 부분은 손도 못댔다.
    
    ```c
    void count(void)
    {
    	int n, i;
    
    	printf("Enter an integer:\n");
    	n = get_integer();
    	for (i = 1; i <= n; ++i)
    		printf("%d\n", i);
    	while (getchar() != '\n')
    		continue;
    
    }
    ```
    
    c를 선택하면 1씩 올라가서 출력해주는 함수 부분이다. 
    
    ```c
    int get_integer(void)
    {
    	int input;
    	char c;
    
    	while (scanf("%d", &input) != 1)
    	{
    		while ((c = getchar()) != '\n')
    			putchar(c);
    		printf(" is not an integer.\nPlease try again.");
    	}
    
    	return input;
    }
    ```
    
    get_integer부분을 따로 함수를 만들어 주어서 정수가 아니면 다시 입력하게 만들 수 있다.
    
    ```c
    char get_choice(void)
    {
    	int user_input;
    
    	printf("Enter the letter of your choice:\n");
    	printf("a. avengers\tb. beep\n");
    	printf("c. count\tq. quit\n");
    
    	user_input = get_first_char();
    
    	while ((user_input < 'a' || user_input > 'c') && user_input != 'q')
    	{
    		printf("Please try again.\n");
    		user_input = get_first_char();
    	}
    
    	return user_input;
    }
    ```
    
    프로그램을 실행시켰을 때 맨처음에 나오는 메뉴선택 부분이다
    
    /t 을 써서 줄 맞춤을 해줄 수 있다.
    
    abc이외의 값을 입력하면 다시 입력하라는 부분도 볼 수 있다.
    
    ```c
    char get_first_char(void)
    {
    	int ch;
    
    	ch = getchar();
    	while (getchar() != '\n')
    		continue;
    
    	return ch;
    
    }
    ```
    
    입력된 값 이외의 버퍼를 없애주는 부분도 따로 만들어 주었다.

</br>

## Chapter 9. 함수

- ### [9.1]함수가 필요할 때
    
    캡쳐한 것과 같이 이름과 밑에 지역이 나오는 예제를 작성 해보았다.
    
    ![이미지 054](https://user-images.githubusercontent.com/96982072/150098401-609c6f55-8ab6-407b-8f4e-fbdee3daae22.png)
    
    이렇게 작성하기 위해 가장 쉬운 방법은
    
    ```c
    printf("********************\n");
    printf("    YEON KYU CHU\n");
    printf("    Yong-In, Korea\n");
    printf("********************\n");
    ```
    
    이렇게 작성하는 것이다. 하지만 이렇게 작성하는 것은 후에
    
    별의 갯수를 늘리거나 줄이는 것과 같이 유지 보수를 하기에는 쉽지 않다.
    
    그러므로 같은 기능을 여러번 반복하는 것은 함수로 만들고, 가변적으로 만들어서
    
    쉽게 작동할 수 있게 개선하는 것이 좋다.
    
    ```c
    void star(void);
    int main()
    {
    	star();
    	printf("   YEON KYU CHU \n");
    	printf("   Yong-In, Korea \n");
    	star();
    	return 0;
    }
    
    void star(void)
    {
    	int i = 0;
    	for (i = 0; i < 20; ++i)
    		printf("*");
    	printf("\n");
    	return 0;
    }
    ```
    
    처음 예제를 봤을 때 예상했던 작성법이다.
    
    별 정도는 함수로 만들었지만, 여전히 유지 보수는 쉽지 않다.
    
    작동을 하기 쉽게 하기 위해
    
    고려 해야 할 사항
    
    - 별의 개수를 바꿀 수 있게 요청할 수 있음
    - 주소가 바뀔 수도 있음
    - 별도 위아래로 두번이상 나오므로 함수로
        
        묶는게 나중에 수정하기 편함
        
    
    ```c
    #define WIDTH 30
    #define NAME "YEON KYU CHU"
    #define ADDRESS "Yong-In, Korea"
    
    void print_multiple_chars(char c, int n_stars, bool end1)
    {
    	for (int i = 0; i < n_stars; ++i)
    		printf("%c",c); // puthcar(c)
    
    	if (end1 == true)
    		printf("\n");
    }
    
    void print_centered_str(char str[])
    {
    	int n_blanks = 0;
    
    	n_blanks = (WIDTH - strlen(str)) / 2;
    	print_multiple_chars(' ', n_blanks, false);
    	printf("%s\n", str);
    }
    
    int main()
    {
    	print_multiple_chars('*', WIDTH, true);
    		
    	print_centered_str(NAME);
    	print_centered_str(ADDRESS);
    		
    	print_multiple_chars('*', WIDTH, false);
    
    	return 0;
    }
    ```
    
    이름에 사용되는 함수도 후에 바꿀 수 있게 NAME으로 정의하고 주소도 정의한다.
    
    별의 개수도 쉽게 바꿀 수 있게 맨위에 WIDTH로 정의 한다.
    
    함수 길이는 길어 보이지만 유지 보수는 쉽게 할 수 있다.
    
    프로그램을 작성할 때 생각해봐야 할 것은
    
    - 더 일반적으로 작동하려면 어떻게 해야하는가.
    - 장기적으로 유지보수가 쉬우려면 어떻게해야하는가

- ### [9.2] 함수의 프로토타입
    
    앞 선 9.1에서 배운 명함을 출력하는 예제에서는 
    
    함수를 위에서 선언하고 작성했었다. 
    
    하지만 진짜 동작하는 프로그램은 main함수에서 작성되기 때문에
    
    이를 확인하려면 main까지 왔다갔다 해야하는 번거로움이 생긴다.
    
    번거로움을 없애기 위해 한페이지에서 작성하려면 프로토타입을 선언해준다
    
    이 것을 블랙 박스로서의 함수라고 부른다.
    
    블랙 박스로서의 함수는
    
    직접 작성하는 것을 예외로 다른 라이브러리의 함수를 보았을 때,
    
    어떻게 작동하는지 외울 필요 없고 뭐가 들어가고 나오는가 즉 재조립을 잘 해야 한다.
    
    입력이 뭐고 출력이 뭔지 알지만 내부에서 어떻게 작동하는지는 모르더라도
    
    일단 무엇을 출력할지 함수로 선언하고 내부를 채워 나가는 식의 함수 디자인을 뜻한다.
    
    ```c
    void print_multiple_chars(char c, int n_stars, bool end1); // prototype
    void print_centered_str(char str[]);
    
    int main()
    {
    	print_multiple_chars('*', WIDTH, true); // argument
    
    	print_centered_str(NAME);
    	print_centered_str(ADDRESS);
    
    	print_multiple_chars('*', WIDTH, false);
    
    	return 0;
    }
    
    void print_multiple_chars(char c, int n_stars, bool end1)
    {
    	for (int i = 0; i < n_stars; ++i)
    		printf("%c", c); // puthcar(c)
    
    	if (end1 == true)
    		printf("\n");
    }
    
    void print_centered_str(char str[])
    {
    	int n_blanks = 0;
    
    	n_blanks = (WIDTH - strlen(str)) / 2;
    	print_multiple_chars(' ', n_blanks, false);
    	printf("%s\n", str);
    }
    ```
    
    프로토타입을 선언 하면
    
    몸체가 없어도 일단 컴파일은 가능 하다
    
    그러나 함수의 몸체가 없어서 링크 에러가 뜬다.
    
    c언어는 컴파일 과 링커는 분리되어 작동하기 때문에
    
    함수의 몸체는 어디서든 있어도 실행 가능하다.
    
    ```c
    void print_multiple_chars(char c, int n_stars, bool end1); //parameter
    ```
    
    이와 같이 작성된 함수에서 괄호 안에 char c, int n_stars 같이 들어오는 값에 따라 변하는 변수를
    
    매개변수라고 부른다.
    
    프로토타입을 선언할 때
    
    ```c
    void print_multiple_chars();
    ```
    
    매개변수가 있음에도 빈칸으로 선언해도 빌드가 되는 것을 알 수 있다.
    
    ```c
    void print_multiple_chars(char, int, bool);
    ```
    
    또한 변수 이름이 없어도 빌드가 되는 것을 알 수 있다.
    
    하지만 프로토 타입과 함수의 몸체를 맞추는 것이 혼란을 줄일 수 있어서 
    
    매개변수까지 입력하는 것을 권장한다.
    
- ### [9.3] 함수의 자료형과 반환 값
    - 정수형(int) 반환 자료형은 int 생략 가능

- ### [9.4] 변수의 영역과 지역 변수
    
    
    변수에도 사용할 수 있는 영역(scope)이 존재한다.
    
    위에서 선언한 함수에 있는 변수를 메인에서도 사용가능할까?
    
    ```c
    int main()
    {
    	int a;
    	
    	a = int_max(1, 2);
    
    	printf("%d\n", a);
    	printf("%p\n", &a);
    ```
    
    불가능, 따로 정의된 함수 안에 있는 변수는 그 함수 바디 안에서만 유효함
    
    여기서 사용한 변수 a는
    
    ```c
    int int_max(int i, int j)
    {
    	//a = 456;
    	int m;
    	m = i > j ? i : j;
    	return m;
    }
    ```
    
    여기서 다른 함수영역에서 사용하지 못한다.
    
    특정 함수의 스코프 안에서만 사용 가능한 변수를 지역 변수라고 부른다
    
    지역 변수는 메인 함수에서는 사용 불가능
    
    ```c
    int main()
    {
    	int a;
    	
    	a = int_max(1, 2);
    
    	printf("%d\n", a);
    	printf("%p\n", &a);
    
    	{
    		int a;
    		a = int_max(4, 5);
    
    		printf("%d\n", a);
    		printf("%p\n", &a);
    
    		int b = 123;
    
    	}
    
    	printf("%d\n", a);
    	printf("%p\n", &a);
    
    	return 0;
    }
    ```
    
    영역 안에 다른 영역에서 선언된 함수는 전혀 다르다
    
    메인함수 제일 위에 선언 된 int a와
    
    중괄호 안의 int a 는 이름은 같지만 다른 변수다.
    
- ### [9.5] 지역 변수와 스택
    
    9.4에 작성했던 코드를 통해
    
    입력된 변수의 메모리에 쌓는다 메인 함수에서 int a가 선언되고
    
    int_max함수에서 선언된  int m이 그 위에 쌓이게 된다 여기서 변수a가 밑에 쌓여있지만
    
    직접 접근할 수 있느냐고 물어볼 수 있는데 포인터를 이용해서 사용할 수 있다.
    
    같은 알파벳으로 선언된 변수라도 주소가 다르면 다른 변수처럼 사용할 수 있다.
    

- ### [9.6~7] recursion 재귀 호출
    
    ```c
    void my_func(int);
    
    int main()
    {
    	my_func(1);
    
    	return 0;
    }
    
    void my_func(int n)
    {
    	printf("Level %d, address of variable n = %p\n", n, &n);
    
    	if(n <= 4)
    		my_func(n + 1);
    
    	//printf("Level %d, address of variable n = %p\n", n, &n);
    }
    ```
    
    재귀 호출 예제이다.
    
    만약에 my_func함수에서 탈출조건인 if문이 없었다면
    
    메모리가 꽉 찰 때까지 스택이 쌓이고 모두 차면 stack overflow 메시지를 출력하고 종료한다
    
    재귀 호출은 무한루프를 실행할 때 사용하는 함수가 아니다.
    
    재귀 호출은 탈출하기 위한 stop condition이 있어야한다.
    
    재귀 호출은 함수를 끝내기전에 다시 돌아오는 것을 볼 수 있는데
    
    영화 인셉션과 비슷하다고 생각하면 된다. 
    
    쌓여있던 스택을 하나씩 빼는 것으로도 볼 수 있다.
    
    즉 1 2 3 순으로 메모리를 쌓았다가 다시 3 2 1 순으로 나가는 것을 디버그를 통해 알 수 있다.
    
- ### [9.8] 팩토리얼 예제
    
    ```c
    loop vs recursion
    	factorial : 3! = 3 * 2 * 1, 0! = 1
    	5! = 5 * 4! = 5 * 4 * 3! = 5 * 4 * 3 * 2! = 5 * 4 * 3 * 2 * 1! = 5 * 4 * 3 * 2 * 1 * 0!
    ```
    
    팩토리얼의 매커니즘이다.
    
    반복문으로 작성하는 방법과 재귀 호출을 통해서 작성 할 수 있다.
    
    반복문으로 작성할 때에는
    
    ```c
    long loop_factorial(int n)
    {
    	long i;
    
    	for (i = 1; n > 1; n--)
    		i *= n;
    
    	return i;
    }
    ```
    
    이렇게 나타낼 수 있고
    
    ```c
    long recursive_factorial(int n)
    {
    	if (n > 0)
    	{
    		//my code
    		//n *= recursive_factorial(n - 1); 
    		return n * recursive_factorial(n - 1); // tail (end) recursion
    	}
    	else
    		return 1;
    ```
    
    재귀로 나타낼 때에는 return을 이용해서 나타낼 수 있다.
    
- ### [9.9] 이진수 변환 예제
    
    다음은 10진수를 이진수로 변환할때 사용하는 방법을 C언어로 작성하는 예제이다.
    
    이 예제 또한 재귀와 반복문으로 작성할 수 있다.
    
    ```c
    10
    	10 / 2 = 5, remainder = 0
    	5 / 2 = 2, remainder = 1
    	2 / 2 = 1, remainder = 0
    	1 / 2 = 0, remainder = 1
    ```
    
    이런식으로 10을 2진수로 표현하면 0101의 거꾸로인 1010으로 나타낼 수 있다.
    
    하지만 현재까지 배운걸로는 반복문을 사용해서는 0101을 거꾸로 꺼낼 방법은 없다.
    
    그래서 0101을 표현하는 식으로 반복문으로 작성하면
    
    ```c
    void print_binary_loop(unsigned long n)
    {
    	while (1)
    	{
    		int quotient = n / 2;
    		int remainder = n % 2;
    
    		printf("%d", remainder); // remainder is 0 or 1
    
    		n = quotient;
    
    		if (n == 0) break;
    	}
    
    	printf("\n");
    }
    ```
    
    이렇게 작성하면 0101이 나온다.
    
    재귀를 사용하면 1010으로 나타낼 수 있다.
    
    ```c
    void print_binary(unsigned long n)
    {
    	int remainder = n % 2;
    
    	if (n >= 2)
    		print_binary(n / 2);
    
    	printf("%d", remainder);
    
    	return;
    }
    ```
    
    그렇다면 거꾸로 출력해야하는 문제는 무조건 재귀호출을 사용해야하는가?
    
    아니다 뒤에 부분에서 배열을 사용하면 반복문도 거꾸로 출력하는 것도 가능하다
    
- ### [9.10] 피보나치 예제
    
    ```c
    Finonacci sequence
    	1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ...
    	ex) fibonacci(5) = 3 + 2 = fibonacci(4) + fibonacci(3)
    ```
    
    피보나치 수열을 나타낸 예제이다. 5번째 수의 값은 1번째 전의 값과 2번째 전의 값을 더한 값으로 표현할 수 있다.
    
    이 것은 재귀 호출로 간결하게 작성할 수있다.
    
    ```c
    int fibonacci(int number)
    {
    
    	if (number > 2)
    		return fibonacci(number - 1) + fibonacci(number - 2); // double recursion
    	else
    		return 1;
    }
    ```
    
    이렇게 간단하게 작성할 수 있지만, 메모리를 비효율적으로 사용하게 되고
    
    뒤로 갈수록 중복으로 호출하는 계산이 늘어나기 때문에 눈으로 보기엔 간결하지만
    
    컴퓨터는 고생을 한다.
    
     
    
- ### [9.11] 헤더 파일 만드는 방법
    
    초반 강의에는 위에 프로토타입을 선언하고 메인 밑에 함수를 작성하는 식으로 했지만
    
    후반에는 여러 개의 헤더 파일을 만들어서 반복 사용하는 것을 권장한다
    
    헤더 파일을 만들고 싶은 프로젝트 오른쪽 클릭 → 추가 → 새 항목
    
    헤더 파일은 프로토타입처럼 차례이자 목록 역할을 한다
    
    ```c
    #pragma once
    
    void print_hello();
    void print_hi();
    void print_str(char* str);
    
    // assume that we have many more longer functions
    ```
    
    헤더에는 이렇게 작성을 해두면
    
    다른 소스파일에서는 프로토타입 선언을 안해도 전부 작성해둔 함수를 사용할 수 있다
    
- ### [9.12~13] 포인터의 작동 원리
    
    변수는 메모리의 주소를 받아서 거기에 받은 값을 저장하는 방식
    
    그렇다면 메모리의 주소는 어떻게 알 수 있을까?
    
    ```c
    int *a_ptr = &a;
    ```
    
    a앞에 있는 주소 연산자 &은 단항 연산자로 주소값을 가져올 수 있다.
    
    int 뒤에 *이 붙으면 int형 변수의 주소를 저장하는 변수가 된다.
    
    포인터 변수에 저장되어 있는 값은 다른 변수의 주소이다.
    
    직접적으로 데이터를 저장하기 보다는 다른 메모리 공간이나 그 공간에 저장되어 있는
    
    데이터를 간접적으로 가리키는 역할을 한다.
    
    ```c
    *a_ptr = 8;
    ```
    
    a_ptr은 a의 주소값이 저장되어 있기 때문에 8을 대입하면
    
    a 에 8을 넣는 것과 같이 작동한다
    
    하지만 완전 같진 않아서 간접 접근, 역참조, 방향 재지정이라 부른다.
    
    포인터는 또한 컴파일러와 작성 스타일에 따라 형식이 조금 다른데
    
    ```c
    int* a_ptr;
    ```
    
    이처럼 int 바로 뒤에 *이 붙을 수 있다.
    
    ```c
    int* a_ptr, b_ptr;
    ```
    
    하지만 이렇게 int 뒤에 *이 붙는다고해서 b_ptr까지 포인터로 선언되는 것은 아니다
    
    여기서는 a_ptr만 포인터이고 b_ptr은 그냥 정수형 변수이다.
    
    b_ptr까지 포인터로 선언되려면 *b_ptr처럼 둘다 *이 붙어야 한다.
    
- ### [9.14~16] NULL 포인터와 런타임 에러
    
    포인터 변수를 선언하고 초기화를 하지 않으면 쓰레기 값이 주소로 들어가서 초기화를 안했다는 메세지 발생한다.
    
    ```c
    int *ptr = 1234;
    ```
    
    하지만 포인터를 선언한 뒤 바로 어떤 값을 넣어주면, 주소 자체를 1234로 지정하는 것이기 때문에 런타임 에러 발생
    
    컴퓨터는 메모리의 주소를 랜덤으로 작성하는 것이기 때문에 이처럼 포인터의 주소에 값을 직접 대입하는 것은
    
    런타임 에러를 부른다.
    
    그렇다면 포인터를 초기화 하기 위해서는 NULL 포인터를 사용한다
    
    ```c
    int* safer_ptr = NULL;
    ```
    
    이처럼 NULL값을 넣어주면 포인터는 초기화 되고 후에 주소연산자 &을 넣으면 대입 가능해진다.
    

- ### [9.17] 포인터 변수의 크기
    
    ```c
    	char a;
    	float b;
    	double c;
    
    	char* ptr_a = &a;
    	float* ptr_b = &b;
    	double* ptr_c = &c;
    
    	printf("%zd %zd %zd \n", sizeof(a), sizeof(b), sizeof(c));
    	printf("%zd %zd %zd \n", sizeof(ptr_a), sizeof(ptr_b), sizeof(ptr_c));
    	printf("%zd %zd %zd \n", sizeof(&a), sizeof(&b), sizeof(&c));
    	printf("%zd %zd %zd \n", sizeof(char*), sizeof(float*), sizeof(double*));
    ```
    
    그렇다면 포인터 변수의 크기는 어떻게 나올까?
    
    다음을 출력해보면
    
    첫번째줄의 a b c는 각각 char, float, double 이므로 1 4 8 byte로 출력된다.
    
    각각의 주소 들의 크기는 x86으로 출력했을 때 전부 4byte로 출력된다
    
    x86은 32bit이고 32bit는 4byte로 보았을 때
    
    x86이나 x64는 메모리의 크기를 나타내는 것을 알 수 있다.
    

- ### [9.18] 포인터형 매개변수
    
    다음은 선언된 변수를 swap하여 입력 값과 출력 값을 바꾸는 예제이다.
    
    ```c
    void swap(int *u, int *v)
    {
    	int temp = *u;
    	*u = *v;
    	*v = temp;
    }
    
    int main()
    {
    	int a = 123;
    	int b = 456;
    
    	printf("%p %p\n", &a, &b);
    
    	swap(&a, &b);
    
    	printf("%d %d\n", a, b);
    
    	return 0;
    }
    ```
    
    다음과 같이 포인터를 선언하고 
    
    주소 값을 바꾸면 쉽게 처음 선언된 값과 바꿀 수 있다.

    </br>

## Chapter 10. 배열과 포인터

- ### [10.1] 배열과 메모리
    
    
    만약에 월 별 최고 기온과 최저 기온을 변수를 선언해서 입력한다고 했을 때 일일이 손으로 입력이 가능한가?
    
    12월까지 변수를 12번 선언하기에는 힘들 것이다.
    
    쉬운 방법은 배열을 사용하는 것이다
    
    ```c
    /* Monthly temperatures */
    int high[12] = {2, 5, 11, 18, 23, 26, 29, 30, 26, 20, 12, 6}; 
    int low[12] = {-7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5};
    ```
    
    선언된 배열 안에 데이터를 모두 집어넣을 수 있다.
    
    &arr[0] 과 &arr[1]의 주소 차이는 얼마나 될까?
    
    선언된 자료형의 크기 만큼의 주소 차이를 보여준다.
    
    int로 선언된 자료형의 경우 arr[0] 과 arr[1]의 차이는 4byte만큼 메모리 주소 차이가 난다
    
    배열이 선언되면서 배열 개수 만큼의 연속적인 주소가 할당 되므로
    
    배열과 다음 배열 사이는 선언된 자료형 크기 만큼의 차이를 보이는 것이다.
    
- ### [10.2] 배열의 기본적인 사용 방법
    
    ```c
    high[12] = {...};
    
    high[12] = 4; //Error
    high[-1] = 123; //Error
    ```
    
    배열의 무서운 점은 컴파일에서 에러를 잡아주지 않는다
    
    ```c
    const int low[12] = {-7, -5, 1, 7, 13, 18, 22, 22, 16, 9, 2, -5};
    low[0] = 123;
    ```
    
    const를 선언하면 배열의 값을 바꿀 수 없다.
    
    ```c
    int not_init[4];
    for (int i = 0; i < 4; ++i)
    	printf("%d\n", not_init[i]);
    ```
    
    배열을 초기화 하지 않으면 의미 없는 주소 값을 출력한다.
    
    ```c
    static int not_init[4];
    ```
    
    앞에 static을 붙이면 초기화를 해주지 않아도 0으로 초기화를 해준다
    
    ```c
    int over[2] = {2, 4, 6, 8};
    ```
    
    선언된 배열보다 많은 데이터를 넣으면 컴파일 오류가 일어난다.
    
    ```c
    const int power_of_twos[] = {1, 2, 4, 8, 16, 32, 64};
    
    for (int i = 0; i < sizeof power_of_twos / sizeof power_of_twos[0]; ++i)
    	printf("%d ", power_of_tows[i]);
    ```
    
    배열의 사이즈를 입력하지 않았을 때, 갯수를 모른다면 반복문을 사용할 수 없게 된다.
    
    그래서 sizeof 함수를 사용해 전체 배열에서 첫 번째 배열의 크기를 나눠주면 정확한 배열 수를 알 수 있다.
    
    하지만 동적 할당에서는 작동하지 않는다.
    
    ```c
    int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};
    ```
    
    출력을 해보면 두 번째에는 28이 아닌 29가 나오는데 [1] = 29에서 배열을 덮어쓰기 때문이다.
    
    지정하지 않은 값은 0이 나온다.
    
    선언이 끝난 배열의 값을 바꾸기 위해서는 따로 값을 넣어 주어야 한다.
    
    ```c
    	int high[12] = { 2, 5, 11, 18, 23, 26, 29, 30, 26, 20, 12, 6 };
    	
    	for (int i = 0; i < MONTHS; ++i)
    		printf("%d ", high[i]);
    	printf("\n");
    
    	float avg = 0.0;
    	for (int i = 0; i < MONTHS; ++i)
    		avg += high[i];
    	printf("Average = %f\n", avg / (float)MONTHS);
    
    	high[0] = 1;
    	high[1] = 2;
    	//선언이 끝나면 하나씩 입력 해주어야함
    	//high[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // not working
    ```
    
    메모리 주소의 값을 알아보고 싶을 때에는
    
    ```c
    printf("%p %p\n", high, &high[0]);
    ```
    
    배열 이름만 사용하거나 앞에 주소 연산자 &과 첫 번째 배열을 입력하면 주소를 알 수 있다.
    
    ```c
    for (int i = 0; i < MONTHS; ++i)
    		printf("%lld\n", (long long)&high[i]);
    	printf("\n");
    ```
    
    반복문을 통해 배열 사이의 주소 값 차이를 볼 수 있는데 이 값을 출력하면
    
    4씩 차이가 나는 것을 알 수 있다. 4라는 숫자인 것을 보면 int의 정수형 4byte만큼 차이 난다
    
- ### [10.3] 포인터의 산술 연산
    
    포인터도 배열처럼 자료형의 주소 값 차이가 나는지 알아보면
    
    int 포인터 선언 시 4 차이
    
    char는 1차이
    
    double은 8차이
    
    void 포인터는 에러가 뜬다
    
    포인터도 자료형 만큼 주소 값을 건너 뛴다
    
    ```c
    int i = ptr2 - ptr1;
    ```
    
    arr[3] - arr[1]을 뺀 두 주소 간의 거리 2가 int i 로 들어간다.
    
- ### [10.4] 포인터와 배열
    
    [https://edu.goorm.io/learn/lecture/201/한-눈에-끝내는-c언어-기초/lesson/1271949/call-by-value-call-by-reference](https://edu.goorm.io/learn/lecture/201/%ED%95%9C-%EB%88%88%EC%97%90-%EB%81%9D%EB%82%B4%EB%8A%94-c%EC%96%B8%EC%96%B4-%EA%B8%B0%EC%B4%88/lesson/1271949/call-by-value-call-by-reference)
    
    포인터와 배열은 비슷하지만 차이도 존재한다
    
    ```c
    int* ptr = arr;
    	
    	printf("%p %p %p \n", ptr, arr, &arr[0]);
    
    	ptr += 2;
    
    	printf("%p %p %p \n", ptr, arr + 2, &arr[2]);
    ```
    
    포인터는 주소 값 그 자체이고 배열은 arr[]식으로 사용했을 때는 값을 불러오기 때문에 주소 연산자를 붙여야 주소를 출력한다.
    
    그냥 arr로 사용했을 때는 주소를 불러올 수 있지만, arr + 2처럼 연산을 사용할 수는 있다.
    
    ```c
    arr += 2;
    ```
    
    더해서 다시 값을 집어넣을 수는 없다.
    
- ### [10.5] 2차원 배열과 메모리
    
    
    ```c
    int arr[2][3] = {{1, 2, 3}{4, 5, 6}};
    ```
    
    2차원 배열은 행렬과 비슷하다.
    
    위의 코드는 2행 3열로 이해할 수 있다.
    
    하지만 내부적으로 메모리 안의 값들은 1차원으로 나열되어 있고, C언어 상으로 2차원처럼 보이게 만들어 주는 것이다.
    
    ```c
    for (int j = 0; j < 2; ++j)
    	{
    		for (int i = 0; i < 3; ++i)
    			printf("%d ", arr[j][i]);
    
    		printf("\n");
    	}
    ```
    
    중첩으로 for문을 사용해서 행렬처럼 출력할 수있다.
    
    ```c
    arr[j][i] 일때 i는 안쪽루프, j는 바깥루프가 메모리 구조상 빠름
    ```
    
    또한 포인터를 이용해서 선언된 배열이 내부적으로 1차원으로 나열된 것을 확인할 수 있다.
    
    ```c
    int* ptr = &arr[0][0];
    	for (int k = 0; k < 6; ++k)
    		printf("%d ", ptr[k]);
    	printf("\n\n");
    ```
    
    이렇게 출력 해보면 1 2 3 4 5 6이 나온다
    
- ### [10.6] 2차원 배열 연습문제
    
    2차원 배열을 이용해서 3년 동안 매월 평균 기온을 출력하는 예제를 작성해보았다.
    
    ```c
    double avg_years[YEARS][MONTHS] = { {-3.2, 0.2, 7.0, 14.1, 19.6, 23.6, 26.2, 28.0, 23.1, 16.1, 6.8, 1.2},
    		{-1.8,-0.2, 6.3, 13.9, 19.5, 23.3, 26.9, 25.9, 22.1, 16.4, 5.6, -1.9},
    		{-4.0, -1.6, 8.1, 13.0, 18.2, 23.1, 27.8, 28.8, 21.5, 13.1, 7.8, -0.6}};
    ```
    
    기상청에 들어가서 각각 16년, 17년, 18년의 월별 평균 기온을 입력해주었다.
    
    2차원 배열을 활용하여 3년의 평균 날씨를 출력해보면
    
    ```c
    printf("[Yearly average temperatures of 3 years]\n");
    	for (int j = 0; j < YEARS; ++j)
    	{
    		double avg_temp = 0.0;
    
    		for (int i = 0; i < MONTHS; ++i)
    		{
    			avg_temp += avg_years[j][i];
    		}
    		avg_temp /= (double)MONTHS;
    		
    		printf("Year %d : average temperature = %.1f\n", j, avg_temp);
    	}
    	printf("\n");
    ```
    
    이중 반복문으로 평균 기온을 알 수 있고
    
    ```c
    printf("[Monthly average temperatures for 3 years]\n");
    	
    	for (int i = 0; i < MONTHS; ++i)
    	{
    		double avg_temp = 0.0;
    
    		for (int j = 0; j < YEARS; ++j)
    		{
    			avg_temp += avg_years[j][i];
    		}
    		avg_temp /= (double)YEARS;
    		printf("\t%.1f",avg_temp);
    	}
    	printf("\n");
    ```
    
    마찬가지로 3년 동안의 매월 평균 기온도 알 수 있다.
    
    실전에서는 만 개 이상의 데이터를 다룰 수 있기 때문에 배열의 활용 법을 익혀 두는 것이 좋다.
    
- ### [10.7] 배열을 함수에게 전달해주는 방법
    
    배열은 포인터와 유사하다
    
    배열은 내부적으로는 포인터처럼 처리한다.
    
    main이 아닌 따로 선언된 함수에서 배열을 받을 때는 배열이 아니라 포인터로 받는다
    
    각각 다르게 선언된 배열의 평균을 구하기 위해
    
    ```c
    int main()
    {
    	double arr1[5] = { 10, 13, 12, 7, 8 };
    	double arr2[3] = { 1.8, -0.2, 6.3 }; // size is different
    
    	printf("Address = %p\n", arr1);
    	printf("Size = %zd\n", sizeof(arr1));
    	printf("Address = %p\n", arr2);
    	printf("Size = %zd\n", sizeof(arr2));
    
    	printf("Avg = %f\n", average(arr1, 5));
    	printf("Avg = %f\n", average(arr2, 3));
    
    	
    	return 0;
    }
    ```
    
    arr1는 5개의 배열이고 arr2는 3개의 배열이다. 각각의 사이즈와 평균을 알아보려면 중복된 기능을 다루기때문에
    
    따로 함수를 선언해주었다.
    
    ```c
    double average(double data_array[], int n)
    {
    	printf("Size = %zd in function average\n", sizeof(data_array));
    
    	double avg = 0.0;
    	for (int i = 0; i < n; ++i)
    	{
    		avg += data_array[i];
    	}
    	avg /= (double)n;
    
    	return avg;
    }
    ```
    
    이렇게 average(배열, 인수)처럼 따로 인수를 넣어주어서 배열내의 인수가 달라도 
    
    평균을 구할 수 있게 넣어준다.
    
- ### [10.8] 두 개의 포인터로 배열을 함수에게 전달해 주는 방법
    
    앞에서 배운 배열의 평균을 구할 때 parameter로 포인터를 사용해 줄 수있다.
    
    ```c
    double average(double* start, double* end)
    {
    	int count = end - start;
    	double avg = 0.0;
    	while (start < end)
    	{
    		avg += *start++;
    		//count++;
    	}
    	avg /= (double)count;
    
    	return avg;
    ```
    
    배열의 정확한 사이즈를 모를 때에는 count++ 보다는
    
    사이즈 값을 넣을 수 있게 하는 방법도 있다.
    
- ### [10.9] 포인터의 연산 총 정리
    
    
    포인터도 변수이고 변수처럼 선언도 가능하고 연산도 가능하다. 일반적인 연산과는 조금 다르다.
    
    ```c
    int arr[5] = { 100, 200, 300, 400, 500 };
    int* ptr1, * ptr2, * ptr3;
    
    ptr1 = arr;		// Assignment
    ```
    
    이렇게 포인터에 배열을 넣어주고
    
    ```c
    ptr3 = ptr1 + 4;
    ```
    
    ptr3에는 ptr1의 0 1 2 3 4에서 4에 들어있는 값인 500이 들어간다.
    
    ```c
    ptr3 = ptr3 - 4; // Subtracing an intger from a pointer
    ```
    
    이렇게 빼는 것도 가능하고
    
    ```c
    ptr1++;			// Incrementing, ptr1 = ptr1 + 1
    ptr1--;			// Decrementing
    --ptr1;
    ++ptr1;
    ```
    
    더해주거나 빼줄 수 있고 prefix, postfix도 사용 가능하다.
    
- ### [10.10] const와 배열의 포인터
    
    ```c
    int main()
    {
    	// type qualifeiers: const, volatile, ...
    
    	const double PI = 3.14159;
    	//PI = 2.14159;
    
    	const int arr[5] = { 1, 2, 3, 4, 5 };
    	//arr[1] = 123;
    
    	const double arr2[3] = { 1.0, 2.0, 3.0 };
    	//arr2[0] = 100.0;
    
    	const double* pd = arr2;
    	//*pd = 3.0;		// pd[0] = 3.0; arr2[0] = 3.0;
    	//pd[2] = 1024.0; // arr2[2] = 1024.0;
    
    	printf("%f %f", pd[2], arr2[2]);
    
    	pd++; // allowed
    
    	printf("%f %f", pd[2], arr2[2]);
    
    	return 0;
    }
    ```
    
    포인터로 배열에 접근할 때 const를 사용할 때 주의
    
    포인터 안에 들어있는 값을 못 바꾼다.
    
    cons pd 는 포인터 주소 값도 못 바꾼다
    
    그러나 pd++을 통해서 주소를 이동 시키는 것은 가능하다
    
    주소 이동도 불가능하게 하려면 포인터 앞에도 const를 붙여주면 된다.
    
- ### [10.11] 배열 매개변수와 const
    - 사람이기 때문에 변경해서는 안되는 값을 건드릴 수도 있다.
        
        실수를 하지 않기 위한 예비 책으로 const를 붙여준다
        
        ```c
        void add_value(int arr[], const int n, const int val)
        {
        	int i;
        	for (i = 0; i < n; i++)
        		arr[i] += val;
        }
        ```
        
    
- ### [10.12] 2중 포인터의 작동원리
    
    ```c
    int a = 7;
    
    int *ptr = &a;
    
    *ptr = 8;
    
    //int (*(*pptr)) = &ptr;
    int **pptr = &ptr;
    
    **pptr = 9; //*(*pptr) = 9;
    ```
    

- ### [10.13] 포인터의 배열과 2차원 배열
    
    ```c
    int arr[2][3] = {{1, 2, 3},{4, 5, 6}};
    
    int* parr[2] = { arr[0], arr[1] };
    ```
    
    포인터의 배열과 배열의 차이
    
    - 방법 1
        
        ```c
        /* Two of 1D arrays */
        int arr0[3] = { 1, 2, 3 };
        int arr1[3] = { 4, 5, 6 };
        
        int* parr[2] = { arr0, arr1 };	// an array of pointers
        
        	for (int j = 0; j < 2; ++j)
        	{
        		for (int i = 0; i < 3; ++i)
        			printf("%d(==%d. %d) ", parr[j][i], *(parr[j] + i),  ( * (parr + j))[i]);
        		printf("\n");
        	}
        	printf("\n");
        ```
        
    - 방법 2
        
        ```c
        /* 2D arrays are arrays of 1D arrays */
        
        int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
        
        int* parr0 = arr[0];
        int* parr1 = arr[1];
        
        for (int i = 0; i < 3; ++i)
        	printf("%d ", parr0[i]);
        printf("\n");
        
        for (int i = 0; i < 3; ++i)
        	printf("%d ", parr1[i]);
        printf("\n");
        ```
        
    - 방법 3
        
        ```c
        int arr[2][3] = { {1, 2, 3}, {4, 5, 6} };
        
        	//int* parr[2] = { arr[0], arr[1] };
        	int* parr[2];
        	parr[0] = arr[0];
        	parr[1] = arr[1];
        
        	for (int j = 0; j < 2; ++j)
        	{
        		for (int i = 0; i < 3; ++i)
        			printf("%d %d %d %d\n",
        				arr[j][i], parr[j][i], *(parr[j] + i), *(*(parr + j) + i));
        		printf("\n");
        	}
        	printf("\n");
        ```
        
    
    다음 방법들은 모두 2차원 배열을 포인터로 담은 것이다.
    
    ```c
    /* Array of string of divers lengths example */
    
    	char* name[] = { "Aladdin", "Jasmin", "Magic Carpet", "Genie" };
    
    	const int n = sizeof(name) / sizeof(char*);
    
    	for (int i = 0; i < n; ++i)
    		printf("%s at %u\n", name[i], (unsigned)name[i]); // Use ull in x64 build
    	printf("\n");
    
    	char aname[][15] = {"Aladdin", "Jasmin", "Magic Carpet", "Genie", "Jafar"};
    
    	const int an = sizeof(aname) / sizeof(char[15]);
    
    	for (int i = 0; i < an; ++i)
    		printf("%s at %u\n", aname[i], (unsigned)& aname[i]); // Use ull in x64 build
    	printf("\n");
    
    	return 0;
    ```
    
    한 가지 재밌는 예제도 있었다.
    
    다음과 같이 포인터로 선언된 배열은 주소의 크기가 일정하지 않고
    
    배열은 주소 차이가 항상 15인 것을 알 수 있다.
    
- ### [10.14] 2차원 배열과 포인터
    
    ```c
    arr2d[0] 은 주소
    arr2d[0][0] 은 배열안의 값
    ```
    
    ---
    
    ```c
    int main()
    {
    	float arr2d[2][4] = { {1.0f, 2.0f, 3.0f, 4.0f}, {5.0f, 6.0f, 7.0f, 8.0f} };
    
    	printf("%u\n", (unsigned)arr2d);		// Use unsigned long long in x64
    	printf("%u\n", (unsigned)arr2d[0]);
    	printf("\n");
    
    	// arr2d points to arr2d[0] (not arr2d[0][0]), KNK Ch. 12.4
    
    	printf("%u\n", (unsigned)* arr2d);
    	printf("%u\n", (unsigned)& arr2d[0]);	// C language allows this
    	printf("%u\n", (unsigned)& arr2d[0][0]);
    	printf("%f %f\n", arr2d[0][0], **arr2d);
    	printf("\n");
    
    	printf("%u\n", (unsigned)(arr2d + 1));
    	printf("%u\n", (unsigned)(&arr2d[1]));
    	printf("%u\n", (unsigned)(arr2d[1]));
    	printf("%u\n", (unsigned)(*(arr2d + 1)));
    	printf("%u\n", (unsigned)(&arr2d[0] + 1));
    	printf("%u\n", (unsigned)(&arr2d[1][0]));
    	printf("\n");
    
    	/* pointers to Multidimensional Arrays */
    
    	float(*pa)[4]; // a SINGLE pointer to an array of 2 floats
    	float* ap[2];  // an array of TWO pointers-to-float
    
    	printf("%zu\n", sizeof(pa));	// 8 in x64
    	printf("%zu\n", sizeof(ap));	// 16 in x64
    	printf("\n");
    
    	pa = arr2d;
    	//pz[0] = arr2d[0]; // error
    	//pa[1] = arr2d[1]; // error
    
    	//ap = arr2d; //error
    	ap[0] = arr2d[0];
    	ap[1] = arr2d[1];
    
    	return 0;
    }
    ```
    
- ### [10.15] 포인터의 호환성
    
    ```c
    int n = 5;
    double x;
    x = n;		// no error
    int* p1 = &n;
    double* pd = &x;
    pd = p1;	// Warning
    
    int* pt;
    int(*pa)[3];
    int ar1[2][3] = { 3, };
    int ar2[3][2] = { 7, };
    int** p2;	// a pointer to a pointer
    
    pt = &ar1[0][0];	// pointer-to-int
    
    for (int i = 0; i < 6; ++i)
    	printf("%d ", *(pt + i));
    
    pt = ar1[0];		// pointer-to-int
    	//pt = ar1;			// Warning (Error)
    pa = ar1;			// pointer-to-int[3]
    
    p2 = &pt;			// pointer-to-int *
    *p2 = ar2[0];		// pointer-to-int
    	//p2 = ar2;			// Warning (Error)
    	//Notes
    	// - p2: pointer to pointer to int
    	// - ar2: a pointer to array-of-2-ints
    
    	/* Pointer and const */
    
    int x = 20;
    const int y = 23;
    int* p1 = &x;
    const int* p2 = &y;
    const int** pp2 = &p1;
    p1 = p2;		// Warning (Error)
    
    *p2 = 123;		// Error
    p2 = p1;
    
    int x2 = 30;
    int* p3 = &x2;
    *pp2 = p3;
    pp2 = &p1;
    ```
    

- ### [10.16] 다차원 배열을 함수에게 전달해주는 방법
    
    ```c
    int sum2d_1(int ar[ROWS][COLS]);
    int sum2d_2(int ar[][COLS], int row);
    int sum2d_3(int* ar, int row, int col);
    
    int main()
    {
    	int data[ROWS][COLS] = {
    								{1, 2, 3, 4},
    								{5, 6, 7, 8},
    								{9, 0, 1, 2}};
    
    	printf("%d\n", data[2][3]);
    
    	int* ptr = &data[0][0];
    	printf("%d\n", *(ptr + 3 + COLS * 2));
    
    	printf("Sum of all elements = %d\n", sum2d_1(data));
    	printf("Sum of all elements = %d\n", sum2d_2(data, ROWS));
    	printf("Sum of all elements = %d\n", sum2d_3(&data[0][0], ROWS, COLS));
    
    	return 0;
    }
    
    int sum2d_1(int ar[ROWS][COLS])
    {
    	int r, c, tot = 0;
    	for (r = 0; r < ROWS; r++)
    		for (c = 0; c < COLS; c++)
    			tot += ar[r][c];
    	return tot;
    }
    
    int sum2d_2(int ar[][COLS], int row)
    {
    	int r, c, tot = 0;
    	for (r = 0; r < row; r++)
    		for (c = 0; c < COLS; c++)
    			tot += ar[r][c];
    	return tot;
    }
    
    int sum2d_3(int* ar, int row, int col)
    {
    	int r, c, tot = 0;
    	for (r = 0; r < row; r++)
    		for (c = 0; c < col; c++)
    			tot += *(ar + c + col * r); //ar[c + col * r]
    	return tot;
    }
    ```
    
    여러가지 배열의 합을 출력하는 함수 중에서도 재밌는 부분은
    
    ```c
    tot += *(ar + c + col * r); //ar[c + col * r]
    ```
    
    sum2d_3의 이 부분이다.  보이는 것은 2차원 행렬이지만 내부적으로는 1차원으로 나열된 값들이기 때문에
    
    행렬의 열 부분인 col과 r을 곱 하면 행 부분을 표현할 수 있다.
    
- ### [10.17] 변수로 길이를 정할 수 있는 배열
    
    ```c
    int main()
    {
    	printf("Input array length : ");
    	scanf("%d", &n);
    
    	float my_arr[n];
    
    	for (int i = 0; i < n; ++i)
    		my_arr[i] = (float)i;
    	for (int i = 0; i < n; ++i)
    		printf("%f\n", my_arr[i]);
    
    	return 0;
    }
    ```
    
    배열을 scanf로 받아서 입력 받은 수만큼 배열을 결정할 수 있다.
    
    우분투에서는 가능하지만 비주얼 스튜디오에서는 작동 하지 않는다.
    
    동적 할당 메모리를 많이 사용하기 때문에 사용 잘 하지 않는다.

    </br>

## Chapter 11. 문자열 함수들

- ### [11.1] 문자열을 정의하는 방법
    
    ```c
    char arr[] = "Hello, world";
    
    char* str = "Hello, world";
    //str[0] = 'M'; // ERROR!!!
    ```
    
    문자열을 초기화하는 방법으로는 문자열 자체로 초기화하거나
    
    문자열이 배열의 일종처럼 메모리에 배치가 되어 있다면 
    
    함수에게 전달할 때는 첫 번째 주소를 포인터로 넘겨줄 수 있다.
    
    배열로 만드는 방법 넉넉한 사이즈를 주고 선언하고 문자열을 집어넣는다.
    
    ```c
    char words[MAXLENGTH] = "A string in an array";
    const char* pt1 = "A pointer to a string.";
    ```
    
    symbolic constant도 매크로처럼 사용 가능하다
    
    ```c
    #define MESSAGE "A symbolic string contant"
    #define MAXLENGTH 81
    ```
    
    포인터는 어딘가 선언된 주소의 첫 번째를 가져오는 것이기 때문에 나머지 주소가 일정하지 않을 수 있다.
    
    ```c
    puts(words);	// char words[21] removes this warning
    ```
    
    puts(words);에서 warning이 생기는 이유는 배열을 선언할 때 생긴 81개에서
    
    words가 받은 21개만 초기화가 되고 나머지 60개는 초기화 되지 않았기 때문이다.
    
    추가로 배열의 값을 바꾸는 것은 오류가 나지 않지만
    
    ```c
    pt1[8] = 'A'; // Error
    ```
    
    포인터로 이미 선언된 문자열을 포인터의 배열로 바꾸려고 하면
    
    런타임 오류가 발생한다.
    
    ```c
    printf("%s, %p, %c\n", "We", "are", *"excellent programmers");
    ```
    
     두 번째 are이 들어갈 부분이 포인터 형식 지정자 %p 인데 are의 포인터 주소는 첫 글자 a가 저장된 주소가 출력
    
    배열에는 또한 실수나 음수가 들어갈 수 없음. 부호 없는 정수만 가능하다
    
- ### [11.2] 메모리 레이아웃과 문자열
    
    ```c
    /* Array Versus Pointer */
    const char* pt2 = "I am a string!.";
    const char* pt3 = "I am a string!.";
    const char* pt4 = "I am a string!!!!!"; // <- different
    const char ar1[] = "I am a string!.";
    const char ar2[] = "I am a string!.";
    const char ar3[] = "I am a string!!."; // <- different
    
    printf("rodata low \t%llu %llu %llu %llu\n",
    		(unsigned long long)pt2, (unsigned long long)pt3, (unsigned long long)pt4,
    		(unsigned long long)"I am a string!.");
    
    printf("Stack high \t%llu %llu %llu \n",
    		(unsigned long long)ar1, (unsigned long long)ar2, (unsigned long long)ar3); 
    			// check address numbers!
    ```
    
    출력 예시
    
    ```c
    rodata low      16677704 16677704 16677724 16677704
    Stack high      7600600 7600576 7600548
    ```
    
    출력 해보면 포인터의 주소는 pt2, pt3 그리고 “I am a string!.” 이 주소가 일치하지만
    
    배열의 주소는 서로 각각 다르다.
    
    배열은 각자 메모리를 갖지만, 포인터는 문자열 첫 번째 글자의 주소만 가지고 있는다.
    
    그렇다면 어떻게 포인터는 I am a string!. 이란 글자까지 주소가 같은 것일까?
    
    여기서 스택, 힙, 정적 변수의 개념이 나온다
    
    ```markdown
    스택(Stack) 메모리 = 지역 변수들, 메모리 크기를 컴파일러가 예측 가능한 경우, 빠름
    
    자유 공간
    
    힙(Heap) 메모리 = 메모리 크기가 얼마가 될지 알 수 없는 경우 
    
    > 초기화되지 않은 전역/정적 변수들 - 크기고정
    
    > 초기화된 전역/정적 변수들 - 크기고정
    
    > 프로그램 코드 - 크기고정
    ```
    
    메모리는 이와 같은 구조를 가지며 
    
    컴파일러 입장에서 같은 문자열이 반복될 경우 메모리를 아끼기 위해 
    
    I am a string이란 문자열을 한 곳에 저장해놓고 여러번 사용하는 식이다. 
    
    배열은 초기화된 전역변수 또는 지역변수라면 스택 메모리로 들어간다.
    
    배열 자체가 메모리를 확보 해놓고 있기 때문에 배열마다 메모리 주소가 모두 다르게 나온다.
    
    포인터는 text segment에 있기 때문에 읽기 전용이고 크기가 고정되어있어 값들을 바꿀 수 없다.
    
    읽기 전용 메모리로 들어가기 때문에 값을 바꾸려고 하면 에러가 발생한다.
    
    ```c
    const char* str1 = "When all the lights ar low, ...";
    const char* copy;
    
    copy = str1;
    ```
    
    text segment의 주소만 옮겨 가고 있음
    
- ### [11.3] 문자열의 배열
    
    
    ```c
    /* Arrays of Character Strings */
    
    	const char* mythings[5] = {
    		"Dancing in the rain",
    		"Counting apples",
    		"Watching movies with friends",
    		"Writing sad letters",
    		"Studying the C language",
    	};
    
    	char yourthings[5][40] = {
    		"Studying the C++ language",
    		"Eating",
    		"Watching Netflix",
    		"Walking around till dark",
    		"Deleting spam emails"
    	};
    
    	const char* temp1 = "Dancing in the rain";
    	const char* temp2 = "Studying the C++ language";
    
    	printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1);
    	printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)temp2);
    ```
    
    출력 예시
    
    ```c
    Dancing in the rain 9599792 9599792
    Studying the C++ language 9369884 9599924
    ```
    
    포인터 변수 자체는 스택에, 문자열 자체는 text segment에 있다.
    
    그래서 포인터로 같은 문자열을 사용하면 메모리를 아낄 수 있으나 값을 바꿀 수는 없다.
    
- ### [11.4] 문자열을 입력받는 다양한 방법들
    
    ```c
    char words[STRLEN] = "";			// Warning without initialization
    	gets(words);						// gets receives pointer. No idea when stringe ends.
    	//gets_s(words, sizeof(words));		// C11
    	//int result = scanf("%s", words);
    	printf("START\n");
    	printf("%s", words);				// no \n at the end
    	puts(words);						// puts() adds \n at the end
    	puts("END.");
    ```
    
    gets()는 문자열을 읽어내는 함수 이다.
    
    scanf()와의 차이는 함수 한 줄을 다 읽을 수 있다. 
    
    또한 마지막 \n줄 바꿈을 없애고 \0인 null character을 추가한다.
    
    마찬가지로
    
    puts()는 문자열을 출력하는 함수 이고
    
    printf() 차이는 마지막에 줄 바꿈을 자동 추가한다.
    
    ```c
    /* fgets() and fputs() */
    
    	char words[STRLEN] = "";
    	fgets(words, STRLEN, stdin);		// does NOT remove \n
    
    	// TODO: replace '\n' with '\0'
    	int i = 0;
    	while (words[i] != '\n' && words[i] != '\0')
    		i++;
    	if (words[i] == '\n')
    		words[i] = '\0';
    
    	fputs(words, stdout);				// does NOT remove \n
    	fputs("END", stdout);
    
    	/* Small array */
    
    	char small_array[5];
    	puts("Enter long strings:");
    	fgets(small_array, 5, stdin);		// FILE *_Stream
    	//printf("%p\n", small_buffer);
    	//printf("%p\n", fgets(small_buffer, 5, stdin));	// Return value of fgets
    	fputs(small_array, stdout);
    ```
    
    fgets()와 fputs()는 파일을 입출력하는 함수이다.
    
    gets()와 puts()의 차이점은 선언한 배열보다 많은 문자열을 받았을 때 
    
    런타임 에러가 나지 않고 버퍼에 임시로 저장 해 놓았다가 출력하여 에러가 나지 않는다.
    
    버퍼 덕분에 많은 문자를 받아도 작은 배열도 문제 없이 출력 가능하다.
    
- ### [11.5] 문자열을 출력하는 다양한 방법들
    
    ```c
    /* 
    		puts() : add \n at the end
    */
    
    char str[60] = "String array initialized";
    const char* ptr = "A pointer initialized";
    
    puts("String without \\n");
    puts("END");
    puts(TEST);
    puts(TEST + 5);
    puts(&str[3]);
    //puts(str[3]); // Error
    puts(ptr + 3);
    ```
    
    puts()는 \0인 NULL character을 만날 때 까지 함수를 찾음
    
    ```c
    char str[] = { 'H', 'I', '!' }; // No \0 at the end
    puts(str);	// VS warns you!
    ```
    
    NULL character 없는 배열을 출력을 하면 ASCII코드에서 \0이 얻어 걸릴 때까지 아무 문자나 출력한다
    
    ```c
    char input[100] = "";
    int ret = scanf("%10s", input);	// Input : "Just do it, do it!\n" (Note %10s)
    printf("%s\n", input);	// Output : "Just"
    ret = scanf("%10s", input);		// Reads remaning buffer
    printf("%s\n", input);			// Output : "do"
    ```
    
    scanf()는 빈칸을 만나면 읽어 들이지 않는다.
    
    Just do it을 입력하면 Just만 출력하고 나머지 do it은 버퍼에서 ret으로 들어가버리고
    
    나중에 출력하면 그 다음 단어인 do가 나온다.
    
- ### [11.6] 다양한 문자열 함수들
    
    strlen() 문자의 길이
    
    strcat() 문자열을 합쳐주는 함수
    
    strncat(char1, char2, int) int의 수 만큼 char2의 문자 수 합쳐줌
    
    strcmp() and strncmp() 문자열 비교
    
    true & false 아님
    
    같으면 0 아스키 순서상 빠르면 -1 느리면 1
    
    뒤에 문자열이 길면 -1, 앞의 문자열이 길면 1
    
    strncmp는 인수만큼만 비교
    
    sprintf()는 printf()를 선언된 문자열에 출력
    
- ### [11.7] 선택 정렬 문제 풀이
    
    선택 정렬 알고리즘을 C언어로 구현하는 예제이다.
    
    [https://www.geeksforgeeks.org/selection-sort/](https://www.geeksforgeeks.org/selection-sort/)
    
    **선택 정렬**은 [제자리 정렬](https://ko.wikipedia.org/wiki/%EC%A0%95%EB%A0%AC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98#%EC%A0%9C%EC%9E%90%EB%A6%AC_%EC%A0%95%EB%A0%AC) 알고리즘의 하나로, 다음과 같은 순서로 이루어진다.
    
    1. 주어진 리스트 중에 최소값을 찾는다.
    2. 그 값을 맨 앞에 위치한 값과 교체한다(패스(pass)).
    3. 맨 처음 위치를 뺀 나머지 리스트를 같은 방법으로 교체한다.
    
    
    ```c
    void swap(int* xp, int* yp)
    {
    	int temp = *xp;
    	*xp = *yp;
    	*yp = temp;
    }
    
    void selectionSort(int arr[], int n)
    {
    	int min_index = 0;
    
    	for (int i = 0; i < n - 1; i++)
    	{
    		min_index = i;
    		for (int j = i + 1; j < n; j++)
    		{
    			if (arr[j] < arr[min_index])
    				min_index = j;
    		}
    		swap(&arr[min_index], &arr[i]);
    	}
    }
    ```
    
    오름차순으로 정렬했을 때의 작동 방식이다.
    
- ### [11.8] 문자열의 포인터를 정리하기
    
    문자열을 선택 정렬 알고리즘으로 정렬할 때 숫자를 정렬할 때와 다른 점은
    
    ```c
    void swap(char** xp, char** yp)
    {
    	char* temp = *xp;
    	*xp = *yp;
    	*yp = temp;
    }
    
    void selectionSort(char* arr[], int n)
    {
    	int min_index = 0;
    
    	for (int i = 0; i < n - 1; i++)
    	{
    		min_index = i;
    		for (int j = i + 1; j < n; j++)
    		{
    			if (strcmp(arr[j], arr[min_index]) < 0)
    				min_index = j;
    		}
    		swap(&arr[min_index], &arr[i]);
    	}
    }
    ```
    
    swap함수 부분이 이중 포인터를 사용했고, strcmp()를 사용해서 0보다 작으면 오름차순, 크면 내림차순으로 정렬할 수 있다.
    
- ### [11.10] 명령줄 인수
    
    ```c
    int main(int argc, char* argv[])
    {
    	int count;
    
    	printf("The command line has %d arguments:\n", argc);
    
    	for (count = 0; count < argc; count++)
    		printf("Arg %d : %s\n", count, argv[count]);
    	printf("\n");
    
    	return 0;
    }
    ```
    
    항상 비어있던 main함수에 인자를 넣으면 빌드를 하고 exe파일을 실행 할 때 입력한 값이
    
    main함수의 인수로 들어간다
    
    예를 들어 cmd에서 > 3 hello를 입력하면 이렇게 출력된다.
    
    ```c
    The command line has 3 arguments:
    Arg 0 : E:\TIL\TBC\CH11\Debug\CH11_10.exe
    Arg 1 : 3
    Arg 2 : hello
    ```
    
- ### [11.11] 문자열을 숫자로 바꾸는 방법들
    
    다음은 문자열을 숫자로 바꾸는 함수들이다.
    
    ```c
    /*
    		string to integer, double, long
    		atoi(), atof(), atol()
    */
    
    if (argc < 3)
    		printf("Worng Usage of %s\n", argv[0]);
    else
    	{
    		/* Example 1 */
    
    		int times = atoi(argv[1]);
    		// atof(), atol()
    
    		for (int i = 0; i < times; i++)
    			puts(argv[2]);
    
    		/* Example 2 */
    
    		//printf("Sum = %d\n", atoi(argv[1]) + atoi(argv[2]));
    
    	}
    
    char str1[] = "-1024Hello";
    	char* end;
    	long l = strtol(str1, &end, 10);
    	printf("%s %ld %s %d\n", str1, l, end, (int)*end);
    
    	char str2[] = "10FFHello";
    	l = strtol(str2, &end, 16);
    	printf("%s %ld %s %d\n", str2, l, end, (int)*end);
    ```
    
     숫자를 문자열로 바꿀 수 있는 함수들이다.

</br>

 ## Chapter 12. Storage Classes, Linkage and Memory Management

- ### [12.1] 메모리 레이아웃 훑어보기
    
    프로그램의 일부에서 큰 메모리가 필요한 경우 메모리 사용에 부담을 느낄 수 있다.
    
    그래서 특정 영역에서만 사용할 수 있는 지역 변수를 사용한다
    
    지역 변수는 포함된 영역의 함수를 실행할 때만 스택 메모리에 들어가고
    
    그 외의 상황에서는 메모리를 차지하지 않는다.
    
    스택 메모리는 필요한 상황에서 늘어났다가 필요 없을 때는 줄어들기 때문에
    
    효율적으로 사용할 수 있다. 
    
    메인 함수에 코드를 작성하는 것 보다 따로 작은 영역의 함수를 사용하는 것이
    
    더 효율적으로 메모리를 사용한다.
    
    대부분의 경우 필요한 메모리의 크기를 미리 알 수 없다.
    
    익숙하게 받아들이게 되면 실력 향상에 도움이 된다.
    
    ```c
    int main()
    {
    	int n = 0;
    	// n from files, internet, scanf, etc.
    	char* arr = (char*)malloc(sizeof(char) * n);
    	// ...
    	free(arr);
    	
    	return 0;
    }
    ```
    
    동적 할당 메모리에서 메모리를 할당 받거나 반납 할 때에 시간이 좀 걸릴 수 있다.
    
    메모리를 할당할 때 프로그래머에게 자유를 주기 위해 반납은 안 할 수도 있지만 
    
    반납을 안하면 런타임 에러가 발생한다.
    
- ### [12.2] 객체와 식별자, lvalue와 rvalue
    
    객체(Object) 와 식별자(identifier) 차이 위주 설명
    
    객체는 값을 저장할 수 있는 메모리의 블럭이다.
    
    C언어에서의 객체는 메모리의 공간을 가지고 있으면 객체라고 불린다.
    
    그 외 C++, JAVA 같은 언어에서의 객체는 객체를 확장시킨 개념이고 후에 
    
    객체지향프로그래밍에 대해 배우게 된다.
    
    식별자는 변수, 함수, 매크로, 그 외의 것들의 이름이다.
    
    ```c
    int var_name = 3;		// creates an object call 'var_name'
    ```
    
    객체와 식별자가 같아 보이지만 C언어가 그렇게 보이게 도와주는 것이다.
    
    ```c
    *pt = 1;				// *pt is not an identifier. *pt designates an object.
    ```
    
    포인터는 객체를 가리킬 수 있다.
    
    ```c
    int arr[100];			// arr is an identifier. Is arr an object?
    arr[0] = 7;				// arr[0] is an object.
    ```
    
    arr은 첫 원소에 대한 주소이고 객체는 아니다. arr[0]은 메모리 공간에 접근할 수 있기 때문에 객체이다.
    
    L-value : 왼쪽 올 수 있고, 객체를 ‘참조‘ 하는 표현식이다.
    
    R-value : 오른쪽에 오는 변수, 상수, 표현식이다.
    
    ```c
    pt = &var_name;
    int* ptr = arr;
    *pt = 7;				// *pt is not an identifier but an modifiable lvalue expression
    ```
    
    *pt는 식별자는 아니지만, L-value 표현식으로 값을 바꿀 수는 있다.
    
    ```c
    int* ptr2 = arr + 2 * var_name; // address rvalue
    *(arr + 2 * var_name) = 456;	// lvalue expression
    ```
    
    arr+2 * var_name 은 R-value로 주소 값을 갖지만, *로 indirection해주면 L_value로 사용할 수 있다
    
    ```c
    char str2[] = "String in an array";
    str2[0] = 'A';	//OK
    //puts(str2);
    ```
    
    배열은 메모리를 직접 할당, 포인터는 메모리를 가리킴
    
- ### [12.3] 변수의 영역(Scope)과 연결 상태(Linkage), 객체의 지속 기간(Duration)
    
    변수의 영역에는 네 가지가 있다.
    
    block, function, function prototype, file
    
    ```c
    int g_i = 123;	// global variable
    int g_j;		// global variable
    
    void func1()
    {
    	g_i++;	// uses g_i
    }
    
    void func2()
    {
    	g_i += 2;	// uses g_i
    
    	//local = 456;	// Error
    }
    
    int main()
    {
    	int local = 1234;
    
    	func1();
    	func2();
    
    	printf("%d\n", g_i); // uses g_i
    	printf("%d\n", g_j); // Not initialized
    	printf("%d\n", local);
    
    	return 0;
    }
    ```
    
    file scope
    
    file은 모든 함수 영역의 밖에 선언되는 변수다. 전역 변수 혹은 파일 변수
    
    전역 변수는 어떤 영역이든 사용 가능
    
    컴파일러가 translation하는 unit의 단위가 파일이다.
    
    파일이 2개라면 따로 컴파일 하기 때문에 서로 무엇이 있는지 알 수 없다.
    
    하지만 그 사이를 연결해주는 것이 링커이다
    
    ```c
    int el;				// file scope with external linkage (global variable)
    static int i1;		// file scope with internal linkage
    
    int main()
    {
    	el = 1024;
    
    	testLinkage();
    
    	printf("%d\n", el);
    
    	return 0;
    }
    ```
    
    이런 파일과
    
    ```c
    extern int el;
    
    void testLinkage()
    {
    	printf("DoSomething called\n");
    	printf("%d\n", el);
    
    	el++;
    
    }
    ```
    
    이 한 소스에 같이 있을 때 실행을 돌려보면
    
    ```c
    DoSomething called
    1024
    1025
    ```
    
    이렇게 둘 다 실행되어 출력 가능한게 보인다
    
    여기서
    
    ```c
    extern int el;
    ```
    
    extern은 다른 파일의 선언된 변수를 가져올 수 있다
    
    ```c
    static int i1;
    ```
    
    여기서 static은 이 영역에서만 변수를 사용 하는 것으로 제한하는 키워드이다.
    
    static이 선언된 곳과 다른 곳에서 변수를 사용하려고 하면 링크에러가 발생한다.
    
    다음으로 Duration은 메모리의 지속 기간을 의미한다.
    
    Duration은 4가지 방법이 있는데
    
    - static storage duration ( 앞의 static 변수와는 다르다 )
    - automatic storage duration
    - allocated storage duration (동적 할당과 관련)
    - thread storage duration (멀티 쓰레딩 관련)
    
    이렇게 네 가지 메모리 지속 방법을 가진다.
    
    ```c
    void count()
    {
    	int ct = 0;
    	printf("count = %d\n", ct);
    	ct++;
    }
    
    void static_count()
    {
    	static int ct = 0;
    	printf("static count = %d\n", ct);
    	ct++;
    }
    
    int main()
    {
    	count();
    	count();
    	static_count();
    	static_count();
    
    	return 0;
    }
    ```
    
    출력하면
    
    ```c
    count = 0
    count = 0
    static count = 0
    static count = 1
    ```
    
    이렇게 static count는 메모리가 사라지지 않고 ct++;이 실행되어 적용한다.
    
- ### [12.4] 저장 공간의 다섯 가지 분류
    저장공간분류|메모리에서의위치|지속 기간|영역|연결 상태|선언 방법  
    ---|---|---|---|---|--- 
     자동 |스택| 자동적| 블록 안| 없음| 블록 안
     레지스터 | 레지스터| 자동적| 블록 안| 없음| register 키워드 사용
     고정적, 내부연결| 데이터| 고정적| 파일 안| 번역 단위의 내부| 모든 함수들 밖에서 static 키워드
     고정적, 외부연결| 데이터| 고정적| 파일 안| 번역 단위의 외부| 모든 함수들 밖
     고정적, 연결없음| 데이터| 고정적| 블록 안| 없음| 블록 안에서  static 키워드
     할당 메모리| 힙heap| 프로그래머가 결정| NA| NA| 운영체제에게 요청
     - 레지스터는 cpu단위이기 때문에 더 빠를 수 있음
- ### [12.5] 자동 변수
    
    메모리를 효율적으로 공유하면서 사용할 수 있는 구조
    
    자동 변수는 블록 안에서 선언 지역 변수와 같음
    
    ```c
    auto int a;	// keyword auto : a storage-class specifier
    ```
    
    지역변수를 선언할 때 사용하지만 굳이 auto를 붙이지 않아도 된다.
    
    자동변수는 초기화를 하지 않으면 오류가 생긴다
    
    자동적으로 초기화 해주지 않는 이유는 C언어 철학상 프로그래머를 믿기 때문이다.
    
- ### [12.6] 레지스터 변수
    
    레지스터는 cpu의 일부이고, 메모리는 램의 일부이다
    
    레지스터는 메모리처럼 작동할 수 있다.
    
    cpu의 일부라 메모리보다 빠르게 작동한다.
    
    빠른 작업이 필요할 때 register 키워드 사용할 수 있다.
    
    ```c
    int main()
    {
    	register int r;
    	r = 123;
    
    	//printf("%p\n", &r);
    	//int* ptr = &r;
    
    	return 0;
    }
    ```
    
- ### [12.7] 블록 영역의 정적 변수
    
    블록영역의 함수에서 static을 선언하면
    
    그렇지 않은 함수의 영역과의 차이가 존재한다
    
    ```c
    void count()
    {
    	int ct = 0;
    	printf("count = %d %lld\n", ct, (long long)& ct);
    	ct++;
    
    	//TODO: return &ct;
    }
    ```
    
    함수를 실행할 때마다 초기화가 된다
    
    ```c
    void static_count()
    {
    	static int ct = 0;	// initialized only once!
    	printf("static count = %d %lld\n", ct, (long long)& ct);
    	ct++;
    
    	//TODO: return &ct;
    }
    ```
    
    선언된 ct가 한번만 초기화가 되고 전체 실행이 끝날 때까지 메모리를 가지고 있다.
    
- ### [12.8] 정적 변수의 외부 연결 external linkage
    
    static 변수들은 초기화를 안 해도 자동으로 알아서 0으로 초기화를 하지만
    
    특별한 일이 없다면 초기화 하는 것을 권장한다.
    
    영역 외에 선언된 전역 변수와 영역 안에 선언 된 지역변수 중에 이름이 같다면
    
    전역 변수가 숨겨진다.
    
    ```c
    extern int g_int;
    ```
    
    해당 파일 밖에 있는 변수, 다른 파일의 변수g_int을 가져올 수 있다.
    
    다른 소스 파일에서 변수를 가져 올 수는 있으나, 값을 초기화 할 수 없다.
    
    파일 영역(scope)에서는 초기화가 가능하나, 해당 파일에서 한번 초기화 했다면
    
    다른 파일에서 동시에 초기화 할 수는 없다.
    
- ### [12.9] 정적 변수의 내부 연결 internal linkage
    
    파일 외부에서 사용 가능한 변수가 있다면,
    
    다른 파일에서는 사용을 제한하고 해당 파일에서만 사용 가능하게 하는 것도 가능하다
    
    파일 영역(scope)에서 선언된 전역 변수에서 static 키워드를 사용하면 고정된 상태이면서
    
    다른 파일 영역(scope)에서는 사용 불가능하다.
    

- ### [12.11] 함수의 저장 공간 분류
    
    함수는 기본적으로 extern이라고 가정하고, 다른 파일에 있는 함수를 가져올 때 extern을 생략할 수 있다
    
    ```c
    int g_int = 123;
    
    void fun();
    void fun_second();
    
    int main()
    {
    	fun();
    	fun_second();
    	
    	return 0;
    }
    
    void fun()
    {
    	extern int g_int;
    
    	g_int += 10;
    
    	printf("g_int is fun() %d %p\n", g_int, &g_int);
    	
    }
    ```
    
    이렇게 되어있고 다른 파일에 fun_second()함수가 있다고 할때
    
    ```c
    extern int g_int;
    
    static void fun_second()
    {
    	g_int += 10;
    
    	printf("g_int is fun() %d %p\n", g_int, &g_int);
    
    }
    ```
    
    void fun_second() 함수에 static을 붙이면 링킹 에러가 나타난다.
    
    파일을 분리할 떄는 모듈이라는 개념으로 분리를 한다.
    
    같은 기능을 하는 함수를 모아서 파일 단위로 정리한다고 생각할 수 있다.
    
    해당 파일에서만 작동하는 함수를 만들고 싶다면 함수 앞에 static을 붙인다.
    
- ### [12.12] 난수 생성기 모듈 만들기 예제
    
    랜덤하게 숫자를 생성하는 모듈이다
    
    rand()라는 함수를 사용하면 난수를 생성할 수 있지만 실행할 때마다 값은 안 바뀌는 것을 알 수 있다.
    
    이때 seed를 바꾸어 주면 숫자가 변하는데, 수동으로 바꿔야 하는 번거로움이 있다. 이 때 time()을 사용한다.
    
    seed값이 자동으로 바뀌어서 설정되는 효과를 보여주게 된다.
    
    ```c
    //srand(3);	// random seed
    	srand((unsigned int)time(0));
    	for (int i = 0; i < 10; ++i)
    	{
    		printf("%d\n", rand());
    		//printf("%d\n", rand() % 6 + 1);
    	}
    ```
    
    오버플로우를 이용한 난수 생성 예시
    
    ```c
    unsigned int next = 1;
    
    	for (int i = 0; i < 10; ++i)
    	{
    		next = next * 1103515245 + 1234;
    		next = (unsigned int)(next / 65536) % 32768;
    		printf("%d\n", (int)next);
    	}
    ```
    
    난수 생성을 모듈로 쪼개서 작성 해보기
    
    main.c
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <time.h>
    #include "my_rand.h"
    
    int main()
    {
    	my_srand((unsigned int)time(0));
    
    	for (int i = 0; i < 10; ++i)
    	{
    		printf("%d\n", my_rand() % 6 + 1);
    	}
    
    	return 0;
    }
    ```
    
    my_rand.h 헤더파일
    
    ```c
    #pragma once
    
    int my_rand();
    void my_srand(unsigned int seed);
    ```
    
    my_rand.c
    
    ```c
    static unsigned int next = 1;
    
    int my_rand()
    {
    	next = next * 1103515245 + 1234;
    	next = (unsigned int) (next / 65536) % 32768;
    	
    	return (int)next;
    }
    
    void my_srand(unsigned int seed)
    {
    	next = seed;
    }
    ```
    
- ### [12.13] 메모리 동적 할당 (Dynamic Storage Allocation)
    
    저장공간분류|메모리에서의위치|지속 기간|영역|연결 상태|선언 방법 
    ---|---|---|---|---|--- 
    동적 할당 메모리|힙(heap)|프로그래머가 결정|NA|NA|운영체제에게 요청
    
    메모리를 요청과 반납을 프로그래머가 직접 작성하면서 관리 해주어야 함
    
    필요한 메모리의 크기를 미리 알 수 없는 경우
    
    즉, 컴파일 타임에는 메모리가 얼마인지 알 수 없고,런타임이 되어야 알 수 있는 경우에는
    
    힙(heap)에 있는 자유 공간을 이용해 동적 할당 메모리를 받아서 사용하는 것이다.
    
    동적 할당 메모리를 불러올 때에는 stdlib.h의 malloc을 사용한다.
    
    동적 할당 메모리를 사용한 후는 반납을 하는 함수인 free()를 사용해야 한다.
    
    malloc()은 void type 포인터를 반환한다. 포인터 연산을 사용할 수 없다.
    
    따라서 사용하는 쪽에서 자료형을 정해 포인터에 넣어줄 수 있다.
    
    ```c
    double* ptr = NULL;
    
    ptr = (double*)malloc(30 * sizeof(double));
    ```
    
    동적 할당 메모를 사용하고 후에 반납하고 나서 ptr을 출력하면
    
    메모리를 반환하였는데도 주소 값은 그대로 출력하는 것을 볼 수 있다.
    
    ptr은 변수이기 때문에 메모리를 반환하여도 주소의 이름은 계속 가지고 있는 것이다.
    
    일반적으로 메모리를 반환하고 ptr = NULL을 이용해 명확하게 초기화 할 수 있다.
    
    malloc함수를 사용해서 메모리를 받아왔을 때는 초기화 해주지 않는다.
    
    Java나 Python같은 다른 언어를 사용할 때에는 자동으로 메모리를 반납해 준다.
    
- ### [12.14] 메모리 누수와 free()의 중요성
    
    메모리를 반납을 하지 않으면 메모리 누수가 생김
    
    메모리를 일부러 누수 시켜 보는 예제
    
    ```c
    int main()
    {
    	printf("Dummy Output\n");
    
    	int* ptr_backup = NULL;
    
    	{
    		int n = 100000000;
    		int* ptr = (int*)malloc(n * sizeof(int));
    
    		if (!ptr)// if(ptr == NULL)
    		{
    			printf("Malloc() failed\n");
    			exit(EXIT_FAILURE);
    		}
    		for (int i = 0; i < n; ++i)
    			ptr[i] = i + 1;
    
    		printf("%d %d\n", ptr[0], ptr[1]);
    		
    		ptr_backup = ptr;
    
    		//free(ptr);
    		ptr = NULL;
    	}
    
    	// what happens ?
    	printf("%d %d\n", ptr_backup[0], ptr_backup[1]);
    	printf("Dummy Output\n");
    
    	return 0;
    }
    ```
    
    ptr이 영역(scope)을 벗어나면서 숨겨졌지만 동적 할당 메모리는 사라지지 않는다.
    
    여기서 영역(scope)을 벗어나기 전에 free(ptr)을 해주면 heap에 있던 메모리를 반납한다.
    
    ptr을 잃어버리기 전에 다른 스코프에 주소를 옮겨두면 누수 없이 메모리를 반납하거나 값을 바꿔줄 수 있다
    
    위의 작성한 프로그램을 반복 없이 for문으로 반복하면 메모리 한도에 도달해 문제가 발생한다.
    

- ### [12.15] 동적 할당 메모리를 배열처럼 사용하기
    
    동적 할당 메모리를 배열처럼 사용할 수 있다.
    
    ```c
    	/*
    		One variable
    	*/
    
    	int* ptr = NULL;
    
    	ptr = (int*)malloc(sizeof(int) * 1);
    	if (!ptr) exit(1);
    
    	*ptr = 1024 * 3;
    	printf("%d\n", *ptr);
    
    	free(ptr);
    	ptr = NULL;
    ```
    
     일반적인 변수를 사용해 동적 할당 메모리를 만든다.
    
    ```c
    	/*
    		1D array
    	*/
    
    	int n = 3;
    	int * ptr = (int*)malloc(sizeof(int) * n);
    	if (!ptr) exit(1);
    
    	ptr[0] = 123;
    	*(ptr + 1) = 456;
    	*(ptr + 2) = 789;
    	
    	free(ptr);
    	ptr = NULL;
    ```
    
    이렇게 1차원 배열로 작성할 수 있다.
    
    ```c
    	int row = 3, col = 2;
    	int(*ptr2d)[2] = (int(*)[2])malloc(sizeof(int) * row * col);
    	//int(*ptr2d)[col] = (int(*)[col])malloc(sizeof(int) * row * col);// VLA
    	if (!ptr2d) exit(1);
    
    	for (int r = 0; r < row; r++)
    		for (int c = 0; c < col; c++)
    			ptr2d[r][c] = c + col * r;
    	
    	for (int r = 0; r < row; r++)
    	{
    		for (int c = 0; c < col; c++)
    			printf("%d ", ptr2d[r][c]);
    		printf("\n");
    	}
    ```
    
    VLA로도 선언할 수 있지만, 컴파일러에 따라 지원을 하지 않을 수 있다.
    
    ```c
    	/*
    		Using 1D array as 2D arrays
    
    		row = 3, col = 2
    
    		(r,c)
    
    		2d
    		(0, 0) (0, 1)
    		(1, 0) (1, 1)
    		(2, 0) (2, 1)
    
    		1d
    		(0, 0) (0, 1)(1, 0) (1, 1)(2, 0) (2, 1)
    		 0		1	  2		 3	   4      5		= c + col * r
    	*/
    
    	
    	int row = 3, col = 2;
    	int* ptr = (int*)malloc(row * col * sizeof(int));
    	if (!ptr) exit(1);
    
    	for (int r = 0; r < row; r++)
    		for (int c = 0; c < col; c++)
    			ptr[c + col * r] = c + col * r;
    
    	for (int r = 0; r < row; r++)
    	{
    		for (int c = 0; c < col; c++)
    			printf("%d ", *(ptr + c + col * r));
    		printf("\n");
    	}
    	
    ```
    
    2차원 배열도 1차원으로 들어있는 메모리의 나열이기 때문에 열의 값을 넘길 때, 
    
    줄 바꿈을 하는 식을 세운다면 2차원 배열처럼 보일 수 있다.
    
- ### [12.16] calloc(), realloc()
    
    calloc(count, size) - contiguous allocation
    
    malloc과 비슷하지만 차이점은 malloc은 초기화를 해주지 않지만, calloc은 초기화를 해준다
    
    ```c
    	int n = 10;
    
    	int* ptr = NULL;
    
    	ptr = (int*)calloc(n, sizeof(int));// contiguous allocation
    	if (!ptr)
    		exit(1);
    
    	for (int i = 0; i < n; ++i)
    		printf("%d ", ptr[i]);
    	printf("\n");
    ```
    
    realloc()은 요청한 사이즈보다 커진다면 그대로 사이즈만큼 한번 더 복사하지만 초기화 해주진 않는다.
    
    ```c
    	/*
    		realloc() KNK p. 422
    		- doesn't initialize the bytes added
    		- returns NULL if can't enlarge the memory block
    		- If first argument is NULL, it behaves like malloc()
    		- if second argument is 0, it frees the memory block
    	*/
    
    	for (int i = 0; i < n; ++i)
    		ptr[i] = i + 1;
    
    	n = 20;
    
    	int* ptr2 = NULL;
    	ptr2 = (int*)realloc(ptr, n * sizeof(int));
    	//ptr = (int*)realloc(ptr, n * sizeof(int));
    
    	printf("%p %p\n", ptr, ptr2);
    
    	printf("%d\n", ptr[0]);
    
    	if (!ptr2)
    		exit(1);
    	else
    		ptr = NULL;
    
    	for (int i = 0; i < n; ++i)
    		printf("%d ", ptr2[i]);		// copies data
    	printf("\n");
    
    	free(ptr2);
    ```
    
- ### [12.18] 자료형 한정자들 const, volatile, restrict
    
    const의 특징은 여러 번 사용하여도 똑같이 적용된다.
    
    ```c
    	/*
    		const
    	*/
    
    	// C99 ideompotent
    	const const const int n = 6; // const int n = 6;
    
    	typedef const int zip;
    	const zip q = 8; // const const int zip
    
    	//const int i; // NOT inintialized!
    	//i = 12;	  // Error
    	
    	const int j = 123;
    	const int arr[] = { 1, 2, 3 };
    
    	float f1 = 3.14f, f2 = 1.2f;
    
    	const float* pf1 = &f1;
    	//*pf1 = 5.0f //Error
    	pf1 = &f2; // Allowed
    
    	float* const pf2 = &f1;
    
    	*pf2 = 6.0f;
    	//pf2 = &f2; //Error
    
    	const float* const pf3 = &f1;
    	//*pf3 = 7.0f; //Error
    	//pf3 = &pf2; //Error
    ```
    
    하지만 자료형에 한번 변수 앞에 한번 넣어주게 되면 변수 값과 자료형 둘 다 값을 바꿀 수 없다.
    
    ```c
    	/*
    		volatile
    		- Do not optimize
    		- (ex: hardward clock)
    	*/
    
    	volatile int vi = 1;	// volatile location
    	volatile int* pvi = &vi;	// points to a volatile location
    
    	int i1 = vi;
    
    	// ...
    
    	int i2 = vi;
    ```
    
    volatile은 휘발성이라는 뜻을 갖고 있지만, c언어에서는 최적화를 하지 않고 값이 유연하게 바뀔 수 있다고
    
    생각하면 된다.
    
    ```c
    	/*
    		restrict (__restrict in VS)
    		- sole initial means of accessing a data object
    		- compiler can't check this restriction
    	*/
    
    	int ar[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    	int* par = ar;
    	
    	int* __restrict restar = (int*)malloc(10 * sizeof(int));
    	if (!restar) exit(1);
    
    	ar[0] += 3;
    	par[0] += 5;
    	// par[0] += 8;
    
    	restar[0] += 3;
    	restar[0] += 5;
    	//restar[0] += 8; // Equalivalent
    
    	free(restar);
    ```
    
    restrict는 현재 선언된 변수를 통해서만 값을 바꾸는 한정자다.
    
- ### [12.19] 멀티쓰레딩
    
    멀티쓰레드는 하나의 프로그램으로 여러가지의 일을 동시에 처리할 수 있도록 해준다.
    
    C언어 자체에서 멀티쓰레드를 지원하지 않으므로 운영체제에서 지원하는 API를 사용한다.
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <Windows.h>

    //_Atomic int acnt = 0; //NA

    DWORD WINAPI ThreadFunc(void* data)
    {
	    int n = 1;
	    Sleep(1000);
	
	    //acnt += n;	//NA
	    printf("Printing from Thread \n");
	    return 0;
    }

    int main()
    {
	    HANDLE thread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);

	    if (thread)
		    WaitForSingleObject(thread, INFINITE);
    }
    ```

</br>

## Chapter 13.  파일 입출력

- ### [13.1] 파일 입출력의 작동 원리
    
    입출력 스트림은 버퍼를 사용한다.
    
    키보드 입력은 stdin을 사용한다.
    
    주소록 백업/복원, 게임 로드/세이브와 같이
    
    파일을 읽어오거나 저장하고 싶을 때
    
    C언어에서 파일 스트림은 두가지로 나누어진다.
    
    - 텍스트파일 IO스트림
        
        메모장 등으로 사람이 직접 읽기 위해 사용한다.
        
        fprintf()를 사용하여 데이터를 문자로 저장한다.
        
        예시 ) 23456(줄바꿈)(EOF)
        
        운영체제마다 인코딩 방식이 다르다.
        
        줄바꿈과 EOF도 운영체제마다 다르다
        
        - 줄바꿈
            - MS : \r,\n
            - MAC : \r
            - Linux : \n
        - EOF
            - MS : ^Z
            - MAC : ^D
            - Linux : 없음
    
    - 바이너리 파일 IO 스트림
        
        순수하게 데이터만 저장
        
        fwrite()를 이용하여 이진수를 저장
        
        운영체제마다 저장 방식이 다르다
        
        Big Endian 혹은 Little Endian 방식으로 저장
        
    
- ### [13.2] 텍스트 파일 입출력 예제
    
    메모장에 작성한 파일을 읽어 들이고 글자 수가 얼마인지 출력 해주는 프로그램 예제이다.
    
    ```c
    int main(int argc, char* argv[])
    {
    	int ch;
    	FILE* fr;	//TODO: file pointer to write
    
    	/*
    	typedef struct _iobuf
    	{
    		char* _ptr;
    		int	  _cnt;
    		char* _base;
    		int   _flag;
    		int   _file;
    		int   _charbuf;
    		int   _bufsiz;
    		char* _tmpfname;
    	} FILE;
    	*/
    
    	//const char* out_filename = "output.txt";	//TODO: Use this
    
    	unsigned long count = 0;
    
    	if (argc != 2)
    	{
    		printf("Usage: %s filename\n", argv[0]);
    		exit(EXIT_FAILURE);
    	}
    
    	if ((fr = fopen(argv[1], "r")) == NULL)	// Open a text file for reading
    	{
    		printf("Can't open %s\n", argv[1]);
    		exit(EXIT_FAILURE);
    	}
    
    	/*
    		fopen mode strings for text files
    		- r : reading
    		- w : creating-and-writing or over-writing
    		- a : appending or creating-and-writing
    		- r+: both reading and writing
    		- w+: reading and writing, over-writing or creating
    		- a+: reading and writing, appending or creating
    	*/
    
    	//TODO : open file to write with "w" mode string
    
    	while ((ch = fgetc(fr)) != EOF) // getc(fr)
    	{
    		//putc(ch, stdout); // same as putchar(ch);
    		fputc(ch, stdout);
    
    		//TODO : use fputs() to write a file stream!
    
    		count++;
    	}
    
    	fclose(fr);
    	//TODO: 
    
    	printf("FIlE %s has %lu characters\n", argv[1], count);
    
    	return 0;
    }
    ```
    
    fopen() mode를 “w”로 변경하면 입력된 파일을 그대로 복사도 가능하다
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <stdlib.h>
    
    int main(int argc, char* argv[])
    {
    	int ch;
    	FILE* fr, * fw;	//TODO: file pointer to write
    
    	const char* out_filename = "output.txt";
    
    	unsigned long count = 0;
    
    	if (argc != 2)
    	{
    		printf("Usage: %s filename\n", argv[0]);
    		exit(EXIT_FAILURE);
    	}
    
    	if ((fr = fopen(argv[1], "r")) == NULL)	// Open a text file for reading
    	{
    		printf("Can't open %s\n", argv[1]);
    		exit(EXIT_FAILURE);
    	}
    
    	if ((fw = fopen(argv[1], "w")) == NULL)
    	{
    		printf("Can't open %s\n", out_filename);
    		exit(EXIT_FAILURE);
    	}
    
    	while ((ch = fgetc(fr)) != EOF) // getc(fr)
    	{
    		//putc(ch, stdout); // same as putchar(ch);
    		fputc(ch, stdout);
    		fputc(ch, fw);
    		count++;
    	}
    
    	fclose(fr);
    	fclose(fw);
    
    	printf("FIlE %s has %lu characters\n", argv[1], count);
    	printf("Copied to %s\n", out_filename);
    
    	return 0;
    }
    ```
    
- ### [13.3] 텍스트 인코딩과 코드 페이지
    
    앞에서 작성한 프로그램으로 한글로 작성한 텍스트 파일을 읽어 들이도록 실행했을 때
    
    글자가 깨지는 것을 알 수 있다. 하지만 사본을 보면 다시 한글이 잘 보인다.
    
    문자를 저장할 때는 바이너리로 저장하고, 디코딩 할 때의 규칙을 모르기 때문에 한글이 깨진다.
    
    여기서 인코딩방식을 utf-8이 아닌 ansi로 바꾸면 콘솔창에서도 한글이 잘 보인다
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <stdlib.h>
    #include <Windows.h> // SetConsoleOutputCP()
    
    int main()
    {
    	const UINT default_cp = GetConsoleOutputCP();
    	printf("%u\n", default_cp);
    
    	int ch;
    	FILE* fr, * fw;
    
    	const char* in_filename = "원본.txt";
    	const char* out_filename = "사본.txt";
    
    	unsigned long count = 0;
    
    	if ((fr = fopen(in_filename, "r")) == NULL)	// Open a text file for reading
    	{
    		printf("Can't open %s\n", in_filename);
    		exit(EXIT_FAILURE);
    	}
    
    	if ((fw = fopen(out_filename, "w")) == NULL)
    	{
    		printf("Can't open %s\n", out_filename);
    		exit(EXIT_FAILURE);
    	}
    
    	SetConsoleOutputCP(CP_UTF8); // UTF-8 mode
    
    	while ((ch = fgetc(fr)) != EOF) // getc(fr)
    	{
    		//putc(ch, stdout); // same as putchar(ch);
    		fputc(ch, stdout);
    		fputc(ch, fw);
    		count++;
    	}
    
    	fclose(fr);
    	fclose(fw);
    
    	SetConsoleOutputCP(default_cp); // ISO 2022 Korean
    
    	printf("FIlE %s has %lu characters\n", in_filename, count);
    	printf("Copied to %s\n", out_filename);
    
    	return 0;
    }
    ```
    
- ### [13.4] 텍스트 파일 입출력 함수들
    
    콘솔창에서 입력한 문자들을 txt파일로 출력해보는 예제이다.
    
    fopen()의 r+모드는 읽기와 쓰기 둘 다 가능하지만, 파일이 없다면 종료한다.
    
    w+ 모드는 읽기와 쓰기가 가능하고, 파일이 없다면 생성하고, 입력한 문자들을 덮어쓰기 한다.
    
    a+ 모드 역시 읽기와 쓰기가 가능하고, 파일이 없다면 생성하고, w+와 다른 점은 덮어쓰지 않고 입력 받은 내용을 추가한다.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #define MAX 31
    
    int main(void)
    {
    	FILE* fp;
    	char words[MAX] = { '\0', };
    
    	const char* filename = "record.txt";
    
    	if ((fp = fopen(filename, "w+")) == NULL) // Try r+, w+, a+
    	{
    		fprintf(stderr, "Can't open \"%s\" file.\n", filename);
    		exit(EXIT_FAILURE);
    	}
    
    	while ((fscanf(stdin, "%30s", words) == 1) && (words[0] != '.'))
    		fprintf(fp, "%s\n", words);
    
    	rewind(fp); /* go back to beginning of file */
    
    	while (fscanf(fp, "%s", words) == 1)
    		fprintf(stdout, "%s\n", words);
    
    	if (fclose(fp) != 0)
    		fprintf(stderr, "Error closing file\n");
    
    	return 0;
    }
    ```
    
    fscanf()대신 fgets()를 쓸 수 있는데
    
    fscanf()와 fgets()의 차이점은 
    
    fscanf()는 한 줄에 여러 문자열을 넣더라도 출력할 때 띄어쓰기한 부분은 줄 바꿈으로 출력한다.
    
    fgets()는 띄어 쓰더라도 한 줄에 모두 입력 받기가 가능하다.
    
    ```c
    while ((fgets(words, MAX, stdin) != NULL) && (words[0] != '.'))
    	fputs(words, fp);
    ```
    
    위에 사용된 fscanf()와 사용법에서도 조금 차이를 보인다.
    
- ### [13.5] 바이너리 파일 입출력
    
    C11에서 fopen()에서 ‘x’ mode가 추가 되었는데, ‘x’ mode는 파일이 존재할 때, 덮어쓰지 않고 종료한다.
    
    ```c
    int main()
    {
    	/*
    	fopen() mode string for binary IO
    	- "rb", "wb", "ab"
    	- "ab+", "a+b"
    	- "wb+", "w+b"
    	- "ab+", "a+b"
    
    	C11 'x' mode fails if the file exists, instead of overwriting it.
    	- "wx", "wbx", "w+x", "wb+x", "w+bx"
    	*/
    
    	// Writing example
    	{
    		FILE* fp = fopen("binary_file", "wb");
    		
    		double d = 1.0 / 3.0;
    		int n = 123;
    		int* parr = (int*)malloc(sizeof(int) * n);
    		if (!parr) exit(1);
    		for (int n = 0; n < 123; ++n)
    			* (parr + n) = n * 2;
    
    		fwrite(&d, sizeof(d), 1, fp);
    		fwrite(&n, sizeof(n), 1, fp);
    		fwrite(parr, sizeof(int), n, fp);
    
    		fclose(fp);
    		free(parr);
    
    		// Total size is 8 * 1 + 4 * 1 + 123 * 4 = 504 bytes
    	}
    
    	// Reading examle, feof(), ferror()
    	{
    		FILE* fp = fopen("binary_file", "rb");
    		double d;
    		int n = 0;
    		fread(&d, sizeof(d), 1, fp);
    		fread(&n, sizeof(n), 1, fp);
    
    		int* parr = (int*)malloc(sizeof(int) * n);
    		if (!parr) exit(1);
    
    		fread(parr, sizeof(int), n, fp);
    
    		printf("feof = %d\n", feof(fp));
    
    		printf("%f\n", d);
    		printf("%d\n", n);
    		for (int i = 0; i < n ; ++i)
    			printf("%d ", *(parr + i));
    		printf("\n");
    
    		printf("feof = %d\n", feof(fp));
    
    		fread(&n, sizeof(n), 1, fp);		// read one more toward EOF
    
    		printf("feof = %d\n", feof(fp));	// returns non-zero at EOF
    		printf("ferror = %d\n", ferror(fp));// returns 0 : OK
    
    		fwrite(&n, sizeof(n), 1, fp);		// try writing to make an error
    
    		printf("ferror = %d\n", ferror(fp));// 0 is ok, non-zero otherwise.
    
    		fclose(fp);
    		free(parr);
    	}
    
    	return 0;
    }
    ```
    
- ### [13.6] 파일 임의 접근
    
    ```c
    /*
    	ABCDEF ...
    	Current position 0 and read -> A
    	Current position 1 and read -> B
    	...
    */
    
    int main()
    {
    	int ch;
    	long cur;
    
    	FILE* fp = fopen("test.txt", "r");
    
    	cur = ftell(fp);
    	printf("ftell() = %ld\n", cur);	//Runtime error
    
    	fseek(fp, 2L, SEEK_SET);
    	cur = ftell(fp);
    	printf("ftell() = %ld\n", cur);
    	ch = fgetc(fp);
    	printf("%d %c\n", ch, ch);
    	cur = ftell(fp);
    	printf("ftell() = %ld\n", cur);
    
    	fseek(fp, -2L, SEEK_CUR);
    	cur = ftell(fp);
    	printf("ftell() = %ld\n", cur);
    	ch = fgetc(fp);
    	printf("%d %c\n", ch, ch);
    
    	/* SEEK_END */
    
    	fseek(fp, 0L, SEEK_END);
    	ch = fgetc(fp);
    	printf("%d %c\n", ch, ch);
    
    	fseek(fp, -1L, SEEK_END);
    	ch = fgetc(fp);
    	printf("%d %c\n", ch, ch);
    
    	fseek(fp, -2L, SEEK_END);
    	ch = fgetc(fp);
    	printf("%d %c\n", ch, ch);
    
    	return 0;
    }
    ```
    
    파일에 있는 임의의 위치에 접근하는 방법이다.
    
    ```c
    fseek(fp, 2L, SEEK_SET);
    ```
    
    fseek함수를 사용해서 SEEK_SET을 이용하면 시작 점으로 가고 2L을 입력하면 2bytes 떨어진 곳으로 이동한다.
    
    SEEK_END를 사용하면 문자열 뒤에서부터 시작해 인수만큼 이동한다.
    
- ### [13.7] 기타 입출력 함수들
    
    
    ```c
    ungetc((int)ch, fp);
    ```
    
    읽어 들인 글자를 다시 버퍼에 집어넣는 함수이다.
    
    ```c
    char buffer[32] = ('\0', );
    
    setvbuf(fp, buffer, _IOFBF, sizeof(buffer)); // _IOLBF, _IOFBF, _IONBF
    ```
    
    setvbuf()함수는 버퍼의 설정을 바꿀 수 있는 함수이다.
    
    ```c
    fflush(fp);
    ```
    
    버퍼에 쌓여있던 데이터를 클리어하는 함수이다.
    
- ### [13.8] 텍스트 파일을 바이너리처럼 읽어보기
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <Windows.h>	// SetConsoleOutputCP()
    
    int main()
    {
    	FILE* fp = fopen("test.txt", "rb");
    
    	unsigned char ch;
    
    	SetConsoleOutputCP(CP_UTF8); // UTF-8 mode
    
    	while (fread(&ch, sizeof(unsigned char), 1, fp) > 0)
    	{
    		printf("%hhu %c", ch, ch);
    	}
    
    	fclose(fp);
    
    	return 0;
    }
    ```
    
    텍스트파일로 읽었지만 데이터는 바이너리로 저장되기 때문에
    
    출력도 바이너리로 가능하고, 문자로도 나타낼 수 있다.

</br>

## Chapter 14. 구조체

- ### [14.1] 구조체가 필요한 이유
    
    환자의 정보를 입력하는 프로그래밍을 한다고 했을 때,
    
    이름, 키, 몸무게를 입력하는데 환자 한명마다 변수를 입력하기에는 번거로울 것이다.
    
    그 때 사용하는 것이 배열이다.
    
    배열은 자료형이 같은 데이터 오브젝트들이 나열된 형태다.
    
    자료형이 서로 다르지만 함께 사용하면 편리한 데이터 오브젝트들끼리 모아놓을 수는 없을까?
    
    이 때 구조체를 사용한다. 태그 정도로 생각하면 될 것 같다.
    
    ```c
    /* Structures */
    
    struct Patient
    {
    	char name[MAX_NAME];
    	float height;
    	float weight;
    	int age;
    };
    
    struct Patient p1, p2, p3;  //structure variables
    //struct Patent pat[MAX_PATIENTS];
    ```
    
    구조체를 사용할 때 p1.name, p1.height, p1.weight 처럼 p1.[object]로 나올 수 있는데
    
    멤버p1에 대해 접근하고 싶을 때는 Dot(.) operator를 사용한다.
    
    ```c
    struct Patient // 쿠키틀
    {
    	// 이부분이 덩어리
    };
    ```
    
    구조체에서 struct patient를 쿠키틀같은 것으로, 중괄호{}안의 나머지를 덩어리라고 보면 된다.
    

- ### [14.2] 구조체의 기본적인 사용법
    
    구조체의 초기화 방법은 배열과 비슷하다. 배열과의 차이점은
    
    배열은 같은 자료형의 나열인데, 구조체는 선언한 구조체와 같은 순서로 나열한다.
    
    ```c
    struct person	/* Person is a tag of structure */
    {
    	char name[MAX];	//member
    	int age;		//member
    	float height;	//member
    };
    ```
    
    이렇게 구조체를 선언했다면
    
    ```c
    struct person princess = { "Naomi Scott", 18, 160.0f }; // name, age, height
    ```
    
    이렇게 나열 가능하고
    
    ```c
    struct person princess2 = {
    		"Naomi Scott",
    		18,
    		160.0f
    	};
    ```
    
    이렇게 작성해도 문법상으로 동일하다.
    
    ```c
    strcpy(princess.name, "Naomi Scott");
    princess.age = 18;
    princess.height = 160.0f;
    ```
    
    이렇게 따로 작성하는 것도 가능하고
    
    ```c
    /* Designated initializers */
    
    	struct person beauty = {
    		.age = 19,
    		.name = "Bell",
    		.height = 150.0f
    	};
    ```
    
    넣고 싶은 데이터를 지정해주면 순서대로 작성하지 않아도 가능하다.
    
    ```c
    struct person* someone;
    
    someone = &genie;
    //someone = (struct Person*)malloc(sizeof(struct Person));	// and free later
    
    /* Indirect member(ship) operator (or structure pointer operator) */
    
    someone->age = 1001;	// arrow(->) operator
    ```
    
    포인터로 사용한 구조체는 Dot(.) 대신 Arrow(→)를 사용한다.
    
    ```c
    /* typedef and structure */
    
    typedef struct person my_person;
    
    my_person p3;
    ```
    
    typedef를 사용하면 이후에는 struct를 사용하지 않고 my_person만으로 자료형처럼 변수를 선언할 수 있다.
    
    ```c
    typedef struct person person;
    
    person p4;
    ```
    
    일반적으로는 이렇게 사용을 많이하고
    
    ```c
    typedef struct {
    		char name[MAX];
    		char hobby[MAX];
    } friend;
    
    friend f4;
    ```
    
    이렇게 No tag로 선언한 다음 friend 단독으로 사용 가능하다.
    
- ### [14.3] 구조체의 메모리 할당
    
    구조체를 선언하는 자체로는 메모리를 할당하지 않는다.
    
    ```c
    struct Aligned
    	{
    		int a;
    		float b;
    		double c;
    	};
    ```
    
    이렇게 구조를 구성하겠다는 templete을 제시한 것이기 때문에 메모리를 할당하는 것은 아니다.
    
    ```c
    /* without padding
    	0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16
    	|a|float b|double c         | ? ? ?
    	1 + 4 + 8 = 13
    */
    
    /* with padding
    	0 1 2 3 4 5 6 7|8 9 10 11 12 13 14 15|16	
    	|char a|float b|double c		      	 |
    	4(char ?) + 4 + 8 = 16
    */
    ```
    
    메모리 패딩(padding)은 구조체의 비어있는 메모리만큼 채워 넣는 형식이다.
    
    32bit에서는 4 bytes씩, 64bit에서는 8 bytes씩 메모리를 보내는데 1word = 4bytes이다
    
    패딩을 하지않으면 메모리가 여러개로 나눠져서 전송하게 된다. 
    
    효율적으로 전송하기 위해 1word를 패딩을해서 한번에 전송하려고 한다.
    
    한번에 보내기 위해 컴파일러상에서 패딩을 해주는 것이다.
    
    패딩은 옵션에서 설정으로 바꿀 수 있다.
    

- ### [14.4] 구조체의 배열 연습문제
    
    구조체를 사용하여 책의 이름, 저자, 가격을 입력 받고 최종적으로 입력 받은 것들을 출력해주는 예제이다.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <string.h>
    #define MAX_TITLE 40
    #define MAX_AUTHOR 40
    #define MAX_BOOKS 3	/* maximum number of books */
    
    char* s_gets(char* st, int n)
    {
    	char* ret_val;
    	char* find;
    
    	ret_val = fgets(st, n, stdin);	// vs. scanf()
    	if (ret_val)
    	{
    		find = strchr(st, '\n');	// look for newline
    		if (find)					// if the address is not NULL
    			*find = '\0';			// place a null character there
    		else
    			while (getchar() != '\n')
    				continue;			// dispose of rest of line
    	}
    	
    	return ret_val;
    }
    
    struct book
    {
    	char title[MAX_TITLE];
    	char author[MAX_AUTHOR];
    	float price;
    };
    
    int main()
    {
    	struct book library[MAX_BOOKS] = { {"Empty","Empty", 0.0f}, }; /* array of book structures */
    
    	int count = 0;
    
    	while (1)
    	{
    		printf("Input a book title or press [Enter] to stop.\n>>");
    		if(s_gets(library[count].title, MAX_TITLE) == NULL) 
    			break;
    		if (library[count].title[0] == '\0')
    			break;
    			
    		printf("Input the author.\n>>");
    		s_gets(library[count].author, MAX_AUTHOR);
    
    		printf("Input the price.\n>>");
    		int flag = scanf("%f",&library[count].price);
    		while (getchar() != '\n')
    			continue;	/* clear input line */
    
    		count++;
    
    		if (count == MAX_BOOKS)
    		{
    			printf("No more books.\n");
    			break;
    		}
    
    		if (count > 0)
    		{
    			printf("\nThe list of books:\n");
    			for (int index = 0; index < count; index++)
    				printf("\"%s\" written by %s: $%.1f\n", library[index].title, library[index].author, library[index].price);
    		}
    		else
    			printf("No books to show.\n");
    	}
    
    	return 0;
    }
    ```
    

- ### [14.5] 구조체를 다른 구조체의 멤버로 사용하기
    
    구조체를 사용하였을 때, 좀 더 간결하고, 재사용이 가능하고, 코딩 시간을 줄여준다.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #define LEN 20
    
    struct names 
    {
    	char given[LEN];
    	char family[LEN];
    };
    
    struct reservation		// Another structure
    {	
    	struct names guest;	// a nested structure
    	struct names host;	// one more nested structure
    	char food[LEN];
    	char place[LEN];
    
    	// time
    	int year;
    	int month;
    	int day;
    	int hours;
    	int minutes;
    
    };
    
    int main()
    {
    	struct reservation res = {
    		.guest = {"Nick", "Carraway"},
    		.host = {"Jay", "Gatsby"},
    		.place = {"the Gatsby mansion"},
    		.food = {"Escargot"},
    		.year = 1925,
    		.month = 4,
    		.day = 10,
    		.hours = 18,
    		.minutes = 30
    	};
    	
    	printf("Dear %s %s,\n", res.guest.given, res.guest.family);
    	printf("I would like to serve you %s.\n", res.food);
    	printf("Please visit %s", res.place);
    	printf("on %d/%d/%d at %d:%d.\n", res.day, res.month, res.year, res.hours, res.minutes);
    	printf("Sincerely,\n%s %s", res.host.given, res.host.family);
    
    	return 0;
    }
    ```
    
- ### [14.6] 구조체와 포인터
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #define LEN 20
    
    struct names
    {
    	char given[LEN];
    	char family[LEN];
    };
    
    struct friend
    {
    	struct names full_name;
    	char mobile[LEN];
    };
    
    int main(void)
    {
    	struct friend my_friends[2] = {
    		{ {"Ariana", "Grande"}, "1234-1234" },
    		{ {"Taylor", "Swift"}, "6550-8888" }
    	};
    
    	struct friend* girl_friend;
    
    	girl_friend = &my_friends[0];
    
    	printf("%zd\n", sizeof(struct friend));
    	printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);
    	// -> : indirect member access operator
    
    	girl_friend++;
    
    	printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.given);
    	// . has higher precedence than *
    
    	return 0;
    }
    ```
    
    구조체를 이용해서 포인터를 사용할 때
    
    ```c
    printf("%lld %s\n", (long long)girl_friend, girl_friend->full_name.given);
    ```
    
    arrow(→) 연산자도 가능하지만
    
    ```c
    printf("%lld %s\n", (long long)girl_friend, (*girl_friend).full_name.given);
    ```
    
    괄호를 사용해서 *을 붙이고 dot(.)을 사용하는 것도 가능하다.
    
    출력 했을 때
    
    ```c
    60
    5241820 Ariana
    5241880 Taylor
    ```
    
    구조체 사이즈인 60만큼 주소 차이가 난다는 것을 알 수 있다.
    
    다른 예제를 하나 더 알아보자
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <stdlib.h>
    
    struct my_data
    {
    	int a;
    	char c;
    	float arr[2];
    };
    
    int main()
    {
    	struct my_data d1 = { 1234, 'A', };
    
    	d1.arr[0] = 1.1f;
    	d1.arr[1] = 2.2f;
    
    	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
    	printf("%f %f\n", d1.arr[0], d1.arr[1]);
    	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);
    
    	struct my_data d2 = d1;
    
    	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
    	printf("%f %f\n", d2.arr[0], d2.arr[1]);
    	printf("%lld %lld\n\n", (long long)&d2.arr[0], (long long)&d2.arr[1]);
    
    	return 0;
    }
    ```
    
    구조체도 그대로 대입이 가능하다.
    
    ```c
    struct my_data d2 = d1;
    ```
    
    출력을 해보았을때
    
    ```c
    //d1
    1234 A 20446552
    1.100000 2.200000
    20446552 20446556
    
    //d2 = d1
    1234 A 20446528
    1.100000 2.200000
    20446528 20446532
    ```
    
    d2의 구조체에 d1을 복사해도 값은 그대로 복사 되지만, 메모리도 그대로 복사하는 것은 아니다.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <stdlib.h>
    
    struct my_data
    {
    	int a;
    	char c;
    	float* arr;
    };
    
    int main()
    {
    	struct my_data d1 = { 1234, 'A', NULL };
    	d1.arr = (float*)malloc(sizeof(float) * 2);
    	d1.arr[0] = 1.1f;
    	d1.arr[1] = 2.2f;
    
    	printf("%d %c %lld\n", d1.a, d1.c, (long long)d1.arr);
    	printf("%f %f\n", d1.arr[0], d1.arr[1]);
    	printf("%lld %lld\n\n", (long long)&d1.arr[0], (long long)&d1.arr[1]);
    
    	struct my_data d2 = d1;
    
    	printf("%d %c %lld\n", d2.a, d2.c, (long long)d2.arr);
    	printf("%f %f\n", d2.arr[0], d2.arr[1]);
    	printf("%lld %lld\n\n", (long long)& d2.arr[0], (long long)& d2.arr[1]);
    
    	return 0;
    }
    ```
    
    구조체를 동적 할당 메모리로 받는 예제이다.
    
    ```c
    d1.arr = (float*)malloc(sizeof(float) * 2);
    ```
    
    이번에는 출력 해보았을 때,
    
    ```c
    1234 A 11360504
    1.100000 2.200000
    11360504 11360508
    
    1234 A 11360504
    1.100000 2.200000
    11360504 11360508
    ```
    
    float* arr을 사용하는 같은 메모리에 대한 공간을 가리키고 있기 때문에 주소 값을 그대로 복사한다.
    
    구조체도 배열과 포인터에 따라 결과 값이 다르다.
    
    차이를 이해한다면 실수도 줄일 수 있을 것이다.
    
- ### [14.7] 구조체를 함수로 전달하는 방법
    
    포인터와 구조체를 이용하여 투자금과 저축을 더하는 예제이다
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <string.h>
    #define FUNDLEN 50
    
    struct fortune
    {
    	char	bank_name[FUNDLEN];
    	double	bank_saving;
    	char	fund_name[FUNDLEN];
    	double	fund_invest;
    };
    
    double sum(double x, double y);
    
    int main()
    {
    	struct fortune my_fortune = {
    		"Wells-Fargo",
    		4032.27,
    		"JPMorgan Chase",
    		8543.94
    	};
    
    	printf("Total : $%.2f.\n",
    		//sum(&my_fortune.bank_saving, &my_fortune.fund_invest)
    		sum(&my_fortune)
    	);
    
    	return 0;
    }
    
    double sum(const double x, const double y)	//TODO: try pointers
    {
    	return x + y;
    }
    ```
    
    포인터를 사용할 수도 있지만
    
    ```c
    double sum(const double* x, const double* y)
    {
    	return *x + *y;
    }
    ```
    
    구조체를 그대로 함수의 인수로 넣어줄 수도 있다.
    
    인수는 다르지만 내용물은 같고 값이 복사가 된다.
    
    구조체의 내용이 많을 경우 복사하는데 시간이 더 걸릴 수 있다.
    
    ```c
    double sum(struct fortune mf)
    {
    	return mf.bank_saving + mf.fund_invest;
    }
    ```
    
    구조체의 내용이 많을 경우 값을 바꿀 필요가 없으면
    
    복사하는 시간을 줄이기 위해 주소만 가져오는 포인터를 사용한다.
    
    ```c
    double sum(const struct fortune *mf)
    {
    	return mf->bank_saving + mf->fund_invest;
    }
    ```
    

- ### [14.8] 구조체와 함수 연습문제
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <string.h>
    
    #define NLEN 30
    
    struct name_count 
    {
    	char first[NLEN];
    	char last[NLEN];
    	int num;
    };
    
    void receive_input(struct name_count*);
    void count_characters(struct name_count*);
    void show_result(const struct name_count*);
    
    int main()
    {
    	struct name_count user_name;
    
    	receive_input(&user_name);
    	count_characters(&user_name);
    	show_result(&user_name);
    
    	return 0;
    }
    
    void receive_input(struct name_count* ptr)
    {
    	int flag;
    
    	printf("Input your first name:\n>> ");	
    	//s_gets(ptr_nc->first, NLEN);
    	flag = scanf("%[^\n]%*c", ptr->first);
    	if (flag != 1)
    		printf("Wrong input");
    
    	printf("Input your last name:\n>> ");
    	//s_gets(ptr_nc->last, NLEN);
    	flag = scanf("%[^\n]%*c", ptr->last);
    	if (flag != 1)
    		printf("Wrong input");
    
    }
    
    void count_characters(struct name_count* ptr)
    {
    	ptr->num = strlen(ptr->first) + strlen(ptr->last);
    }
    void show_result(const struct name_count* ptr)
    {
    	printf("Hi, %s %s. Your name hs %d characters.\n", ptr->first, ptr->last, ptr->num);
    }
    ```
    
    구조체를 이용하여 이름과 이름의 글자 수를 출력 해주는 예제다.
    
    ```c
    flag = scanf("%[^\n]%*c", ptr_nc->first);
    ```
    
    scanf에서 [^\n]은 줄 바꿈이 나타날 때까지 입력을 받으라는 뜻이고 %*c는 글자 하나를 무시하라는 뜻인데, 
    
    여기서는 줄 바꿈을 나타날 때까지 입력을 받고 줄 바꿈 하나를 무시하라는 뜻이 된다.
    
    Tip)
    
    c++에서는 구조체 안에 함수를 넣는 것도 가능하다
    
    객체지향 언어에서는 구조체는 데이터를 묶어 놓고, 기능까지 집어넣을 수 있는 것이 객체 지향 class이다.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <string.h>
    
    #define NLEN 30
    
    struct name_count
    {
    	char first[NLEN];
    	char last[NLEN];
    	int num;
    };
    
    struct name_count receive_input();
    struct name_count count_characters(struct name_count);
    void show_result(const struct name_count);
    char* s_gets(char* st, int n);
    
    int main()
    {
    	struct name_count user_name;
    
    	user_name = receive_input();
    	user_name = count_characters(user_name);
    	show_result(user_name);
    
    	return 0;
    }
    
    char* s_gets(char* st, int n)
    {
    	char* ret_val;
    	char* find;
    
    	ret_val = fgets(st, n, stdin);	// vs. scanf()
    	if (ret_val)
    	{
    		find = strchr(st, '\n');	// look for newline
    		if (find)					// if the address is not NULL
    			*find = '\0';			// place a null character there
    		else
    			while (getchar() != '\n')
    				continue;			// dispose of rest of line
    	}
    
    	return ret_val;
    }
    
    struct name_count receive_input()
    {
    	struct name_count nc;
    
    	int flag;
    
    	printf("Input your first name:\n>> ");
    
    	s_gets(nc.first, NLEN);
    
    	printf("Input your last name:\n>> ");
    
    	s_gets(nc.last, NLEN);
    
    	return nc;
    }
    
    struct name_count count_characters(struct name_count ptr)
    {
    	ptr.num = strlen(ptr.first) + strlen(ptr.last);
    
    	return ptr;
    }
    void show_result(const struct name_count ptr)
    {
    	printf("Hi, %s %s. Your name has %d characters.\n", ptr.first, ptr.last, ptr.num);
    }
    ```
    
    앞의 예제와 같지만 다른 스타일로 작성하는 예제이다.
    
- ### [14.9] 구조체와 할당 메모리
    
    앞의 예제와 같지만 동적 할당 메모리를 이용하여 작성하는 예제이다.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <string.h> // strlen(),strcmp()
    #include <stdlib.h> // malloc(),free()
    #define SLEN 81
    
    struct namect {
    	char* fname;	// Use malloc()
    	char* lname;	// Use malloc()
    	int letters;
    };
    
    void getinfo(struct namect*);			// allocate memory
    void makeinfo(struct namect*);
    void showinfo(const struct namect*);
    void cleanup(struct namect*);			// free memory when done
    
    int main()
    {
    	struct namect person;
    
    	getinfo(&person);
    	makeinfo(&person);
    	showinfo(&person);
    	cleanup(&person);
    
    	return 0;
    }
    
    void getinfo(struct namect* person)
    {
    	char buffer[SLEN] = { 0, };
    	int f2;
    
    	printf("Input your first name:\n>> ");
    	f2 = scanf("%[^\n]%*c", buffer);
    	if (f2 != 1)
    		printf("Worng input");
    	else
    	{
    		person->fname = (char*)malloc(strlen(buffer) + 1);
    		if (person->fname != NULL)
    			strcpy(person->fname, buffer);
    		else
    			printf("Malloc() failed");
    	}
    
    	printf("Input your last name:\n>> ");
    	f2 = scanf("%[^\n]%*c", buffer);
    	if (f2 != 1)
    		printf("Worng input");
    	else
    	{
    		person->lname = (char*)malloc(strlen(buffer) + 1);
    		if (person->lname != NULL)
    			strcpy(person->lname, buffer);
    		else
    			printf("Malloc() failed");
    	}
    	printf("%s %s\n", person->fname, person->lname);
    }
    
    void makeinfo(struct namect* person)
    {
    	person->letters = strlen(person->fname) + strlen(person->lname);
    }
    void showinfo(const struct namect* person)
    {
    	printf("Hi, %s %s. Your name has %d characters.\n", person->fname, person->lname, person->letters);
    }
    
    void cleanup(struct namect* person)
    {
    	free(person->fname);
    	free(person->lname);
    }
    ```
    

- ### [14.10] 복합 리터럴
    
    구조체의 값을 임시로 사용할 때 편하게 사용할 수 있는 복합 리터럴에 대해 알아보자
    
    ```c
    book_to_read = (struct book){ "Alice in Wonderland", "Lewis Carroll", 20.3f };
    ```
    
    복합 리터럴은 이렇게 사용한다.
    
    복합 리터럴은 L-value 이므로 주소를 가져와서 전달 할 수 있다.
    
    ```c
    struct rectangle rec1 = { 1.0, 2.0 };
    double area = rect_area(rec1);
    area = rect_area((struct rectangle) { 1.0, 2.0 });
    
    area = rect_area_ptr(&(struct rectangle) { .height = 3.0, .width = -2.0 }); // Designated initialized
    printf("%f\n", area);
    ```
    
    복합 리터럴의 주소를 가져와서 rect_area_ptr()함수에게 전달해주고 있다.
    
- ### [14.11] 신축성(Flexible)이 있는 배열 멤버
    
    배열이 신축성이 있다는 것은 길이가 변할 수 있다는 것을 의미한다.
    
    ```c
    struct flex
    	{
    		size_t count;
    		double average;
    		double values[];		// flexible array member (last member!)
    	};
    ```
    
    구조체에 배열을 선언하고
    
    ```c
    const size_t n = 3;
    
    struct flex* pf = (struct flex*)malloc(sizeof(struct flex) + n * sizeof(double));
    if (pf == NULL) exit(1);
    ```
    
    원하는 배열 만큼 n * sizeof(double)로 동적 할당한다.
    
    n의 값만큼 동적 할당 배열처럼 사용할 수 있다
    
- ### [14.12] 익명 구조체
    
    ```c
    struct names
    {
    	char first[20];
    	char last[20];
    };
    
    struct person
    {
    	int id;
    	struct names name;	// nested structure member
    };
    ```
    
    중첩 구조체는 구조체 안에 구조체를 다시 tag와 함께 사용하는 것이다.
    
    ```c
    struct person2
    {
    	int id;
    	struct { char first[20]; char last[20]; }; // anonymous structure
    };
    ```
    
    이렇게 사용하면 중첩 구조체와 비슷하지만 구조체 안에 구조체가 tag가 없는 것을 익명 구조체라고 한다.
    
    이는 뒤에 나오는 Union과 연결된다.
    
    ```c
    puts(ted.name.first);
    puts(ted3.name.first);
    ```
    
    중첩 구조체는 ted.name.first처럼 dot(.)을 두 번 사용해야하지만,
    
    ```c
    puts(ted2.first);
    ```
    
    익명 구조체는 member access가 한번 줄어들어 dot(.)을 한 번 사용한다.
    
- ### [14.13] 구조체의 배열을 사용하는 함수
    
    복합 리터럴을 사용해서 구조체의 배열을 초기화하고 출력하는 예제이다.
    
    ```c
    struct book
    {
    	char name[SLEN];
    	char author[SLEN];
    };
    
    void print_books(const struct book books[], int n);
    
    int main()
    {
    	struct book my_books[3];	// = {{"The Great Gatsby", "F. Scott Fitzgerald"}, ...};
    	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
    	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
    	my_books[2] = (struct book){ "The Odyssey", "Homer" };
    
    	print_books(my_books, 3);
    
    	return 0;
    }
    
    void print_books(const struct book books[], int n)
    {
    	for (int count = 0; count < n; ++count)
    		printf("Book %d : \"%s \" written by \"%s\"\n", count + 1, books[count].name, books[count].author);
    }
    ```
    
    출력 예시
    
    ```c
    Book 1 : "The Great Gatsby " written by "F. Scott Fitzgerald"
    Book 2 : "Hamlet " written by "William Shakespeare"
    Book 3 : "The Odyssey " written by "Homer"
    ```
    
    동적 할당 배열을 사용할 경우 어떻게 바뀌는지 작성 해보았다.
    
    ```c
    struct book my_books[3];	// = {{"The Great Gatsby", "F. Scott Fitzgerald"}, ...};
    ```
    
    이 부분을
    
    ```c
    struct book* my_books = (struct book*)malloc(sizeof(struct book) * 3);
    
    	if (!my_books)
    	{
    		printf("Malloc failed");
    		exit(1);
    	}
    ```
    
    이렇게 바꿔주면 동적 할당 배열로 사용할 수 있고, 초기화 경고 문구도 사라진다.
    
- ### [14.14] 구조체 파일 입출력 연습문제
    
    파일에 저장했던 구조체를 다시 읽어들이는 방법에 대해서 알아보자
    
    [14.13]에서 작성했던 책 제목과 저자를 구조체에 저장하고 txt파일로 내보내거나
    
    txt파일에 추가한 내용이 있다면 다시 출력해주는 예제이다.
    
    ```c
    void write_books(const char* filename, const struct book* books, int n)
    {
    	FILE* file = fopen(filename, "w");
    
    	if (file == NULL) 
    	{
    		fputs("Can't open file.", stderr);
    		exit(1);
    	}
    
    	fprintf(file, "%d\n", n);	// number of books
    
    	for (int i = 0; i < n; ++i)
    		fprintf(file, "%s %s\n", books[i].name, books[i].author);
    
    	fclose(file);
    }
    ```
    
    txt파일로 작성해주는 함수다.
    
    ```c
    struct book* read_books(const char* filename, int* n_ptr)
    {
    	FILE* file = fopen(filename, "r");
    
    	if (file == NULL)
    	{
    		fputs("Can't open file.", stderr);
    		exit(1);
    	}
    
    	int flag;
    	flag = fscanf(file, "%d%*c", n_ptr); // Remove last \n
    	if (flag != 1)
    	{
    		fprintf("File read failed");
    		exit(1);
    	}
    
    	struct book* books = (struct book*)calloc(sizeof(struct book), *n_ptr); // Note: calloc()
    
    	if (!books)
    	{
    		printf("Malloc() failed");
    		exit(1);
    	}
    
    	for (int i = 0; i < *n_ptr; ++i)
    	{
    		flag = fscanf(file, "%[^\n]%*c%[^\n]%*c", books[i].name, books[i].author);
    
    		if (flag != 2)
    		{
    			printf("File read failed");
    			exit(1);
    		}
    	}
    
    	fclose(file);
    
    	//*books_dptr = books;
    }
    ```
    
    추가된 내용이 있다면 다시 읽어서 출력해주는 함수다.
    
    ```c
    int main()
    {
    	int temp;
    	int n = 3;
    
    	struct book* my_books = (struct book*)malloc(sizeof(struct book) * n);
    
    	if (!my_books) {
    		printf("Malloc failed");
    		exit(1);
    	}
    
    	my_books[0] = (struct book){ "The Great Gatsby", "F. Scott Fitzgerald" };
    	my_books[1] = (struct book){ "Hamlet", "William Shakespeare" };
    	my_books[2] = (struct book){ "The Odyssey", "Homer" };
    
    	print_books(my_books, n);
    
    	printf("\nWriting to a file.\n");
    	write_books("books.txt", my_books, n);
    	free(my_books);
    	n = 0;
    	printf("Done.\n");
    
    	printf("\nPress any key to read data from a file.\n\n");
    	temp = _getch();
    
    	my_books = read_books("books.txt", &n);
    	//read_books2("books.txt", &my_books, &n);
    	print_books(my_books, n);
    	free(my_books);
    	n = 0;
    
    	return 0;
    }
    ```
    
    메인 함수는 이렇게 작성되었다.
    
- ### [14.15] 공용체의 원리
    
    공용체의 원리를 이해하기 위해서 메모리의 구조를 이해하는 것부터 시작한다.
    
    ```c
    union my_union 
    {
    		int		i;
    		double	d;
    		char	c;
    };
    ```
    
    형식은 서로 다른 자료형을 사용하는 것은 구조체와 비슷해 보이지만,
    
    구조체와의 차이점은 union은 메모리 공간을 같이 사용한다
    
    ```c
    union my_union uni;
    
    	printf("%zd\n", sizeof(union my_union));
    	printf("%lld\n", (long long)&uni);
    	printf("%lld %lld %lld\n", (long long)&uni.i, (long long)&uni.d, (long long)&uni.c);
    
    	union my_union save[10];
    
    	printf("%zd\n", sizeof(save));
    ```
    
    사이즈와 메모리 주소를 출력하면
    
    ```c
    8
    7339468
    7339468 7339468 7339468
    80
    ```
    
    같은 메모리 공간을 공유한다.
    
    [https://binaryconvert.com/](https://binaryconvert.com/)
    
    메모리 상의 이진법, 16진법 등을 쉽게 변환하여 볼 수 있다.
    
    공용체는 유연하게 사용 가능하지만, 의도를 명확하게 알 수 없고
    
    쉽게 실수 할 수 있다.

- ### [14.16] 공용체와 구조체를 함께 사용하기
    
    공용체를 활용하는 방법은 구조체와 함께 사용한다.
    
    ```c
    struct personal_owner {
    	char rrn1[7];	// Resident Registration Number
    	char rrn2[8];	// ex: 830422-1185600
    };
    
    struct company_owner {
    	char crn1[4];	// Company Registration Number
    	char crn2[3];	// ex: 111-22-33333
    	char crn3[6];
    };
    
    union data {
    	struct personal_owner	po;
    	struct company_owner	co;
    };
    ```
    
    이렇게 구조체를 선언하고 공용체 안에 선언한 구조체를 넣으면
    
    둘 중 하나만 필요한 데이터를 만들 때 유용하다.
    
    ```c
    struct car_data {
    	char model[15];
    	int status;	/* 0 = personal, 1 = company */
    	union data ownerinfo;
    };
    
    void print_car(struct car_data car)
    {
    	printf("---------------------------------\n");
    	printf("Car model : %s\n", car.model);
    
    	if (car.status == 0) /* 0 = personal, 1 = company */
    		printf("Personal owner : %s-%s\n", car.ownerinfo.po.rrn1, car.ownerinfo.po.rrn2);
    	else
    		printf("Company owner : %s-%s-%s\n", car.ownerinfo.co.crn1, car.ownerinfo.co.crn2, car.ownerinfo.co.crn3);
    	printf("---------------------------------\n");
    }
    ```
    
    자동차 소유주에 관한 정보를 입력하고 출력 할때, car.ownerinfo.po.rrn1 같이 출력하는데 사용할 수 있다.
    
- ### [14.17] 익명 공용체
    
    익명 구조체와 비슷한 면이 많다.
    
    ```c
    union data {
    	struct personal_owner	po;
    	struct company_owner	co;
    };
    
    struct car_data {
    	char model[15];
    	int status;	/* 0 = personal, 1 = company */
    	union data ownerinfo;
    };
    ```
    
    앞의 예제에서 사용한 공용체와 구조체를
    
    ```c
    struct car_data {
    	char model[15];
    	int status;	/* 0 = personal, 1 = company */
    	union {
    		struct personal_owner	po;
    		struct company_owner	co;
    	};
    };
    ```
    
    이렇게 ownerinfo 부분을 줄일 수 있다.
    
    ```c
    void print_car(struct car_data car)
    {
    	printf("---------------------------------\n");
    	printf("Car model : %s\n", car.model);
    
    	if (car.status == 0) /* 0 = personal, 1 = company */
    		printf("Personal owner : %s-%s\n", car.po.rrn1, car.po.rrn2);
    	else
    		printf("Company owner : %s-%s-%s\n", car.co.crn1, car.co.crn2, car.co.crn3);
    	printf("---------------------------------\n");
    }
    ```
    
    다른 함수에서도 ownerinfo를 없애서 간결하게 줄인다.
    
    ```c
    struct Vector2D{
    	union {
    		struct { double x, y;   };
    		struct { double i, j;   };
    		struct { double arr[2]; };
    	};
    };
    
    typedef struct Vector2D vec2;
    
    vec2 v = { 3.14, 2.99 };
    printf("%.2f %.2f\n", v.x, v.y);
    printf("%.2f %.2f\n", v.i, v.j);
    printf("%.2f %.2f\n", v.arr[0], v.arr[1]);
    ```
    
    2차원 벡터를 사용할 때 좋은 또 다른 예제다.
    
- ### [14.18] 열거형 (Enumerated Types)
    
    만약에 색깔을 넣는다고 가정했을 때, 색깔을 나타내는 자료형은 없으므로
    
    색깔에 정수를 넣어서 기억하는 식으로 프로그램을 작성해볼 수 있다.
    
    ```c
    int c = 0; // red:0, orange:1, yellow:2, green:3, ...
    if (c == 2)
    	printf("yellow");
    ```
    
    하지만 그 숫자에 무슨 색을 하기로 했는지 기억하기는 어렵다.
    
    이때 우리가 할 수 있는 방법으로는 
    
    ```c
    #define RED		1
    #define ORANGE	2
    #define YELLOW	3
    
    int c = YELLOW;
    if (c == YELLOW)
    	pirntf("yellow");
    ```
    
    define 매크로를 사용하는 것이다. 하지만 컴파일러 입장에서 YELLOW를 3으로 복사 붙여 넣는 식이기 때문에 오류를 잡아줄 수 없다.
    
    이 때 열거형이라는 문법을 사용하면 편하게 프로그래밍을 할 수 있다.
    
    열거형을 사용하면 가독성이 증가하고 유지 보수가 편하다
    
    사용하는 방법은 정수 상수에게 기호적인 이름을 붙여주는 것이다.
    
    ```c
    enum spectrum { red, orange, yellow, green, blue, violet };
    //               0     1     2       3      4     5  
    ```
    
    여기서 선언된 spectrum 열거형의 yellow는 정수형이지 문자열이 아니다
    
    ```c
    if (color == yellow)
    		printf("yellow");	//Note: enumerators are not strings
    ```
    
    문자열처럼 보이지만 가독성을 높이기 위해 바꾼 것일 뿐 내부는 정수형이다.
    
    ```c
    enum levels { low = 100, medium = 500, high = 2000 };
    
    	int scroe = 800; //TODO: user input
    	if (score > high)
    		printf("High score!\n");
    	else if (score > medium)
    		printf("Good job\n");
    	else if (score > low)
    		printf("Not bad\n");
    	else
    		printf("Do your best\n");
    ```
    
    점수대를 설정해서 가독성을 높일 수 있다.
    
- ### [14.20] 이름 공간(namespace) 공유하기
    
    프로그램 전체에서 이름이 인식될 수 있는 공간을 namespace라고 한다.
    
    ```c
    {
    		int myname = 345;
    		//double myname = 3.14;//ERROR
    }
    ```
    
    영역 안에 선언된 myname은 같은 영역 안에서는 같은 이름으로 선언 될 수 없다.
    
    ```c
    struct rect { double x; double y; };
    
    int rect = 123;	// OK in C (Not OPK in C++)
    struct rect rect = { 1.1, 2.2 };  // struct rect and rect are in different categories
    ```
    
    구조체의 rect와 변수의 rect는 category가 다르다고 할 수 있다. 그래서 같은 이름으로 사용할 수 있다.
    
    구조체 rect와 같은 태그의 rect도 사용 가능하다.
    
    이름이 겹치는 것은 헷갈리므로 추천하지 않는다.
    
    ```c
    int iamfunction()
    {
    	return 0;
    }
    
    int main()
    {
    	int iamfunction = iamfunction();//ERROR
    	
    	return 0;
    }
    ```
    
    함수에 사용된 이름을 변수로 다시 사용할 수 없다.
    
- ### [14.21] 함수 포인터의 원리
    
    함수 포인터는 다른 포인터처럼 주소 값을 저장하는 변수에 불과하다.
    
    어떠한 함수의 주소 값을 저장해줄 수 있는지는
    
    ```c
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
    ```
    
    이런 예제를 통해 알 수 있다.
    
    ```c
    void (*pf1)() = f1;
    ```
    
    함수의 포인터는 함수와 마찬가지로 자료형과 반환 값, 파라미터가 중요하다.
    
    함수의 주소 값을 저장하는 특이한 성질을 갖게 된다.
    
    ```c
    (*pf1)();//call f1 via pf1;
    //pf1();
    ```
    
    나중에 포인터를 통해 함수를 호출할 수 있다.
    
    함수 포인터의 성질은
    
    실행파일을 실행할 때, 운영체제에서 프로그램 자체를 메모리에 자체에 복사해서 올려야하는데
    
    프로그램 코드 자체가 저장되는 곳을 TEXT segment에 저장된다. TEXT segment는 읽기 전용이고
    
    만약 문자열 리터럴에 대한 주소만 가지고 있을 경우 포인터의 메모리에 접근해 값을 바꾸려고 시도하면
    
    런타임 에러가 발생한다.
    
    마찬가지로 함수 포인터도 주소 값을 가지고 있고 스택에 저장된다.
    
- ### [14.22] 함수 포인터의 사용 방법
    
    프로그래밍을 유연하게 만드는 함수 포인터의 사용 방법을 알아 보자.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <ctype.h> // toupper(), tolower()
    
    void ToUpper(char* str)
    {
    	while (*str)
    	{
    		*str = toupper(*str);
    		str++;
    	}
    }
    
    void ToLower(char* str)
    {
    	while (*str)
    	{
    		*str = tolower(*str);
    		str++;
    	}
    }
    ```
    
    이렇게 같은 자료형을 반환하는 함수는 함수 포인터를 사용하면 같이 사용할 수 있다
    
    ```c
    void (*pf)(char*);
    ```
    
    함수 포인터를 실행시키기 위해서는 함수의 반환 값과 파라미터를 알아야 하기 때문이다.
    
    ```c
    int main()
    {
    	char str[] = "Hello, World!";
    
    	void (*pf)(char*);
    
    	pf = ToUpper;	// Name of a function is a popinter
    	//pf = &ToUpper;// Acceptable
    	//pf = ToUpper(str);//Not acceptable in C
    
    	printf("String literal %lld\n", (long long)("Hello, World!"));
    	printf("Function pointer %lld\n", (long long)ToUpper);
    	printf("Variable %lld\n", (long long)str);
    
    	(*pf)(str);
    	//pf(str);	//K&R X, ANSI OK
    
    	printf("ToUpper %s\n", str);
    
    	pf = ToLower;
    
    	pf(str);
    
    	printf("ToLower %s\n", str);
    
    	return 0;
    }
    ```
    
    함수의 포인터를 통해 대문자를 바꿔주는 함수나, 소문자로 바꿔주는 함수를 둘 다 함수 포인터에 넣어서 사용할 수 있다.
    
    그렇다면 공통적인 부분을 묶어서 하나의 함수처럼 사용할 수 있지 않을까?
    
    공통적인 부분을 합치는 것도 함수 포인터를 통해 가능하다.
    
    ```c
    void UpdateString(char* str, int(*pf)(int))
    {
    	while (*str)
    	{
    		*str = (*pf)(*str);
    		str++;
    	}
    }
    ```
    
    함수 포인터를 매개변수로 받아서 실행시키는 방법이다.
    
    ```c
    /*
    		passing function pointers to functions
    */
    
    UpdateString(str, toupper);
    	
    printf("ToUpper %s\n", str);
    
    UpdateString(str, tolower);
    
    printf("ToLower %s\n", str);
    ```
    
    함수들을 조립해서 사용하는 느낌으로 사용한다.
    
- ### [14.23] 자료형에게 별명을 붙여주는 typedef
    
    typedef는 자료형의 이름을 새롭게 정의해준다.
    
    ```c
    typedef unsigned char BYTE;	//Note the scope of BYTE
    ```
    
    BYTE는 부호가 없는 문자형을 바꿔서 부르게 해준다. 하지만 이렇게 선언 한다고 해서
    
    이 외의 문자형을 못 쓰는게 아니다. 이름이 바뀌는 것이지 없던 자료형이 생겨나는 것은 아니다.
    
    긴 자료형을 짧게 줄여쓰기 위해 typedef를 사용한다.
    
    typedef를 통해 이식성이 높은 프로그래밍을 할 수 있다.
    
    typedef vs #define
    
    typedef 대신 #define를 사용하여 매크로를 설정해주는 것의 차이는
    
    #define은 전처리기에 속하기 때문에 컴파일 전에 단순히 치환된다.
    
    typedef는 컴파일러가 처리해준다.
    
    ```c
    #define STRING char *
    	
    STRING name, sign;
    ```
    
    #define으로 사용한 STRING은
    
    ```c
    char * name, sign;
    ```
    
    전처리기가 이렇게 단순히 복사해서 붙여 넣는 식으로 바꾼다.
    
    이렇게 되면 name만 포인터이고, sign은 char 자료형이 되어 문제가 발생할 수 있다.
    
    ```c
    typedef struct complex {
    		float real;
    		float imag;
    	} COMPLEX;	// typedef struct complex COMPLEX
    ```
    
    typedef를 구조체로 선언할 때는 이렇게 사용할 수 있다.
    
- ### [14.24] 복잡한 선언(Declaration)을 해석하는 요령
    
    선언을 할 때 복잡하게 느끼는 세 가지의 조합이다.
    
    ```c
    *	indicates a pointer
    ()	indicates a function
    []	indicates an array
    ```
    
    포인터(*), 우선순위, 함수의 매개변수인 괄호(), 배열을 의미하는 [] 까지 세 가지다.
    
    복잡한 선언을 해석할 때에는 먼저 안쪽부터 바깥쪽으로 읽고, *보다 ()와 []가 우선순위가 높다는 것을 기억하면 된다.
    
    ```c
    int* ap[10]; // Identifier ap is an array of pointers
    ```
    
    ap는 int 포인터의 10개 짜리 배열이라고 해석할 수 있다.
    
    typedef를 사용하면 더 쉽게 이해할 수 있다.
    
    ```c
    typedef int* pint;
    pint ap2[10];
    ```
    
    ap2는 pint의 10개 짜리 배열이고, pint는 int의 포인터라는 것을 알 수 있다.
    
    ```c
    void (*pf)(int);
    /*
    	void (*pf)(int);
    		   1		    1. pointer to
    			    2		2. function with int argument
    	 3				    3. returning void
    */
    ```
    
    마찬가지로 int를 매개변수로 갖는 포인터 함수라는 것을 알 수 있다.
    
    ```c
    int* (*x[10])(void);
    ```
    
    복잡하지만, 함수인데, 매개변수는 없고, int에 대한 포인터를 반환해주는 포인터의 배열인 것을 알 수 있다.
    
    불가능한 선언도 존재한다.
    
    ```c
    int f(int)[];  // Wrong
    ```
    
    함수는 배열을 반환 할 수 없다.
    
    그러나 배열에 대한 포인터를 반환할 수 있다.
    
    ```c
    int(*f(int))[];
    ```
    
    함수가 함수를 리턴할 수 없다
    
    ```c
    int g(int)(int); // Wrong
    ```
    
    그러나 함수의 포인터를 리턴할 수 있다.
    
    ```c
    int (*g(int))(int);
    ```
    
    함수의 배열은 불가능하지만, 함수의 포인터의 배열은 가능하다.
    
    ```c
    int a[10](int); //Wrong
    
    int (*x2[10])(int);  //OK
    ```
    
    typedef로 나누어보면
    
    ```c
    typedef int FCN(int);
    typedef FCN* FCN_PTR;
    typedef FCN_PTR FCN_PTR_ARRAY[10];
    FCN_PTR_ARRAY x3;
    ```
    
    이렇게 이해할 수 있다.
    
- ### [14.25] qsort 함수 포인터 연습문제
    
    함수 포인터의 장점을 이해하기 위한 예제다.
    
    빠른정렬 함수 qsort를 이용한 구조체를 정렬해보는 문제이다.
    
    ```c
    #define _CRT_SECURE_NO_WARNINGS
    #include <stdio.h>
    #include <stdlib.h>
    
    struct kid
    {
    	char name[100];
    	int height;
    };
    
    int compare(const void* first, const void* second);
    
    int main()
    {
    	struct kid my_friends[] = {
    		"Jack Jack", 40, "Geenie", 300, "Aladdin", 170, "Piona", 150
    	};
    
    	const int n = sizeof(my_friends) / sizeof(struct kid);
    
    	qsort(my_friends, n, sizeof(struct kid), compare);
    
    	for (int i = 0; i < n; i++)
    		printf("%s\t%d\n", my_friends[i].name, my_friends[i].height);
    
    	return 0;
    }
    
    int compare(const void* first, const void* second)
    {
    	if (((struct kid*)first)->height > ((struct kid*)second)->height)
    		return 1;
    	else if (((struct kid*)first)->height < ((struct kid*)second)->height)
    		return -1;
    	else
    		return 0;
    }
    ```