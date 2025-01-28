#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

int livingroom = 5;
int bedroom = 6;
int diningroom = 7;

SoftwareSerial Bluetooth(0, 1);
char Data;
void sendData(String transmitData){
Bluetooth.println(transmitData);}

void setup(){
    Bluetooth.begin(9600);
    pinMode(livingroom,OUTPUT);
    pinMode(bedroom,OUTPUT);
    pinMode(diningroom,OUTPUT);
}

void loop(){
    if(Bluetooth.available()){
        Data=Bluetooth.read();
        if(Data==('4')){
            digitalWrite(livingroom,1);
            sendData("Living Room Light ON");
        }
        if(Data==('1')){
            digitalWrite(livingroom,0);
            sendData("Living Room Light OFF");
        }
        if(Data==('5')){
            digitalWrite(bedroom,1);
            sendData("Bedroom Light ON");
        }
        if(Data==('2')){
            digitalWrite(bedroom,0);
            sendData("Bedroom Light OFF");
        }
        if(Data==('6')){
            digitalWrite(diningroom,1);
            sendData("Dining Room Light ON");
        }
        if(Data==('3')){
            digitalWrite(diningroom,0);
            sendData("Dining Room Light OFF");
        }
        if(Data==('9')){
            digitalWrite(livingroom,1);
            digitalWrite(bedroom,1);
            digitalWrite(diningroom,1);
            sendData("ALL LIGHTS ON");
        }
        if(Data==('0')){
            digitalWrite(livingroom,0);
            digitalWrite(bedroom,0);
            digitalWrite(diningroom,0);
            sendData("ALL LIGHTS OFF");
        }
    }
}
