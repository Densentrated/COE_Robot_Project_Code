
class DriveTrain {
  public: 
    DriveTrain(Motor& lm, Motor& rm) : leftMotor(lm), rightMotor(rm) {}

    void moveForward(int distance) {
        // move one motor forward
        leftMotor.rotate(distance * timeToDistance, true);  
        // move one motor backward
        rightMotor.rotate(distance * timeToDistance, false);

    }

    void moveBackward(int distance) {
        // move one motor backward
        leftMotor.rotate(distance * timeToDistance, false);
        // move one motor forward
        rightMotor.rotate(distance * timeToDistance, true);
    }
  private: 
    Motor leftMotor;
    Motor rightMotor;
    int timeToDistance = 1;
};