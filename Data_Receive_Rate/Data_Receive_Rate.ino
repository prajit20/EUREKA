/*
  Rui Santos
  Complete project details at https://randomnerdtutorials.com/esp-now-one-to-many-esp8266-nodemcu/

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <ESP8266WiFi.h>
#include <SPI.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include<ESP8266WiFi.h>
#include <espnow.h>




// Structure example to receive data
// Must match the sender structure
typedef struct test_struct {
    int x;
    int y;
} test_struct;
double myTime;
double timediff;


// Create a struct_message called myData
test_struct myData;

// Callback function that will be executed when data is received
void OnDataRecv(uint8_t * mac, uint8_t incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(myData));
  Serial.print("Bits received: ");
  Serial.println(8len);
  //Serial.print("Time: ");
  timediff = millis() - myTime;
  myTime = millis();
 // Serial.println(myTime);
  Serial.print("Time Differece [ms]: ");
  Serial.println(timediff);

  //added

  double L;
  double datarate;
  datarate = 8*len/timediff;
  Serial.print("Data Rate [Kbps]: ");
  Serial.println(datarate);
  //done added
}
 
void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Set device as a Wi-Fi Station
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for recv CB to
  // get recv packer info
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);


}
void loop() {
