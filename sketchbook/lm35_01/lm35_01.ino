#include <LM35.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  LM35 sensor1(A1);
  
  double temp = sensor1.read();
  double temp5 = sensor1.read(5);
  
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" / ");
  Serial.println(temp5);
  
  delay(1000);
}
