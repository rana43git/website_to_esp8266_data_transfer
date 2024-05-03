#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h"

const char* ssid = "Hlw"; // Your WiFi SSID
const char* password = "1234567#"; // Your WiFi password

ESP8266WebServer server(80);

String val_ESP = ""; // Variable to store the string input

void setup() {
  Serial.begin(115200);
  
  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");

  // Define server routes
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", htmlContent);
  });
  
  server.on("/update", HTTP_POST, handleUpdate);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
  Serial.println(WiFi.localIP());
}

void loop() {
  server.handleClient();
}

// Handle update page
void handleUpdate() {
  if (server.hasArg("input")) {
    val_ESP = server.arg("input"); //Try to get value by input's id "val_ESP = server.arg("alpha");"
    Serial.println("Received input: " + val_ESP);
    server.send(200, "text/plain", "Input received: " + val_ESP);
  } else {
    server.send(400, "text/plain", "Bad Request");
  }
}
