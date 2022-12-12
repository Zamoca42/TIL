# Timer : Input Capture Interrupt - 초음파 센서 측정

![스크린샷 2022-12-12 오후 10 22 45](https://user-images.githubusercontent.com/96982072/207055749-ca22bdec-f6eb-4694-b246-7e69ece06f83.png)

![스크린샷 2022-12-12 오후 10 22 51](https://user-images.githubusercontent.com/96982072/207055736-a64d4a31-5d9c-4e01-9982-22fe864564d0.png)

- `Th = pulseIn(9, HIGH);`

  - Arduino 함수 `pulseIn()`

- 거리 (cm) = 초음파 속력(v) \* Th
  - Th = 왕복시간(T) / 2
  - 초음파 속력(v) = 0.017

## 프로그램 : 초음파 센서 구동 - 아두이노

```c
#include <avr/io.h>
void trig_pulse();

int main()
{
    long int Th;
    int distance;
    DDRF = 0xFF; // A0(PF0) trigger Out

    init();
    Serial.begin(9600);

    while(1)
    {
        trig_pulse();
        Th = pulseIn(48, HIGH); // 48 echo In
        distance = Th * 0.017;
        Serial.print("dist (cm) : ");
        Serial.print(distance);
    }
}

void trig_pulse()
{
    // trigger pulse A0(PF0) trigger
    PORTH = 0b0; _delay_us(2);
    PORTH = 0b1; _delay_us(10);
    PORTH = 0b0;
}

```

![스크린샷 2022-12-12 오후 10 28 52](https://user-images.githubusercontent.com/96982072/207056864-55f48693-cf49-4892-94e3-53d15c9c4863.png)

## (ICI 이용) 초음파센서 거리 측정

![스크린샷 2022-12-12 오후 10 31 57](https://user-images.githubusercontent.com/96982072/207057372-a953da8a-e464-4adc-b842-83a1b5d8641b.png)

- 거리(dist) = 초음파 속력(v) \* (왕복시간(T) / 2)

  - v = 340 m/sec
  - T = (n2 -n1) \* Tclk_tcnt5

- ICI (Input Capture Interrupt) 원리 - timer5

  - ICP5 핀에서 RE/FE 발생하면 - TCNT5 값이 ICR5 에 복사됨  
     ![스크린샷 2022-12-12 오후 10 34 10](https://user-images.githubusercontent.com/96982072/207057902-b968f63a-a41b-4df1-9fe3-e38c7dcd9127.png)

  - (ICI 허가 설정 후) 인터럽트 함수 실행됨
    `ISR(TIMER5_CAPT_vect) { }`  
    ![스크린샷 2022-12-12 오후 10 34 42](https://user-images.githubusercontent.com/96982072/207057908-577059fc-491a-44a7-82c5-cacdb77da820.png)

## ICI (Input Capture Interrupt) 설정 - 타이머 5

![스크린샷 2022-12-12 오후 11 00 52](https://user-images.githubusercontent.com/96982072/207064392-cd95a3fa-ec5a-4995-9966-e73bcd947304.png)

| N    | CS 52, 51, 50 |
| :--- | :-----------: |
| 1    |      001      |
| 8    |      010      |
| 64   |      011      |
| 256  |      100      |
| 1024 |      101      |
| FE   |      110      |
| RE   |      111      |

- (시스템 클럭 사용) TCNT5 숫자 증가 주기
  - Tclk_tcnt5 = Tclk_io \* N (내부 시스템 클럭 \* N)
- (외부 클럭 사용) TCNT5 숫자 증가
  - T5 핀에 입력되는 FE / RE 회수에 따라 증가
  - T5: PL2 pin, Arduino 47
- TCNT5의 1clock 주기
  - Tclk_tcnt5 = Tclk_io \* N
    = N/16000000 = N/16 usec
- 거리계산 예제

  ```
  N=8 (010)
  TCCR5B = 0b01000010 //RE
  TCCR5B = 0b00000010 //FE
  Tclk_tcnt5 = 8/16 = 0.5 usec

  dist [cm]
  = 340 [m/s] * T/2
  = 340 [m/s] * (N2 - N1) * N/16 (usec)/2 * 단위환산
  = 340 * 8/16 * (N2 - N1)/2 * 100cm/1m * 1s/(1,000,000usec)
  = 0.017 * (N2 - N1)/2 cm
  ```

## avr 초음파 센서 프로그램

```c
volatile int diff;

int main()
{
    int dist;
    Serial.begin(9600);
    // ICP5 interrupt, PL1 48
    TCCR5B = 0b01000010; //N=256(100), 8(010)
    TIMSK5 = 0b00100000;
    sei();

    while (1)
    {
        trigger_pulse();
        dist = (float)diff * 0.0085;

        Serial.print("dist (cm) : ");
        Serial.println(dist);
    }
}

void trigger_pulse()
{
    // generating trigger pulse on the pin A0(PF0)
    DDRF = 0xff;
    PORTF = 0b0;
    _delay_us(2);
    PORTF = 0b1;
    _delay_us(10);
    PORTF = 0b0;
}

ISR( TIMER5_CAPT_vect ) //ICP5: PL1, 48
{
    static char flag=1; // 1:RE, 0:FE
    static unsigned int n1_start, n2_end;

    switch ( flag )
    {
        case 1: // for ICI(RE)
            n1_start = ICR5; // copy TCNT5 at RE
            flag = 0; // to FE
            TCCR5B = TCCR5B & 0b10111111; //ICI : FE break;
        case 0: // for ICI(FE)
            n2_end = ICR5; // copy TCNT5 at FE flag=1; // to RE
            TCCR5B = TCCR5B | 0b01000000; //ICI : RE diff = n2_end - n1_start;
            TCNT5 = 0;
    }
}
```

- T/2 = diff(TCNT5변화)/2 \* 0.5
  - 0.5us = 1/16us(Tclk_io) \* 8(N)
- dist = sound vel \* time(T/2)
  - 340m/s \* 0.25us \* (100 cm/m)/(10^6 s/us) [cm]
