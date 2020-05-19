#include <Servo.h>
#include <elapsedMillis.h>

#define PINSERVO1 9

elapsedMillis timerGlobal;
const int timeStep = 2000/180; // ms
const int angleStep = 1; // degres
const int angleRange = 90; // degres

Servo myServo;
int angleServo;
int stepServo;

void setup() {
  // Servo Setup
  myServo.attach(PINSERVO1);
}

void loop() {
  if( timerGlobal > timeStep ) // Control Frequency time
  {
    // Reset Timer
    timerGlobal = 0; 

    myServo.write(angleServo); 
    stepServo = (angleServo >=angleRange)?-angleStep:(angleServo <= 0) ?angleStep:stepServo;
    angleServo += stepServo;

    // 
    Serial.print(timerGlobal);
    Serial.print(" ");
    Serial.println(angleServo);
  }

}
