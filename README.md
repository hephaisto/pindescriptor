# pindescriptor

This tool allows to place pin descriptions for ATMEL AVRs outside the code.
The macro options allow easy generation of register settings with speaking names.

The code is written in python, so you have to have the interpreter installed.

The code is released using the MIT license.

## Motivation

### pindescription

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

Additional features include:
* produces `#error` statements when one pin is assigned to multiple names
* produces initialisation routine which sets DDR (and PORT for inputs)
* different pinouts for different controllers

### macros
Instead of having unreadable code like

	TCCR0B |=  (1<<CS02);
	TCCR0B |=  (1<<CS01);
	TCCR0B &= ~(1<<CS00);

in setup routines, the macros generated from the supplied config file have names like

	timer0_clockselect_on_falling_T0();

which greatly increases readability. Compared to comments, they remove redundancy of information and don't permit asynchronities between code and comments.


## Usage

### pindescription

copy pindescriptor to your project file or somewhere in your PATH.

	chmod a+x pindescriptor
	mv pindescriptor /usr/bin/

Create a file `pindescription.conf` (see example below) in your project file and run `pindescriptor` there.
This will create a `pindescription.h` at the same directory which you can `#include` where you need it.
Alternatively, you can place the config file whereever you want and run `pindescriptor CONFIG OUTPUT` (this way you can also use a different name for the header file).

#### using makefiles

	pindescription.h: pindescription.conf
		pindescriptor

#### pindescription.conf
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

### macros
Generate macros for supplied controllers (currently only ATmega328, as used on most Arduino boards) by running

	generate_macros.py ATmega328

This will generate both an `ATmega328.c` file with all defined functions, and an `ATmega328.h` with the necessary prototypes ready for inclusion.
The header file also includes defines in the form `BITNAME_reg`, which point to the register of the bit with the name `BITNAME`.
This allows to set the corresponding bit without looking up the register, e.g. `COM0A1_reg |= 1<<COM0A1;` will resolve to `TCCR0A |= 1<<COM0A1;` on the ATmega328. In fact, the previous line can even be written as `SET_BIT_1(COM0A1);`.

Additionally, all interrupt vectors have enable/disable macros of the form `int_SOURCE_enable/disable`.

The macros are best used with automatic code completion of your IDE.


#### config file
The config file is in INI format.
If you want to add your own macros, add a new INI header `[PREFIX]`.
Under this section, add a field named `bits` which are a space separated list of bit-position names like in the headers of a table in the datasheet.
For each combination of 0/1, add an entry of the form `001=NAME`. This will generate a function with the name `PREFIX_NAME` which sets the bits defined above to `0`, `0` and `1` in the order as defined in the `bits` field.
For reserved combinations, use the special name `-`, which will skip this combination.

If you need additional registers, define them in the `registers` section.
Each register name should have a space-separated list of 8 bit-field-names (use `-` again if the bit is reserved).

For interrupts, just assign the name of the corresponding enable-bit to the name you want to use as a function name.

If you add new functionality, please remember to contribute your changes (e.g. via pull request).
