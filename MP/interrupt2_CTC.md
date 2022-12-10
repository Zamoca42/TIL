# 타이머 인터럽트 (Timer Interrupt)

## 이벤트(event) 설정방법 : 오버플로(overflow) 이벤트

- 오버플로 이벤트 발생시점

  - TCNT0, TCNT2 : 255 -> 0 일 때 발생

- 카운터 레지스터 (TCNT0/2) 동작 : Normal 모드
  - TCNT0/2 (8bit) : 0 에서 255까지 tp(Tclk_io\*N) 마다 1씩 증가
    - tp = Tclk_io(시스템 클럭 주기, 1/16M sec) \* N(Prescaler 분주비)
    - tp \* 256 시간마다 오버플로 이벤트 발생
- TCNT0/2 = 100 : TCNT0/2의 숫자가 설정 값(100)에서 255까지 증가
  - tp \* 156 시간마다 오버플로 이벤트 발생
  - Normal 모드, N = 1024, TCNT0 = 100 에서 오버플로 이벤트 발생 주기
    - tp = 1/16M \* 1024
    - tp \* 156 = 1/16M \* 1024 \* 156 = 0.009984 sec (거의 10msec)

## 이벤트 설정방법 : 비교일치(compare match) 이벤트

- 비교일치 이벤트 발생시점
  - OCR0A = K1, OCR0B = K2, OCR2A = K3, OCR2B = K4
  - TCNT0 == OCR0A/B, TCNT2 == OCR2A/B 일 때 비교일치 이벤트 발생
- 카운터 레지스터 (TCNTn) 동작
  - OCRnA/B = 155 (n = 0, 2)
  - 비교일치 이벤트 발생 직후에 TCNTn =0 설정
    - TCNTn의 숫자가 0에서 155까지 증가 후 0으로 돌아감 (156 count)
  - Normal 모드, N=1024 조건에서 비교일치 이벤트 발생주기
    - tp \* 156 시간마다 비교일치 이벤트 발생
      - tp = Tclk_io \* N = 1/16000000 \* 1024
      - tp \* 156 = 1/16000000 \_ 1024 \* 156 = 0.009984 sec (거의 10msec)

## (Normal Mode) 비교일치(compare match) 이벤트 발생주기

- Counter : TCNTn (8bit, 0~255)

  - OCRnA/B = 255 사용
    - TCNTn: 0~255까지 증가 (256 Count)
    - 1/16 μsec \* 256 = 16 μsec
  - OCRnA/B = 15, TCNTn = 0 (이벤트 발생 직후 설정해야 함)
    - TCNTn : 0~15까지 증가 (16 Count)
    - 1/16μsec \* 16= 1μsec 주기로 이벤트 발생
  - OCRnA/B = 155, TCNTn = 0 (이벤트 발생 직후 설정), N=1024 사용
    - TCNTn : 0 ~155 까지 증가(156 Count)
    - 1/16 μsec \* 156 \* 1024(N)= 9.984 msec (거의 10msec)

- 이벤트 발생 주기 Ts 결정 후 OCRnA/B 값 계산
  - tp = N \* Tclk_io = N/16000000
  - icount = Ts/tp = 1~256
  - OCRnA/B = icount-1
  - 비교일치 이벤트 발생 직후 TCNTn = 0 설정

## (Normal Mode) 비교일치 인터럽트

- Timer 2 출력 비교일치(Compare Match) 인터럽트
  - TCNT2 == OCR2A/B 일 때 비교일치가 발생했음을 알려주는 인터럽트 발생  
    (OCFnA/B set at the next timer clock cycle)
- 인터럽트 허가 설정 후
  - TCNT2 == OCR2A 일 때 다음 인터럽트 서비스 루틴 실행
    ```
    ISR( Timer2_COMPA_vect ) { }
    ```
  - TCNT2 == OCR2B 일 때 다음 인터럽트 서비스 루틴 실행
    ```
    ISR( Timer2_COMPB_vect ) { }
    ```
- Timer 0 에 대해서도 동일하게 설정 가능

- Timer/Counter2 출력 비교일치 인터럽트 A/B 허가(enable)
  - TIMSK2 레지스터 bit1에 1을 설정 (비교일치 인터럽트A 허가 설정)
  - TIMSK2 레지스터 bit2에 1을 설정 (비교일치 인터럽트B 허가 설정)
  - `sei()` 함수 실행
