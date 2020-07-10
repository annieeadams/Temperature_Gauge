#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#include <Servo.h>
Servo myServo;


void setup() {
  // put your setup code here, to run once:
  myServo.attach(6);
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  delay(2000);
  float f = dht.readTemperature(true);

  if (isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return; 
 }

  int fValue = digitalRead (2);
  Serial.println(f);

  int servoPos = map(fValue, 70, 80, 0, 180);
 
  myServo.write(servoPos);
  delay(20);
  
 
}
