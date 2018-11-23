#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include <avr/io.h>

class SevenSegment {
  public:
    void init(void);
    void display(uint8_t number);
};

#endif // SEVEN_SEGMENT_H_