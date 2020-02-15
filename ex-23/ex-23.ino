#include "InfraredRemote.h"

#define IR_IN 4

void setup()
{
    Serial.begin(9600);
    pinMode(IR_IN, INPUT_PULLUP);
    Serial.flush();
    
}