class DriveTrain(Motor lm, Motor rm) {
  public: 
    Motor leftMotor = lm;
    Motor RightMotor = rm;
    int timeToDistance = 1;

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
}