#ifndef OTA_SERVER_HPP
#define ORA_SERVER_HPP

#ifdef ARDUINO_ARCH_ESP32
  #include <ESPmDNS.h>
  #include <Update.h>
#elif defined(ARDUINO_ARCH_ESP8266)
  #include <ESP8266mDNS.h>
#endif

#include <ArduinoOTA.h>
#include <WiFiUdp.h>

class OtaServer {
  static const uint16_t PORT;
  static const String HOST;

 public:
  OtaServer();
  void listen();
};

#endif
