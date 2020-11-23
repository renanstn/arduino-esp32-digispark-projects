#include <Servo.h>
#define SERVO_PIN_LEFT 9 // azul
#define SERVO_PIN_RIGHT 10 // verde
#define SERVO_PIN_APOIO 11 // amarelo


Servo servo_left;
Servo servo_right;
Servo servo_apoio;
int pos_left = 0;
int pos_right = 180;

void setup() {
  servo_left.attach(SERVO_PIN_LEFT);
  servo_right.attach(SERVO_PIN_RIGHT);
  servo_apoio.attach(SERVO_PIN_APOIO);
  servo_apoio.write(180);
}

void loop() {
  for (int i=0; i<180; i++) {
    pos_left += 1;
    pos_right -= 1;
    servo_left.write(pos_left);
    servo_right.write(pos_right);
    delay(15);
  }
  for (int i=180; i>=90; i--) {
    servo_apoio.write(i);
    delay(15);
  }
  delay(500);
  pos_left = 0;
  pos_right = 180;
  servo_left.write(pos_left);
  servo_right.write(pos_right);
  delay(500);
  servo_apoio.write(180);
  delay(50);
}
