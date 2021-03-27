// Instalar a lib LiquidCrystal_I2C
// https://www.arduinoecia.com.br/modulo-i2c-display-16x2-arduino

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);


void setup() {
  lcd.init();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0, 0);
  lcd.print("Linha 1");
  lcd.setCursor(0, 1);
  lcd.print("Linha 2");

}

void loop() {
}
