#include <ArduinoJson.h>
#include <ArduinoJson.hpp>

/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

int pin1 = D1;
int pin2 = D2;
int pin3 =D3;
int pin4 = D4;
int pin5 = D5;

void setup() {

  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5,OUTPUT);

  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("AunSo", "11198kkkk");
}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    checkOnLed();
    connectLed("D1");
    connectLed("D2");
    connectLed("D3");
    connectLed("D4");
  }

  delay(1000);
}

void connectLed(String id) {
  Serial.print("[HTTP] begin...\n"+id);
  WiFiClient client;
  HTTPClient http;
  if (http.begin(client, "http://192.168.43.221/iot/led_api.php?id=" + id)) {  // HTTP

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
        Serial.println(st);
        if (st == "ON") {
          if(id == "D1"){
            digitalWrite(pin1, HIGH);
          }
          if(id == "D2"){
            digitalWrite(pin2, HIGH);
          }
          if(id == "D3"){
            digitalWrite(pin3, HIGH);
          }
          if(id == "D4"){
            digitalWrite(pin4, HIGH);
          }
        } else {
          if(id == "D1"){
            digitalWrite(pin1, LOW);
          }
          if(id == "D2"){
            digitalWrite(pin2, LOW);
          }
          if(id == "D3"){
            digitalWrite(pin3, LOW);
          }
          if(id == "D4"){
            digitalWrite(pin4, LOW);
          }
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

void checkOnLed(){
  Serial.print("[HTTP] begin...\n count led");
  WiFiClient client;
  HTTPClient http;
  if (http.begin(client, "http://192.168.43.221/iot/led_api.php")) {  // HTTP

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
        int st = doc["status"];
        Serial.println(st);
        if(st <= 2){
          digitalWrite(pin5, LOW);
        }else{
          digitalWrite(pin5, HIGH);
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
