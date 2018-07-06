#include "quadcopter_config.h"
#include <PID_v1.h>
#include <Wire.h>
#include<Servo.h>
#include"RF24.h"


float angleX,angleY,angleZ = 0.0;

int throttle=THROTTLE_RMIN;

static bool goodSignal;

RF24 rx(7,8);


double pid_roll_in,   pid_roll_out,   pid_roll_setpoint = 0;
double pid_pitch_in,  pid_pitch_out,  pid_pitch_setpoint = 0;
double pid_yaw_in,    pid_yaw_out,    pid_yaw_setpoint = 0;
  

int m0, m1, m2, m3; 
int i=0;


void setup() 
{  
   
    Serial.begin(115200);
    if(Serial.available())
    Serial.println("Debug Output ON");
 
  
  motors_initialize();
 
 pinMode(PIN_LED, OUTPUT);
 digitalWrite(PIN_LED, LOW); 



  rx_Initialize();
  pid_initialize();
  motors_arm();
  imu_setup();
  
}

unsigned long lastRecvTime = 0;

void loop() 
{
  
  receiver_update();
  unsigned long now = millis();
  if(now - lastRecvTime > 1000)
  {
    signal_loss();
  }
  imu_loop();

  
  control_update();
   
}
