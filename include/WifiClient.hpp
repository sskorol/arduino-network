#ifndef WIFI_CLIENT_HPP
#define WIFI_CLIENT_HPP

#ifdef ARDUINO_ARCH_ESP32
    #include <WiFi.h>
#elif defined(ARDUINO_ARCH_ESP8266)
    #include <ESP8266WiFi.h>
#endif

#include <Arduino.h>
#include "Helpers.hpp"

class WifiClient {
    static const unsigned int CONNECTION_ATTEMPT_DELAY;
    WiFiClient *client;

public:
    WifiClient(const char *, const char *, const char *, const char *, const char *);

    WiFiClient *instance();
};

#endif
