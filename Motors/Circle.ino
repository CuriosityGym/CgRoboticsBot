#include <MotorDriver.h>

MotorDriver m;
void setup()
{

}


void loop()
{
  m.motor(1,FORWARD,200);
  m.motor(4,BACKWARD,0);
  delay(200);
  

}
