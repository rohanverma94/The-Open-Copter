/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <PID_v1.h>





#include "quadcopter_config.h"
#include <Wire.h>
#include<Servo.h>
#include <SPI.h>
#include"RF24.h"


float angleX,angleY,angleZ = 0.0;

int throttle=THROTTLE_RMIN;

static bool goodSignal;

RF24 rx(7,8);
unsigned long lastRecvTime = 0;


double pid_roll_in,   pid_roll_out,   pid_roll_setpoint = 0;
double pid_pitch_in,  pid_pitch_out,  pid_pitch_setpoint = 0;
double pid_yaw_in,    pid_yaw_out,    pid_yaw_setpoint = 0;
  

int m0, m1, m2, m3; 
int i=0;
#include "Receiver.h"
#include "pid_controller.h"
#include "motor_initialize.h"
#include "control_movement_update.h"
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio






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
