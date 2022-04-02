
//the working of the DHT11 sensor: Initialisation
#include "DHT.h"
#include <Servo.h>
#define DHTPIN 2     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

//the working of the fan: Initialisation
int motorPin = 3;
int speed = 0;

//the working of the servo for essential oil perfume spray: Initialisation
const int servo = 9; //define Servo Signal Pin

long duration;
Servo myservo;
int pos = 0; //create servo command to control the servo
void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  pinMode(motorPin, OUTPUT);
  
  dht.begin();
  myservo.attach(servo); //Attach the servo to Pin9 to the servo command
  myservo.write(0); // Set servo to 0 degrees initially
}

void loop() {
  // Wait a few seconds between measurements.
  delay(1000);
  
  // Sensor readings may also be up to 2 seconds 'old' 
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  delay(500);
  
  if(h >= 70 && h <=85 ){
    speed = 190;
    analogWrite(motorPin, speed);
    if(h >= 81 && h <= 84){
    speed = 190;
    analogWrite(motorPin, speed);  
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
    }
  else if(h >=86 && h <= 100 ){
    speed = 255;
    analogWrite(motorPin, speed);
    if(h >= 90 && h <= 95){
    speed = 190;
    analogWrite(motorPin, speed);  
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
    }
  else{
    speed = 0;
    analogWrite(motorPin, speed);
    }
}
