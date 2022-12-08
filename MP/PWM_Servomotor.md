# PWM : 서보모터 (Servo motor)

- PWM 듀티사이클에 따라서 서보모터 각도 조정 가능 : 동작범위 (0도 ~ 180도)

  - 요구 주기(주파수) : 10~20 msec ( 50~100 Hz )
  - 주파수 결정 : Fast 비반전 pwm 사용 시 -> T = Tclk_io(256N)

    - T = (1/16000000) _ (1024 _ 256) = 약 17 msec (16.384 msec)
    - f = 1/T = 약 61 Hz (61.035 Hz)

  - OCR0B 결정 : Fast 비반전 pwm 사용시 -> 듀티사이클 = (OCR0B+1)/256\*100 (%)
    - 0도 : 0.64 / 16.384 = (1+OCR0B) / 256
      - OCR0B = 9
    - 90도 : 1.60 / 16.384 = (1+OCR0B) / 256
      - OCR0B = 24
    - 180도 : 2.56 / 16.384 = (1+OCR0B) / 256
      - OCR0B = 39

![스크린샷 2022-12-08 오후 10 45 49](https://user-images.githubusercontent.com/96982072/206462083-d89d6280-94be-4a23-8f09-f4ea21ab8261.png)

- 서보모터 구동을 위한 PWM 설정 (OC0B)

  - TCCR 설정
    - OC0B(Timer/Counter 0), Fast PWM, 비반전 mode, N=1024 (약61Hz)
      - TCCR0A = 0b00 _10_(COM0B1 0B0) _00_ _11_(WGM01 00)
      - TCCR0B = 0b0000 _0_(WGM02) _101_(CS02 01 00)

- OCR 설정
  - OCR0B = 9~39
    - OCR0B = 9 (0도)
    - OCR0B = 24 (90도)
    - OCR0B = 39 (180도)

## 서보모터 코드

```C
#include <avr/io.h>

int main()
{
    unsigned char key;
    DDRG = 0xff; // Direction for PWM, OC0B: PG5(4)
    TCCR0A = 0b00100011; // PWM setting
    TCCR0B = 0b00000101; // N = 1024
    DDRF = 0x0f; // Keypad
    PORTF = 0b11111011; //keypad pull-up and 2nd column
    OCR0B=9; // 0도 위치
    while(1)
    {
        key = PINF;
        switch ( key ) // keypad 두번째 세로줄(2열)
        {
            case 0b11101011 : OCR0B = 9; break; // sw0: 0도 위치
            case 0b11011011 : OCR0B = 24; break; // sw8: 90도 위치
            case 0b10111011 : OCR0B = 29; break; // sw5: 120도 위치
            case 0b01111011 : OCR0B = 39; break; // sw2: 180도 위치
        }
    } // while close
} // main close
```

- 0도(OCR = 9), 180도(OCR = 39)
- OCR0B : 1 증가 -> 모터회전 : 6도(180/30) 증가
