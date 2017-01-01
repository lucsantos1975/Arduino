#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

char lettersLowerCase[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' 
};

char lettersUpperCase[26] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
    'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' 
};

char numbersAndSymbols[32] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ' ', '!', '@', 
    '#', '$', '%', '&', '*', '/', '|', '?', ':', '.', ',', '(', ')', 
    '{', '}', '[', ']', '<', '>'
};

void setup() {
    lcd.begin(16, 2);
    lcd.clear();
}

void printChar(char charToPrint, byte column, byte line) {
    lcd.setCursor(column, line);
    lcd.print(charToPrint);
}

void printCharArray(char charArray[], int charCount) {
    lcd.clear();

    byte column = 0;
    byte line = 0;
    
    for (int i = 0; i < charCount; i++) {
        printChar(charArray[i], column, line);
        delay(500);

        column++;

        if (column > 15) {
            column = 0;
            line++;
        }
    }
}

void loop() {
    lcd.setCursor(0, 0);
    lcd.print("Arduino is cool!");
    lcd.setCursor(0, 1);
    lcd.print("    LCD 16x2");
    delay(4000);

    printCharArray(lettersLowerCase, (sizeof(lettersLowerCase)/sizeof(char)));
    delay(1000);

    printCharArray(lettersUpperCase, (sizeof(lettersUpperCase)/sizeof(char)));
    delay(1000);

    printCharArray(numbersAndSymbols, (sizeof(numbersAndSymbols)/sizeof(char)));
    delay(1000);

    lcd.clear();
    delay(1000);
}
