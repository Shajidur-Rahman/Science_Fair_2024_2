#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
#include "DHT.h"

// WiFi credentials
const char* ssid = "A20";
const char* password = "wfvt8118";

#define DHTPIN 27       // GPIO pin where the DHT22 is connected
#define DHTTYPE DHT22   // DHT22 sensor type

DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor

// Telegram Bot credentials
#define BOTtoken "7072881281:AAHMfKYnp1y-70XXOK-6HWKh1p4eY7z1RgI"
#define CHAT_ID "6381289661"

// Pins
const int lightPin = 33;
const int gas_sensor = 34;
const int rain_sensor = 32;
const int some_sensor = 35;
const int gdl = 2;

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

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

  Serial.println("\nWiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  dht.begin();  // Start DHT sensor
  bot.sendMessage(CHAT_ID, "Bot started up", "");

  pinMode(lightPin, OUTPUT);
  pinMode(gdl, OUTPUT);
  digitalWrite(gdl, HIGH);
}

void loop() {
  // Check for new Telegram messages every 1 second
  if (millis() - lastTime > 1000) {
    lastTime = millis();

    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while (numNewMessages) {
      for (int i = 0; i < numNewMessages; i++) {
        String message = bot.messages[i].text;
        String fromName = bot.messages[i].from_name;

        Serial.print("Message from ");
        Serial.print(fromName);
        Serial.print(": ");
        Serial.println(message);

        if (message == "turn") {
          digitalWrite(lightPin, HIGH);
          Serial.println("Light turned on");
          bot.sendMessage(CHAT_ID, "The light has been turned on.", "");
        }
      }
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
  }

  // Read temperature and humidity from DHT22
  float temperature = dht.readTemperature(); // Celsius
  float humidity = dht.readHumidity();

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");

    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println("%");
  }

  // Read gas, rain, and other sensor values
  int gasValue = analogRead(gas_sensor);
  int rainValue = analogRead(rain_sensor);
  int someValue = analogRead(some_sensor);

  // Debugging sensor values
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  Serial.print("Rain Value: ");
  Serial.println(rainValue);

  Serial.print("Some Sensor Value: ");
  Serial.println(someValue);

  // If gas is detected, send a message to Telegram
  if (gasValue > 3050) {
    bot.sendMessage(CHAT_ID, "Gas leakage detected!", "");
  }

  // If rain is detected (based on the threshold value), send a message to Telegram
  if (rainValue < 3000) {
    bot.sendMessage(CHAT_ID, "Raining detected!", "");
  }

  delay(2000);  // Avoid spamming messages and allow time for sensor reading
}
