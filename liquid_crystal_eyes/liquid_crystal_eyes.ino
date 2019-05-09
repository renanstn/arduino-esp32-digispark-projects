#include<LiquidCrystal.h>

const int buzzer = 8;
LiquidCrystal lcd(2,3,4,5,6,7);

byte eyeOpen[8] = {
  B00000,
  B01100,
  B01100,
  B01100,
  B01100,
  B01000,
  B01100,
  B00000,
};

byte eyeClosed[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B00000,
  B00000,
  B00000,
};

byte eyeHappy[8] = {
  B00000,
  B00100,
  B01010,
  B10001,
  B10001,
  B10001,
  B10001,
  B00000,
};

void setup() {
  lcd.begin(16,2);
  lcd.createChar(0,eyeOpen);
  lcd.createChar(1,eyeClosed);
  lcd.createChar(2,eyeHappy);
  lcd.home();
  pinMode(buzzer,OUTPUT);
  tone(buzzer, 2000, 1000);
}

void loop() {
  lcd.setCursor(5,1);
  lcd.write(byte(0));
  lcd.setCursor(10,1);
  lcd.write(byte(0));
  lcd.setCursor(5,0);
  lcd.print("-----");
  delay(3000);
  //-------------------
  lcd.setCursor(5,1);
  lcd.write(1);
  lcd.setCursor(10,1);
  lcd.write(1);
  tone(buzzer,1000,200);
  delay(500);
}
