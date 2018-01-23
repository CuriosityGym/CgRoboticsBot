#include <NewPing.h>
#include <MotorDriver.h>
#include <Servo.h>
Servo servo_9;
int distance;
NewPing sonar_A0(A0,A1);
MotorDriver m;

void setup()
{
  servo_9.attach(9);
}


void loop()
{
  distance= sonar_A0.ping_cm();
  if(distance>=15)
  { 
     servostraight();
     //moveforward();
  }  
  else 
   {
     //stopcar();
     servoright();
     distance = sonar_A0.ping_cm(); 
     if(distance>=15)  
     {   servostraight();
         //turnright();  
         //moveforward();
     }
     else
     {
         //stopcar();
         servoleft();
         distance = sonar_A0.ping_cm();
         if(distance>=15)
         {
             servostraight();
             //turnleft();
             //moveforward();
         }
         else
         {
             servostraight();
             //reverse();
             //moveforward();
         }
     }
   }
  
  

}

void moveforward()
{
   m.motor(1,FORWARD,255);
   m.motor(3,FORWARD,255); 
}

void stopcar()
{
   m.motor(1,BRAKE,0);
   m.motor(3,BRAKE,0);
}

void turnleft()
{
  m.motor(1,FORWARD,255);
  m.motor(3,BACKWARD,255);
  delay(800);
}

void turnright()
{
  m.motor(1,BACKWARD,255);
  m.motor(3,FORWARD,255);
  delay(800);
}

void reverse()
{
  m.motor(1,FORWARD,255);
  m.motor(3,BACKWARD,255);
  delay(1600);
}

void servoright()
{
  servo_9.write(0);
  delay(500);
}

void servoleft()
{
  servo_9.write(180);
  delay(500);
}

void servostraight()
{
  servo_9.write(90);
  delay(500);
}
