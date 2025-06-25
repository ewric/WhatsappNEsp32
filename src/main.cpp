#include <Arduino.h>
#include <WiFiManager.h>

// put function declarations here:
/**
 * @file Whatsapp_Message.ino
 * @author Hafidh Hidayat (hafidhhidayat@hotmail.com)
 * @brief Example WhatsApp Messages
 * 
 * @copyright Copyright (c) 2022
 * 
 * Github :
 * https://github.com/hafidhh
 * https://github.com/hafidhh/Callmebot-ESP32
 */
#include <Callmebot_ESP32.h>

// Note :
// phoneNumber : Indonesia +62, Example: "+62897461238"
// apiKey : Follow instruction on https://www.callmebot.com/blog/free-api-whatsapp-messages/
String phoneNumber = "+55XXXXXXXXXX"; //não coloque o 9 no número.
String apiKey = "XXXXXX";
String messsage = "your_text_message";

void connectToWifi();

void setup() {
	Serial.begin(115200);
  connectToWifi();

	// Whatsapp Message
	Callmebot.whatsappMessage(phoneNumber, apiKey, messsage);
	Serial.println(Callmebot.debug());
}

void loop() {
	
}




void connectToWifi() {
  WiFiManager wm;
  //wm.resetSettings();
  bool res;
  res = wm.autoConnect("Esp32Conexao");
  if(!res){
    Serial.println("Failed connecting to internet.");
    ESP.restart();
  }
  else{
    Serial.println("Connected to Wifi.");
  }
  Serial.println("IP Address: ");
  Serial.println(WiFi.localIP());
}