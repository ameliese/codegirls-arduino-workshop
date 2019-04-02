#include <Time.h>
#include <TimeLib.h>

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
float fadeAmount = 5;    // how many points to fade the LED by

const int buzzer = 6; //buzzer to arduino pin 6

// the setup routine runs once when you press reset:
void setup() {

  Serial.begin(9600);
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
  // set the brightness of pin 9:
  while(!Serial) ;    // wait for serial port to connect.

  // set the current time to 14:27:00, December 14th, 2015
  setTime(15, 59, 50, 19, 01, 2019);

  pinMode(buzzer, OUTPUT); // Set buzzer - pin 6 as an output
  
}

void loop (){

Serial.print("Time now is: ");

  print2digits(hour());
  Serial.print(":");
  print2digits(minute());
  Serial.print(":");
  print2digits(second());

  Serial.print(" ");

  Serial.print(day());
  Serial.print("/");
  Serial.print(month());
  Serial.print("/");
  Serial.print(year());

  Serial.println();

  delay(1000);

if (hour()==16) {
   // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
}

if (brightness==50) {
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);        // ...for 1sec
}
}

void print2digits(int number) {
  if (number >= 0 && number < 10) {
    Serial.print('0');
  }
  Serial.print(number);
}


   /*analogWrite(led, brightness);
   time_t aktuelleZeit = now();
   Serial.println(now());
  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;
  //Serial.println(brightness);
  delay(30);
}


/*
// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    /*fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30)
} */
