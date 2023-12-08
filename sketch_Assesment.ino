#include <Arduino.h>
const int lm35Pin = A0; 
const int ledPin = 13;  

const int belowThresholdBlinkInterval = 250;  
const int aboveThresholdBlinkInterval = 500;  

const int temperatureThreshold = 30; 

float readTemperature() 
{
  int sensorValue = analogRead(lm35Pin);
  float voltage = (sensorValue / 1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100.0;
  return temperature;
}

void controlLED(float temperature)
 {
  if (temperature < temperatureThreshold)
 {
  
    digitalWrite(ledPin, HIGH);
    delay(belowThresholdBlinkInterval / 2);
    digitalWrite(ledPin, LOW);
    delay(belowThresholdBlinkInterval / 2);
  } else 
{
    digitalWrite(ledPin, HIGH);
    delay(aboveThresholdBlinkInterval / 2);
    digitalWrite(ledPin, LOW);
    delay(aboveThresholdBlinkInterval / 2);
  }
}

void setup()
 {
  pinMode(lm35Pin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  float currentTemperature = readTemperature();
  controlLED(currentTemperature);
}