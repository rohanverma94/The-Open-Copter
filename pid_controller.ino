#include "mpu.h"
#include "I2Cdev.h"

int ret;
void imu_setup() {
    Fastwire::setup(400,0);
    
     mympu_open(200);
     delay(15000);
    Serial.print("MPU init: "); Serial.println(ret);

	
}

//unsigned int c = 0; //cumulative number of successful MPU/DMP reads

void imu_loop() {
mympu_update();

  
	    Serial.print(" P: "); Serial.print(round(mympu.ypr[1]));
	    Serial.print(" R: "); Serial.print(round(mympu.ypr[2]));
	    Serial.print("\tgy: "); Serial.println(round(mympu.gyro[0]));
  
}



PID roll_controller(&pid_roll_in,   &pid_roll_out,  &pid_roll_setpoint,  ROLL_PID_KP, ROLL_PID_KI, ROLL_PID_KD, REVERSE);
PID pitch_controller(&pid_pitch_in, &pid_pitch_out, &pid_pitch_setpoint, PITCH_PID_KP , PITCH_PID_KI, PITCH_PID_KD, DIRECT);
PID yaw_controller(&pid_yaw_in,     &pid_yaw_out,   &pid_yaw_setpoint,   YAW_PID_KP, YAW_PID_KI, YAW_PID_KD, REVERSE); 


void pid_initialize() {
  roll_controller.SetOutputLimits(ROLL_PID_MIN,ROLL_PID_MAX);
  pitch_controller.SetOutputLimits(PITCH_PID_MIN,PITCH_PID_MAX);
  yaw_controller.SetOutputLimits(YAW_PID_MIN,YAW_PID_MAX);
  roll_controller.SetMode(AUTOMATIC);
  pitch_controller.SetMode(AUTOMATIC);
  yaw_controller.SetMode(AUTOMATIC);
  roll_controller.SetSampleTime(PID_SAMPLE_TIME );
  pitch_controller.SetSampleTime(PID_SAMPLE_TIME );
  yaw_controller.SetSampleTime(PID_SAMPLE_TIME );
}

void pid_update(){
  pid_roll_in = round(mympu.ypr[2]);
  pid_pitch_in = round(mympu.ypr[1]);
  pid_yaw_in = round(mympu.gyro[0]); 
}

void pid_compute() {
   roll_controller.Compute();
   pitch_controller.Compute();
   yaw_controller.Compute();
}
