/* PixMob Music Rhythm 0.1v
   Copyright (c) 2022, Carlos Ganoza Plasencia
   url: http://carlosganoza.com
   github.com/drneox

*/

#include <IRremoteESP8266.h>
#include <IRsend.h>
const int IRLedPin = 5;  // led GPIO pin
const int microAnalog = A0; // analog pin for the sound sensor
const int microDigital = 16; // digital pin for the sound sensor
IRsend irsend(IRLedPin);

/*
   some colors codes
*/
uint16_t yellow[21] = {1400, 1400, 700, 700, 700, 1400, 700, 2800, 700, 2100, 1400, 700, 700, 700, 700, 1400, 1400, 2800, 1400, 2800, 700};
uint16_t red[21] =   {1400, 1400, 700, 700, 700, 1400, 700, 2800, 700, 2100, 1400, 700, 700, 700, 700, 1400, 1400, 2800, 1400, 2800, 700};
uint16_t green[21] = {1400, 1400, 700, 700, 700, 700, 1400, 2800, 700, 1400, 700, 1400, 700, 1400, 700, 1400, 1400, 2800, 1400, 2800, 700};
uint16_t pink[23] = {700, 700, 700, 2100, 1400, 700, 700, 2800, 700, 1400, 700, 700, 700, 2800, 1400, 1400, 700, 2100, 700, 700, 700, 2100, 700};
uint16_t blue[27] =   {700, 700, 700, 2100, 1400, 700, 700, 2800, 700, 1400, 700, 700, 700, 1400, 1400, 700, 700, 1400, 700, 700, 700, 700, 700, 700, 700, 2100, 700};



void setup() {
  Serial.begin(115200);
  irsend.begin();
  pinMode(microAnalog, INPUT);
  pinMode(microDigital, INPUT);
}

void loop() {
  int randomNumber = random(1, 5);

  if (digitalRead(microDigital) == HIGH) {
    if (randomNumber == 1) {
      Serial.println("send yellow code");
      irsend.sendRaw(yellow, 21, 38);
    }
    if (randomNumber == 2) {
      Serial.println("send green code");
      irsend.sendRaw(green, 21, 38);
    }
    if (randomNumber == 3) {
      Serial.println("send pink code");
      irsend.sendRaw(pink, 23, 38);
    }
    if (randomNumber == 4){
      Serial.println("send red code");
      irsend.sendRaw(blue, 27, 38);
    }
    delay(200);
    Serial.println(randomNumber);
    Serial.println("-----");
  }





}
