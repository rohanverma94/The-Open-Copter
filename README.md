# TOC - The Open Copter #

 TOC or The Open Copter is a semi-autonomous-quadcopter which is made with help of Accelerometer,Gyroscope and Magnetometer which is present on single chip MPU9250 with help of I2C interface and AVR Atmega328 microcontroller to give stable output to the underlying PID routine which does all the balancing for Quadcopter in air. 

 ## Requirement ##

* Atmel Studio 7
*  Visual Studio to back Atmel Studio

There is no need to add any extra libraries. All open source libraries are embedded in the project itself, the following are the libraries used and they are licensed under respective project license:

* jrowberg's I2CDevlib
* RF24 library

## Directory Structure ##

* (project-root-dir)/ quadcopter-core - core firmware for quadcopter.
* (project-root-dir)/ quadcopter-simulation - matlab/octave simulation for quadcopter.
* (project-root-dir)/ quacopter-documentation - quadcopter full documentation
* (project-root-dir)/ quadcopter-controller - hand-held controller

## Uploading Firmware(s) ##

Navigate to (project-root-dir) then do following:

### Core Firmware: ###

* Command Line via avrdude (Linux)

avrdude -C "avrdude.conf" -v -p atmega328p -c arduino -P /dev/ttyUSB0 -b 57600 -D -U flash:w: quadcopter.hex:i

    -b This option sets the baud rate for communicating with the board
    -p This specifies the target type. The configuration file for avrdude has a long list of supported targets, with all the important parameters for each.
    -P Specifies the communication port. As soon as the device is hooked up to your USB, it should be assigned a file in /dev/, and this is the string that needs to be passed to the -P option. The easiest way to find this is just dmesg | grep ttyUSB*

* Command Line via avrdude (Windows)

avrdude -C "avrdude.conf" -v -p atmega328p -c arduino -P .COMxx -b 57600 -D -U flash:w: quacopter.hex:i

where COMxx is port no. eg. COM34

### Hand-Held Controller Firmware: ###

* Command Line via avrdude (Linux)

avrdude -C "avrdude.conf" -v -p atmega328p -c arduino -P /dev/ttyUSB0 -b 57600 -D -U flash:w: transmitter_rf24.hex:i

    -b This option sets the baud rate for communicating with the board
    -p This specifies the target type. The configuration file for avrdude has a long list of supported targets, with all the important parameters for each.
    -P Specifies the communication port. As soon as the device is hooked up to your USB, it should be assigned a file in /dev/, and this is the string that needs to be passed to the -P option. The easiest way to find this is just dmesg | grep ttyUSB*

* Command Line via avrdude (Windows)

avrdude -C "avrdude.conf" -v -p atmega328p -c arduino -P .COMxx -b 57600 -D -U flash:w: transmitter_rf24.hex:i



For more information visit [my blog](https://cryptecx.xyz).
## The Open Copter in action ##

Top View of Quadcopter:

<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0174.JPG" width="800" /> 

Side View of Quadcopter:

<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0292.JPG" width="800" /> 


Hand-held Conroller:

<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0178.JPG" width="800" /> 
Hand-held Controller construction:

Basically a modified game-boy controller, the joystick is kept intact but main controller board from game-boy is removed , and a arduino nano is  installed in place of that.

<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0182.JPG" width="800" /> 

Main board construction Quadcopter:

<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0181.JPG" width="800" /> 


<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0179.JPG" width="800" /> 


<img src="https://github.com/rohan-0100010110010100/The-Open-Copter/raw/master/images/IMG_0180.JPG" width="800" /> 
