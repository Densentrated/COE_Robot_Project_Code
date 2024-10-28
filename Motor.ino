class Motor(int cp0, int cp1, int pp) {
  public: 
    int controlPin0 = cp0
    int controlPin1 = cp1
    int pwmPin = pp;
    const int msDistRatio = 0;

  pinMode(controlPin0, OUTPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(pwmPin, OUTPUT);

  moveForward(int distance) {
    digitalWrite(AIN1, HIGH);                    
    digitalWrite(AIN2, LOW);                         
    analogWrite(PWMA, 255);              
    delay(3000);
        
    //stop motor
    digitalWrite(AIN1, LOW);                      
    digitalWrite(AIN2, LOW);                   
    analogWrite(PWMA, 0);            
    delay(3000);
  }

  moveBackward(int distance) {

  }

  turnRight90() {

  }

  turnLeft90(){

  }
}