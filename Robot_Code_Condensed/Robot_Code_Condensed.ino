class Motor{
  public: 
    Motor(int cp0, int cp1, int pp) : controlPin0(cp0), controlPin1(cp1), pwmPin(pp) {
      pinMode(controlPin0, OUTPUT);
      pinMode(controlPin1, OUTPUT);
      pinMode(pwmPin, OUTPUT);
    }

    /**
      takes an int [durration] in ms and a boolean direction
      and rotates the motor for that many seconds
    **/
    void rotate(int duration, bool direction) {
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

  void stop() {
    digitalWrite(controlPin0, LOW);                      
    digitalWrite(controlPin1, LOW);                   
    analogWrite(pwmPin, 0);            
  }

  private:
    int  controlPin0;
    int controlPin1;
    int pwmPin;
};

class DriveTrain {
  public: 
    Motor leftMotor;
    Motor rightMotor;
    int timeToDistance = 1;

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
};

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