#include "DHT.h" 
#include "UbidotsMicroESP8266.h"
#define DHTPIN 4
#define TOKEN ""
#define ssid ""
#define psswd ""
DHT dht(DHTPIN, DHT11);
Ubidots client (TOKEN);
unsigned long last =0;

void setup(){
  Serial.begin(9600);
  dht.begin();
  delay(20);
  client.wifiConnection(ssid,psswd);
  
}

void loop(){
  if (millis()-last>1000){
    float hum = dht.readHumidity(); //tipe data float untuk menampung data kelembapan

    float temp = dht.readTemperature(); //tipe data float untuk menampung data suhu

    last=millis();

    client.add("kelembapan" ,hum);

    client.add("temp" ,temp);

    client.sendAll(true);
  }
}
