# TOC - The Open Copter #

 TOC or The Open Copter is a semi-autonomous-quadcopter which is made with help of Accelerometer,Gyroscope and Magnetometer which is present on single chip MPU9250 with help of I2C interface and AVR Atmega328 microcontroller to give stable output to the underlying PID routine which does all the balancing for Quadcopter in air. 

 ## Requirement ##

* Atmel Studio 7
*  Visual Studio to back Atmel Studio

There is no need to add any extra libraries. All open source libraries are embedded in the project itself, the following are the libraries used and they are licensed under respective project license:

* jrowberg's I2CDevlib
* RF24 library

## Directory Structure ##

* (root-dir)/ quadcopter-core - core firmware for quadcopter.
* (root-dir)/ quadcopter-simulation - matlab/octave simulation for quadcopter.
* (root-dir)/ quacopter-documentation - quadcopter full documentation
* (root-dir)/ quadcopter-conroller - hand-held controller

For more information visit [my blog](https://cryptecx.xyz).
## The Open Copter in action ##

Top View of Quadcopter:

<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0174.JPG" width="800" /> 

Side View of Quadcopter:

<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0292.JPG" width="800" /> 


Hand-held Conroller:

<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0178.JPG" width="800" /> 
Hand-held Controller construction:

Basically a modified game-boy controller, the joystick is kept intatct but main controller board from game-boy is removed , and a arduino nano is  installed in place of that.

<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0182.JPG" width="800" /> 

Main board construction Quadcopter:

<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0181.JPG" width="800" /> 


<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0179.JPG" width="800" /> 


<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0180.JPG" width="800" /> 
