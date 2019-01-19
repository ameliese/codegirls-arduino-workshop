//Example for KY-026
//LED geht an, wenns brennt
//Analoge Werte auslesen, je nach Entfernung zur Flamme


int Led = 13 ;// define LED Interface
int digitalpin = 3; // define the flame sensor interface
int analogpin = A3; // define the flame sensor interface
 
int val ;// define numeric variables val
float sensor; //read analog value
 
void setup ()
{
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (digitalpin, INPUT) ;// output interface defines the flame sensor
  pinMode (analogpin, INPUT) ;// output interface defines the flame sensor
  Serial.begin(9600);
}
 
void loop ()
{
  
  //Analoge Werte mit seriellem Monitor oder Plotter auslesen, je nach Entfernung zur Flamme

  sensor = analogRead(analogpin);
  Serial.println(sensor);  // display tempature

 //LED geht an, wenns brennt

  val = digitalRead (digitalpin) ;// digital interface will be assigned a value of 3 to read val
    if (val == HIGH) // When the flame sensor detects a signal, LED flashes
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
  delay(1000);
}
