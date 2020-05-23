#include <ESP8266WiFi.h>
WiFiServer server(80);
void setup()
{
  WiFi.mode(WIFI_AP);
  WiFi.softAP("master","111222333");
  server.begin();
  Serial.begin(9600);
  IPAddress HTTPS_ServerIP=WiFi.softAPIP();
  Serial.println("Server Ip is: " );
  Serial.println(HTTPS_ServerIP);
}
void loop()
{
  WiFiClient client=server.available();
  if(!client)
  {
    return;
  }
  Serial.println("Clint has connected");
  String request=client.readString();
  Serial.println(request);
  }
