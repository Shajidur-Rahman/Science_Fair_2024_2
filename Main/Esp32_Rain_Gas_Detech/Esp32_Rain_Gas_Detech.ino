#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
const char* ssid = "A20";
const char* password = "wfvt8118";

// const char* ssid = "MEZBAH";
// const char* password = "komoladadur";

#define BOTtoken "7072881281:AAHMfKYnp1y-70XXOK-6HWKh1p4eY7z1RgI"  // your Bot Token (Get from Botfather) 
#define CHAT_ID "6381289661"
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);


// main work place 



// define pins 

//const int buttonPin = 4;
//const int ledPin =  5; 

const int gas_sensor = 34;    

const int rain_sensor = 32;

const int some_sensor = 35;
const int gdl = 2; 

//int analogValue = 0;   

//int gas_sensor = 4;







// state
//int buttonState = 0;
//gas_sensor = 0;










void setup() {
  Serial.begin(115200);
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); 
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  bot.sendMessage(CHAT_ID, "Bot started up", "");










  // pinMode
  pinMode(gdl,OUTPUT);

digitalWrite(gdl,HIGH);




  
}

void loop() {

 int sensorValue = analogRead(gas_sensor);
 int rainValue = analogRead(rain_sensor);
 int someValue = analogRead(some_sensor);
  Serial.println(sensorValue);
//  Serial.print("rin :");
 Serial.println(sensorValue);
//Serial.println(someValue);
//  if (sensorValue > 3200)
//  {
//    digitalWrite(gdl,LOW);
//    bot.sendMessage(CHAT_ID, "Gas deteched", "");
//    
//  } 
//  else{
//    digitalWrite(gdl,HIGH);  
//    }
delay(100);

if (sensorValue > 3050){
  bot.sendMessage(CHAT_ID, "Gas leakagehas been detected!! ", "");
  }
if (rainValue < 3000){
  // bot.sendMessage(CHAT_ID, "Raining, raining!!", "");
  }

//   delay(2000);
  
// bot.sendMessage(CHAT_ID, "Mewo", "");

}