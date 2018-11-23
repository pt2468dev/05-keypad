#include <avr/io.h>
#include <util/delay.h>
#include "Keypad.h"

void KeyPad::init(void) {
  // Column pins: 4, 5, 6, 7
  // Set column pins as input port with internal pull up register
  DDRC = 0x0F;
  PORTC = 0xF0;
}
// Function to return which button is pressed
uint8_t KeyPad::get_pressed_button(void) {
  uint8_t index = 255;  // No key pressed
  for (uint8_t row = 0; row < 4; row ++) {
    // Set current row low, other rows high
    PORTC = ((~(1<<row)) | 0xF0);
    // Read column states
    for (uint8_t col = 0; col < 4; col ++) {
      if ((PINC & (1<<(4+col))) == 0) {
        while ((PINC & (1<<(4+col))) == 0);
        index = row * 4 + col;
        break;
      }
    }
  }  
  return index;
}