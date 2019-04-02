#include <Servo.h>
// Initialisierung Variablen ServoMotor
Servo myservo;  // create servo object to control a servo
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

//  Inititaliserung Variablen PiezoPin und LedPin
//Initialisiere LEDs auf Digital Pin
int ledPin = 2;
int ledPin2 = 3;
int ledPin3 = 4;
// Analog-Pin für den Piezo-Sensor
int piezoPin = 1;              
 
// Aktuell gemessener Wert
int wert = 0;
// Anfangs Wert Zähler
int zaehler = 0;
// Aktuelle Status der LED (wechselt bei Piezo-Klopfzeichen)
int ledStatus = LOW;
// WICHTIG: Diesen Wert zwischen 0 und 1023 anpassen, wenn Klopfzeichen nicht (oder zu oft) erkannt werden
int schwelle = 25;


void setup() { // initialize serial communication:
    myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  
   Serial.begin(9600);
   pinMode(ledPin, OUTPUT); 
   pinMode(ledPin2, OUTPUT);
 
 // Serielle Übertragung zum PC starten
}

void loop() {
  // ode für den ServoMototr aus den Beispielen
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                            // waits for the servo to get there

//Code für LEDs und Piezopin
   wert = analogRead(piezoPin);   
 if (wert >= schwelle) {
    // Wert zu Testzwecken an den PC schicken
    Serial.println(wert);
    // Der Piezo braucht einige Zeit, um sich wieder zu beruhigen, daher 200ms warten.
    delay(200);
    zaehler++; 
  }
 int rest = zaehler % 4; //zaehler Modulo 3, dass immer 0,1,2 rauskommt
    switch (rest) {
       case 0:
        digitalWrite(2, LOW); //rot aus
        digitalWrite(3, LOW); //blau aus
        digitalWrite(4, LOW); //weiß aus
         break;
      case 1:
        digitalWrite(2, HIGH); //rot an
        digitalWrite(3, LOW); //blau aus
        digitalWrite(4, LOW); //weiß aus
        break;
      case 2:
        digitalWrite(3, HIGH); //blau an
        digitalWrite(2, LOW); //rot aus
        digitalWrite(4, LOW); //weiß aus
        break;
        case 3:
        digitalWrite(4, HIGH); //weiß an
        digitalWrite(2, LOW); //rot aus
        digitalWrite(3, LOW); //blau aus
        break;
      default:
        break;
        }
        Serial.println(zaehler);  // gibt den zählerstand im Monitor aus
    }
 
