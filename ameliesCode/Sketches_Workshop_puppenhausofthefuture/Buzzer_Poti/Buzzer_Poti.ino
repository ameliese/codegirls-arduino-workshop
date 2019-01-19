/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a buzzer connected to digital pin 9.
 The amount of time the buzzer will be on and off depends on
 the value obtained by analogRead().

 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * buzzer attached to digital pin 9 with R=100Ohm

 */

int sensorPin = A0;    // select the input pin for the potentiometer
int buzzer = 9;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the buzzer as an OUTPUT:
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  // turn the ledPin on
  tone(buzzer, 500);
  // stop the program for <sensorValue> milliseconds:
  delay(sensorValue);
  // turn the ledPin off:
  noTone(buzzer);
  // stop the program for for <sensorValue> milliseconds:
  delay(sensorValue);
}
