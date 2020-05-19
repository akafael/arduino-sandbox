/**
 * Open Loop Speed Control for servo motor
 */

#include <Servo.h>
#include <elapsedMillis.h>

#define PINSERVO1 9

elapsedMillis timerGlobal;
int timeStep = 2000/180; // ms
const int angleStep = 1; // degres
const int angleRange = 180; // degres

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
    // set speed by timeStep Change (speed = angleStep/timeStep)
    timeStep = analogRead(A0);

    // Swep from 0 to angleRange then from angleRange to 0
    stepServo = (angleServo >=angleRange)?-angleStep:(angleServo <= 0)?angleStep:stepServo;
    angleServo += stepServo;

    // Send Command
    myServo.write(angleServo); 
  }
}
