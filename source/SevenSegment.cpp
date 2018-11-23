#include <avr/io.h>
#include "SevenSegment.h"

void SevenSegment::init(void) {
  DDRL = 0xFF; // Set PORTL as output port
}

void SevenSegment::display(uint8_t number) {
  switch(number) {
    case 0: {
      PORTL = 0b00111111;
      break;
    }
    case 1: {
      PORTL = 0b00000110;
      break;
    }
    case 2: {
      PORTL = 0b01011011;
      break;
    }
    case 3: {
      PORTL = 0b01001111;
      break;
    }
    case 4: {
      PORTL = 0b01100110;
      break;
    }
    case 5: {
      PORTL = 0b01101101;
      break;
    }
    case 6: {
      PORTL = 0b01111101;
      break;
    }
    case 7: {
      PORTL = 0b00000111;
      break;
    }
    case 8: {
      PORTL = 0b01111111;
      break;
    }
    case 9: {
      PORTL = 0b01101111;
      break;
    }
    default: {
      PORTL = 0b00000000;
      break;
    }
  }
}