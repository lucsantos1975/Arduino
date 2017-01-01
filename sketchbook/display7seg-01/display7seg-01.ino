// Common anode: pin 2

// Pin-segment mapping:
//    A,B,C,D,E,F,G,dot
//    3,4,5,6,7,8,9,10
byte pinsDigits[17][8] = {
    { 1,1,1,1,1,1,0,0 }, //  0   :  A,B,C,D,E,F    :  3,4,5,6,7,8
    { 0,1,1,0,0,0,0,0 }, //  1   :  B,C            :  4,5
    { 1,1,0,1,1,0,1,0 }, //  2   :  A,B,D,E,G      :  3,4,6,7,9
    { 1,1,1,1,0,0,1,0 }, //  3   :  A,B,C,D,G      :  3,4,5,6,9
    { 0,1,1,0,0,1,1,0 }, //  4   :  B,C,F,G        :  4,5,8,9
    { 1,0,1,1,0,1,1,0 }, //  5   :  A,C,D,F,G      :  3,5,6,8,9
    { 1,0,1,1,1,1,1,0 }, //  6   :  A,C,D,E,F,G    :  3,5,6,7,8,9
    { 1,1,1,0,0,0,0,0 }, //  7   :  A,B,C          :  3,4,5
    { 1,1,1,1,1,1,1,0 }, //  8   :  A,B,C,D,E,F,G  :  3,4,5,6,7,8,9
    { 1,1,1,1,0,1,1,0 }, //  9   :  A,B,C,D,F,G    :  3,4,5,6,8,9
    { 1,1,1,0,1,1,1,0 }, //  A   :  A,B,C,E,F,G    :  3,4,5,7,8,9
    { 0,0,1,1,1,1,1,0 }, //  B   :  C,D,E,F,G      :  5,6,7,8,9
    { 1,0,0,1,1,1,0,0 }, //  C   :  A,D,E,F        :  3,4,8,9
    { 0,1,1,1,1,0,1,0 }, //  D   :  B,C,D,E,G      :  4,6,7,8,9
    { 1,0,0,1,1,1,1,0 }, //  E   :  A,D,E,F,G      :  3,6,7,8,9
    { 1,0,0,0,1,1,1,0 }, //  F   :  A,E,F,G        :  3,7,8,9
    { 0,0,0,0,0,0,0,1 }  //  dot :  H              :  6
};

void setup() {
    pinMode(2,  OUTPUT); // anode
    pinMode(3,  OUTPUT); // A
    pinMode(4,  OUTPUT); // B
    pinMode(5,  OUTPUT); // C
    pinMode(6,  OUTPUT); // D
    pinMode(7,  OUTPUT); // E
    pinMode(8,  OUTPUT); // F
    pinMode(9,  OUTPUT); // G
    pinMode(10, OUTPUT); // dot

    digitalWrite(2, 1);
}

void clearDisplay() {
    digitalWrite(3,  1);
    digitalWrite(4,  1);
    digitalWrite(5,  1);
    digitalWrite(6,  1);
    digitalWrite(7,  1);
    digitalWrite(8,  1);
    digitalWrite(9,  1);
    digitalWrite(10, 1);
}

void showDigit(byte digit) {
    clearDisplay();
    byte pin = 3;
    for (byte i = 0; i < 8; i++) {
        if (pinsDigits[digit][i] == 1) {
          digitalWrite(pin, 0); // low level to turn on led segment (because display is common anode)
        }
        pin++;
    }
}

void loop() 
{ 
    clearDisplay();
    delay(1000);
  
    for (byte i = 0; i < 17; i++) {
      showDigit(i);
      delay(1000);
    }    
}

