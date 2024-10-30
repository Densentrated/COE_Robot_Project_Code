#include "DriveTrain.h"
#include "Motor.h"

// setup for left motor
int LM0 = 12;
int LM1 = 13;
int LMPWM = 11; 
Motor leftMotor(LM0, LM1, LMPWM);

// setup for right motor
int RM0 = 9;
int RM1 = 8;
int RMPWM = 10;
Motor rightMotor(RM0, RM1, RMPWM);

// setup for the drivetrain
DriveTrain robotDriveTrain(leftMotor, rightMotor);

void setup() {
  // Initialization code here if needed
}

void loop() {
  robotDriveTrain.moveForward(4000);
  robotDriveTrain.moveBackward(4000);
}

