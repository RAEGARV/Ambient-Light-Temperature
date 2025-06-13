# Ambient Light & Temperature Logger - Arduino

**Files**  
- `README.md`  
- `AmbientLightLogger.ino`

## 1. Concept  
A self-hosted logger that measures ambient light (lux) via BH1750 and temperature via DS18B20, then serves a live dashboard (charts) over Wi-Fi. No external server—just browse to the ESP8266’s IP.

**Key Features**  
- BH1750 (I²C) for lux measurements  
- DS18B20 (1-Wire) for °C readings  
- ESP8266 (NodeMCU) hosting an HTTP server  
- Responsive web page with two real-time line charts (Chart.js)  
- Auto-refreshes every 5 s  

## 2. Bill of Materials  
- 1 × NodeMCU ESP8266 board  
- 1 × BH1750 light sensor (I²C)  
- 1 × DS18B20 temperature probe + 4.7 kΩ pull-up resistor  
- Breadboard & jumper wires  
- USB cable for power/programming  

## 3. Wiring Diagram

    NodeMCU ESP8266       Module
    ┌──────────────┐      ┌──────────┐
    │ VIN ──► 5 V    │      │ BH1750   │
    │ GND ──► GND   │      │ BH1750   │
    │ D2  ──► SDA   │◄───►│ SDA      │
    │ D1  ──► SCL   │◄───►│ SCL      │
    ├──────────────┤                
    │ D4  ──► DATA  │◄───►│ DS18B20  │
    │ 5 V ──► VCC   │      │ VCC      │
    │ GND ──► GND   │      │ GND      │
    └──────────────┘                

> Pull DS18B20 DATA up to 5 V via 4.7 kΩ.

## 4. Software Setup  
1. In Arduino IDE, install libraries:  
   - **ESP8266WiFi**  
   - **ESP8266WebServer**  
   - **OneWire**, **DallasTemperature**  
   - **BH1750** by Christopher Laws  
2. Create folder `AmbientLightLogger/` and save:  
   - `README.md`  
   - `AmbientLightLogger.ino`  
3. Open the `.ino` in Arduino IDE, set your **SSID** & **PASSWORD**, select **NodeMCU 1.0**, then **Upload**.

## 5. Usage  
- After upload, open Serial Monitor @ 115200 baud.  
- Wait for `Connected! IP: ` message.  
- In a browser, go to `http://<ESP_IP>/`.  
- Watch live charts of light (lux) and temperature (°C).  

---

Say **continua** to move on to project #10!  
