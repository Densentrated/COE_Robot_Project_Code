#include "DriveTrain.h"
#include "Arduino.h"

DriveTrain::DriveTrain(Motor& lm, Motor& rm) : leftMotor(lm), rightMotor(rm) {}

void DriveTrain::moveForward(int distance) {
  leftMotor.rotate(distance * timeToDistance, true);  
  rightMotor.rotate(distance * timeToDistance, false);
}

void DriveTrain::moveBackward(int distance) {
  leftMotor.rotate(distance * timeToDistance, false);
  rightMotor.rotate(distance * timeToDistance, true);
}
