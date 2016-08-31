int ledPin = 7;
int ldrPin = 0;
int ldrValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  ldrValue = analogRead(ldrPin);
  
  if (ldrValue >= 950)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
    
  Serial.println(ldrValue);
  delay(100);
}
