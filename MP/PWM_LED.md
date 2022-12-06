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
