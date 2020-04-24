#include <Arduino.h>
#include "Pong.hpp"
#include "constants.h"

void setup()
{
    Serial.begin(9600);
    Pong p;
    p.start();
}

void loop()
{
}
