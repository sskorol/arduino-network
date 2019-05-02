#include "EntryPoint.hpp"
#include "MqttClient.hpp"
#include "OtaServer.hpp"
#include "WifiClient.hpp"

MqttConfig* mqttConfig;
MqttClient* mqttClient;
OtaServer* otaServer;
WifiClient* wifiClient;

void setup() {
  Serial.begin(BAUD_RATE);
  initNetwork();
}

void initNetwork() {
  randomSeed(micros());
  wifiClient = new WifiClient(DEVICE_IP, MASK, GATEWAY, WIFI_SSID, WIFI_PASSWORD);
  otaServer = new OtaServer();
  mqttConfig = new MqttConfig(MQTT_BROKER_IP, MQTT_BROKER_PORT, MQTT_USERNAME, MQTT_PASSWORD, mqttCallback);
  mqttClient = new MqttClient(mqttConfig, wifiClient);
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  char json[length];
  for (unsigned int i = 0; i < length; i++) {
    json[i] = (char)payload[i];
  }

  StaticJsonDocument<JSON_BUFFER_SIZE> jsonBuffer;
  deserializeJson(jsonBuffer, json);
  JsonArray dataArray = jsonBuffer.as<JsonArray>();

  for (auto data : dataArray) {
    const char* command = data["command"];
    if (strcmp(Topic::DISCOVERY, topic) == 0 && strcmp(Command::REPORT_STATE, command) == 0) {
      mqttClient->publish(Topic::DEVICES, "device discovery response");
    }
  }
}

void loop() {
  otaServer->listen();

  if (!mqttClient->isConnected()) {
    mqttClient->connect([] { mqttClient->subscribe(Topic::HOME); });
  }
  mqttClient->keepAlive();
}
