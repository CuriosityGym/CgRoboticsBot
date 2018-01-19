#include <Servo.h>

int i;

int j;

Servo servo_9;

void setup()
{
  servo_9.attach(9);

}


void loop()
{
  for (i = 0; i <= 180; i++) {
    servo_9.write(i);
    delay(15);
  }
  for (j = 180; j >= 0; j--) {
    servo_9.write(j);
    delay(15);
  }

}
