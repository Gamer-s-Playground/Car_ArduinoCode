#include <SoftwareSerial.h>

#define LEFT_MOTOR_GO 13
#define LEFT_MOTOR_BACK 12
#define RIGHT_MOTOR_GO 11
#define RIGHT_MOTOR_BACK 10

#define RXD 3
#define TXD 2
#define KEY 4

SoftwareSerial HC05(2, 3);

char t;

void setup() {
  Serial.begin(115200);

  pinMode(LEFT_MOTOR_GO, OUTPUT);
  pinMode(LEFT_MOTOR_BACK, OUTPUT);
  pinMode(RIGHT_MOTOR_GO, OUTPUT);
  pinMode(RIGHT_MOTOR_BACK, OUTPUT);

  pinMode(KEY, OUTPUT);
  digitalWrite(KEY, HIGH);
  HC05.begin(38400);
}

void loop() {

  if(HC05.available()) {
    t = HC05.read();
    Serial.println(t);
  }

  // if(Serial.available()) {
  //   t = Serial.read();
  //   Serial.println(t);
  // }

  if(t == 'F') { //move forward
    digitalWrite(LEFT_MOTOR_GO, HIGH);
    digitalWrite(RIGHT_MOTOR_GO, HIGH);
  }

  else if(t == 'B') { //move reverse
    digitalWrite(LEFT_MOTOR_BACK, HIGH);
    digitalWrite(RIGHT_MOTOR_BACK, HIGH);
  }

  else if(t == 'L') { //turn left
    digitalWrite(RIGHT_MOTOR_GO, HIGH);
  } 

  else if(t == 'R') { //turn right 
    digitalWrite(LEFT_MOTOR_GO, HIGH);
  }

  else if(t == 'S') { //stop
    digitalWrite(LEFT_MOTOR_GO, LOW);
    digitalWrite(LEFT_MOTOR_BACK, LOW);
    digitalWrite(RIGHT_MOTOR_GO, LOW);
    digitalWrite(RIGHT_MOTOR_BACK, LOW);
  }
  
  delay(10);
}
