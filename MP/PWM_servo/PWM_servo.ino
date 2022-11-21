// 키패드 "A" "B" "C" "D"를 누름에 따라 다음과 같이 서보모터가 회전하도록 실험장치를 구성하시오
// - 키패드 "A" 를 누룰 때 : 서보모터 각도 0 도
// - 키패드 "B" 를 누룰 때 : 서보모터 각도 30 도
// - 키패드 "C" 를 누룰 때 : 서보모터 각도 150 도
// - 키패드 "D" 를 누룰 때 : 서보모터 각도 180 도

#include <avr/io.h>

int main() 
{
  unsigned char key;
  char zero = 9; // 0도 기준
  DDRG = 0xff;          // Direction for PWM, OC0B: PG5(4)
  TCCR0A = 0b00100011;  // PWM setting
  TCCR0B = 0b00000101;
  DDRF = 0x0f;         // Keypad
  PORTF = 0b11111110;  //keypad pull-up and 4nd column
  OCR0B = zero;           // 0도 위치
  
  while (1) 
  {
    key = PINF;
    
    switch (key)  // keypad 네번째 세로줄(2열)
    {
      // OCR0B = 1증가 -> 모터회전 6도 증가
      case 0b01111110 : OCR0B = zero; break;   // swA: 0도 위치
      case 0b10111110 : OCR0B = zero + 5; break;  // swB: 30도 위치
      case 0b11011110 : OCR0B = zero + 25; break;  // swC: 150도 위치
      case 0b11101110 : OCR0B = zero + 30; break;  // swD: 180도 위치
    }
  }  // while close 
} // main close