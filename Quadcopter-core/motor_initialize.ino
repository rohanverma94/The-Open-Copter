Servo motor0;
Servo motor1;
Servo motor2;
Servo motor3;

void motors_initialize(){
  motor0.attach(3);
  motor1.attach(5);
  motor2.attach(6);
  motor3.attach(9);
    motor0.writeMicroseconds(MOTOR_MAX_LEVEL);
  motor1.writeMicroseconds(MOTOR_MAX_LEVEL);
  motor2.writeMicroseconds(MOTOR_MAX_LEVEL);
  motor3.writeMicroseconds(MOTOR_MAX_LEVEL);
  delay(2500);
  motor0.writeMicroseconds(MOTOR_ZERO_LEVEL);
  motor1.writeMicroseconds(MOTOR_ZERO_LEVEL);
  motor2.writeMicroseconds(MOTOR_ZERO_LEVEL);
  motor3.writeMicroseconds(MOTOR_ZERO_LEVEL);
}

void motors_arm(){
  motor0.writeMicroseconds(MOTOR_ZERO_LEVEL);
  motor1.writeMicroseconds(MOTOR_ZERO_LEVEL);
  motor2.writeMicroseconds(MOTOR_ZERO_LEVEL);
  motor3.writeMicroseconds(MOTOR_ZERO_LEVEL);
  delay(3000);
}

void update_motors(int m0, int m1, int m2, int m3)
{
  motor0.writeMicroseconds(m0);
  motor1.writeMicroseconds(m1);
  motor2.writeMicroseconds(m3);
  motor3.writeMicroseconds(m2);
  
  Serial.print("\t Front left :");
  Serial.print(m3);
  Serial.print("\t Front Right :");
  Serial.print(m2);
  Serial.print("\t Rear left :");
  Serial.print(m0);
  Serial.print("\t Rear Right :");
  Serial.print(m1);
  Serial.println();
}

