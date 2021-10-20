#pragma once

#include <Arduino.h>

class SR74HC595
{
public:
    SR74HC595(const uint8_t serialDataPin, const uint8_t clockPin, const uint8_t latchPin, const uint8_t _enable);

    void set(const uint8_t _pin, const bool _value);
    void AllOff();

 
private:
    uint8_t _clockPin;
    uint8_t _serialDataPin;
    uint8_t _latchPin;
    uint8_t _enable;
    uint8_t pinState;
    void updateShiftRegister();
};
