#ifndef HELPERS_HPP
#define HELPERS_HPP

#ifdef ARDUINO_ARCH_ESP32
    #include <WiFi.h>
#elif defined(ARDUINO_ARCH_ESP8266)
    #include <ESP8266WiFi.h>
#endif

namespace Helpers {
    IPAddress toIP(const String&);
}

#endif
