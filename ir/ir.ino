#include <IRremote.h>

const int led = 9;
const int IRleitor = 8;
IRrecv leitor(IRleitor);
decode_results valor;

void setup() {
  Serial.begin(9600);
  leitor.enableIRIn();
  pinMode(led, OUTPUT);
}

void loop() {
  if (leitor.decode(&valor)) {
    Serial.println(valor.value, HEX);
    if (valor.value == 0x39C600FF){
      digitalWrite(led, HIGH);
    }
    if (valor.value == 0x39C6807F){
      digitalWrite(led, LOW);
    }
    leitor.resume();}
}
