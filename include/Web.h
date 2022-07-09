#include <ESPmDNS.h>
#include <SPIFFS.h>

#define HTTP_SERVICE "http"
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <SPIFFS.h>

#define HTTP_PROTOCOL "tcp"
#define HTTP_PORT 80

AsyncWebServer server(80);

void initWeb() {
  if (MDNS.begin(HOSTNAME)) {
    MDNS.addService(HTTP_SERVICE, HTTP_PROTOCOL, HTTP_PORT);
  }

  SPIFFS.begin();

  server.serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");
  server.on("/readCO2", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", String(co2));
  });
  server.on("/readTemperature", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", String(temp));
  });
  server.on("/readHumidity", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send(200, "text/plain", String(hum));
  });
  server.onNotFound([](AsyncWebServerRequest *request) {
    request->send(400, "text/plain", "Not found");
  });
  server.begin();
}

