// File: AmbientLightLogger.ino
// ESP8266 Web Logger: BH1750 (lux) & DS18B20 (°C) with live charts

#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <BH1750.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// ===== User Wi-Fi Config =====
const char* WIFI_SSID = "YOUR_SSID";
const char* WIFI_PASS = "YOUR_PASSWORD";

// ===== Sensor Pins =====
#define ONEWIRE_PIN D4      // DS18B20 data pin
OneWire      oneWire(ONEWIRE_PIN);
DallasTemperature ds18b20(&oneWire);
BH1750       bh1750;

// ===== Web Server =====
ESP8266WebServer server(80);

// ===== HTML + Chart.js page (served from PROGMEM) =====
const char INDEX_HTML[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Ambient Light & Temperature Logger</title>
  <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
  <style>
    canvas { max-width: 600px; width: 100%; margin-bottom: 30px; }
  </style>
</head>
<body>
  <h2>Ambient Light & Temperature Logger</h2>
  <canvas id="luxChart"></canvas>
  <canvas id="tempChart"></canvas>
  <script>
    const luxCtx  = document.getElementById('luxChart').getContext('2d');
    const tempCtx = document.getElementById('tempChart').getContext('2d');
    const luxChart = new Chart(luxCtx, {
      type: 'line',
      data: { labels: [], datasets: [{ label: 'Lux', borderColor: 'orange', fill: false, data: [] }] },
      options: { responsive: true, scales: { y: { beginAtZero: true } } }
    });
    const tempChart = new Chart(tempCtx, {
      type: 'line',
      data: { labels: [], datasets: [{ label: '°C', borderColor: 'teal', fill: false, data: [] }] },
      options: { responsive: true }
    });
    function fetchData() {
      fetch('/data')
        .then(resp => resp.json())
        .then(d => {
          const t = new Date(d.time).toLocaleTimeString();
          // Lux
          luxChart.data.labels.push(t);
          luxChart.data.datasets[0].data.push(d.lux);
          if (luxChart.data.labels.length > 30) {
            luxChart.data.labels.shift();
            luxChart.data.datasets[0].data.shift();
          }
          luxChart.update();
          // Temperature
          tempChart.data.labels = luxChart.data.labels;
          tempChart.data.datasets[0].data.push(d.temp);
          if (tempChart.data.datasets[0].data.length > 30) {
            tempChart.data.datasets[0].data.shift();
          }
          tempChart.update();
        });
    }
    setInterval(fetchData, 5000);
    window.onload = fetchData;
  </script>
</body>
</html>
)rawliteral";

// ===== HTTP Handlers =====
void handleRoot() {
  server.send_P(200, "text/html", INDEX_HTML);
}

void handleData() {
  float lux = bh1750.readLightLevel();
  ds18b20.requestTemperatures();
  float temp = ds18b20.getTempCByIndex(0);
  // JSON with timestamp (ms since boot)
  String json = "{";
  json += "\"time\":" + String(millis()) + ",";
  json += "\"lux\":"  + String(lux,1)   + ",";
  json += "\"temp\":" + String(temp,1);
  json += "}";
  server.send(200, "application/json", json);
}

// ===== Setup & Loop =====
void setup() {
  Serial.begin(115200);

  // Initialize sensors
  Wire.begin(D2 /* SDA */, D1 /* SCL */);
  if (!bh1750.begin()) {
    Serial.println("BH1750 init failed");
    while (1);
  }
  ds18b20.begin();

  // Connect Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  // Start web server
  server.on("/",    handleRoot);
  server.on("/data", handleData);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
