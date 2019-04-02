// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.

#include "LedControl.h"
#include "binary.h"

// pin 10 = display input
// pin 11 = clock
// pin 12 = CS
LedControl lc=LedControl(10,11,12,1);

DHT dht(DHTPIN, DHTTYPE);

int LED1 = 11;
int LED2 = 10;

// Boolean that is needed to decide if happy or sad face should be drawn
bool tempStatus = 1;

// Delay in between measuring temperature
int t=5000;
  


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

void setup() {
   lc.shutdown(0,false);
  
  // Set brightness to a medium value
  lc.setIntensity(0,8);
  
  // Clear the display
  lc.clearDisplay(0);
    
  Serial.begin(9600);

  // Draw happy face initially
  drawFace(true);
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht.begin();
  

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temperature = dht.readTemperature();
 

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(temperature) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

 

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" *C ");


  /*digitalWrite(LED1, HIGH); // schaltet Lampe an
  delay(1000); // geht 1000ms lang
  //digitalWrite(LED1, LOW);
  //delay(1000); // aus

  digitalWrite(LED2, HIGH); // schaltet Lampe an
  delay(1000); // geht 1000ms lang
  //digitalWrite(LED2, LOW);
  //delay(1000); // aus */

// Another Boolean to store the last temperature status (we do this to only draw a new face, if the status changes from happy to sad or vice versa)
bool previousStatus = tempStatus;

  // Face should be happy as long as the temperature is in between 15 and 25 C
  if (temperature > 15 && temperature < 25) {
    tempStatus = true;
  } else {
    tempStatus = false;
  }

// Delay in beetween measuring temperature
  delay(t);


  // Check if the status changed from the previous status and update smiley respectively
  if (previousStatus != tempStatus) {
    Serial.println("Smiley updated");
    drawFace(tempStatus);
  } else {
    Serial.println("Smiley not updated");
  }
}
