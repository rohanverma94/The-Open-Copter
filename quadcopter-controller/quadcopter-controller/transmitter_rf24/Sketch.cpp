/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include<SPI.h>
#include"RF24.h"
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio



#define throttle_pin A0
#define yaw_pin A1
#define pitch_pin A2
#define roll_pin A3

boolean hashardware=false; //set true when connecting joysticks

RF24 tx(7,8);
byte addresses[][6]={"tx","rx"};

struct packet
{
  int throttle;
  int yaw;
  int roll;
  int pitch;
}packet_tx;

void setup() {
  Serial.begin(115200);
  pinMode(throttle_pin,INPUT);
  pinMode(yaw_pin,INPUT);
  pinMode(pitch_pin,INPUT);
  pinMode(roll_pin,INPUT);
  tx.begin();
  tx.setChannel(105);
  tx.setDataRate(RF24_250KBPS);
  tx.setPALevel(RF24_PA_LOW);
  tx.openWritingPipe(addresses[0]);
  tx.openReadingPipe(1,addresses[1]);
}
void loop() {
  if(hashardware){
  packet_tx.throttle = analogRead(throttle_pin);
  packet_tx.yaw = analogRead(yaw_pin);
  packet_tx.pitch = analogRead(pitch_pin);
  packet_tx.roll = analogRead(roll_pin);
  }
  else{
  packet_tx.throttle = 512;
  packet_tx.yaw = 414;
  packet_tx.pitch = 454;
  packet_tx.roll = 768;
  }
  Serial.println();
  Serial.println("Transmitting");
  Serial.print("  throttle : " );
  Serial.print(packet_tx.throttle);
  Serial.print("  yaw : " );
  Serial.print(packet_tx.yaw);
  Serial.print("  pitch : " );
  Serial.print(packet_tx.pitch);
  Serial.print("  roll : " );
  Serial.print(packet_tx.roll);
  
  
  if(!tx.write(&packet_tx,sizeof(packet_tx))){
    Serial.println("Transmission failed");
  }
  delay(100);
}
