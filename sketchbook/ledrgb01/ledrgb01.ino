const int ledAzul = 8;
const int ledVerde = 9;
const int ledVermelho = 10;

void setup() {
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop() {
  digitalWrite(ledAzul, HIGH);
  delay(500);
  digitalWrite(ledAzul, LOW);
  
  digitalWrite(ledVerde, HIGH);
  delay(500);
  digitalWrite(ledVerde, LOW);  
  
  digitalWrite(ledVermelho, HIGH);
  delay(500);
  digitalWrite(ledVermelho, LOW);
  
  digitalWrite(ledAzul, HIGH);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho, HIGH);
  delay(1500);
  
  digitalWrite(ledAzul, HIGH);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho, LOW);
  delay(1500);
  
  digitalWrite(ledAzul, LOW);
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho, HIGH);
  delay(1500);
  
  digitalWrite(ledAzul, HIGH);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);
  delay(1500);
}
