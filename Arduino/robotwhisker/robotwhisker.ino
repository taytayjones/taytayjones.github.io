//need to test both the left and right whisker
//pinmode sets the pins, set w/ an input
//if the whisker is touched the value of that will read  0, else read 1
//print to the monito by opening a port Serial.begin(9600), using Serial.print()
#include <Servo.h>

Servo servoRight;
Servo servoLeft;
int whiskerL = digitalRead(5);
int whiskerR = digitalRead(7);

void moveForward(int Duration) {
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
  delay(Duration);

}

void turnClockwise(int Duration) {
  servoRight.writeMicroseconds(1500);
  servoLeft.writeMicroseconds(1100);
  delay(Duration);
}


void stopServos(int Duration){
  servoLeft.detach();
  servoRight.detach();
  delay(Duration);
  servoLeft.attach(13);
  servoRight.attach(12);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(7, INPUT); //left
  pinMode(5, INPUT); //
  servoRight.attach(12);
  servoLeft.attach(13);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(whiskerL);                       // Display left whisker state
  Serial.println(whiskerR);

  if ((whiskerL == 0) && (whiskerR == 0)){ // both touching
    Serial.println("both touching, should work");
    turnClockwise(500);
    moveForward(500);
  }
  else if ((whiskerL == 0) && (whiskerR == 1)){ //left is touching, right not touching
    Serial.println("l touching, r touching");
    turnClockwise(500);
    moveForward(500);
  }

  
  else if ((whiskerR == 1) && (whiskerL == 0)){ // right is touching, left not touching
    Serial.println("r touching, l not");
    turnClockwise(500);
    moveForward(500);
  }
  else { //both not touching
    Serial.println("both not touching");
    moveForward(200);
  }
}

