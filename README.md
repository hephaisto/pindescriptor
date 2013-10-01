pindescriptor
=============

This tool allows to place pin descriptions for ATMEL AVRs outside the code.

The code is written in python, so you have to have the interpreter installed.

The code is released using the MIT license.

Motivation
----------

Previously you had to do something like this (for a motor connected to pin A1):

	// somewhere at top
	#if defined __AVR_ATmega32__
	#define MOTOR1_DDR DDRA
	#define MOTOR1_PORT PORTA
	#define MOTOR1_BIT 1
	#define BUTTON1_DDR DDRA
	#define BUTTON1_PIN PINA
	#define BUTTON1_BIT 2
	#endif
	
	// in init routine
	MOTOR1_DDR|=(1<<MOTOR1_BIT);
	BUTTON1_DDR&=~(1<<BUTTON1_BIT);
	
	// switch on MOTOR1 when BUTTON1 is high
	if(BUTTON1_PIN& (1<<BUTTON1_BIT))
		MOTOR1_PORT|=(1<<MOTOR1_BIT);


This creates a lot of code which is hard to maintain, especially if you want to write code for more than one controller and they have different pinouts.

Using this library, defining the pins is as easy as writing

	[ATmega32]
	MOTOR1=A1,out
	BUTTON1=A2,in

and using

	// init routine
	INIT_ALL_PINS;
	
	// switch on motor
	if(BUTTON1_IS_ON)
		MOTOR1_ON;
	

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

pindescription.conf
-------------------

Example

	[ATmega32]
	MOTOR_A:A1,out
	MOTOR_B:A2,out
	BUTTON_OK:A3,in
	BUTTON_CANCEL:A4,pullup
	IO_PIN1:A5,generic
	IO_PIN2:A6

All pin names are converted to uppercase!!
	
the following modes are allowed:

* `out` sets DDR to 1
* `in` sets DDR to 0 and PORT to 0 (disable pullups)
* `pullup` sets DDR to 0 and PORT to 1 (enable pullups)
* `generic` (or no mode given) does not set any registers, but still defines an empty INIT macro

The following macros are defined (`X` representing the respective name)

* `X_DDR`: data direction register
* `X_PORT`: port register (output value and pullup state)
* `X_PIN`: input register
* `X_BIT`: bit number in register
* `X_INIT`: macro to init DDR (and PORT for in/pullup)
* `X_ON` (output/generic only): set output to HIGH
* `X_OFF` (output/generic only): set output to LOW
* `X_IS_ON` (input/pullup only): use in stuff like `if(X_IS_ON)`
* `X_INPUT_BIT` (input/pullup only): gives numerical value `0` for low input and `1` for high input
* `X_HIGHZ` (generic only): switches pin to high-impedance input (equivalent to mode "in")

For a list of device name macros automatically inserted by avr-gcc look at http://www.nongnu.org/avr-libc/user-manual/using_tools.html and strip the leading `__AVR_` and the trailing `__`.
