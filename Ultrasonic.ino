
#include<Servo.h>
#include <NewPing.h>

int distance;
NewPing sonar_A0(A0,A1);  
Servo myservo;
void setup()
{
  Serial.begin(115200);
  myservo.attach(10);
}


void loop()
{
  myservo.write(90);  //Servo is in forward direction.
  distance = sonar_A0.ping_cm(); // Get distance in cm from ultrasonic sensor
  Serial.println(distance);
  delay(1000);  
}
