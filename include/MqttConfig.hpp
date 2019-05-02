#ifndef MQTT_CONFIG_HPP
#define MQTT_CONFIG_HPP

#include <Arduino.h>
#include <PubSubClient.h>

class MqttConfig {
  static const String CLIENT_ID;
  const char* brokerIp;
  const uint16_t brokerPort;
  const char* username;
  const char* password;
  MQTT_CALLBACK_SIGNATURE;

 public:
  MqttConfig(const char*, uint16_t, const char*, const char*, std::function<void(char*, uint8_t*, unsigned int)>);
  const char* getBrokerIp() const;
  const uint16_t getBrokerPort() const;
  const char* getUsername() const;
  const char* getPassword() const;
  std::function<void(char*, uint8_t*, unsigned int)> getCallbackFn();
};

#endif
