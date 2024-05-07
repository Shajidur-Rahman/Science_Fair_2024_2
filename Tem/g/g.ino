#include <Servo.h>
char val;
Servo servo;

int fan = 5;
int ser = 4;

void setup() {
servo.attach(ser);

pinMode(13,OUTPUT);
pinMode(fan,OUTPUT);
pinMode(ser,OUTPUT);
Serial.begin(9600);
 digitalWrite(13,HIGH);
  
}

void loop() {

  if(Serial.available()){
 val = Serial.read();
 Serial.println(val);
}


if(val=='7'){
  digitalWrite(ser,LOW);

delay(10);
 
}
else if(val=='8'){
  digitalWrite(ser,HIGH);

delay(10);

}


if(val=='1'){
  digitalWrite(13,LOW);
delay(10);
 
}
else if(val=='2'){
  digitalWrite(13,HIGH);
delay(10);

}


if(val=='3'){
  digitalWrite(fan,LOW);
delay(10);
 
}
else if(val=='4'){
  digitalWrite(fan,HIGH);
delay(10);

}






delay(10);

}
