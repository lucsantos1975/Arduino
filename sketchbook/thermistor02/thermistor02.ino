#define PINOTERMISTOR A0
#define TERMISTORNOMINAL 10000
#define TEMPERATURANOMINAL 25
#define NUMAMOSTRAS 5
#define BCOEFICIENTE 3977
#define SERIESRESISTOR 10000

int amostra[NUMAMOSTRAS];
int i;
void setup(void) {
  Serial.begin(9600);
  analogReference(EXTERNAL);
}

void loop(void) {
  float media;
  
  for (i = 0; i < NUMAMOSTRAS; i++) {
    amostra[i] = analogRead(PINOTERMISTOR);
    delay(10);
  }
  
  media = 0;
  for (i = 0; i < NUMAMOSTRAS; i++) {
    media += amostra[i];
  }
  media /= NUMAMOSTRAS;
  
  media = 1023 / media - 1;
  media = SERIESRESISTOR / media;
  
  float temperatura;
  temperatura = media / TERMISTORNOMINAL;
  temperatura = log(temperatura);
  temperatura /= BCOEFICIENTE;
  temperatura += 1.0 / (TEMPERATURANOMINAL + 273.15);
  temperatura = 1.0 / temperatura;
  temperatura -= 273.15;
  
  Serial.print("Temp: ");
  Serial.print(temperatura);
  Serial.println(" *C");
  
  delay(1000);
}
