/*Receive Midi
By Amanda Ghassaei
July 2012
<a href="https://www.instructables.com/id/Send-and-Receive-MIDI-with-Arduino/">

https://www.instructables.com/id/Send-and-Receive-...>

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

*/

#include <Arduino.h>

byte commandByte;
byte noteByte;
byte velocityByte;

byte noteOn = 144;
const int ledPin =  23;
//light up led at pin 13 when receiving noteON message with note = 60

void setup(){
  
  pinMode(ledPin,OUTPUT);
  
  }

void loop(){

//for (int i = 0; i <= 4; i++){
    digitalWrite(ledPin, LOW);  // turn the LED on (HIGH is the voltage level)
    delay(500);                      // wait for a second
    digitalWrite(ledPin, HIGH);   // turn the LED off by making the voltage LOW
    delay(500);                      // wait for a second
 // }

  delay(4000);
}
