#include "framework.h"

int main(void) {
  DDRB |= (1 << PORTB5);

  while (1) {
    PORTB |= (1 << PORTB5);
    delay(500);
    PORTB &= ~(1 << PORTB5);
    delay(500);
  }

  return 0;
}
