#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>

// WiFi credentials
const char* ssid = "A20";
const char* password = "wfvt8118";

// Telegram Bot credentials
#define BOTtoken "7072881281:AAHMfKYnp1y-70XXOK-6HWKh1p4eY7z1RgI"
#define CHAT_ID "6381289661"

// Pins
const int lightPin = 33;   // Pin for the light (could be a relay or an LED)
const int gas_sensor = 34;    
const int rain_sensor = 32;
const int some_sensor = 35;
const int gdl = 2; 

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Variable to store the last update timestamp
unsigned long lastTime = 0;

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
  pinMode(lightPin, OUTPUT);
  pinMode(gdl, OUTPUT);
  digitalWrite(gdl, HIGH);
}

void loop() {
  // Check for new messages every 1 second
  if (millis() - lastTime > 1000) {
    lastTime = millis();

    // Get the latest updates from the bot
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages) {
      for (int i = 0; i < numNewMessages; i++) {
        String message = bot.messages[i].text;  // Get the message text
        String fromName = bot.messages[i].from_name; // Get sender's name

        Serial.print("Message from ");
        Serial.print(fromName);
        Serial.print(": ");
        Serial.println(message);

        // Check if the message is "turn off light"
        if (message == "turn") {
          digitalWrite(lightPin, HIGH);  // Turn off the light
          Serial.print("alodmahmud");
          bot.sendMessage(CHAT_ID, "The light has been turned off.", "");
        }

        // You can add more commands here if you like

      }

      // Update the last message received ID
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
  }

  // Read the gas, rain, and other sensor values
  int sensorValue = analogRead(gas_sensor);
  int rainValue = analogRead(rain_sensor);
  int someValue = analogRead(some_sensor);
  Serial.println(sensorValue);

  // If gas is detected, send a message to Telegram
  if (sensorValue > 3050) {
    bot.sendMessage(CHAT_ID, "Gas leakage has been detected!!", "");
  }

  // If rain is detected (based on the threshold value), send a message to Telegram
  if (rainValue < 3000) {
    //bot.sendMessage(CHAT_ID, "Raining, raining!!", "");
  }

  delay(1000);  // Delay to avoid flooding the bot with messages
}
