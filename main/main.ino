#include <SoftwareSerial.h>

#define LEFT_MOTOR_GO 13
#define LEFT_MOTOR_BACK 12
#define RIGHT_MOTOR_GO 11
#define RIGHT_MOTOR_BACK 10

#define Tx 2
#define Rx 3

SoftwareSerial BTSerial(Tx, Rx);

char t;

void setup() {
  pinMode(LEFT_MOTOR_GO, OUTPUT);
  pinMode(LEFT_MOTOR_BACK, OUTPUT);
  pinMode(RIGHT_MOTOR_GO, OUTPUT);
  pinMode(RIGHT_MOTOR_BACK, OUTPUT);

  Serial.begin(9600);
  BTSerial.begin(38400);
}

void loop() {

  if (BTSerial.available()) {
    int a = BTSerial.read();
    Serial.println(a);
  }

  // if(Serial.available()) {
  //   t = Serial.read();
  //   Serial.println(t);
  // }

  // if(t == 'F') { //move forward
  //   digitalWrite(LEFT_MOTOR_GO, HIGH);
  //   digitalWrite(RIGHT_MOTOR_GO, HIGH);
  // }

  // else if(t == 'B') { //move reverse
  //   digitalWrite(LEFT_MOTOR_BACK, HIGH);
  //   digitalWrite(RIGHT_MOTOR_BACK, HIGH);
  // }

  // else if(t == 'L') { //turn left
  //   digitalWrite(RIGHT_MOTOR_GO, HIGH);
  // }

  // else if(t == 'R') { //turn right
  //   digitalWrite(LEFT_MOTOR_GO, HIGH);
  // }

  // else if(t == 'S') { //stop
  //   digitalWrite(LEFT_MOTOR_GO, LOW);
  //   digitalWrite(LEFT_MOTOR_BACK, LOW);
  //   digitalWrite(RIGHT_MOTOR_GO, LOW);
  //   digitalWrite(RIGHT_MOTOR_BACK, LOW);
  // }

  delay(10);
}
