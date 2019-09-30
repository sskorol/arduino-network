#include "OtaServer.hpp"

const uint16_t OtaServer::PORT = 8266;
const String OtaServer::HOST = "NodeMCUClient-" + String(random(0xffff), HEX);

OtaServer::OtaServer() {
    Serial.println("Configuring OTA device...");
    ArduinoOTA.setPort(PORT);
    ArduinoOTA.setHostname(HOST.c_str());
    ArduinoOTA.onStart([]() {
        Serial.println("OTA starting...");
    });
    ArduinoOTA.onEnd([]() {
        Serial.println("OTA update finished!");
        Serial.println("Rebooting...");
    });
    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("OTA in progress: %u%%\r\n", (progress / (total / 100)));
    });
    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        if (error == OTA_AUTH_ERROR) {
            Serial.println("Auth Failed");
        } else if (error == OTA_BEGIN_ERROR) {
            Serial.println("Begin Failed");
        } else if (error == OTA_CONNECT_ERROR) {
            Serial.println("Connect Failed");
        } else if (error == OTA_RECEIVE_ERROR) {
            Serial.println("Receive Failed");
        } else if (error == OTA_END_ERROR) {
            Serial.println("End Failed");
        }
    });
    ArduinoOTA.begin();
    Serial.println("OTA setup is completed");
}

void OtaServer::listen() {
    ArduinoOTA.handle();
}
