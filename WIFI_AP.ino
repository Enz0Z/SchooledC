#include <ESP8266WiFi.h>
 
const char ssid[] = "NodeMCU-ESP8266";
const char password[] = "12345678";
WiFiServer server(80);
 
void setup() {
  Serial.begin(115200);
  server.begin();
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  Serial.println();
  Serial.print("IP: ");
  Serial.println(WiFi.softAPIP());
  Serial.print("MAC: ");
  Serial.println(WiFi.softAPmacAddress());
}

void loop() {}
