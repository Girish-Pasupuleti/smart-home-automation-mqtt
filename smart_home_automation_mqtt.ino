#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

// WIFI
const char* WIFI_SSID = "Mukhesh";
const char* WIFI_PASS = "nee peru enti";

// MQTT
const char* MQTT_HOST = "bf2ca32aa0204eb8b2c137f8def7b444.s1.eu.hivemq.cloud";
const int MQTT_PORT = 8883;

const char* MQTT_USER = "mukhesh";
const char* MQTT_PASS = "Mukhesh@2005";

const char* CLIENT_ID = "esp32_home_001";

// PINS
#define PIN_BEDROOM 2
#define PIN_HALL 4
#define PIN_FAN 5
#define PIN_DOOR 18

WiFiClientSecure secureClient;
PubSubClient mqtt(secureClient);

int deviceToPin(String d) {
  if (d == "bedroom") return PIN_BEDROOM;
  if (d == "hall") return PIN_HALL;
  if (d == "fan") return PIN_FAN;
  if (d == "door") return PIN_DOOR;
  return -1;
}

void publishState(String device, String state) {
  String topic = "home/" + device + "/state";
  mqtt.publish(topic.c_str(), state.c_str());
}

void callback(char* topic, byte* payload, unsigned int length) {
  String t = String(topic);
  String msg = "";

  for (int i = 0; i < length; i++) msg += (char)payload[i];

  Serial.print("Received: ");
  Serial.print(t);
  Serial.print(" => ");
  Serial.println(msg);

  int a = t.indexOf('/');
  int b = t.indexOf('/', a + 1);
  String device = t.substring(a + 1, b);

  int pin = deviceToPin(device);
  if (pin == -1) {
    Serial.println("Unknown device");
    return;
  }

  int on_level;
  int off_level;

  if (device == "bedroom" || device == "hall") {
    on_level = LOW;
    off_level = HIGH;
  } else {
    on_level = HIGH;
    off_level = LOW;
  }

  if (msg == "ON") {
    digitalWrite(pin, on_level);
    publishState(device, "ON");
  } else if (msg == "OFF") {
    digitalWrite(pin, off_level);
    publishState(device, "OFF");
  }
}

void connectMQTT() {
  while (!mqtt.connected()) {
    Serial.print("Connecting to MQTT...");
    if (mqtt.connect(CLIENT_ID, MQTT_USER, MQTT_PASS)) {
      Serial.println("connected");
      mqtt.subscribe("home/+/set");
    } else {
      Serial.print("failed rc=");
      Serial.print(mqtt.state());
      Serial.println(" retry in 3s");
      delay(3000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  pinMode(PIN_BEDROOM, OUTPUT);
  pinMode(PIN_HALL, OUTPUT);
  pinMode(PIN_FAN, OUTPUT);
  pinMode(PIN_DOOR, OUTPUT);

  digitalWrite(PIN_BEDROOM, HIGH);
  digitalWrite(PIN_HALL, HIGH);
  digitalWrite(PIN_FAN, LOW);
  digitalWrite(PIN_DOOR, LOW);

  Serial.print("Connecting to WiFi...");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("OK");

  secureClient.setInsecure();
  mqtt.setServer(MQTT_HOST, MQTT_PORT);
  mqtt.setCallback(callback);
}

void loop() {
  if (!mqtt.connected()) connectMQTT();
  mqtt.loop();
}