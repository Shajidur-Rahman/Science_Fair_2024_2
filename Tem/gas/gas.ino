int gasSensorPin = A0;   // Connect sensor to analog pin A0
int gasValue = 0;        // Variable to store gas sensor readings

void setup() {
  Serial.begin(9600);   // Start serial communication
  Serial.println("Gas Sensor Test");
}

void loop() {
  gasValue = analogRead(gasSensorPin);  // Read the analog value from the gas sensor
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);   // Print the gas sensor value to Serial Monitor

  if (gasValue > 300) {   // Threshold value for detecting gas (adjust based on your sensor and environment)
    Serial.println("Gas Detected!");
  }
  else {
    Serial.println("No Gas Detected");
  }
  delay(1000);   // Wait for 1 second before reading again
}
