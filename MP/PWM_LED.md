# PWM

- Pulse Width Modulation의 약어
- 펄스(구형파) 폭 조절

![스크린샷 2022-12-06 오후 10 51 10](https://user-images.githubusercontent.com/96982072/205930513-e135e5d5-cd9a-4ebc-a37c-973a5aba1413.png)

- 주파수 f = 1/T
- 듀티사이클 D = W/T\*100[%]
  - ex) LED밝기, 모터제어 : 0~100%

![스크린샷 2022-12-06 오후 10 51 49](https://user-images.githubusercontent.com/96982072/205930799-1c09108d-317b-4857-8d2b-d8cb3eea9d04.png)

- 1 타이머 -> 2PWM

# 듀티 사이클 변화

![스크린샷 2022-12-06 오후 10 55 50](https://user-images.githubusercontent.com/96982072/205931091-7a1c7e2d-87fd-47f9-ab1e-4bd68590f6d3.png)

# 아두이노 방식 PWM(OC2B) 구동 프로그램

- 간단하지만 주파수가 고정
- PWM 연결핀 : 9(아두이노 핀번호)

```C
int main()
{ unsigned char key;
    pinMode(9, OUTPUT);
        // Direction for PWM, OC2B(PH6)
    DDRF = 0x0f; // Keypad input/output
    PORTF = 0b11111011;
        //keypad 내부 pull-up & keypad 두번째 세로줄 구동
    while(1)
    {
        key = PINF;
        switch ( key )
        {
         case 0b01111011 : analogWrite(9, 255); break;
         case 0b10111011 : analogWrite(9, 177); break;
         case 0b11011011 : analogWrite(9, 80); break;
         case 0b11101011 : analogWrite(9, 10); break;
        }
    } // while close
} // main close
```

# PWM 듀티사이클 조절 방법

- Fast PWM 방식

  ![스크린샷 2022-12-06 오후 11 39 55](https://user-images.githubusercontent.com/96982072/205941787-c5853365-bfcf-47a3-8be1-9bd115726734.png)

- TCNT2 [8bit]

  - 0 -> 255 증가 [1 cycle : 256 count]
  - 1 cycle = 1/16000000 초
  - 255가 지나면 다시 0count부터 시작

- OCR2B

  - 사용자가 설정할 수 있는 설정값
  - OCR2B = 100 일 때, TCNT2와 만나는 순간 5V에서 0V로 떨어짐
  - TCNT2 0count부터 다시 5V로
  - OCR2B = 200일 때  
    ![스크린샷 2022-12-06 오후 11 46 55](https://user-images.githubusercontent.com/96982072/205943483-7ccc048d-144c-4fb1-9029-e4754e7dc3e2.png)

- PWM - Phase Correct 방식

  ![스크린샷 2022-12-06 오후 11 48 59](https://user-images.githubusercontent.com/96982072/205944391-23fbcbca-05d7-420c-883c-5b4960e06f68.png)

  - PCPWM으로 줄여서 부름
  - TCNT2
    - 0 -> 255까지 증가 -> 1까지 감소
    - 1 cycle : 510 count
  - OCR2B = 200일 때  
    ![스크린샷 2022-12-06 오후 11 49 34](https://user-images.githubusercontent.com/96982072/205944396-9d704055-8583-4052-a519-3d3a1f83f25f.png)

# PWM 레지스터 설정

- PWM 파형 발생 모드 설정(WGM: Waveform Generation Mode)  
  ![스크린샷 2022-12-07 오후 11 46 40](https://user-images.githubusercontent.com/96982072/206210346-eb80f373-cebf-4de1-9e32-cb73d55c0833.png)

  | WGMn2 | WGMn1 | WGMn0 | 모드                |
  | ----- | ----- | ----- | ------------------- |
  | 0     | 1     | 1     | PWM : Fast          |
  | 0     | 0     | 1     | PWM : Phase correct |
  | 0     | 0     | 0     | Normal              |
  | 0     | 1     | 0     | CTC                 |

- Compare Output Mode(COM) 설정  
  ![스크린샷 2022-12-07 오후 11 50 39](https://user-images.githubusercontent.com/96982072/206210900-5258a8c1-bd7d-469e-b6c6-6c90e4048b35.png)

  - Fast PWM과 PC PWM 모두 설정 레지스터비트는 같다
  - OCR 값이 증가함에 따라 duty cycle 증가/감소를 결정
  - TCNT 와 OCR 레지스터가 동일한 값을 가질 때(Compare Match 가 발생할 때) PWM 출력핀에서 High(5V), Low(0V) 신호가 변경됨

    - 비반전 모드

      - 5V에서 OCR2B와 만나면 0V

    - 반전 모드
      - 0V에서 OCR2B와 만나면 5

- PWM 주파수 설정 (CS: Clock Select)

  - 원하는 PWM 발생 주파수 설정
  - PWM 주파수 계산 방법
    - fclk_io = 16000000 Hz, Tclk_io = 1/fclk_io
    - Fast PWM 방식
      - 주파수 f = fclk_io / (256 N) Hz
      - 주기 T = Tclk_io (256 N) sec
    - Phase Correct PWM 방식
      - 주파수 f = fclk_io / (510 N) Hz
      - 주기 T = Tclk_io (510 N) sec
  - N : 분주비 (Prescale factor) 설정 (CS210)

    - N = 1
      - TCCR2B = 0bXXXXX001;
    - N = 8
      - TCCR2B = 0bXXXXX010;
    - N = 32
      - TCCR2B = 0bXXXXX011;
    - N = 64
      - TCCR2B = 0bXXXXX100;
    - N = 128
      - TCCR2B = 0bXXXXX101;
    - N = 256
      - TCCR2B = 0bXXXXX110;
    - N = 1024
      - TCCR2B = 0bXXXXX111;

  - 주파수 설정 예시 (Fast PWM 방식)

    - TCCR2B = 0bxxxxx111
      - 분주비 N : 1024
    - Clock 주파수 (fclk/N)
      - 16,000,000 / 1024 = 15625 Hz
    - pwm 주파수
      - 15625 / 256 = 61 Hz
    - pwm 주기
      - 1 / 61 = 16.38 msec

  - 주파수 설정 예시 (Phase Correct PWM 방식)

    - TCCR2B = 0bxxxxx111
      - 분주비 N : 1024
    - Clock 주파수 (fclk / N)
      - 16,000,000 / 1024 = 15625 Hz
    - pwm 주파수
      - 15625 / 510 = 30.6 Hz
    - pwm 주기
      - 1 / 30.6 = 32.64 msec

  - Phase correct pwm 주기는 fast pwm 보다 약 2배 길어짐

## OC2B PWM설정 정리

![스크린샷 2022-12-08 오전 12 10 39](https://user-images.githubusercontent.com/96982072/206216141-ca5d1bde-8821-4ac0-8292-a399b2f5997e.png)

- 파형발생모드(waveform generation mode) 설정
  - (2A)Bit1,0 = 1,1
  - (2B)Bit3 = 0
  - 파형 : Fast PWM
- 반전/비반전 설정 (Compare Match Output Mode)
  - (2A)Bit5,4 = 1,0
  - 비반전 : OCR2B 증가에 따라 duty cycle 증가
- PWM 주파수 설정
  - (2B)bit2,1,0 = 1,1,1
    - 분주비 N = 1024
- Clock 주파수
  - fclk / 1024
  - 16,000,000 / 1024 = 15625 Hz
- fast pwm 주파수
  - 15625/256 (8bit up count)
  - 61 Hz
