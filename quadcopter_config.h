
#define PID_SAMPLE_TIME 5

#define ROLL_PID_KP 2
#define ROLL_PID_KI  1.75
#define ROLL_PID_KD  0.25
#define ROLL_PID_MIN  -200.0
#define ROLL_PID_MAX  200.0

#define PITCH_PID_KP 2
#define PITCH_PID_KI  1.75
#define PITCH_PID_KD  0.25
#define PITCH_PID_MIN  -200.0
#define PITCH_PID_MAX  200.0

#define YAW_PID_KP  1.5
#define YAW_PID_KI  0
#define YAW_PID_KD  .2
#define YAW_PID_MIN  -100.0
#define YAW_PID_MAX  100.0

#define THROTTLE_RMIN  0
#define THROTTLE_SAFE_SHUTOFF 1120
#define THROTTLE_RMAX  1023
#define THROTTLE_RMID  499

#define ROLL_RMIN  THROTTLE_RMIN
#define ROLL_RMAX  THROTTLE_RMAX
#define ROLL_WMIN  -30
#define ROLL_WMAX  30

#define PITCH_RMIN  THROTTLE_RMIN
#define PITCH_RMAX  THROTTLE_RMAX
#define PITCH_WMIN  -30
#define PITCH_WMAX  30

#define YAW_RMIN  THROTTLE_RMIN
#define YAW_RMAX  THROTTLE_RMAX
#define YAW_WMIN  -30
#define YAW_WMAX  30

#define MOTOR_ZERO_LEVEL  1000
#define MOTOR_ARM_START  1500
#define MOTOR_MAX_LEVEL  2000

#define PIN_MOTOR0  3  // lower left motor
#define PIN_MOTOR1  5  // lower right motor
#define PIN_MOTOR2  6  //front right motor
#define PIN_MOTOR3  9  // front left motor

#define PIN_LED 2

