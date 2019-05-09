#include "DigiKeyboard.h"

void setup() {
}

void loop() {
  DigiKeyboard.delay(5000);
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.println("Hello Digispark!");
}
