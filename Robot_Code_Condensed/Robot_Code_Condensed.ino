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
  void rotate(bool direction, int power) {
    if (direction) {
      digitalWrite(controlPin0, HIGH);                    
      digitalWrite(controlPin1, LOW);
      analogWrite(pwmPin, power);  
    } else {
      digitalWrite(controlPin0, LOW);                    
      digitalWrite(controlPin1, HIGH);                         
      analogWrite(pwmPin, power);              
    }
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
    int lPower;
    int rPower;

    DriveTrain(Motor& lm, Motor& rm, int lPower, int rPower) : leftMotor(lm), rightMotor(rm), lPower(lPower), rPower(rPower) {}

    void moveForward(int distance) {
        // move one motor forward
        leftMotor.rotate( true, lPower);  
        rightMotor.rotate( true, rPower);
        delay(distance);
        rightMotor.stop();
        leftMotor.stop();
    }

    void moveBackward(int distance) {
        leftMotor.rotate(false, lPower);
        rightMotor.rotate(false, rPower);
        delay(distance);
        leftMotor.stop();
        rightMotor.stop();
    }

    void stop() {
      leftMotor.stop();
      rightMotor.stop();
      delay(2500);
    }

    void rotate90DegreesLeft() {
      int timeToTurn = 625;
      leftMotor.rotate(false, 100);
      rightMotor.rotate(true, 100);
      delay(timeToTurn);
      stop();
    }

    void rotate90DegreesRight() {
      int timeToTurn = 625;
      leftMotor.rotate(true, 100);
      rightMotor.rotate(false, 100);
      delay(timeToTurn);
      stop();
    }

    void s
};

// NEED TO IMPLEMENT ACTIVE PIN NUMBERS
// setup for left motor
// Wires Need To Be Switched
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
DriveTrain robotDriveTrain(leftMotor, rightMotor, 215, 200);
 
void setup()
{


}

void loop()
{
  
  // forever loop so code only gets executed once
  // move 36 in forward
  robotDriveTrain.moveForward(2000);
  // rotate left 90 degrees
  // move 24 in forwward
  // rotate right 90 degrees
  // move 36 in forward
  while(true) {}
}