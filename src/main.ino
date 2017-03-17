// #include <RedBot.h>
int STBY = 10; //standby

//Motor A
int PWMA = 3; //Speed control
int AIN1 = 9; //Direction
int AIN2 = 8; //Direction

//Motor B
int PWMB = 5; //Speed control
int BIN1 = 11; //Direction
int BIN2 = 12; //Direction

int led = 23; // LED

//Ultrasonic sensor
int trigPin = 14;
int echoPin = 15;

/* Sensors */
const LS = A2; // left sensor
const RS = A3; // right sensor

// RedBotSensor IRSensor1 = RedBotSensor(A2);
// RedBotSensor IRSensor2 = RedBotSensor(A3);

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
  //move(1, 255, 1); //motor 1, full speed, left
  //move(2, 255, 1); //motor 2, full speed, left
  // Serial.println(IRSensor1.read());

  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  // goForward(150);
  if(distance < 20) {
    // digitalWrite(led, HIGH);
    // stop();
    // delay(100);
    // goReverse(100);
    // delay(1000);
    // stop();
    for(int i = 0; i < 3; i++) {
      // turnRight(255);

    }
  } else if (distance >= 20){
    // digitalWrite(led, LOW);
    // goForward(150);
  } else {
    stop();
  }
  // Move Forward
  if(LS < 800 && RS > 800 {
    turnRight();
  }

  // Turn right
  else if(LS > 800 && RS < 800) {
    turnLeft();
  }

  // turn left
  else {
    goForward();
  }


/*  delay(1000); //go for 1 second
  stop(); //stop
  delay(250); //hold for 250ms until move again

  move(1, 128, 0); //motor 1, half speed, right
  move(2, 128, 0); //motor 2, half speed, right

  delay(1000);
  stop();
  delay(250);*/
}


void move(int motor, int speed, int direction){
//Move specific motor at speed and direction
//motor: 0 for B 1 for A
//speed: 0 is off, and 255 is full speed
//direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY, HIGH); //disable standby

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

void turnLeft(int speed) {
  move(1, speed, 0);
  move(2, speed, 1);
}

void turnRight(int speed) {
  move(1, speed, 0);
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
//enable standby
  digitalWrite(STBY, LOW);
}
