#include <Servo.h>

Servo Base;
Servo Braco;
Servo Inclina;
Servo Garra;

void setup() {
  Serial.begin(9600);
  Base.attach(3);
  Braco.attach(4);
  Inclina.attach(5);
  Garra.attach(6);

  Base.write(90);
  delay(2000);
  Garra.write(90);
  delay(2000);
  Braco.write(90);
  delay(2000);
  Inclina.write(90);
  delay(2000);
  
}
void loop() {
  int num;
  
  while (true) {
    Serial.println("Digite um valor para a base:");
    if (Serial.available() > 0) {
      num = Serial.parseInt();
      Serial.println(num);
      Base.write(num);
    }
    Serial.println("Digite um valor para o braco:");
    if (Serial.available() > 0) {
      num = Serial.parseInt();
      Serial.println(num);
      Braco.write(num);
    }
    Serial.println("Digite um valor para a inclinacao:");
    if (Serial.available() > 0) {
      num = Serial.parseInt();
      Serial.println(num);
      Inclina.write(num);
    }
    Serial.println("Digite um valor para a garra:");
    if (Serial.available() > 0) {
      num = Serial.parseInt();
      Serial.println(num);
      Garra.write(num);
    }
  }
}

