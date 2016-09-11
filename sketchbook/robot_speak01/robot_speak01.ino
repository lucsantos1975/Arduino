const int buzzerPin = 10;
const int buttonPin = 2;

const int eye1Pin = 3;
const int eye2Pin = 4;

const int mouth1Pin = 5;
const int mouth2Pin = 6;
const int mouth3Pin = 7;

const int numberOfMouthLeds = 3;

int mouthPins[numberOfMouthLeds];

int buttonState = 0;
int fraseCount = 0;
int mouthCount = 0;

int frase0[] = {1100, 1100, 1400, 1800, 1100, 1400, 1100, 2400, 2200, 2800};
int delay0[] = { 250,  250,  500,  650,  250,  100,  400,  700,  150,  400};

int frase1[] = {2000, 2000, 1800, 3800, 3000, 1800, 2000, 2400, 3400, 1800, 1000, 1600};
int delay1[] = { 500,  300,  900,  150,  250,  200,  500,  100,  450,  700,  200,  250};

int frase2[] = {2000, 3000, 1800, 1000, 2500, 1200, 3000, 2400};
int delay2[] = { 500,  300,  700,  150,  250,  800,  200,  100};

int frase3[] = {1200, 4000, 3800, 2800, 2000, 2800, 3000, 3400, 2400, 2400};
int delay3[] = { 300,  100,  500,  200,  650,  200,  700,  200,  100,  500};

const int numberOfFrases = 4;

int* frases[numberOfFrases];
int* delays[numberOfFrases];
int fraseSizes[numberOfFrases];

void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  pinMode(eye1Pin, OUTPUT);
  pinMode(eye2Pin, OUTPUT);
  
  digitalWrite(eye1Pin, HIGH);
  digitalWrite(eye2Pin, HIGH);
  
  pinMode(mouth1Pin, OUTPUT);
  pinMode(mouth2Pin, OUTPUT);
  pinMode(mouth3Pin, OUTPUT);
  
  mouthPins[0] = mouth1Pin;
  mouthPins[1] = mouth2Pin;
  mouthPins[2] = mouth3Pin;
  
  frases[0] = frase0;
  frases[1] = frase1;
  frases[2] = frase2;
  frases[3] = frase3;
  
  delays[0] = delay0;
  delays[1] = delay1;
  delays[2] = delay2;
  delays[3] = delay3;
  
  fraseSizes[0] = sizeof(frase0) / sizeof(frase0[0]);
  fraseSizes[1] = sizeof(frase1) / sizeof(frase1[0]);
  fraseSizes[2] = sizeof(frase2) / sizeof(frase2[0]);
  fraseSizes[3] = sizeof(frase3) / sizeof(frase3[0]);
}

void loop()
{
    buttonState = digitalRead(buttonPin);
    
    if (buttonState == HIGH) {
      for (int i = 0; i < fraseSizes[fraseCount]; i++) {
        tone(buzzerPin, frases[fraseCount][i], delays[fraseCount][i]);
        digitalWrite(mouthPins[mouthCount], HIGH);
        
        delay(200);
        digitalWrite(mouthPins[mouthCount], LOW);
        mouthCount++;
        
        if (mouthCount >= numberOfMouthLeds) {
          mouthCount = 0;
        }
      }
      
      fraseCount++;
      
      if (fraseCount >= numberOfFrases) {
        fraseCount = 0;
      }
    }
    
    delay(200);
}
