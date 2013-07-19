pindescriptor
=============

This tool allows to place pin descriptions for ATMEL AVRs outside the code. Previously you had to do something like this (for a motor connected to pin A1):

	// somewhere at top
	#if defined __AVR_ATmega32__
	#define MOTOR1_DDR DDRA
	#define MOTOR1_PORT PORTA
	#define MOTOR1_BIT 1
	#endif
	// in init routine
	MOTOR1_DDR|=(1<<MOTOR1_BIT);


This creates a lot of code which is hard to maintain, especially if you want to write code for more than one controller and they have different pinouts.

Using this library, defining the pins is as easy as writing

	[ATmega32]
	MOTOR1=A1,out

and using

	MOTOR1_INIT
	
or even (to initialize all pins at once)

	INIT_ALL_PINS

in the init routine.

Features
--------

* produces `#error` statements when one pin is assigned to multiple names
* produces initialisation routine which sets DDR (and PORT for inputs)
* different pinouts for different controllers


Usage
-----

copy pindescriptor to your project file or somewhere in your PATH.

	chmod a+x pindescriptor
	mv pindescriptor /usr/bin/

Create a file `pindescription.conf` (see example below) in your project file and run `pindescriptor` there.
This will create a `pindescription.h` at the same directory which you can `#include` where you need it.
Alternatively, you can place the config file whereever you want and run `pindescriptor CONFIG OUTPUT` (this way you can also use a different name for the header file).

### using makefiles

	pindescription.h: pindescription.conf
		pindescriptor

Example pindescription.conf
---------------------------

	[ATmega32]
	MOTOR_A:A1,out
	MOTOR_B:A2,out
	BUTTON_OK:A3,in
	BUTTON_CANCEL:A4,pullup
	
the following modes are allowed:

* `out` sets DDR to 1
* `in` sets DDR to 0 and PORT to 0 (disable pullups)
* `pullup` sets DDR to 0 and PORT to 1 (enable pullups)
