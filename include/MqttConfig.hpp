#ifndef MQTT_CONFIG_HPP
#define MQTT_CONFIG_HPP

#include <Arduino.h>
#include <PubSubClient.h>

class MqttConfig {
    const char *brokerIp;
    const uint16_t brokerPort;
    const char *username;
    const char *password;
    MQTT_CALLBACK_SIGNATURE;
    const char *willTopic;
    const char *willMessage;
    uint16 bufferSize;
    uint8_t willQos;
    boolean willRetain;

public:
    MqttConfig(const char *brokerIp, uint16_t brokePort, const char *username, const char *password,
               std::function<void(char *, uint8_t *, unsigned int)> callback);

    MqttConfig *withWill(const char *topic, const char *message, uint8_t qos = 0, boolean retain = false);

    MqttConfig *withBufferSize(uint16 size);

    uint16 getBufferSize() const;

    const char *getBrokerIp() const;

    uint16_t getBrokerPort() const;

    const char *getUsername() const;

    const char *getPassword() const;

    const char *getWillTopic() const;

    const char *getWillMessage() const;

    uint8_t getWillQos() const;

    boolean getWillRetain() const;

    std::function<void(char *, uint8_t *, unsigned int)> getCallbackFn();
};

#endif
