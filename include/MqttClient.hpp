#ifndef MQTT_CLIENT_HPP
#define MQTT_CLIENT_HPP

#include <PubSubClient.h>
#include "MqttConfig.hpp"
#include "WifiClient.hpp"

class MqttClient {
    static const String CLIENT_ID;
    PubSubClient *mqttClient;
    MqttConfig *config;

public:
    MqttClient(MqttConfig *, WifiClient *);

    void connect(void (*)() = [] {});

    bool isConnected();

    void subscribe(const char *);

    void publish(const char *, const char *, boolean = false);

    void keepAlive();
};

#endif
