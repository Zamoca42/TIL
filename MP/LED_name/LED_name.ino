// 본인 이름 마지막 글자를 Dot matrix에 작성하시오
// - 원하지 않는 LED가 켜지는 경우에는 LED가 깜박이는 현상이 나타나도 delay 시간을 늘려서 프로그램하시오
//    즉 원하지 않는 LED가 켜지지 않는 최소한의 delay 시간을 사용하시오. 
// 8*8 LED에 회로를 연결하고 가능한 글자를 크게 작성하시오.

#include <avr/io.h>

void LED_row(int);

int main()
{ 
  DDRA = 0b11111111; 
  DDRF = 0b11111111;
  while (1) 
  {
    LED_row(1);
    PORTF = 0b01111111;
    _delay_ms(2);
    LED_row(2);
    PORTF = 0b01000000;
    _delay_ms(2);
    LED_row(3);
    PORTF = 0b01000000;
    _delay_ms(2);
    LED_row(4);
    PORTF = 0b01000000;
    _delay_ms(2);
    LED_row(5);
    PORTF = 0b11111111;
    _delay_ms(2);
    LED_row(6);
    PORTF = 0b01000010;
    _delay_ms(2);
    LED_row(7);
    PORTF = 0b01000010;
    _delay_ms(2);
    LED_row(8);
    PORTF = 0b01000010;
    _delay_ms(2);
  }
}

void LED_row(int noRow) // row 선택
{
  switch (noRow) 
  {
    case 1 : PORTA = 0b11111110; break;
    case 2 : PORTA = 0b11111101; break;
    case 3 : PORTA = 0b11111011; break;
    case 4 : PORTA = 0b11110111; break;
    case 5 : PORTA = 0b11101111; break;
    case 6 : PORTA = 0b11011111; break;
    case 7 : PORTA = 0b10111111; break;
    case 8 : PORTA = 0b01111111; break;
  }
}
