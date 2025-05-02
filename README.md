# ESP8266_wifi_sniffer
A quick presentation of ESP8266 network tools possibilities. The ESP8266 board is searching for the WiFi networks within its range, creates a HTTP server which can be entered through the local ip connection and lists the availible WiFi networks in SSID, RSSI, BSSID format.

This project runs on an ESP8266 microcontroller and creates a simple HTTP server that scans for nearby WiFi networks and displays their details (SSID, RSSI, BSSID) in a web browser.

Features:
    - Scans available WiFi networks every 10 seconds
    - Hosts a local web server accessible via LAN
    - Displays results in a programmer-style HTML interface with monospaced font and dark theme
    - Manual refresh button to update scan results on demand
    - Clean and readable nested structure for each detected network

What You'll See:
WiFi Networks in range of ESP8266:
- SSID: MyWiFiNetwork
    - RSSI: -42 dBm
    - BSSID: AA:BB:CC:DD:EE:FF
- SSID: AnotherNetwork
    - RSSI: -70 dBm
    - BSSID: 11:22:33:44:55:66
 
How to Use:
    1. Update your ssid and password in the code to match your WiFi.
    2. Upload the code to your ESP8266 via Arduino IDE.
    3. Open the Serial Monitor (115200 baud) and find the assigned IP address.
    4. Enter that IP in a browser on the same local network to view the WiFi scan results.

Needed libraries:
        - ESP8266WiFi.h
        - ESP8266WebServer.h
