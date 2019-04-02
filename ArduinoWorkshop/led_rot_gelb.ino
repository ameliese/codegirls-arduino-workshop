int LEDrot=13;
int LEDgelb=11;
int LEDgruen=8; 
int buzzer=5;


void setup() {
  // put your setup code here, to run once:
pinMode(LEDrot, OUTPUT);
pinMode(LEDgelb, OUTPUT);
pinMode(buzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

C();
D();
E();

}


void C (){
  tone(buzzer, 262);  
  delay(500);         
  digitalWrite(LEDrot, HIGH);  
  delay(500);
  noTone(buzzer);  
  delay(500); 
  digitalWrite(LEDrot, LOW);  
  delay(500);  
}

  void D (){
  tone(buzzer, 294);   
  delay(500); 
  digitalWrite(LEDgelb, HIGH);
  delay(500);           
  noTone(buzzer);     
  delay(500);  
  digitalWrite(LEDgelb, LOW);  
  delay(500); 
}

void E () {

  tone(buzzer, 330);
  delay(500); 
  digitalWrite(LEDgruen, HIGH);
  delay(500);               
  noTone(buzzer);
  delay(500);
  digitalWrite(LEDgruen, LOW);
  delay(500); 
}
