#include<SPI.h>



byte addresses[][6]={"tx","rx"};

struct packet
{
  int throttle;
  int yaw;
  int roll;
  int pitch;
}packet_rx;

void rx_Initialize(){
//  Serial.begin(115200); used for debugging
 
  rx.begin();
  rx.setChannel(115);
  rx.setDataRate(RF24_250KBPS);
  rx.setPALevel(RF24_PA_LOW);
  rx.openWritingPipe(addresses[1]);
  rx.openReadingPipe(1,addresses[0]);
  rx.startListening();
  rx.setAutoAck(0);
  rx.setCRCLength(RF24_CRC_16);

}


void receiver_update(){

  if(rx.available())
  {
    while(rx.available())
      {rx.read(&packet_rx,sizeof(packet_rx));
      lastRecvTime = millis();
  }
     

  }
    
  Serial.print(packet_rx.throttle);
  Serial.print("\t");
  Serial.print(packet_rx.yaw);
  Serial.print("\t");
  Serial.print(packet_rx.pitch);
  Serial.print("\t");
  Serial.print(packet_rx.roll);
  Serial.print("\t");
    
}




void signal_loss(){
  packet_rx.throttle=0;
  packet_rx.yaw=522;
  packet_rx.pitch=508;
  packet_rx.roll=508;
}
