#include "DHT.h"

int DHTPIN =8;
int relayPin = 13;

int start = 12;
int reset =11;
int stop = 10;

int buttonstart; //state
int buttonreset;
int buttonstop;


//initialize the sensor

#define DHTTYPE DHT11
DHT dht (DHTPIN,DHTTYPE);


void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   Serial.println("Temperature and humidity test");

   dht.begin();

    pinMode(relayPin,OUTPUT);
    pinMode(start,INPUT_PULLUP);
    pinMode(reset,INPUT_PULLUP);
    pinMode(stop,INPUT_PULLUP);


}

void loop() {
  buttonstart=digitalRead(start);
  buttonreset=digitalRead(reset);
  buttonstop=digitalRead(stop);


  delay(100);
  
  //Humidity is measured

  float h = dht.readHumidity();

  //temperature is measured

  float t = dht.readTemperature();

  //CHECK FOR ERROR MEASUREMENT
    if(isnan(h) || isnan(t)){
        Serial.println("Error reading the sensor");
      }

  if(!buttonstart== HIGH){
    Serial.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    Serial.print("Humidity: ");
    Serial.print(h)  ;                //print the value of  humidity
    Serial.print("%\n") ;             //add space 
    Serial.print("Temperature: ");
    Serial.print(t );
    Serial.print(char(186));          //
    Serial.print("C ");
    Serial.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    Serial.print("");

    if(t>30 ||h>70){
     digitalWrite(relayPin,HIGH);
     delay(500);
     digitalWrite(relayPin,LOW);
    }else{
     digitalWrite(relayPin,LOW);
    }

    delay(1000);
  }


  if(!buttonreset==HIGH){
      h=0;
      t=0;

    Serial.println("Values have been reset");
    Serial.print("Humidity: ");
    Serial.print(h)  ;                //print the value of  humidity
    Serial.print("%\n") ;             //add space 
    Serial.print("Temperature: ");
    Serial.print(t );
    Serial.print(char(186));          //
    Serial.print("C ");
    Serial.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    Serial.print("");

    delay(10000);
  }

  if(!buttonstop==HIGH){

    Serial.println("Push start button to continue");

    Serial.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    Serial.print("Humidity: ");
    Serial.print(h)  ;                //print the value of  humidity
    Serial.print("%\n") ;             //add space 
    Serial.print("Temperature: ");
    Serial.print(t );
    Serial.print(char(186));          //
    Serial.print("C ");
    Serial.println("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ ");
    Serial.print("");

    digitalWrite(relayPin,LOW);
    delay(900000);
  }

}
  



 



