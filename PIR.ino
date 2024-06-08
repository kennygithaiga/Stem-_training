#include <arduino.h>

int ledPin=12;
int inputPin=8;
int pirState = LOW;
int Val =0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin,INPUT);

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {

  Val = digitalRead(inputPin);

  if(Val == HIGH){

    digitalWrite(ledPin,HIGH);
    if(pirState == LOW);{

      Serial.println("Motion detected");
      pirState = HIGH;
    }
  }

      else{
        digitalWrite(ledPin,LOW);
        if(pirState == HIGH);
        Serial.println("Motion ended");
        pirState =LOW;




      }




    }




  

  // put your main code here, to run repeatedly:


