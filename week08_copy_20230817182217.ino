#include <ArduinoJson.h>
#include <ArduinoJson.hpp>

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

int pin1 = D1;
int pin2 = D2;
int pin3 = D3;

void setup() {

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);

  Serial.begin(115200);

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("Onizuka", "Por091111");

}

void loop() {
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    connectLed("D1");
    connectLed("D2");
    connectLed("D3");
    connectLed("D4");
  }

  delay(1000);
}

void connectLed(String id) {
  Serial.print("[HTTP] begin...\n" + id);
  WiFiClient client;
  HTTPClient http;
  if (http.begin(client, "http://192.168.225.183/iot/led_api.php?id=" + id)) {  // HTTP

    Serial.print("[HTTP] GET...\n");
    // start connection and send HTTP header
    int httpCode = http.GET();

    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
        String Json = http.getString();
        DynamicJsonDocument doc(1024);
        deserializeJson(doc, Json);
        String st = doc["status"];
        String closeDate = doc["close_date_time"];
        Serial.println(st);
        Serial.println(closeDate);


        if (st == "ON") {
          if (id == "D1" ) {
            digitalWrite(pin1, HIGH);
          }
          if (id == "D2" ) {
            digitalWrite(pin2, HIGH);
          }
          if (id == "D3" ) {
            digitalWrite(pin3, HIGH);
          }
          if (id == "D4" ) {
          }
        } else {
          if (id == "D1" ) {
            digitalWrite(pin1, LOW);
          }
          if (id == "D2") {
            digitalWrite(pin2, LOW);
          }
          if (id == "D3") {
            digitalWrite(pin3, LOW);
          }
          if (id == "D4") {
          }
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }


      http.end();
    } else {
      Serial.println("[HTTP] Unable to connect");
    }
  }
}

// void sensor() {
//   long duration, cm;
//   digitalWrite(pingTrig, LOW);
//   delayMicroseconds(2);
//   digitalWrite(pingTrig, HIGH);
//   delayMicroseconds(5);
//   digitalWrite(pingTrig, LOW);
//   duration = pulseIn(pinEcho, HIGH);
//   cm = microsecondsToCentimeters(duration);
//   Serial.println(String(cm) + " cm.");
//   delay(300);
//   if (cm < 20) {
//     digitalWrite(D4, HIGH);
//     digitalWrite(D5, HIGH);
//   } else {
//     digitalWrite(D4, LOW);
//     digitalWrite(D5, LOW);
//   }
// }
// long microsecondsToCentimeters(long microseconds) {
//   return microseconds / 29 / 2;
// }
