#define ENABLE_BASIC
#include "framework.h"

int main(void) {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);

  while (1) {
    // B5
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
    delay(500);

    // B4
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(12, LOW);
    delay(500);
  }

  return 0;
}
