// - DotMatrix 회로를 bread board 에 구성하고 아두이노 보드에 연결하시오.
// - DotMatrix 첫째 가로줄 8개 LED를 순차적으로 점등(turn on)/소등(turn off)하는 프로그램을 작성하시오

#include <avr/io.h>

int main() {
  unsigned long int i = 0;
  DDRA = 0b11111111;  //ground
  DDRF = 0b11111111;  //vcc
  // 첫번째 가로줄 LED 순차점등
  while (1)  // 무한반복
  {
    // PORTA = 0b00000000;
    // _delay_ms(1000);
    // PORTF = 0b00000001;
    // _delay_ms(1000);
    // PORTF = 0b00000010;
    // _delay_ms(1000);
    // PORTF = 0b00000100;
    // _delay_ms(1000);
    // PORTF = 0b00001000;
    // _delay_ms(1000);
    // PORTF = 0b00010000;
    // _delay_ms(1000);
    // PORTF = 0b00100000;
    // _delay_ms(1000);
    // PORTF = 0b01000000;
    // _delay_ms(1000);
    // PORTF = 0b10000000;
    // _delay_ms(1000);

    for(int i = 0; i < 8 ; i++)
    {
      LED_col(i);
      _delay_ms(1000);
    }
  }
}

void LED_col(int noCol)
{
  if(noCol == 1)
  { PORTF = 0b00000001; }
  else if(noCol == 2)
  { PORTF = 0b00000010; }
  else if(noCol == 3)
  { PORTF = 0b00000100; }
  else if(noCol == 4)
  { PORTF = 0b00001000; }
  else if(noCol == 5)
  { PORTF = 0b00010000; }
  else if(noCol == 6)
  { PORTF = 0b00100000; }
  else if(noCol == 7)
  { PORTF = 0b01000000; }
  else if(noCol == 8)
  { PORTF = 0b10000000; }
  
}