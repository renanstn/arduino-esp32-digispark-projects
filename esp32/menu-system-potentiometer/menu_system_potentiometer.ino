#include <ArduinoJson.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define BUTTON_PIN 18
#define POTENTIOMETER_PIN 34
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
StaticJsonDocument<256> menu;
JsonArray menuOptions;
int buttonState;
int lastButtonState = HIGH;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(115200);
  // OLED load ============================================================
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED não encontrado"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Iniciando...");
  display.display();
  // JSON load ============================================================
  const char* json = "{\"opcoes\": [\"opcao 1\", \"opcao 2\", \"opcao 3\"]}";
  DeserializationError error = deserializeJson(menu, json);
  if (error) {
    Serial.print("Erro ao carregar JSON: ");
    Serial.println(error.c_str());
    return;
  }
  menuOptions = menu["opcoes"];
  for (int i = 0; i < menuOptions.size(); i++) {
    const char* option = menuOptions[i];
    Serial.println(option);
  }
}

void loop() {
  // Button detection ========================================================
  buttonState = digitalRead(BUTTON_PIN);
  if (lastButtonState == HIGH && buttonState == LOW) {
    Serial.println("Click!");
  }
  lastButtonState = buttonState;
  // Detectar e mapear potenciômetro =========================================
  int potentiometerValue = analogRead(POTENTIOMETER_PIN);
  // Serial.println(potentiometerValue);
  display.clearDisplay();
  int menuLength = menuOptions.size();
  // int selectedOption = map(potentiometerValue, 0, 4095, 0, menuLength - 1);
  int step = 4096 / menuLength;
  int selectedOption = potentiometerValue / step;
  if (selectedOption >= menuLength) selectedOption = menuLength - 1;
  // Exibir menu =============================================================
  display.setCursor(0,0);
  for (int i = 0; i < menuLength; i++) {
    const char* option = menuOptions[i];
    if (i == selectedOption) {
      display.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
    } else {
      display.setTextColor(SSD1306_WHITE);
    }
    display.println(option);
  }
  display.display();
  delay(15);
}
