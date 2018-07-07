
void setpoint_update() {
  
  if(packet_rx.roll > 508 - 20 && packet_rx.roll < 508 + 20)
    pid_roll_setpoint = 0;
  else
    pid_roll_setpoint = map(packet_rx.roll,ROLL_RMIN,ROLL_RMAX,ROLL_WMIN,ROLL_WMAX);
    
  
    
  if(packet_rx.pitch > 508 - 20 && packet_rx.pitch < 508 + 20)
    pid_pitch_setpoint = 0;
  else
    pid_pitch_setpoint = map(packet_rx.pitch,PITCH_RMIN,PITCH_RMAX,PITCH_WMIN,PITCH_WMAX);
  
  
  if(packet_rx.yaw > 522 - 20 && packet_rx.yaw < 522 + 20)
    pid_yaw_setpoint = 0;
  else
    pid_yaw_setpoint = map(packet_rx.yaw,YAW_RMIN,YAW_RMAX,YAW_WMIN,YAW_WMAX);
    
    Serial.println();
    Serial.println(pid_roll_setpoint);
    Serial.println(pid_pitch_setpoint);
    Serial.println(pid_yaw_setpoint);
}

void control_update(){
   throttle=map(packet_rx.throttle,THROTTLE_RMIN,THROTTLE_RMAX,MOTOR_ZERO_LEVEL,MOTOR_MAX_LEVEL);
   
   
  setpoint_update();
  pid_update();
  pid_compute();
  
  m0 = throttle + pid_pitch_out - pid_roll_out + pid_yaw_out;
  m1 = throttle + pid_pitch_out + pid_roll_out - pid_yaw_out;
  m2 = throttle - pid_pitch_out + pid_roll_out + pid_yaw_out;
  m3 = throttle - pid_pitch_out - pid_roll_out - pid_yaw_out;
  
  if(throttle < THROTTLE_SAFE_SHUTOFF)
    {
      m0 = m1 = m2 = m3 = MOTOR_ZERO_LEVEL;
    }
    
  update_motors(m0, m1, m2, m3);
 }






