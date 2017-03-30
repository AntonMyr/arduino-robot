# 1 "/var/folders/b5/52p0kv2s1rbd73klhqg6hq_m0000gn/T/tmpOq_Wkk"
#include <Arduino.h>
# 1 "/Users/oskar/Dropbox/nodemcu/teensy-motors/src/main.ino"

int STBY = 10;


int PWMA = 3;
int AIN1 = 9;
int AIN2 = 8;


int PWMB = 5;
int BIN1 = 11;
int BIN2 = 12;

int led = 23;


int trigPin = 14;
int echoPin = 15;


int LS = A2;
int RS = A3;
void setup();
void loop();
void move(int motor, int speed, int direction);
void turnLeft(int speed1, int speed2);
void turnRight(int speed1, int speed2);
void goForward(int speed);
void goReverse(int speed);
void stop();
#line 27 "/Users/oskar/Dropbox/nodemcu/teensy-motors/src/main.ino"
void setup(){
  Serial.begin(115200);
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);

  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
}

void loop(){
# 61 "/Users/oskar/Dropbox/nodemcu/teensy-motors/src/main.ino"
  int lineLeft = analogRead(LS);
  int lineRight = analogRead(RS);
# 77 "/Users/oskar/Dropbox/nodemcu/teensy-motors/src/main.ino"
  if(lineLeft < 900 && lineRight > 930) {
    turnRight(100, 10);
    Serial.print("Right");
    Serial.print(lineRight);
    Serial.println();
  }

  else if(lineLeft > 930 && lineRight < 900) {
    Serial.print("Left");
    Serial.print(lineLeft);
    Serial.println();
    Serial.print("Right");
    Serial.print(lineRight);
    Serial.println();
    turnLeft(100, 10);
  }


  else {
    goForward(100);

  }
# 111 "/Users/oskar/Dropbox/nodemcu/teensy-motors/src/main.ino"
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

void turnLeft(int speed1, int speed2) {

  move(1, speed1, 0);
  move(2, speed2, 1);
}

void turnRight(int speed1, int speed2) {
  move(1, speed2, 1);
  move(2, speed1, 0);
}

void goForward(int speed) {
  move(1, speed, 0);
  move(2, speed, 0);
}

void goReverse(int speed) {
  move(1, speed, 1);
  move(2, speed, 1);
}

void stop(){

  digitalWrite(STBY, LOW);
}