#include <Arduino.h>
#include "74HC595.h"

SR74HC595::SR74HC595(const uint8_t serialDataPin, const uint8_t clockPin, const uint8_t latchPin, const uint8_t enablePin)
{
    _clockPin = clockPin;
    _serialDataPin = serialDataPin;
    _latchPin = latchPin;
    _enable = enablePin;

    // define pins as outputs
    pinMode(clockPin, OUTPUT);
    pinMode(serialDataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
    pinMode(enablePin, OUTPUT);

    // set pins low
    digitalWrite(clockPin, LOW);
    digitalWrite(serialDataPin, LOW);
    digitalWrite(latchPin, LOW);
    digitalWrite(enablePin, HIGH); // OUTPUT WILL BE LOW 74HC595 WILL BE OFF
}

void SR74HC595::set(const uint8_t pin, const bool value)
{
    if (value) //==1
    {
        digitalWrite(_enable, LOW);
        bitSet(pinState, pin);
        updateShiftRegister();
    }
    else
    {
        bitClear(pinState, pin);
        updateShiftRegister();
     digitalWrite(_enable, HIGH);
    }
}
void SR74HC595::updateShiftRegister()
{
    digitalWrite(_latchPin, LOW);
    shiftOut(_serialDataPin, _clockPin, MSBFIRST, pinState);
    digitalWrite(_latchPin, HIGH);
}

void SR74HC595::AllOff()
{
    digitalWrite(_latchPin, LOW);
    digitalWrite(_latchPin, HIGH);
    digitalWrite(_enable, HIGH);
}

