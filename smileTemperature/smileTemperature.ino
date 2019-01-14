#include "LedControl.h"
#include "binary.h"

// pin 10 = display input
// pin 11 = clock
// pin 12 = CS
LedControl lc=LedControl(10,11,12,1);

// Temperature sensor is connected to the pin A0
int TMP36 = A0;

// Integers for storing the current temperature value measured
int sensorValue;
int temperature = 0;

// Delay in between measuring temperature
int t=5000;

// Boolean that is needed to decide if happy or sad face should be drawn
bool tempStatus = 1;

// happy face
byte hf[8]= {B00111100,B01000010,B10010101,B10100001,B10100001,B10010101,B01000010,B00111100};
// sad face
byte sf[8]= {B00111100,B01000010,B10100101,B10010001,B10010001,B10100101,B01000010,B00111100};

// input parameter: bool isHappy
// if true this function will draw a happy face on the LED matrix
// if false this function will draw a sad face on the LED matrix
void drawFace(bool isHappy){
  if (isHappy) {
    for (int i = 0; i <= 7; i = i + 1) {
      lc.setRow(0,i,hf[i]);
    }
  } else {
    for (int i = 0; i <= 7; i = i + 1) {
    lc.setRow(0,i,sf[i]);
    }
  }
}

void setup() 
{
  lc.shutdown(0,false);
  
  // Set brightness to a medium value
  lc.setIntensity(0,8);
  
  // Clear the display
  lc.clearDisplay(0);
    
  Serial.begin(9600);

  // Draw happy face initially
  drawFace(true);
}

void loop() 
{
  // Read sensor value
  sensorValue=analogRead(TMP36);

  // Convert sensorValue to Celsius
  temperature= map(sensorValue, 0, 410, -50, 150);

  // Delay in beetween measuring temperature
  delay(t);

  // Send current temperature value to PC to print it on the serial monitor
  Serial.print(temperature);
  Serial.println(" C");

  // Another Boolean to store the last temperature status (we do this to only draw a new face, if the status changes from happy to sad or vice versa)
  bool previousStatus = tempStatus;

  Serial.print(previousStatus);

  // Face should be happy as long as the temperature is in between 15 and 20 C
  if (temperature < 30 && temperature > 15) {
    tempStatus = true;
  } else {
    tempStatus = false;
  }

  Serial.print(tempStatus);

  // Check if the status changed from the previous status and update smiley respectively
  if (previousStatus != tempStatus) {
    Serial.println("Smiley updated");
    drawFace(tempStatus);
  } else {
    Serial.println("Smiley not updated");
  }
}
