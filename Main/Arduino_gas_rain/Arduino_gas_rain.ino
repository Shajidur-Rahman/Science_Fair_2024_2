
#include <Servo.h>

Servo myservo;  

// #defin 

const int gasSensorPin = A0;
const int rain = 3;

// int relay = 5;

void setup() {
  Serial.begin(9600);  // Initialize Serial Monitor
  // int relay = 5;
  // relay = HIGH;
  pinMode(5,OUTPUT);
  pinMode(rain,INPUT);
  myservo.attach(9);
}

void loop() {
  int gasValue = analogRead(gasSensorPin);  // Read gas sensor value
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue); 
  Serial.println(digitalRead(3));
  // delay(1000);  // Update every second
  digitalWrite(5,HIGH);

  if (gasValue > 600){
    digitalWrite(5,LOW);
    Serial.println("ababb");
  }

  if (digitalRead(3)==0){
    myservo.write(0);
  } else{
    myservo.write(90);
  }

}
