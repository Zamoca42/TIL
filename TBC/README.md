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
