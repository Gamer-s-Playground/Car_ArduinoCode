#include <SoftwareSerial.h>

#define LEFT_MOTOR_GO 13
#define LEFT_MOTOR_BACK 12
#define RIGHT_MOTOR_GO 11
#define RIGHT_MOTOR_BACK 10

#define Tx 2
#define Rx 3

SoftwareSerial BTSerial(Tx, Rx);

char t;

void controlMoter(int a, int b, int c, int d) {
  digitalWrite(LEFT_MOTOR_GO, a);
  digitalWrite(LEFT_MOTOR_BACK, b);
  digitalWrite(RIGHT_MOTOR_GO, c);
  digitalWrite(RIGHT_MOTOR_BACK, d);
}

void setup() {
  pinMode(LEFT_MOTOR_GO, OUTPUT);
  pinMode(LEFT_MOTOR_BACK, OUTPUT);
  pinMode(RIGHT_MOTOR_GO, OUTPUT);
  pinMode(RIGHT_MOTOR_BACK, OUTPUT);

  digitalWrite(LEFT_MOTOR_GO, LOW);
  digitalWrite(LEFT_MOTOR_BACK, LOW);
  digitalWrite(RIGHT_MOTOR_GO, LOW);
  digitalWrite(RIGHT_MOTOR_BACK, LOW);

  Serial.begin(9600);
  BTSerial.begin(9600);
}

void loop() {

  if (BTSerial.available()) {
    t = BTSerial.read();
  }

  if(t == 'F') { //move forward
    //Serial.println("move forward");
    controlMoter(1, 0, 1, 0);
  }

  else if(t == 'B') { //move reverse
    //Serial.println("move reverse");
    controlMoter(0, 1, 0, 1);
  }

  else if(t == 'L') { //turn left
    //Serial.println("turn left");
    controlMoter(0, 0, 1, 0);
  }

  else if(t == 'R') { //turn right
    //Serial.println("turn right");
    controlMoter(1, 0, 0, 0);
  }

  else if(t == 'S') { //stop
    //Serial.println("stop");
    controlMoter(0, 0, 0, 0);
  }

  delay(10);
}