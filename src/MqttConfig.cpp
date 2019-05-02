#include "MqttConfig.hpp"

const String MqttConfig::CLIENT_ID = "NodeMCUClient-" + String(random(0xffff), HEX);

MqttConfig::MqttConfig(const char* _brokerIp, uint16_t _brokerPort, const char* _username, const char* _password, std::function<void(char*, uint8_t*, unsigned int)> _callbackFn) : brokerIp(_brokerIp), brokerPort(_brokerPort), username(_username), password(_password), callback(_callbackFn) {}

const char* MqttConfig::getBrokerIp() const {
  return brokerIp;
}

const uint16_t MqttConfig::getBrokerPort() const {
  return brokerPort;
}

const char* MqttConfig::getUsername() const {
  return username;
}

const char* MqttConfig::getPassword() const {
  return password;
}

std::function<void(char*, uint8_t*, unsigned int)> MqttConfig::getCallbackFn() {
  return callback;
}
