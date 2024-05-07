#define LED_PIN 4 // GPIO 2 for onboard LED

void setup() {
  pinMode(LED_PIN, OUTPUT); // Set the LED pin as output
}

void loop() {
  digitalWrite(LED_PIN, HIGH); // Turn on the LED
  delay(1000); // Wait for 1 second
  digitalWrite(LED_PIN, LOW); // Turn off the LED
  delay(1000); // Wait for 1 second
}
