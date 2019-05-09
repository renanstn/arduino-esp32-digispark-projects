int comando = 0;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Digite 1 para ligar, e 0 para desligar o led");}

void loop() {
  if (Serial.available()){
    comando = Serial.read();}
    
    if (comando=='0'){
      digitalWrite(LED_BUILTIN, LOW);
      delay(1000);}
    else if (comando=='1'){
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);}
    else{
      delay(1000);}
    }

