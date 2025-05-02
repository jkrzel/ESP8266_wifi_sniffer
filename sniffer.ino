#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "Local_WiFi_SSID";
const char* password = "Local_WiFi_password";

ESP8266WebServer server(80);

String scanResults = "";

void handleRoot() {
  String html = "<!DOCTYPE html><html><head><meta charset='UTF-8'>";
  html += "<title>Skaner WiFi - ESP8266</title>";
  html += "<style>";
  html += "body { font-family: 'Courier New', monospace; background-color: #222; color: #fff; padding: 20px;}";
  html += "h2 { color: #00ff00; }";
  html += "ul { list-style-type: none; padding-left: 20px; }";
  html += "li { margin-bottom: 15px; font-size: 18px; }";
  html += "li span { color: #aaff00; font-weight: bold; }";
  html += "button { padding: 10px 20px; background-color: #00cc00; color: white; border: none; cursor: pointer;}";
  html += "button:hover { background-color: #008800; }";
  html += "</style>";
  html += "</head><body>";
  html += "<h2>WiFi Networks in range of ESP8266:</h2>";
  html += "<form action='/' method='get'><button type='submit'>Refresh Networks</button></form>";
  html += "<ul>";
  html += scanResults;
  html += "</ul>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void scanWiFi() {
  int n = WiFi.scanNetworks();
  scanResults = "";

  for (int i = 0; i < n; ++i) {
    scanResults += "<li><span>SSID:</span> " + WiFi.SSID(i) + 
                   "<ul><li><span>RSSI:</span> " + String(WiFi.RSSI(i)) + " dBm</li>" + 
                   "<li><span>BSSID:</span> " + WiFi.BSSIDstr(i) + "</li></ul></li>";
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting with Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server up.");

  scanWiFi();
}

unsigned long lastScan = 0;

void loop() {
  server.handleClient();

  if (millis() - lastScan > 10000) {
    scanWiFi();
    lastScan = millis();
  }
}