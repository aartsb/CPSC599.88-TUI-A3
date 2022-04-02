#include <Servo.h>
const int servo = 9; //define Servo Signal Pin

long duration;
Servo myservo;
int pos = 0; //create servo command to control the servo
void setup()
{
  
  myservo.attach(servo); //Attach the servo to Pin9 to the servo command
  myservo.write(0); // Set servo to 0 degrees initially
  Serial.begin(9600); // start the serial communication with a Baud Rate of 9600
}

//experimented with different delay times for smooth spray experience.
void loop()           
{
    myservo.write(45);
    delay(100);
    myservo.write(90);
    delay(100);
    myservo.write(135);
    delay(100);
    myservo.write(180);
    delay(100);
    myservo.write(00);
    delay(2500);
  }
