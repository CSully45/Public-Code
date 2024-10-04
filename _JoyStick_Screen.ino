

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int xPin = A0;
int yPin = A1;
int xVal;
int yVal;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
}

void loop() {
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  // when characters arrive over the serial port...
  if (xVal > 512 || xVal < 517) {
    lcd.clear();
    lcd.print("Middle");
  }
  if (xVal < 512) {
    lcd.clear();
    lcd.print("Left");
  }
  if (xVal > 517) {
    lcd.clear();
    lcd.print("Right");
    
  }
  if (yVal == 510 || yVal == 511 || yVal == 509) {
    lcd.setCursor(0, 1);
    lcd.print("Middle");
  }
  if (yVal < 508) {
    lcd.setCursor(0, 1);
    lcd.print("Up");
  }
  if (yVal > 512) {
    lcd.setCursor(0, 1);
    lcd.print("Down");
  }
  delay(1000);
}