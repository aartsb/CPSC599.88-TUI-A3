//Just the working of thr fan
int motorPin = 3;
int speed = 200;
 
void setup() 
{ 
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Speed 0 to 255");
} 
 
 
void loop() 
{ 
  
 analogWrite(motorPin, speed);
    
} 
