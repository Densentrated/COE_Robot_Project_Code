#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include "Motor.h"

class DriveTrain {
  public: 
    DriveTrain(Motor& lm, Motor& rm);
    void moveForward(int distance);
    void moveBackward(int distance);

  private:
    Motor& leftMotor;
    Motor& rightMotor;
    int timeToDistance = 1;
};

#endif
