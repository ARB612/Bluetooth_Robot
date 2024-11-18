/* 
Designed and Developed by:
 "YOUNG INNOVATORS EDUCATIONAL SERVICES PVT. LTD."


NOTE:
 YOU HAVE TO INSTALL THE AFMOTOR LIBRARY BEFORE UPLOAD THE CODE//
 GO TO SKETCH >> INCLUDE LIBRARY >> ADD .ZIP LIBRARY >> SELECT AF MOTOR ZIP FILE //

*/

#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

int state;
 
void setup()
{
  Serial.begin(9600);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  Stop();
}

void loop() 
{
 
 if(Serial.available() > 0) 
 {     
   state = Serial.read(); 
   Serial.println(state);
  }
  
 if(state=='1') //Forward
 {
  forward(); 
 }

 if(state=='2') //Back
 {
  backward(); 
 }

 if(state=='3')//Right
 {
  right();
 }

 if(state=='4')//Left
 {
  left(); 
 }

 if(state=='0') //Stop
 {
  Stop(); 
 }

}

void forward()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void backward()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void left()
{
  motor1.run(FORWARD);
  motor2.run(RELEASE);
}

void right()
{
  motor1.run(RELEASE);
  motor2.run(FORWARD);
}

void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}