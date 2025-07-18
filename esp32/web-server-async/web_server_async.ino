#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "<wifi_id>";
const char* password = "<wifi_password>";

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.print("Conectando ao Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Wi-Fi conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  // Rota padrão "/"
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html",
      "<!DOCTYPE html><html>\
       <head><title>ESP32 Async Server</title></head>\
       <body><h1>Servidor ESP32 Async Funcionando</h1>\
       <p>Servidor web rápido sem travar o loop.</p>\
       </body></html>");
  });

  server.on("/cadeira", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html",
      "<!DOCTYPE html><html>\
      <img src=\"https://cdn.leroymerlin.com.br/products/poltrona_do_papai_reclinavel_san_diego_c__porta_copo_suede_1571880441_6aae_600x600.jpg\">\
      </body></html>");
  });

  server.on("/secret", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html",
      "<!DOCTYPE html><html>\
      <img src=\"https://famososnusbr.com/wp-content/uploads/2024/11/Nudes-do-Jogador-Vampeta-Pelado-para-G-Magazine.png\">\
      </body></html>");
  });

  server.begin();
}

void loop() {
  // Nada aqui, o servidor roda em paralelo sem travar o loop
}
