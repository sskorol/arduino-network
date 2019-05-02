#ifndef OTA_SERVER_HPP
#define ORA_SERVER_HPP

#include <ArduinoOTA.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>

class OtaServer {
  static const uint16_t PORT;
  static const String HOST;

 public:
  OtaServer();
  void listen();
};

#endif
