const int timer = 100;
const int num_leds = 10;
const int leds[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

int idx = 0;
int factor = 1;

void setup() {
  for (int i = 0; i < num_leds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  digitalWrite(leds[idx], HIGH);
  delay(timer);
  digitalWrite(leds[idx], LOW);

  if (idx == 0) {
    factor = 1;
  } else if (idx == (num_leds - 1)) {
    factor = -1;
  }
  
  idx = idx + factor;
}

