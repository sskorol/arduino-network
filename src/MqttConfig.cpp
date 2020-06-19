#include "MqttConfig.hpp"
#include <utility>

MqttConfig::MqttConfig(const char *_brokerIp, uint16_t _brokerPort, const char *_username, const char *_password,
                       std::function<void(char *, uint8_t *, unsigned int)> _callbackFn) : brokerIp(_brokerIp),
                                                                                           brokerPort(_brokerPort),
                                                                                           username(_username),
                                                                                           password(_password),
                                                                                           callback(std::move(
                                                                                                   _callbackFn)),
                                                                                           willTopic(nullptr),
                                                                                           willMessage(nullptr),
                                                                                           willQos(0),
                                                                                           willRetain(true) {}

MqttConfig *MqttConfig::withWill(const char *topic, const char *message, uint8_t qos, boolean retain) {
    willTopic = topic;
    willMessage = message;
    willQos = qos;
    willRetain = retain;
    return this;
}

MqttConfig *MqttConfig::withBufferSize(uint16 size) {
    bufferSize = size;
    return this;
}

uint16 MqttConfig::getBufferSize() const {
    return bufferSize;
}

const char *MqttConfig::getBrokerIp() const {
    return brokerIp;
}

uint16_t MqttConfig::getBrokerPort() const {
    return brokerPort;
}

const char *MqttConfig::getUsername() const {
    return username;
}

const char *MqttConfig::getPassword() const {
    return password;
}

const char *MqttConfig::getWillTopic() const {
    return willTopic;
}

const char *MqttConfig::getWillMessage() const {
    return willMessage;
}

uint8_t MqttConfig::getWillQos() const {
    return willQos;
}

boolean MqttConfig::getWillRetain() const {
    return willRetain;
}

std::function<void(char *, uint8_t *, unsigned int)> MqttConfig::getCallbackFn() {
    return callback;
}
