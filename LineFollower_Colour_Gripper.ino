#include <Wire.h>
#include <NewPing.h>
#include <Adafruit_TCS34725.h>
#include <MotorDriver.h>
#include <Servo.h>
int distance;
NewPing sonar_A0(A0, A1);
MotorDriver m;
uint16_t clear_0, red_0, green_0, blue_0;
Adafruit_TCS34725 tcs_0 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
Servo myservo;
Servo gripper;
int a, b, c, i;
String robot_direction= "LEFT"; //Specify Robot Direction at start

void setup() {
  a = 0, b = 0,c = 0, i = 0;
  Wire.begin();
  tcs_0.begin();
  Serial.begin(115200);
  #define LS A3      // left sensor
  #define RS A2      // right sensor
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  myservo.attach(10);
  myservo.write(90);
  gripper.attach(9);
  gripper.write(10);
  delay(5000);
}

void loop() {
  int right = digitalRead(RS);
  int left = digitalRead(LS);
  if (!(digitalRead(LS)) && !(digitalRead(RS)))    // Move Forward
  {
    if(c>0)
    {
        m.motor(1, BRAKE, 0);
        m.motor(4, BRAKE, 0);
    }
    else
    {
          m.motor(1, FORWARD, 255);
          m.motor(4, FORWARD, 255);
          distance = sonar_A0.ping_cm();
          if (distance>5 && distance<12 && i == 0)
          {
            gripper.write(100);
            m.motor(1, BRAKE, 0);
            m.motor(4, BRAKE, 0);
            delay(1000);
            m.motor(1, FORWARD, 255);
            m.motor(4, BACKWARD, 255);
            delay(3000);
            i++;
          }
          else if (distance>5 && distance < 12 && i > 0)
          {
            gripper.write(100);
          }
          /*else
          {
            gripper.write(10);
          }*/
    }
  }
  else if (!(digitalRead(LS)) && digitalRead(RS))    // Turn right
  {

    m.motor(1, BACKWARD, 255);
    m.motor(4, FORWARD, 255);
  }

  else if (digitalRead(LS) && !(digitalRead(RS)))    // turn left
  {
    m.motor(1, FORWARD, 255);
    m.motor(4, BACKWARD, 255);
  }

  else if ((digitalRead(LS)) && (digitalRead(RS)))    // stop
  {
    m.motor(1, BRAKE, 0);
    m.motor(4, BRAKE, 0);
    tcs_0.setInterrupt(false);// turn on LED
    delay(60);  // takes 60ms to read
    tcs_0.getRawData(&red_0, &green_0, &blue_0, &clear_0);
    tcs_0.setInterrupt(true);  // turn off LED
    int red = map(red_0, 0, 1300, 0, 255);
    int blue = map(blue_0, 0, 1100, 0, 255);
    int green = map(green_0, 0, 1200, 0, 255);
    distance = sonar_A0.ping_cm();
    
    if((red-blue)>30 && (red-green)>30)    //RED
    {
      if (distance > 15)
      {
        myservo.write(0);
        delay(1000);
        distance = sonar_A0.ping_cm();
        if (distance <= 40)
        {
          myservo.write(90);
          while ((red-blue)>30 && (red-green)>30)
          {
            m.motor(1, BACKWARD, 100); //RIGHT
            m.motor(4, FORWARD, 255);
            if (((!(digitalRead(LS)) && !(digitalRead(RS)) )))
            {
              a++;
              break;
            }
          }
        }
        else
        {
          myservo.write(180);
          delay(1000);
          distance = sonar_A0.ping_cm();
          if (distance <= 40)
          {
            myservo.write(90);
            while((red-blue)>30 && (red-green)>30)
            {
              m.motor(1, FORWARD, 255); //LEFT
              m.motor(4, BACKWARD, 100);
              if (((!(digitalRead(LS)) && !(digitalRead(RS)) )))
              {
                b++;
                break;
              }
            }
          }
          else
          {
            myservo.write(90);
            delay(500);
            m.motor(1, FORWARD, 255);
            m.motor(4, FORWARD, 255);
            delay(500);
          }
        }
      }
      else
      {
        if (a > 0)
        {
          while ((red-blue)>30 && (red-green)>30)
          {
            m.motor(1, BACKWARD, 100); //RIGHT
            m.motor(4, FORWARD, 255);
            if (((!(digitalRead(LS)) && !(digitalRead(RS)) )))
            {
              break;
            }
          }
        }
        if (b > 0)
        {
          while ((red-blue)>30 && (red-green)>30)
          {
            m.motor(1, FORWARD, 255); //LEFT
            m.motor(4, BACKWARD, 100);
            if (((!(digitalRead(LS)) && !(digitalRead(RS)) )))
            {
              break;
            }
          }
        }
      }
    }
    if ((green-blue)>15 && (green-red)>10)    //GREEN
    {
      if (distance > 15)
      {
        myservo.write(0);
        delay(1000);
        distance = sonar_A0.ping_cm();
        if (distance <= 35)
        {
          myservo.write(90);
          while ((green-blue)>15 && (green-red)>10)
          {
            m.motor(1, BACKWARD, 100); //RIGHT
            m.motor(4, FORWARD, 255);
            if (((!(digitalRead(LS)) && !(digitalRead(RS)) )))
            {
              a++;
              break;
            }
          }
        }
        else
        {
          myservo.write(180);
          delay(1000);
          distance = sonar_A0.ping_cm();
          if (distance <= 35)
          {
            myservo.write(90);
            while ((green-blue)>15 && (green-red)>10)
            {
              m.motor(1, FORWARD, 255); //LEFT
              m.motor(4, BACKWARD, 100);
              if (((!(digitalRead(LS)) && !(digitalRead(RS)) )))
              {
                b++;
                break;
              }
            }
          }
          else
          {
            myservo.write(90);
            delay(500);
            m.motor(1, FORWARD, 255);
            m.motor(4, FORWARD, 255);
            delay(500);
          }
        }
      }
      else
      {
        if (a > 0)
        {
          while ((green-blue)>15 && (green-red)>10)
          {
            m.motor(1, BACKWARD, 100); //RIGHT
            m.motor(4, FORWARD, 255);
            if (((!(digitalRead(LS)) && !(digitalRead(RS)) )))
            {
              break;
            }
          }
        }
        if (b > 0)
        {
          while ((green-blue)>15 && (green-red)>10)
          {
            m.motor(1, FORWARD, 255); //LEFT
            m.motor(4, BACKWARD, 100);
            if (((!(digitalRead(LS)) && !(digitalRead(RS)) )))
            {
              break;
            }
          }
        }
      }
    }
    while ((red-blue)>60 && (green-blue)>60) //YELLOW
    {
          if(distance > 12)
          {
                m.motor(1, FORWARD, 255);
                m.motor(4, FORWARD, 255);
                if (((!(digitalRead(LS)) && !(digitalRead(RS)))))
                {
                  break;
                }
          }
          else if(robot_direction == "LEFT")
          {
                  c++;
                  m.motor(1, FORWARD, 255); //LEFT
                  m.motor(4, BACKWARD, 100);
                  if (((!(digitalRead(LS)) && !(digitalRead(RS)))))
                  {
                    gripper.write(10);
                    break;
                  }
          }
          else if(robot_direction == "RIGHT")
         {
                  c++;
                  m.motor(1, BACKWARD, 100); //RIGHT
                  m.motor(4, FORWARD, 255);
                  if (((!(digitalRead(LS)) && !(digitalRead(RS)))))
                  {
                    gripper.write(10);
                    break;
                  }
          }
    }
    while ((blue-red)>8 && (blue-green)>8)    //BLUE
    {
         if(distance > 12)
          {
                m.motor(1, FORWARD, 255);
                m.motor(4, FORWARD, 255);
                if (((!(digitalRead(LS)) && !(digitalRead(RS)))))
                {
                  break;
                }
          }
          else if(robot_direction == "LEFT")
          {
                  c++;
                  m.motor(1, FORWARD, 255); //LEFT
                  m.motor(4, BACKWARD, 100);
                  if (((!(digitalRead(LS)) && !(digitalRead(RS)))))
                  {
                    gripper.write(10);
                    break;
                  }
          }
          else if(robot_direction == "RIGHT")
         {        
                  c++;
                  m.motor(1, BACKWARD, 100); //RIGHT
                  m.motor(4, FORWARD, 255);
                  if (((!(digitalRead(LS)) && !(digitalRead(RS)))))
                  {
                    gripper.write(10);
                    break;
                  }
          }
    }
    while (abs(red-blue)<10 && abs(green-blue)<10 && abs(green-red)<10) //Black
    {
      m.motor(1, FORWARD, 255);
      m.motor(4, FORWARD, 255);
      if (((!(digitalRead(LS)) && !(digitalRead(RS)))))
      {
        break;
      }
    }
  }
}
