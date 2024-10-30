// Putting Class Declarations on Top Until I figure out arduino schematics
#include <Arduino.h>

// NEED TO IMPLEMENT ACTIVE PIN NUMBERS
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

void setup()
{


}

void loop()
{
  robotDriveTrain.moveForward(4000);
  robotDriveTrain.moveBackward(4000);
}