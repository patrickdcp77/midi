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

void blink(){

  for (int i = 0; i <= 4; i++){
    digitalWrite(ledPin, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000);                      // wait for a second
    digitalWrite(ledPin, LOW);   // turn the LED off by making the voltage LOW
    delay(1000);                      // wait for a second
  }
}


void setup(){
  Serial.begin(31250);
  Serial.print(" programme en route ");
  pinMode(ledPin,OUTPUT);
  //digitalWrite(ledPin,LOW);

  //blink();

  digitalWrite(ledPin,LOW);
  
}

void checkMIDI(){
  do{
    if (Serial.available()){
      commandByte = Serial.read();//read first byte
      noteByte = Serial.read();//read next byte
      velocityByte = Serial.read();//read final byte

      Serial.print(" no note ");
      if (commandByte == noteOn){//if note on message
        //check if note == 60 and velocity > 0
        if (noteByte == 60 && velocityByte > 0){

          Serial.print(" oui do ");
          digitalWrite(ledPin,HIGH);//turn on led
        }
      }
    }
  }
  while (Serial.available() > 2);//when at least three bytes available
}
    

void loop(){
  checkMIDI();
  delay(100);
  digitalWrite(ledPin, LOW);//turn led off
}
