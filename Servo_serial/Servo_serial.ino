/*
 * Este exemplo esta 100% funcional
 * presta atencao pq essa merda da pau
 * pra caramba pq o Serial le as coisa
 * tudo cagadas!
 */

#include <Servo.h>

Servo servo1;
long num;

void setup(){
  servo1.attach(10);
  Serial.begin(9600);
  Serial.print("Enter position = ");
}
void loop(){
  while (Serial.available()>0){
    num = Serial.parseInt();
    Serial.print(num);
    Serial.println(" degree");
    Serial.print("Enter position: ");
  }
  servo1.write(num);
  delay(15);
}

