#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'.','0','C','='}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String num1 = "";
String num2 = "";
char op = 0;
bool isSecondNum = false;

void printCharAndAppend(String &target, char key) {
  // ensure only one decimal point per number; prepend 0 if starting with '.'
  if (key == '.') {
    if (target.length() == 0) target += '0';
    if (target.indexOf('.') != -1) return; // ignore extra dots
  }
  target += key;
  lcd.print(key);
}

void resetAll() {
  lcd.clear();
  num1 = "";
  num2 = "";
  op = 0;
  isSecondNum = false;
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Calculator");
  delay(1000);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();
  if (!key) return;

  if ((key >= '0' && key <= '9') || key == '.') {
    if (!isSecondNum) {
      printCharAndAppend(num1, key);
    } else {
      printCharAndAppend(num2, key);
    }
  }
  else if (key == '+' || key == '-' || key == '*') {
    if (num1.length() > 0 && !isSecondNum) {
      op = key;
      isSecondNum = true;
      lcd.print(op);
    }
  }
  else if (key == '=') {
    if (num1.length() > 0 && num2.length() > 0 && op != 0) {
      float n1 = num1.toFloat();
      float n2 = num2.toFloat();
      float result = 0;

      if (op == '+') result = n1 + n2;
      else if (op == '-') result = n1 - n2;
      else if (op == '*') result = n1 * n2;

      lcd.clear();
      lcd.print("Result:");
      lcd.setCursor(0,1);
      lcd.print(result);

      // Reset for next calculation (simple mode)
      num1 = "";
      num2 = "";
      op = 0;
      isSecondNum = false;

      // If you prefer chaining, comment out the four lines above and use:
      // num1 = String(result); num2 = ""; isSecondNum = false; op = 0;
      // lcd.setCursor(0,0); lcd.print(num1);
    }
  }
  else if (key == 'C') {
    resetAll();
  }
}
