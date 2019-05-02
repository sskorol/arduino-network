#ifndef ENTRY_POINT_HPP
#define ENTRY_POINT_HPP

#include <ArduinoJson.h>

// Common settings
#define BAUD_RATE 115200

// WiFi settings
const char* DEVICE_IP = "";
const char* MASK = "";
const char* GATEWAY = "";
const char* WIFI_SSID = "";
const char* WIFI_PASSWORD = "";

// Mqtt settings
const char* MQTT_BROKER_IP = "";
const uint16_t MQTT_BROKER_PORT = 1883;
const char* MQTT_USERNAME = "";
const char* MQTT_PASSWORD = "";

// Commands
namespace Command {
  const char* REPORT_STATE = "reportState";
}

// Topics
namespace Topic {
  const char* HOME = "home/#";
  const char* DISCOVERY = "home/discovery";
  const char* DEVICES = "home/devices";
}

void initNetwork();
void mqttCallback(char*, byte*, unsigned int);

#endif
