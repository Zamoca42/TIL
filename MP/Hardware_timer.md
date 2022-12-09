# (인터럽트 이용) 하드웨어 시계 만들기

- 일정시간 간격 계산
- (일정시간 간격으로) 인터럽트 함수 실행

## Timer/Counter 를 이용한 일정간격 시간구현

- Counter 레지스터 (TCNT)
  - 내부/외부 펄스(Pulse)의 개수를 셀 수 있음.
- 시스템 클럭 펄스
  - 펄스 1주기(1 클럭)가 발생하는 시간이 있음.
  - 1 클럭 발생시간 : 0.0625 μsec (1/ 16 MHz)
- 시간 측정

  - 1 pulse 발생시간 : 0.0625 μsec
  - 256 pulse 발생시간 : 0.0625 \* 256 = 16 μsec

- Prescaler 사용시 256 pulse 시간
  - 16 \* (8, 64, 256, 1024) μsec => ( 0.128, 1.024, 4.096, 16.384 ) msec

## TCNT2 counter 설정 : 모드, 분주비

- Prescaler 사용시 256 pulse 시간
  - 16 \* (8, 64, 256, 1024) μsec

![스크린샷 2022-12-09 오후 9 58 19](https://user-images.githubusercontent.com/96982072/206707854-dffbaa26-68c2-4519-99e5-4edcb30428f4.png)

## TCNT2 counter 설정 : 초기값 설정

- Prescaler 사용시 256 pulse 발생시간
  - 16 \* (8, 64, 256, 1024) μsec
    - ( 0.128, 1.024, 4.096, 16.384 ) msec
- Counter : TCNT2 (8bit, 0~255) -> Ts 계산(count 주기)

  - 0 ~ 255까지 증가(256 Count)
    - 1/16μsec \* 256 = 16μsec
  - 240 ~ 255 까지 증가(16 Count)
    - TCNT2 = 240 -> 240부터 count 시작
    - 1/16μsec \* 16 = 1μsec
  - 100 ~ 255 까지 증가(156 Count)
    - TCNT2 = 100 -> 100부터 count 시작
    - 1/16 μsec \* 156 = 9.75 μsec
    - Prescaler 1024 => 9.75 \* 1024 = 9.984 msec (거의 10msec)

- overflow 이벤트 발생 주기 Ts 결정 후 TCNT2 초기값 계산

  - tp = N \* Tclk_io = N/16000000 (TCNT 숫자를 1 증가시키는데 걸리는 시간)
  - tp \* icount = Ts -> icount = Ts/tp = 1~256
  - TCNT2 = 256 - icount (Ts 에 해당하는 icount 만큼 숫자를 세도록 설정)

- 시간 조절 설정
  - Prescaler 분주비 N 설정(TCCRnB )
  - WGMn0,1,2 설정 (TCCRnA/B)
  - Counter TCNT2 설정

## 오버플로(overflow) 인터럽트

- Timer2 오버플로 인터럽트 (Overflow interrupt)
- 표준(Normal) 모드에서 TCNT2=255 -> 0 일 때 TCNT2가 오버플로라는 것을 알려주는 event 발생
- (인터럽트 설정 후) 이벤트 발생시 다음 인터럽트 서비스 루틴 실행.
  ```C
  ISR( TIMER2_OVF_vect ) { }
  ```
  _ISR 실행되는 동안 다른 프로그램 실행 일시중단_

## Timer Interrupt 실행을 위한 설정

- Timer/Counter2 오버플로(overflow) 인터럽트를 허가(enable)
  - TIMSK2 레지스터 bit 0에 1을 설정 (개별 인터럽트 허가 설정)
  - `sei()` 함수 실행
- 허가된 개별 인터럽트 중에서 event가 발생한 인터럽트 서비스 루틴(ISR)을 실행함

  - TCNT2에서 오버플로 이벤트가 발생하면 `ISR( TIMER2_OVF_vect ) { }` 실행

- `sei()` : 개별 허가된 인터럽트들을 실행가능한 상태로 만드는 함수
- `cli()` : 모든 인터럽트를 금지할 때 사용하는 함수
  - 하나의 인터럽트가 발생하면 cli() 기능이 수행되어 모든 인터럽트 금지됨
  - 해당 인터럽트가 처리된 후 다시 sei() 기능이 수행되어 인터럽트 금지를 해제함

![스크린샷 2022-12-09 오후 10 05 23](https://user-images.githubusercontent.com/96982072/206709580-ee794567-3fd3-46a5-bdd5-be2ba71f226d.png)


## 일정시간 간격 프로그램 (Normal mode, Overflow interrupt)

```c
#include <avr/io.h>
#include <avr/interrupt.h>
volatile int var_sec=0, old=-1;

int main()
{
    Serial.begin(9600);
    TCCR2A = 0b00000000; // normal mode
    TCCR2B = 0b00000111; // N=1024
    TCNT2 = 100; // 156 count

    TIMSK2 = 0b00000001;
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

ISR(TIMER2_OVF_vect) //0.01sec간격으로 실행
{
    static unsigned char count_10ms=0;
    static unsigned char count_100ms=0;

    TCNT2 = 100;
    count_10ms = count_10ms + 1;
    if( count_10ms==10 ) //0.1sec간격으로 실행
    {
        count_10ms = 0;
        count_100ms = count_100ms +1;
    }

    if( count_100ms==10 ) //1sec간격으로 실행
    {
        count_100ms = 0;
        var_sec = var_sec +1;
        if(var_sec == 60) var_sec = 0;
    }
}

```
