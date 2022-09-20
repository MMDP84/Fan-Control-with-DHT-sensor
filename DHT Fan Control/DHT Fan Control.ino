/*
This project is made by MMDP
Fan Control With DHT sensor
*/
#include <dht.h>

dht DHT;

#define ENABLE 5
#define DIRA 3
//#define DIRB 4
#define DHT11_PIN 2

/*this is where we have to define the Initial values and portds and communication speed*/
void setup(){
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  //pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  
  int h = DHT.humidity;
  int t = DHT.temperature;

  // Send data (temperature,humidity)
  Serial.println(String(t) + "," + String(h));
 
  if (25<=t<30){t1=1};
  else if (30<=t<35){t1=2};
  else if (t=>35){t1=3};
    switch (t1) {
      case '1':
        analogWrite(ENABLE,128); //enable on
        digitalWrite(DIRA,HIGH); //one way
        break;
      case '2':
        analogWrite(ENABLE,190); //enable on
        digitalWrite(DIRA,HIGH); //one way
        break;
      case '3':
        analogWrite(ENABLE,255); //enable on
        digitalWrite(DIRA,HIGH); //one way
        break;
      default:
        for (int t < 25) {
           analogWrite(ENABLE,0); //enable on
           digitalWrite(DIRA,LOW); //one way
        }

  }
  /*
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);*/
  delay(1000);
}
