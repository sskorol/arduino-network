#include "WifiClient.hpp"

using namespace Helpers;

const unsigned int WifiClient::CONNECTION_ATTEMPT_DELAY = 500;

WifiClient::WifiClient(const char *ip, const char *mask, const char *gateway, const char *ssid, const char *password) {
    client = new WiFiClient();
    WiFi.mode(WIFI_STA);
    WiFi.config(toIP(ip), toIP(mask), toIP(gateway));
    WiFi.begin(ssid, password);

    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        delay(CONNECTION_ATTEMPT_DELAY);
        Serial.print(".");
    }

    Serial.println("\nWiFi connected");
    Serial.println(WiFi.localIP());
}

WiFiClient *WifiClient::instance() {
    return client;
}
