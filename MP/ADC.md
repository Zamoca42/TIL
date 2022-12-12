# A/D 변환(Conversion)

- A/D 변환
  - 센서신호 입력 등에 이용
- Sampling 속도
  - 최대 15000 sample/sec (200KHz / 13clock )
  - 속도가느리면높은주파수신호측정못함
- 입력전압 범위
  - 0V ~ AREF, AVCC, 내부전압
- 분해능 (Resolution) : 10 bit (0~1023)
  - 1bit : 0, 3 V
  - 2bit : 0, 1, 2, 3 V
- 변환된 디지털 데이터 변수
  - ADC(16bit) : ADCH(8bit), ADCL(8bit)
  - 사용방법
    - `int ADC1024;`
    - `ADC1024 = ADC;`

## AD 변환 프로그램 절차

1. AD 변환 초기화 설정

   - 입력핀(채널), 입력전압범위
   - ADC 기능 허용, ADC clock 설정
   - ADMUX = 0b00000000;
     - 입력전압범위 선택(bit 7,6) : AREF 입력
     - 채널선택(bit 4,3,2,1,0) : ADC0 입력
   - ADCSRA = 0b1000 0111;
     - ADC Enable(기능허용) : bit 7
     - 50~200 KHz ADC clock 사용 : bit 2,1,0
     - ADC Clock : 16MHz/128 = 125 KHz

2. AD 변환 시작

   - ADC 시작신호 : ADCSRA bit 6
   - ADCSRA = ADCSRA | 0b 0100 0000
     - AD 변환시작, 변환완료후 bit 6 이 0 이 됨

3. AD 변환 완료를 기다림

   - `While( (ADCSRA & 0b01000000) != 0); `
     - ADC 변환완료까지 기다림
     - 변환이 완료되면 bit6 가 0 이 됨

4. AD 변환 완료 후
   - 변환값을 ADC 에 저장
   - ADC1024 = ADC;
     - AD 변환 값 읽기
     - ADC1024 = 1024 \* V_in/V_ref, input
     - 10bit : 0~1023

## 레지스터

![스크린샷 2022-12-12 오후 11 53 13](https://user-images.githubusercontent.com/96982072/207077215-f7a7fb88-76d7-414d-92ee-44f8e853a7b6.png)

| REFS1 | REFS0 | 기준전압          |
| :---: | :---: | ----------------- |
|   0   |   0   | External AREF pin |
|   0   |   1   | External AVCC     |
|   1   |   0   | Internal 1.1V     |
|   1   |   1   | Internal 2.56V    |

| MUX 543210 | 채널  |
| :--------: | :---: |
|   000000   | ADC0  |
|   000001   | ADC1  |
|   000010   | ADC2  |
|   000011   | ADC3  |
|   000100   | ADC4  |
|   000101   | ADC5  |
|   000110   | ADC6  |
|   000111   | ADC7  |
|   100000   | ADC8  |
|   100001   | ADC9  |
|   100010   | ADC10 |
|   100011   | ADC11 |
|   100100   | ADC12 |
|   100101   | ADC13 |
|   100110   | ADC14 |
|   100111   | ADC15 |

![스크린샷 2022-12-12 오후 11 58 50](https://user-images.githubusercontent.com/96982072/207078111-93238520-28d6-4c7a-8c9a-0025093260ff.png)

- ADEN : ADC Enable
- ADSC : ADC Start Conversion
- ADIF : ADC interrupt Flag (ADC 완료시 set)
- ADIE : ADC interrupt Enable  
  (ADC 인터럽트 허가: AD변환종료가 이벤트)  
  `ISR( ADC_vect ) { }`
- ADATE : ADC Auto Trigger Enable

- 분주비표  
   | ADPS2 |ADPS1|ADPS0|N|
  |:---:|:---:|:---:|--|
  |0| 0| 1| 2|
  |0| 1| 0| 4|
  |0| 1| 1| 8|
  |1| 0| 0| 16|
  |1| 0| 1| 32|
  |1| 1| 0| 64|
  |1| 1| 1| 128|

- 단일변환모드 코드

  - `ADCSRA = 0b10000111;`
    - bit 7 : ADC enable
    - bit 210 : division 16000/128 = 125 KHz
  - `ADCSRA |= 0b01000000;`
    - bit 6 : ADC start
    - `while( (ADCSRA&0b01000000) != 0 ) { }`
      - 변환 종료되면 bit 6 가 0이 됨

## 가변저항(potentiometer) 원리 및 연결

![스크린샷 2022-12-13 오전 12 04 16](https://user-images.githubusercontent.com/96982072/207079326-ff8f62b0-9cfd-4c1e-88f5-098365c22da2.png)

- 아두이노 코드

  ```c
  #include <avr/io.h>
  int main()
  {
      int ADC1024;
      init();
      Serial.begin(9600);

      while (1)
      {
          ADC1024 = analogRead( A1 ); // A0~A15 : PF0~7, PK0~7
          Serial.print("ch1 = ");
          Serial.println(ADC1024);
      }
  }
  ```

- AVR 코드

  ```c
  #include <avr/io.h>

  int main()
  {
      int ADC1024;

      Serial.begin(9600);

      ADCSRA = 0b10000111; // ADC enable, ADC Clock 분주비(N)=128
      ADMUX = 0b00000001; //Vref, A1 입력설정

      while (1)
      {
          ADCSRA |= 0b01000000; // ADC start
          while ( (ADCSRA & 0b01000000) != 0 ) { } // AD 변환 완료를 기다림

          ADC1024 = ADC; //ADC1024=1024*Vin/Vref
          Serial.println(ADC1024);
      }
  }

  ```

- AVR : ADC interrupt

  ```c
  int ADC_ch0, ADC_ch1, ADC_ch2;
  int main()
  {
      ADC_init();
      sei();

      Serial.begin(9600);

      while (1)
      {
          Serial.print("ch0 = ");
          Serial.println(ADC_ch0);
          Serial.print("ch1 = ");
          Serial.println(ADC_ch1);
          Serial.print("ch2 = ");
          Serial.println(ADC_ch2);
          Serial.println("");

          _delay_ms(500);
      }
  }

  void ADC_init()
  {
    ADMUX = 0b00000000; //Vref, ADC0
    ADCSRA = 0b10000111; // ADC enable, ADC clock N
    ADCSRA = ADCSRA | 0b00001000;
    // ADC interrupt Enable
    ADCSRA = ADCSRA | 0b01000000; // ADC start
  }

  ISR( ADC_vect )
  {
    static char flag = 0; // channel 선택

    if ( flag == 0 ) // ch0
    {
        ADC_ch0 = ADC;
        ADMUX = 0b00000001; flag = 1; // ch1(A1) 으로 변경
    }
    else if ( flag == 1 )
    {
        ADC_ch1 = ADC;
        ADMUX = 0b00000010; flag = 2; // ch2(A2) 으로 변경
    }
    else if ( flag == 2 )
    {
        ADC_ch2 = ADC;
        ADMUX = 0b00000000; flag = 0; // ch0(A0) 으로 변경
    }

    ADCSRA |= 0b01000000; // ADC start
  }
  ```
