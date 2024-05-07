#include <Servo.h>

// Create a servo object
Servo myServo;

// Define the pin for the servo
const int servoPin = 9;

// Variables to store servo position
int pos = 0;
int increment = 1; // Increment step for servo movement

void setup() {
  // Attach the servo to the pin
  myServo.attach(servoPin);
}

void loop() {
  // Sweep the servo from 0 to 180 degrees
  for (pos = 0; pos <= 180; pos += increment) {
    myServo.write(pos); // Set servo position
    delay(15); // Wait for the servo to reach the position
  }

  // Sweep the servo from 180 to 0 degrees
  for (pos = 180; pos >= 0; pos -= increment) {
    myServo.write(pos); // Set servo position
    delay(15); // Wait for the servo to reach the position
  }
}
