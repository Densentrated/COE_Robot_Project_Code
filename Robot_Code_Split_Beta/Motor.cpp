#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int cp0, int cp1, int pp) : controlPin0(cp0), controlPin1(cp1), pwmPin(pp) {
  pinMode(controlPin0, OUTPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(pwmPin, OUTPUT);
}

void Motor::rotate(int duration, bool direction) {
  if (direction) {
    digitalWrite(controlPin0, HIGH);                    
    digitalWrite(controlPin1, LOW);
    analogWrite(pwmPin, 255);  
  } else {
    digitalWrite(controlPin0, LOW);                    
    digitalWrite(controlPin1, HIGH);                         
    analogWrite(pwmPin, 255);              
  }

  delay(duration);
  stop();
}

void Motor::stop() {
  digitalWrite(controlPin0, LOW);                      
  digitalWrite(controlPin1, LOW);                   
  analogWrite(pwmPin, 0);            
}
