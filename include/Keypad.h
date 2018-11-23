#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <avr/io.h>

class KeyPad {
  public:
    void init(void);
    uint8_t get_pressed_button(void);
};

#endif // KEYPAD_H_