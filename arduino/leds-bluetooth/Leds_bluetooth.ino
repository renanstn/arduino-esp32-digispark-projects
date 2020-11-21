/*
 * Conectar modulo Bluetooth
 * NAO ESQUECER de desconectar os fios TX e RX
 * antes de fazer upload do codigo, senao da pau
 */

int led_green = 9;
int led_yellow = 11;
int led_red = 13;

void setup() {
  pinMode(led_green, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_red, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char z;
  z = Serial.read();

  if (z == 'C') digitalWrite(led_green, HIGH);
  if (z == 'c') digitalWrite(led_green, LOW);

  if (z == 'B') digitalWrite(led_yellow, HIGH);
  if (z == 'b') digitalWrite(led_yellow, LOW);

  if (z == 'A') digitalWrite(led_red, HIGH);
  if (z == 'a') digitalWrite(led_red, LOW);
  delay(20);
}
