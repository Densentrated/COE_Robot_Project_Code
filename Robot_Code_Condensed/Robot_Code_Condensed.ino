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
        leftMotor.rotate( false, lPower);  
        rightMotor.rotate( false, rPower);
        delay(distance);
        stop();
    }

    void moveBackward(int distance) {
        leftMotor.rotate(true, lPower);
        rightMotor.rotate(true, rPower);
        delay(distance);
        stop();
    }

    void stop() {
      leftMotor.stop();
      rightMotor.stop();
      delay(1000);
    }

    void rotate90DegreesLeft() {
      int timeToTurn = 330;
      leftMotor.rotate(true, 100);
      rightMotor.rotate(false, 100);
      delay(timeToTurn);
      stop();
    }

    void rotate90DegreesRight() {
      int timeToTurn = 330;
      leftMotor.rotate(false, 100);
      rightMotor.rotate(true, 100);
      delay(timeToTurn);
      stop();
    }

    void moveForwardIndefinitly() {
      leftMotor.rotate(false, lPower);
      rightMotor.rotate(false, rPower);
    }

    void moveBackwardIndefinitly() {
      leftMotor.rotate(true, lPower);
      rightMotor.rotate(true, rPower);
    }

    /**
      * Might not be needed, us used to counteract the fact that the left motor stops beore the right one
    **/
    void straighten() {
      int timeToTurn = 25;
      leftMotor.rotate(true, 80);
      rightMotor.rotate(false, 80);
      delay(timeToTurn);
      stop();
    }
};

class Sensor {
  public: 
    int triggerPin;
    int echoPin;

    Sensor(int tp, int ep) : triggerPin(tp), echoPin(ep) {}

    float getDistanceInInches() {
      digitalWrite(triggerPin, LOW);
      delayMicroseconds(5);

      digitalWrite(triggerPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(triggerPin, LOW);

      long duration = pulseIn(echoPin, HIGH);
      float distanceInches = duration * 0.034 / 2 / 2.54;
      return distanceInches;
    }
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
// ideal motor power ration is 215: 200
DriveTrain robotDriveTrain(leftMotor, rightMotor, 83, 80);
// setup for the sensor
int TP = 6;
int EP = 5;
Sensor robotSensor(TP, EP);

// setup for the button
int buttonPin = 7;
 
void setup()
{
  Serial.begin (9600); 
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(LM0, OUTPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LMPWM, OUTPUT);
  pinMode(RM0, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RMPWM, OUTPUT);
  pinMode(TP, OUTPUT);  
  pinMode(EP, INPUT); 
}

// outside of the loop to keep track of button state
int lastButtonState = HIGH;
bool codeExecuted = false;

// outside the loop to keep track of the robot
bool pathFound = true;
bool leftChecked = false;
bool rightChecked = false;
long distFromWall = 6.0;

void loop()
{
  int buttonState = digitalRead(buttonPin);
  if(lastButtonState == HIGH && buttonState == LOW) {
    if (!codeExecuted) {
      delay(500);
      while (true) {
        while (robotSensor.getDistanceInInches() > distFromWall && pathFound) {
          robotDriveTrain.moveForwardIndefinitly();
        } 
        robotDriveTrain.stop();
        pathFound = false;
        if (!leftChecked) {
          robotDriveTrain.rotate90DegreesLeft();
          if (robotSensor.getDistanceInInches() > distFromWall) {
            pathFound = true;
          } else {
            leftChecked = true;
          }
        } else if (!rightChecked) {
          robotDriveTrain.rotate90DegreesRight();
          robotDriveTrain.rotate90DegreesRight();
          if (robotSensor.getDistanceInInches() > distFromWall) {
            pathFound = true;
            leftChecked = false;
          } else {
            rightChecked = true;
          }
        } else {
          break;
        }
      }
      robotDriveTrain.stop(); 
      codeExecuted = true;
    }
  }
  if (buttonState == HIGH && lastButtonState == LOW) {
    codeExecuted = false;
  }
  lastButtonState = buttonState;
  digitalWrite(13, LOW);
}