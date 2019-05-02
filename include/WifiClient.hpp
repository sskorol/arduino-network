#ifndef WIFI_CLIENT_HPP
#define WIFI_CLIENT_HPP

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "Helpers.hpp"

class WifiClient {
  static const unsigned int CONNECTION_ATTEMPT_DELAY;
  WiFiClient *client;

 public:
  WifiClient(const char*, const char*, const char*, const char*, const char*);
  WiFiClient* instance();
};

#endif
