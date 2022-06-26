#include <SoftwareSerial.h>
SoftwareSerial bt(2, 3); // RX, TX

#include "dht.h"
#define dataPin 7
dht DHT;

int temp;
int hum;
int rele = 4;
int rele1 = 5;

void setup() {
  Serial.begin(9600);
  pinMode(rele, OUTPUT);
  pinMode(rele1, OUTPUT);
  bt.begin(9600);
}

void loop() {

  int readData = DHT.read11(dataPin);

  hum = DHT.humidity;
  temp = DHT.temperature;
  Serial.print("Temp:");
  Serial.print(temp);
  Serial.print("   " );
  Serial.print("Hum: ");
  Serial.println(hum);
  bt.print(temp);
  bt.print(";");
  bt.print(hum);
  bt.println(";");
  delay(2000);

  
  

  if (temp >= 29 ) {
    digitalWrite(rele1, HIGH);
   digitalWrite(rele,LOW);
    delay(5000);
  } else {
    digitalWrite(rele1, LOW);
    digitalWrite(rele,HIGH);
     
  }

  

  

}
