#include "MqttClient.hpp"

const String MqttClient::CLIENT_ID = "NodeMCUClient-" + String(random(0xffff), HEX);

MqttClient::MqttClient(MqttConfig *_config, WifiClient *wifiClient) : config(_config) {
    mqttClient = new PubSubClient(*wifiClient->instance());
    mqttClient->setServer(config->getBrokerIp(), config->getBrokerPort());
    mqttClient->setCallback(config->getCallbackFn());
}

void MqttClient::connect(void (*subscriptionFn)()) {
    while (!mqttClient->connected()) {
        if (mqttClient->connect(CLIENT_ID.c_str(), config->getUsername(), config->getPassword(), config->getWillTopic(),
                                config->getWillQos(), config->getWillRetain(), config->getWillMessage())) {
            Serial.println("MQTT connected");
            subscriptionFn();
        } else {
            Serial.println("MQTT connection failed");
        }
    }
}

bool MqttClient::isConnected() {
    return mqttClient->connected();
}

void MqttClient::subscribe(const char *topic) {
    mqttClient->subscribe(topic);
}

void MqttClient::publish(const char *topic, const char *message, boolean retain) {
    mqttClient->publish(topic, message, retain);
}

void MqttClient::keepAlive() {
    mqttClient->loop();
}
