int LED=13;
int bewegung=8;
int bewegungsstatus=0;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(bewegung, INPUT);
}

void loop()
{
  bewegungsstatus=digitalRead(bewegung);
  if (bewegungsstatus == HIGH)
  {
 
    digitalWrite(LED, HIGH);
    delay(2000);
    digitalWrite(LED, LOW);
    delay(100);
   
  }
else
  {
    digitalWrite(LED, LOW);
    delay(100);
  }
}
