#include <NewPing.h>
#include <Servo.h>
#define PIN_MOTORF 3
#define PIN_MOTORB 11

NewPing sonarL(2, 2, 200), sonarR(4, 4, 200);
Servo myservo;
char dir='L';

// function delaration
void autoSteer(char);

void setup() {
  Serial.begin(9600);
  pinMode(PIN_MOTORF, OUTPUT);pinMode(PIN_MOTORB, OUTPUT);
  
  myservo.attach(12);
  myservo.write(mid_pos);
  setMotor(0);
  delay(1000);
}

void loop() {
  int count=0;
  setMotor(spd);
  if(count>=lapTime){
    setMotor(0);
  }
  digitalRead(8) ? dir='R' : dir='L';
  autoSteer(dir);
  count++;
}

void setMotor(int spd){
  if(spd>0){
    analogWrite(PIN_MOTORF, spd);
    analogWrite(PIN_MOTORB, 0);
  }else{
    analogWrite(PIN_MOTORB, spd);
    analogWrite(PIN_MOTORF, 0);
  }
}
