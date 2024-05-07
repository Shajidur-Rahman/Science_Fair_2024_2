#include <Servo.h>

Servo gas_servo1;
Servo rain_servo2;

int gas_ser = 6 ; 
int rain_ser = 7 ; 


int gas_sen = A0;
int rain_sen = 5;

int led_red = 8 ; 
int led_green = 9 ; 

int fan_ralay = 10 ; 





void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);

gas_servo1.attach(gas_ser); 
rain_servo2.attach(rain_ser);

pinMode(gas_sen,INPUT);
pinMode(rain_sen,INPUT);
pinMode(led_red,OUTPUT);
pinMode(led_green,OUTPUT);
pinMode(fan_ralay,OUTPUT);



}

void loop() {
  // put your main code here, to run repeatedly:

//  gas_sen + gas_ser + relay
int gas_val = analogRead(gas_sen);
int rain_val = digitalRead(rain_sen);

Serial.println(gas_val);
Serial.println(rain_val);

// Gas_sen start

  if (gas_val > 510) {
    digitalWrite(led_red , HIGH);
    digitalWrite(led_green , LOW);

    digitalWrite(fan_ralay,LOW);

    gas_servo1.write(95);  
    delay(15);   
  }
  else {
    digitalWrite(led_green , HIGH);
    digitalWrite(led_red , LOW);

    digitalWrite(fan_ralay,HIGH);

    gas_servo1.write(5);  
    delay(15);  
  }

  //gas_sen end && rain_sen start

  if (rain_val == 1) {
    rain_servo2.write(95);  
    delay(15);  
  }
  if (rain_val == 0) {
    rain_servo2.write(0);  
    delay(15);  
  }

  //rain_sen end


delay(1);

}