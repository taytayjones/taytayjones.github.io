#include <Servo.h>

Servo servoRight;
Servo servoLeft;

void stopServos(int Duration){
  servoLeft.detach();
  servoRight.detach();
  delay(Duration);
  servoLeft.attach(13);
  servoRight.attach(12);
//  servoLeft.writeMicroseconds(1500);
//  servoRight.writeMicroseconds(1500);
  //delay(Duration);
}

void moveForward(int Duration) {
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(Duration);

}

void moveBackward(int Duration) {
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
  delay(Duration);
}

void turnClockwise(int Duration) {
  servoRight.writeMicroseconds(1500);
  servoLeft.writeMicroseconds(1100);
  delay(Duration);
}

void turnCounterclockwise(int Duration) {
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1900);
  delay(Duration);
}



void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(13);
  servoRight.attach(12);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

void loop() {
  // put your main code here, to run repeatedly:
  turnClockwise(9000);
  for(int i=0; i<4; i++) {
    moveForward(500); 
    stopServos(250);
  }
  for(int i=0; i<4; i++) {
    moveBackward(500);
    stopServos(250);
  }
  for(int i=0; i<2; i++) {
  turnClockwise(500); 
  stopServos(250);
  turnCounterclockwise(500); 
  stopServos(250);
  }
 moveBackward(5000);
 turnClockwise(4000);
 stopServos(500);
 turnCounterclockwise(4000);
 stopServos(500);
 //moveFoward(4000);
 turnClockwise(6000);
  for(int i=0; i<4; i++) {
    moveForward(500); 
    stopServos(250);
  }
  for(int i=0; i<4; i++) {
    moveBackward(500);
    stopServos(250);
}
}
