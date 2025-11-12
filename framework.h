#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#define delay(time) _delay_ms(time);
#define interruptOn() sei();
#define interruptOff() cli();
#define A0 14
#define A1 15
#define A2 16
#define A3 17
#define A4 18
#define A5 19

enum m { OUTPUT, INPUT };

enum s { HIGH, LOW };

#ifdef ENABLE_BASIC
static void pinMode(uint8_t pin, uint8_t m) {
  if (pin >= 0 && pin <= 7) {
    uint8_t bit = pin;
    if (m == OUTPUT) {
      DDRD |= (1 << bit);
    } else {
      DDRD &= ~(1 << bit);
    }
  } else if (pin >= 8 && pin <= 13) {
    uint8_t bit = pin - 8;
    if (m == OUTPUT) {
      DDRB |= (1 << bit);
    } else {
      DDRB &= ~(1 << bit);
    }
  } else if (pin >= 14 && pin <= 19) {
    uint8_t bit = pin - 14;
    if (m == OUTPUT) {
      DDRC |= (1 << bit);
    } else {
      DDRC &= ~(1 << bit);
    }
  }
}

static void digitalWrite(uint8_t pin, uint8_t s) {
  if (pin >= 0 && pin <= 7) {
    uint8_t bit = pin;
    if (s == HIGH) {
      PORTD |= (1 << bit);
    } else {
      PORTD &= ~(1 << bit);
    }
  }

  if (pin >= 8 && pin <= 13) {
    uint8_t bit = pin - 8;
    if (s == HIGH) {
      PORTB |= (1 << bit);
    } else {
      PORTB &= ~(1 << bit);
    }
  }

  if (pin >= 14 && pin <= 19) {
    uint8_t bit = pin - 14;
    if (s == HIGH) {
      PORTC |= (1 << bit);
    } else {
      PORTC &= ~(1 << bit);
    }
  }
}

static uint8_t digitalRead(uint8_t pin) {
  if (pin >= 0 && pin <= 7) {
    uint8_t bit = pin;
    if (PIND & (1 << bit)) {
      return 1;
    } else {
      return 0;
    }
  }

  if (pin >= 8 && pin <= 13) {
    uint8_t bit = pin - 8;
    if (PINB & (1 << bit)) {
      return 1;
    } else {
      return 0;
    }
  }

  if (pin >= 14 && pin <= 19) {
    uint8_t bit = pin - 14;
    if (PINC & (1 << bit)) {
      return 1;
    } else {
      return 0;
    }
  }

  return 0;
}
#endif
