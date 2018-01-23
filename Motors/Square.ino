#include <MotorDriver.h>

int i;

MotorDriver m;
void setup()
{

}


void loop()
{
  
    m.motor(1,FORWARD,255);
    m.motor(4,FORWARD,255);
    delay(1000);
    for (i = 1; i <= 4; i++) {
    m.motor(1,FORWARD,200);
    m.motor(4,BRAKE,0);
    delay(350);
    m.motor(1,FORWARD,200);
    m.motor(4,FORWARD,200);
    delay(250);
  }

}
