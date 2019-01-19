// Ausgangspin für die LED
int ledPin = 13;
 
// Analog-Pin für den Piezo-Sensor
int piezoPin = 0;               
 
// Aktuell gemessener Wert
int wert = 0;
 
// Aktuelle Status der LED (wechselt bei Piezo-Klopfzeichen)
int ledStatus = LOW;
 
// WICHTIG: Diesen Wert zwischen 0 und 1023 anpassen, wenn Klopfzeichen nicht (oder zu oft) erkannt werden
int schwelle = 20;
 
// setup() wird einmalig beim Programmstart ausgeführt
void setup() {
 // Pin 13 für die LED als Ausgangspin setzen
 pinMode(ledPin, OUTPUT); 
 // Serielle Übertragung zum PC starten
 Serial.begin(9600);
}
 
// loop() wird nach setup() ununterbrochen ausgeführt
void loop() {
  // Eingangswert an A0 lesen
  wert = analogRead(piezoPin);   
  // Liegt der Wert über dem oben definierten Schwellenwert? Dann Ereignis auslösen  
  if (wert >= schwelle) {
    // Status der LED umkehren (1/0 = ein/aus)
    ledStatus = !ledStatus;
    // Pin 13 auf den Status setzen
    digitalWrite(ledPin, ledStatus);
    // Wert zu Testzwecken an den PC schicken
    Serial.println(wert);
    // Der Piezo braucht einige Zeit, um sich wieder zu beruhigen, daher 200ms warten.
    delay(200);
}
}
