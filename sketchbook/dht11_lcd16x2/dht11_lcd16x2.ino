#include <DHT.h>
#include <LiquidCrystal.h>
 
#define DHTPIN A1
#define DHTTYPE DHT11
 
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
void setup() {
    lcd.begin(16, 2);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Teste do sensor");
    
    dht.begin();
    
    delay(5000);
}

void loop() {
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    
    if (isnan(t) || isnan(h)) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Falha de leitura");
        
        delay(5000);
    } else {
        lcd.clear();
        
        lcd.setCursor(0, 0);
        lcd.print("Umid.:");
        lcd.setCursor(7, 0);
        lcd.print(h, 1);
        lcd.setCursor(15, 0);
        lcd.print("%");

        lcd.setCursor(0, 1);
        lcd.print("Temp.:");
        lcd.setCursor(7, 1);
        lcd.print(t, 1);
        lcd.setCursor(14, 1);
        lcd.print((char)223);
        lcd.setCursor(15, 1);
        lcd.print("C");
    }
  
    delay(10000);
}