- 허가된 모든 인터럽트 중에서 event가 발생한 인터럽트의 서비스루틴(ISR)을 실행함

  - TCNT2 == OCR2*A* 이면 `ISR( TIMER2_COMPA_vect ) { }` 실행
  - TCNT2 == OCR2*B* 이면 `ISR( TIMER2_COMPB_vect ) { }` 실행

- 여러 interrupt가 동시에 발생하면 우선순위가 높은 인터럽트를 먼저 처리함

![스크린샷 2022-12-10 오후 7 22 54](https://user-images.githubusercontent.com/96982072/206849969-ca6df7ad-ca42-4d69-8348-c2e845c6e946.png)

## 타이머2 비교일치 인터럽트 A (normal mode)

```c
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int var_sec=0, old=-1;

int main()
{
 Serial.begin(9600);
 //TCCR2A = 0b00000000; // normal mode
 TCCR2B = 0b00000111; //N=1024
 OCR2A = 155;

 TIMSK2 = TIMSK2 | 0b00000010;
 sei();
 while(1)
 {
  if( !(var_sec == old) )
  {
   Serial.println(var_sec);
   old = var_sec;
   }
 }
}

ISR( TIMER2_COMPA_vect ) //0.01sec간격으로 실행
{
 static unsigned char count_10ms=0;
 static unsigned char count_100ms=0;

 TCNT2 = 0;
 count_10ms = count_10ms + 1;
 if( count_10ms==10 ) //0.1sec간격으로 실행
 {
  count_10ms = 0;
  count_100ms = count_100ms +1;
 }
 if( count_100ms==10 ) //1sec간격으로 실행
 {
  count_100ms = 0;
  var_sec = var_sec + 1;
  if(var_sec == 60) var_sec = 0;
 }
}

```

## "|" (Bit OR) 연산

![스크린샷 2022-12-10 오후 7 53 58](https://user-images.githubusercontent.com/96982072/206851548-691d6a87-731e-4139-bffd-b11456637c33.png)

## 타이머2 비교일치 인터럽트 B (normal mode)

```c
#include <avr/io.h>
#include <avr/interrupt.h>
volatile int var_sec=0, old=-1;
int main()
{
 Serial.begin(9600);
 //TCCR2A = 0b00000000; // normal mode
 TCCR2B = 0b00000111; //N=1024
 OCR2B = 155;

 TIMSK2 = TIMSK2 | 0b00000100;
 sei();

 while(1)
 {
  if( !(var_sec == old) )
  {
   Serial.println(var_sec);
   old = var_sec;
  }
 }
}

ISR( TIMER2_COMPB_vect ) //0.01sec간격으로 실행
{
 static unsigned char count_10ms=0;
 static unsigned char count_100ms=0;

 TCNT2 = 0;
 count_10ms = count_10ms + 1;

 if( count_10ms==10 ) //0.1sec간격으로 실행
 {
  count_10ms = 0;
  count_100ms = count_100ms +1;
 }

 if( count_100ms==10 ) //1sec간격으로 실행
 {
  count_100ms = 0;
  var_sec = var_sec + 1;
  if(var_sec == 60) var_sec = 0;
 }
}
```

## CTC mode

- Timer n 출력 비교일치 인터럽트
  - TCNTn == OCRnA -> 0 일 때 비교일치(compare match)가 발생했음을 알려주는 인터럽트 발생
  - 비교일치 발생후 TCNTn = 0 으로 자동 설정됨

## 타이머2 비교일치 인터럽트 A (CTC mode)

```c
#include <avr/io.h>
#include <avr/interrupt.h>
volatile int var_sec=0, old=-1;
int main()
{
 Serial.begin(9600);
 TCCR2A = 0b00000010;
 TCCR2B = 0b00000111; //N=1024
 OCR2A = 155;

 TIMSK2 = TIMSK2 | 0b00000010;
 sei();
 while(1)
 {
  if( !(var_sec == old) )
  {
   Serial.println(var_sec);
   old = var_sec;
  }
 }
}

ISR(TIMER2_COMPA_vect) //0.01sec간격으로 실행
{
 static unsigned char count_10ms=0;
 static unsigned char count_100ms=0;

 //TCNT2 = 0;
 count_10ms = count_10ms + 1;

 if( count_10m == 10 ) //0.1sec간격으로 실행
 {
  count_10ms = 0;
  count_100ms = count_100ms +1;
 }
 if( count_100ms == 10 ) //1sec간격으로 실행
 {
  count_100ms = 0;
  var_sec = var_sec +1;
  if(var_sec == 60) var_sec = 0;
 }
}

```
