#include <ArduinoJson.h>
#include <ArduinoJson.hpp>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>  // This is the key change for HTTPS support
#include <WiFiUdp.h>
#include <NTPClient.h>

ESP8266WiFiMulti WiFiMulti;

int pin1 = D1;
int pin2 = D2;
int pin3 = D3;
int pin4 = D4;
int pingTrig = D5;
int pinEcho = D6;

int Timezone = 7 * 3600;
const char* ssid = "gggokopannn____";
const char* password = "1212312121";

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pingTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(D4, OUTPUT);

  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  timeClient.begin();
  timeClient.setTimeOffset(Timezone);
}

void loop() {

  if ((WiFiMulti.run() == WL_CONNECTED)) {
    connectLed("D1", pin1);
    connectLed("D2", pin2);
    connectLed("D3", pin3);
    connectLed("D4", pinEcho);
  }
  delay(1000);
}

void connectLed(String id, int ledPin) {
  Serial.print("=========================================================");
  Serial.print("[HTTP] begin...\n" + id);
  WiFiClientSecure client;
  HTTPClient http;
  client.setInsecure();

  if (http.begin(client, "https://genss333.000webhostapp.com/iot/led_api.php?id=" + id)) {  // HTTP

    Serial.print("[HTTP] GET...\n");
    int httpCode = http.GET();

    if (httpCode > 0) {
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String Json = http.getString();
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, Json);
        String st = doc["status"];
        String closeTime = doc["close_date_time"];
        Serial.println(st);
        Serial.println(closeTime);
        timeClient.update();
        String formattedTime = formatTime(timeClient.getHours(), timeClient.getMinutes());
        Serial.print("Current Time: ");
        Serial.println(formattedTime);

        if (st == "ON") {
          if (closeTime == formattedTime) {
            if (http.begin(client, "https://genss333.000webhostapp.com/iot/update_api.php?id=" + id)) {  // HTTP
              int httpCode = http.GET();
              if (httpCode > 0) {
                if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
                  Serial.printf("Update Success");
                } else {
                  Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
                }
                http.end();
              } else {
                Serial.println("[HTTP] Unable to connect");
              }
              Serial.print("=========================================================");
            }
          } else {
            if(id=="D4"){
              sensor();
            }
            digitalWrite(ledPin, HIGH);
          }
        } else {
          digitalWrite(ledPin, LOW);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.println("[HTTP] Unable to connect");
    }
  }
  Serial.print("=========================================================");
}

void sensor() {
  long duration, cm;
  digitalWrite(pingTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pingTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingTrig, LOW);
  duration = pulseIn(pinEcho, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.println(String(cm) + " cm.");
  delay(300);
  if (cm < 10) {
    digitalWrite(D4, HIGH);
  } else {
    digitalWrite(D4, LOW);
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

String formatTime(int hours, int minutes) {
  // Format hours and minutes as "HH:MM"
  String formattedHours = (hours < 10) ? "0" + String(hours) : String(hours);
  String formattedMinutes = (minutes < 10) ? "0" + String(minutes) : String(minutes);
  return formattedHours + ":" + formattedMinutes;
}

