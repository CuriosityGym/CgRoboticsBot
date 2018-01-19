#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <MotorDriver.h>

MotorDriver m;
uint16_t clear_0, red_0, green_0, blue_0;

Adafruit_TCS34725 tcs_0 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup()
{
 Wire.begin();
 tcs_0.begin();
  Serial.begin(115200);

}


void loop()
{
  tcs_0.setInterrupt(false);// turn on LED
  delay(60);  // takes 60ms to read
  tcs_0.getRawData(&red_0, &green_0, &blue_0, &clear_0);
  tcs_0.setInterrupt(true);  // turn off LED
  int red=map(red_0,0,1300,0,255);
  int blue=map(blue_0,0,1100,0,255);
  int green=map(green_0,0,1200,0,255);
  Serial.println("R=");
  Serial.println(red);
  delay(500);
   Serial.println("B=");
  Serial.println(blue);
  delay(500);
  Serial.println("G=");
  Serial.println(green);
  delay(500);
  if((red-blue)>30 && (red-green)>30)
  {
    Serial.println("RED");  
  }
  else if((blue-red)>8 && (blue-green)>8)
  {
    Serial.println("BLUE");  
  }
  else if((green-blue)>15 && (green-red)>10)
  {
    Serial.println("GREEN");  
  }
  else if((red-blue)>60 && (green-blue)>60)
  {
    Serial.println("YELLOW");  
  }
   else if(abs(red-blue)<10 && abs(green-blue)<10 && abs(green-red)<10)
  {
    Serial.println("BLACK");  
  }
  else
    Serial.println("COLOUR NOT DETECTED");
  Serial.println("--------------------------------------------------------------------");
  delay(500); 
}
