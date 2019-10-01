#ifndef MQTT_CONFIG_HPP
#define MQTT_CONFIG_HPP

#include <Arduino.h>
#include <PubSubClient.h>

class MqttConfig {
    const char *brokerIp;
    const uint16_t brokerPort;
    const char *username;
    const char *password;
    const char *willTopic;
    const char *willMessage;
    uint8_t willQos;
    boolean willRetain;
    MQTT_CALLBACK_SIGNATURE;

public:
    MqttConfig(const char *, uint16_t, const char *, const char *,
               std::function<void(char *, uint8_t *, unsigned int)>);

    MqttConfig *withWill(const char *, const char *, uint8_t = 0, boolean = true);

    const char *getBrokerIp() const;

    uint16_t getBrokerPort() const;

    const char *getUsername() const;

    const char *getPassword() const;

    const char *getWillTopic() const;

    const char *getWillMessage() const;

    uint8_t getWillQos();

    boolean getWillRetain();

    std::function<void(char *, uint8_t *, unsigned int)> getCallbackFn();
};

#endif
