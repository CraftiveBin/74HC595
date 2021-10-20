#include <Arduino.h>
#include "74HC595.h"

SR74HC595 Zone(9,10,11,12); //DA,CL,LA,EN

void setup()
{
}
void loop()
{

for (int i = 0; i < 8; i++)
{
 Zone.set(i,HIGH);
}

delay(500);
Zone.AllOff();
delay(500);
}
