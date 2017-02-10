# 1 "/tmp/tmp3S8klz"
#include <Arduino.h>
# 1 "/home/oskar/Dropbox/nodemcu/teensy-motors/src/main.ino"
int STBY = 10;


int PWMA = 3;
int AIN1 = 9;
int AIN2 = 8;


int PWMB = 5;
int BIN1 = 11;
int BIN2 = 12;
void setup();
void loop();
void move(int motor, int speed, int direction);
void stop();
#line 13 "/home/oskar/Dropbox/nodemcu/teensy-motors/src/main.ino"
void setup(){
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void loop(){
  move(1, 255, 1);
  move(2, 255, 1);
# 39 "/home/oskar/Dropbox/nodemcu/teensy-motors/src/main.ino"
}


void move(int motor, int speed, int direction){





  digitalWrite(STBY, HIGH);

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }else{
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
}

void stop(){

  digitalWrite(STBY, LOW);
}