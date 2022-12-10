# 타이머 : 외부 펄스 입력

![스크린샷 2022-12-10 오후 8 02 34](https://user-images.githubusercontent.com/96982072/206851833-b2de61df-2ba0-424f-ab0e-ea448fef9ffd.png)

- PWM 주파수 계산

  - PWM 펄스 count
    - 펄스입력 : Timer 5 (입력 T5)
  - ISR 함수로 시간 측정
    - Timer 0 : interrupt 이용

- 모터 위치 및 속도 계산
  - 위치 계산 : 엔코더 센서 펄스 count
    - 펄스입력 : Timer 5 (입력 T5)
  - 속도계산 : ISR함수로 시간 측정
    - Timer 0 : interrupt 이용

## Timer 5 외부 펄스 Count

- 외부에서 입력되는 펄스의 개수를 센다
  - 외부에서 펄스가 T5(PL2, 47) pin에 입력될 때마다 TCNT5 값이 증가
  - TCNT5 : 16 bit 레지스터
  - TCCR5B = 0b00000xxx => xxx = 110 or 111
    - CSn2:n0 = 110 : falling edge (펄스가 내려갈 때)에서 TCNT5 증가
    - CSn2:n0 = 111 : rising edge (펄스가 올라갈 때)에서 TCNT5 증가

## 외부펄스 입력 회로 구성

- 외부펄스가 T5(PL2, 47) pin에 입력되는 경우
  - TCNT5를 이용하여 펄스 개수 count
  - 외부 펄스 : 스위치 사용

![스크린샷 2022-12-10 오후 8 08 39](https://user-images.githubusercontent.com/96982072/206852053-1cbd5599-584e-4562-8a08-da971ae262e3.png)

## 외부펄스 입력 프로그램

```c
#include <avr/io.h>

int main()
{
    DDRL = 0x00;
    PORTL = 0xFF;//SW

    Serial.begin(9600);

    TCCR5B = 0b00000110;
     //외부 펄스가 falling edge일때 TCNT5 값 증가
    //TCCR5B = 0b00000111;
     //외부 펄스가 rising edge일때 TCNT5 값 증가
    while(1) {
        Serial.println(TCNT5);
    }
}
```

## PWM 주파수 측정 프로그램

![스크린샷 2022-12-10 오후 8 24 58](https://user-images.githubusercontent.com/96982072/206852587-c3648656-8420-4818-af34-1ae2745e8602.png)

```c
#include <avr/io.h>
#include <avr/interrupt.h>

volatile int var_sec=0, old=-1;
volatile unsigned int T5, oldT5=0;
volatile unsigned int vel;

int main()
{
    Serial.begin(9600);

    // overflow interrupt 설정 : 타이머 0
    TCCR0B = 0b00000101; // Normal 모드, N=1024
    TCNT0 = 100; // 156 count : 100~255
    TIMSK0 = TIMSK0 | 0b00000001; // 오버플로 인터럽트 허가
    sei(); //전체 인터럽트 허가

    // pwm 설정 : 타이머 2
    TCCR2A = 0b00100011; // fast, 비반전
    TCCR2B = 0b00000111; //N=1024
    DDRH = 0xff; //PH6, OC2B, 9
    OCR2B = 200; // duty cycle 설정

    // 펄스입력 설정 : 타이머 5
    TCCR5B = 0b00000111; // T5(Rising Edge), PL2, 47

    while(1)
    {
     // Serial.println(var_sec);
     Serial.println(vel);
    }
}

ISR(TIMER0_OVF_vect) //0.01sec간격으로 실행(0.009984sec)
{
    static unsigned char count_10ms=0;
    static unsigned char count_100ms=0;

    TCNT0 = 100;
    count_10ms = count_10ms + 1;

    if( count_10ms==10 ) //0.1sec간격으로 실행
    {
        count_10ms = 0;
        count_100ms = count_100ms +1; }
    if( count_100ms==10 ) //1sec간격으로 실행
    {
        count_100ms = 0;
        var_sec = var_sec +1;

        if(var_sec == 60) var_sec = 0;
    // Serial.println(var_sec);
        calc_vel();
    }
}

void calc_vel() // 약 1초 간격으로 실행
{
    T5 = TCNT5;
    vel = (T5-oldT5)/0.9984;
    // 1초당 pwm 펄스 개수 -> pwm 주파수
    oldT5 = T5;
}
```
