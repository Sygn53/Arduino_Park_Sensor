int trigPin = 2;
int echoPin = 7;
long sure;
long uzaklik;
int buzzer = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  sure = pulseIn(echoPin, HIGH);
  uzaklik = sure /29.1/2;
  if(uzaklik > 200)
    uzaklik = 200;
  Serial.print("Uzaklik "); 
  Serial.print(uzaklik);
  Serial.println(" CM ");
  if(uzaklik <= 50 and uzaklik > 30){
    tone(buzzer, 1000); 
    delay(500);       
    noTone(buzzer);    
  }
  else if(uzaklik <= 30 and uzaklik > 10){
    tone(buzzer, 1000); 
    delay(300);       
    noTone(buzzer);    
  }
  else if(uzaklik <= 15 and uzaklik > 5){
    tone(buzzer, 1000); 
    delay(100);       
    noTone(buzzer);    
  }
  else if(uzaklik <= 5){
    tone(buzzer, 1000); 
    delay(100);          
  }
delay(100);
}
