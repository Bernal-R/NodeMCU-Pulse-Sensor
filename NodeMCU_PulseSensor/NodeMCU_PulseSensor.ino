/*
  Código hecho por Bernal Rojas
*/

#include <Ticker.h>

Ticker flipper;

int blinkPin = 15;
int fadePin = 12;
int fadeRate = 0;

volatile int BPM;
volatile int Signal;
volatile int IBI = 600;
volatile boolean Pulse = false;
volatile boolean QS = false;


void setup() {
  Serial.begin(115200);
  Serial.println("Estoy comenzando");
  pinMode(blinkPin, OUTPUT);
  pinMode(fadePin, OUTPUT);
  interruptSetup();
}


void loop() {
  sendDataToProcessing('S', Signal);
  if (QS == true) {
    fadeRate = 255;
    sendDataToProcessing('B', BPM);
    sendDataToProcessing('Q', IBI);
    QS = false;
  }

  ledFadeToBeat();

  Serial.println(BPM);
  delay(20);
}


void ledFadeToBeat() {
  fadeRate -= 15;                        
  fadeRate = constrain(fadeRate, 0, 255); 
  analogWrite(fadePin, fadeRate);       
}


void sendDataToProcessing(char symbol, int data ) {
  Serial.print(symbol);                
  Serial.println(data);               
}




