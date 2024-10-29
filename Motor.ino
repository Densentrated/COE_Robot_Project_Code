class Motor(int cp0, int cp1, int pp) {
  public: 
    int controlPin0 = cp0;
    int controlPin1 = cp1;
    int pwmPin = pp;
    const int msDistRatio = 0;

  pinMode(controlPin0, OUTPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(pwmPin, OUTPUT);

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
    igitalWrite(controlPin0, LOW);                      
    digitalWrite(controlPin1, LOW);                   
    analogWrite(pwmPin, 0);            
  }
}