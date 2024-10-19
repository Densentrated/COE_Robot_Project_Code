/******************************************************************
 * SparkFun Inventor's Kit
 * Example sketch 05 -- PUSH BUTTONS
 * 
 *   Use pushbuttons for digital input
 * 
 *   Connect one side of the pushbutton to GND, and the other
 *   side to a digital pin. When we press down on the pushbutton,
 *   the pin will be connected to GND, and therefore will be read
 *   as "LOW" by the Arduino.
 *
 * This sketch was written by SparkFun Electronics,
 * with lots of help from the Arduino community.
 * This code is completely free for any use.
 * Visit http://learn.sparkfun.com/products/2 for SIK information.
 * Visit http://www.arduino.cc to learn about the Arduino.
 * 
 * Version 2.0 6/2012 MDG
 * Version 2.1 9/2014 BCH
/*****************************************************************/


  // variables to hold the pushbutton states


void setup()
{
  pinMode(6, OUTPUT);  
}

void loop()
{
  float potState = analogRead(A0);
  int brightness = potState/4;

  // if button1 or button 2 are pressed (but not both)
  analogWrite(6, brightness);
}
