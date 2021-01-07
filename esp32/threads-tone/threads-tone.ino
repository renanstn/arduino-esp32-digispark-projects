int buzzer_pin      = 15;
int channel         = 0;
int frequence       = 2000;
int resolution      = 10;
unsigned long timer = millis();

TaskHandle_t dobitaobyte;
eTaskState statusOf;

void sirene(void *pvParameters) {
    float sinVal;
    int   toneVal;
    for (byte t=0; t<10; t++) {
        for (byte x=0; x<180; x++) {
            sinVal = (sin(x*(3.1412/180)));
            toneVal = 2000+(int(sinVal*100));
            ledcWriteTone(channel,toneVal);
            delay(4);
        }
    }
    ledcWriteTone(channel, 0);
    vTaskDelete(NULL);
}

void setup() {
  ledcSetup(channel, frequence, resolution);
  ledcAttachPin(buzzer_pin, channel);
  timer = millis();
  Serial.begin(115200);
  xTaskCreatePinnedToCore(sirene, "sirene", 10000, NULL, 1, &dobitaobyte, 0);
}

void loop() {
  if (millis() - timer > 10000) {
    statusOf = eTaskGetState(dobitaobyte);
    if (statusOf == eReady) {
      timer = millis();
      xTaskCreatePinnedToCore(sirene, "sirene", 10000, NULL, 1, &dobitaobyte, 0);
    }
  }
  Serial.println("executando livremente...");
  delay(1000);
}
