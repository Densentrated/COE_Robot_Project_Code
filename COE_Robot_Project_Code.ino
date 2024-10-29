void setup()
{
    // NEED TO IMPLEMENT ACTIVE PIN NUMBERS
    // setup for left motor
    int LM0;
    int LM1;
    int LMPWM; 
    Motor leftMotor(LM0, LM1, LMPWM);
    // setup for right motor
    int RM0;
    int RM1;
    int RMPW;
    Motor rigthMotor(RM0, RM1, RMPWM);
    // setup for the drivetrain
    DriveTrain robotDriveTrain(leftMotor, rightMotor);

}

void loop()
{
  robotDriveTrain.moveForward(4);
  robotDriveTrain.moveBackward(4);
}