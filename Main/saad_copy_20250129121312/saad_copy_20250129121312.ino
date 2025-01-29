#include <Servo.h>
int gas=A0;
int relay=6;
int rain=3

Servo myServo;  // Create a Servo object

void setup() {
    pinMode(gas, INPUT);
    pinMode(rain,INPUT);
    pinMode(relay,OUTPUT);
    Serial.begin(9600);
    myServo.attach(9); 
}

void loop() {
    // Nothing needed in loop, servo will stay at 90 degrees
    // myServo.attach(9);  // Connect servo signal pin to D9
    myServo.write(0);  // Move servo to 90 degrees
    
    // myServo.write(90);
    // delay(2000);
    Serial.println(analogRead(gas));
    // if (analogRead(gas)>200){
    //   // digitalWrite(relay, LOWjho);
    //   Serial.println("yes");
    // }
    // else{
    //   // digitalWrite(relay, HIGH);
    //   Serial.println("no");
    // }



    
}
