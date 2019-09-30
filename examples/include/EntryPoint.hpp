#ifndef ENTRY_POINT_HPP
#define ENTRY_POINT_HPP

/**
 * Add lib_deps = https://github.com/bblanchon/ArduinoJson.git to platformio.ini to run this sample
 */
#include <ArduinoJson.h>
#include <list>
#include "Arduino.h"

// Common settings
#define BAUD_RATE 115200

// WiFi settings
const char *DEVICE_IP = "";
const char *MASK = "";
const char *GATEWAY = "";
const char *WIFI_SSID = "";
const char *WIFI_PASSWORD = "";

// Mqtt settings
const char *MQTT_BROKER_IP = "";
const uint16_t MQTT_BROKER_PORT = 1883;
const char *MQTT_USERNAME = "";
const char *MQTT_PASSWORD = "";
const unsigned int JSON_BUFFER_SIZE = 1024;

namespace HeaderName {
    String TURN_ON = "on";
    String TURN_OFF = "off";
}

namespace Topic {
    String HOME = "home/#";
    String DEVICES = "home/devices";
    String DEVICE_PREFIX = "home/device";
}

namespace Device {
    String LAMP = "lamp_1";
}

void initNetwork();

void mqttCallback(char *, byte *, unsigned int);

bool matchesTopicAndCommand(String, const String&, std::list<String>, const String&);

String composeDeviceTopic(String);

#endif
