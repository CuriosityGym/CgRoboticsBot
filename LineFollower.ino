#include <MotorDriver.h>
MotorDriver m;
void setup() {
  Serial.begin(9600);
  #define LS A3      // left sensor
  #define RS A2      // right sensor
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
}

void loop() {
  int right=digitalRead(RS);
  int left=digitalRead(LS);
   if(digitalRead(LS) && digitalRead(RS))     // Move Forward
  {
    
    m.motor(1,FORWARD,255);
    m.motor(4,FORWARD,255);
  }
  else if(!(digitalRead(LS)) && digitalRead(RS))     // Turn right
  { 
    m.motor(1,BACKWARD,255);
    m.motor(4,FORWARD,255);
  }
  
 else if(digitalRead(LS) && !(digitalRead(RS)))     // turn left
  {  
    m.motor(1,FORWARD,255);
    m.motor(4,BACKWARD,255);
  }
  
 else if(!(digitalRead(LS)) && !(digitalRead(RS)))     // stop
  {
    m.motor(1,BRAKE,0);
    m.motor(4,BRAKE,0);
  }
}
