#ifndef MOTOR_H
#define MOTOR_H

class Motor {
  public: 
    Motor(int cp0, int cp1, int pp);
    void rotate(int duration, bool direction);
    void stop();

  private:
    int controlPin0;
    int controlPin1;
    int pwmPin;
};

#endif
