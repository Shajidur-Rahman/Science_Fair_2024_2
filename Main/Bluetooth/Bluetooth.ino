#include <Servo.h>
Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position


int tf = 7;  //table fan
int cf = 6; //celling fan
int l1 = 5; // led
int l2 = 4; //led
char bt = 'a';


void setup() {
  Serial.begin(9600);

  pinMode(tf,OUTPUT);
  pinMode(cf,OUTPUT); 
  pinMode(l1,OUTPUT); 
  pinMode(l2,OUTPUT); 

  digitalWrite(tf,LOW);
  digitalWrite(cf,LOW);
  digitalWrite(l1,LOW);
  digitalWrite(l2,LOW);

  myservo.attach(9);

}

void loop() {

if(Serial.available())
{
  bt = Serial.read();
  delay(20);
  char val = bt;
  

  //Fan 1
  if(val == '1'){
    digitalWrite(cf,HIGH);
    Serial.println(val);
    Serial.println("Table Fan ON");
  }
  else if(val == '2'){
    digitalWrite(cf,LOW);
    Serial.println(val);
    Serial.println("Table Fan OFF");
  }

  //Fan 2
  else if(val == '3'){
    digitalWrite(tf,HIGH);
    myservo.write(100);              // tell servo to go to position in variable 'pos'
    delay(15);
    Serial.println(val);
    Serial.println("Celling Fan ON");
  }
  else if(val == '4'){
    digitalWrite(tf,LOW);
    Serial.println(val);
    Serial.println("Celling Fan OFF");
  }

  //LED 
  else if(val == '5'){
    digitalWrite(l1,HIGH);
    Serial.println(val);
    Serial.println("LED1 ON");
  }
  else if(val == '6'){
    digitalWrite(l1,LOW);
    Serial.println(val);
    Serial.println("LED1 OFF");
  }

  //LED
  else if(val == '7'){
    digitalWrite(l2,HIGH);
    Serial.println(val);
    Serial.println("LED2 ON");
  }
  else if(val == '8'){
    digitalWrite(l2,LOW);
    Serial.println(val);
    Serial.println("LED2 OFF");
  }
}
delay(10);

}