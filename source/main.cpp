#include <avr/io.h>
#include <util/delay.h>
#include "SevenSegment.h"
#include "Keypad.h"

int main(void) {
    KeyPad kp;
    SevenSegment seg7;
    kp.init();
    seg7.init();
    while(1) {
      uint8_t key = kp.get_pressed_button();
      if (key != 255) {
        seg7.display(key);
      }
    }
}