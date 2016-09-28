int sensorPin = A0;
int sensorValue;
float voltage;
float temperature;

void setup() {
  analogReference(INTERNAL);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  voltage = sensorValue * 3.3 / 1024;
  temperature = (voltage - 0.5) * 100;

  Serial.print("Sensor value: ");
  Serial.println(sensorValue);
  Serial.print("Voltage: ");
  Serial.println(voltage);
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");
  Serial.println("----------------------------");
  
  delay(2000);
}
