#include "DigiKeyboard.h"
#define LED_PIN 1


void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(100);
  DigiKeyboard.println("powershell Set-ItemProperty -path 'HKCU:\\Control Panel\\Desktop\\' -name wallpaper -value \"C:\\Users\\renan\\Pictures\\wp_test.jpg\";rundll32.exe user32.dll, UpdatePerUserSystemParameters;");
  digitalWrite(LED_PIN, HIGH);
  for(;;);
}

// powershell Set-ItemProperty -path 'HKCU:\Control Panel\Desktop\' -name wallpaper -value "C:\Users\renan\Pictures\wp_test.jpg";rundll32.exe user32.dll, UpdatePerUserSystemParameters;

// C:\Users\renan\Documents\ArduinoData\packages\digistump\hardware\avr\1.6.7\libraries\DigisparkKeyboard\scancode-ascii-table.h
