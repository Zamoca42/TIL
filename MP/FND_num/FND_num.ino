//* 본인 학번중 뒤 4자리를 FND 에 표시하시오.
//- 예) 홍길동 12345678 인 경우 FND 에 5678 을 표시하시오

#include <avr/io.h>
typedef unsigned char U8;

void FND_Display(U8,U8,U8,U8);
U8 Font[16] = { 0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71};

int main()
{
  U8 d0, d1, d2, d3;
  DDRD = 0xFF; DDRK = 0xFF;
  
  while (1)
  {
    FND_Display(5, 1, 9, 6);
  }
}

void FND_Display(U8 digit3, U8 digit2, U8 digit1, U8 digit0)
{
  unsigned int no_delay=2;
  
  PORTD = 0b00001110; //우측 첫 번째
  PORTK = Font[digit0];
  _delay_ms(no_delay);

  PORTD = 0b00001101; //우측 두 번째
  PORTK = Font[digit1];
  _delay_ms(no_delay);

  PORTD = 0b00001011; //우측 세 번째
  PORTK = Font[digit2];
  _delay_ms(no_delay);

  PORTD = 0b00000111; //우측 네 번째
  PORTK = Font[digit3];
  _delay_ms(no_delay);

}