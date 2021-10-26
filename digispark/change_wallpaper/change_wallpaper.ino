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
  DigiKeyboard.println("powershell Set-ItemProperty -path 'HKCU:\\Control Panel\\Desktop\\' -name wallpaper -value \"C:\\Users\\renan\\Pictures\\vampeta.jpg\";rundll32.exe user32.dll, UpdatePerUserSystemParameters;");
  digitalWrite(LED_PIN, HIGH);
  for(;;);
}

// Comando sem os caracteres de escape, somente para referência
// powershell Set-ItemProperty -path 'HKCU:\Control Panel\Desktop\' -name wallpaper -value "C:\Users\renan\Pictures\vampeta.jpg";rundll32.exe user32.dll, UpdatePerUserSystemParameters;
