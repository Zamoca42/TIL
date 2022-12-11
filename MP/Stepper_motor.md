# 스텝 모터 (Stepper motor)

- 스텝모터 구동원리

  - 그림에서 1, 2, 3, 4에 감긴 전선에 5V를 가하면 전자석이 S극이 됨.
  - 1, 2, 3, 4에 순서대로 5V를 가하여 영구자석 N극을 끌 어당기면 영구자석이 시계방향(CW)으로 회전하게 됨

    ![스크린샷 2022-12-11 오후 11 07 31](https://user-images.githubusercontent.com/96982072/206908485-27949311-da14-4b89-bde5-cc42d8becd79.png)

- 스텝모터 구동 프로그램
  - 아두이노 -> 모터 연결
    ```c
    void StepMotorCW(unsigned char i)
    {
        switch (i)
        {
            case 1: PORTF = 0b00000001; break;
            case 2: PORTF = 0b00000010; break;
            case 3: PORTF = 0b00000100; break;
            case 4: PORTF = 0b00001000; break;
        }
    }
    ```
    ```c
    void StepMotorCCW(unsigned char i)
    {
        switch (i)
        {
            case 1: PORTF = 0b00001000; break;
            case 2: PORTF = 0b00000100; break;
            case 3: PORTF = 0b00000010; break;
            case 4: PORTF = 0b00000001; break;
        }
    }
    ```

## 프로그램 : 스텝모터 구동

```c
volatile unsigned int var_sec=0, oldv=-1;
volatile unsigned int rev=0, oldr=-1;

int main()
{
    DDRF=0xff; Serial.begin(9600);
    // 비교일치B interrupt 설정 : 타이머 0
    TCCR0B = 0b00000101; // Normal 모드, N=1024
    OCR0B = 155; // 156 count : 0~155 -> 약10ms
    TIMSK0 = TIMSK0 | 0b00000100;
    // 비교일치 인터럽트B 허가
    sei(); //전체 인터럽트 허가

    while (1)
    {
        if( rev != oldr )
        {
            Serial.print("motor revolution = ");
            Serial.println(rev);
            oldr = rev;
        }
        if( var_sec != oldv )
        {
            Serial.print("elapsed time (sec) = ");
            Serial.println(var_sec);
            oldv = var_sec;
        }
    }
}

ISR(TIMER0_COMPB_vect) //약10msec간격으로 실행
{
    static unsigned char count_10ms = 0;
    static unsigned char count_100ms = 0, i=1;
    static unsigned int j=0;

    TCNT0 = 0;
    count_10ms = count_10ms + 1;
    StepMotorCW(i);
    i=i+1;

    if(i==5) { i=1; j=j+1;}
    if(j==512) { j=0; rev = rev+1; }
    if ( count_10ms == 10 ) //0.1sec간격으로 실행
    {
        count_10ms = 0;
        count_100ms = count_100ms + 1;
    }
    if ( count_100ms == 10 ) //1 sec간격으로 실행
    {
        count_100ms = 0;
        var_sec = var_sec + 1;
    }
}

// 모터 시계방향 회전
void StepMotorCW(unsigned char i)
{
    switch (i)
    {
        case 1: PORTF = 0b00000001; break;
        case 2: PORTF = 0b00000010; break;
        case 3: PORTF = 0b00000100; break;
        case 4: PORTF = 0b00001000; break;
    }
}
// 모터 반시계방향 회전
void StepMotorCCW(unsigned char i)
{
    switch (i)
    {
        case 1: PORTF = 0b00001000; break;
        case 2: PORTF = 0b00000100; break;
        case 3: PORTF = 0b00000010; break;
        case 4: PORTF = 0b00000001; break;
    }
}

```
