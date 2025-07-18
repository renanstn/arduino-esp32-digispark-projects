#include <WiFi.h>

const char* ssid = "<wifi_id>";
const char* password = "<wifi_password>";

WiFiServer server(80); // Porta 80 HTTP

void setup() {
  Serial.begin(115200);

  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    Serial.println("Novo cliente conectado");
    String currentLine = "";

    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          // Linha em branco indica fim da requisição HTTP
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println();

          // Conteúdo da página
          client.println("<!DOCTYPE html><html>");
          client.println("<head><title>ESP32 Web Server</title></head>");
          client.println("<body><h1>Servidor ESP32 Ativo</h1>");
          client.println("<p>Teste de servidor web local.</p>");
          client.println("</body></html>");

          client.println();
          break;
        }
      }
    }
    client.stop();
    Serial.println("Cliente desconectado");
  }
}
