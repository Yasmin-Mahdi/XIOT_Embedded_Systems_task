
The aim of the project is to control the output pin using an interrupt on an input pin and send the status using serial communication (i used UART). when the button is pressed it will generate interrupt which switch the LED on and send its  state using UART on the other hand it can send the temperature sensor reading via UART each 3 sec using Timer0 .


my files:-
----------
Libraries:-
	   - "BIT_MATH.h"	 : it is used to handle bits of registers like set, clear, toggle or get bit value.
	   - "STD_TYPES.h"     	 : it is used to convert types of int and double to another easy and known sizes such

Drivers:-				   char -----> i convert it to u8 because its size on my compiler is 8 bits.
	   - "DIO_reg.h"	 : it is used to store the register address of DIO peripheral.
	   - "DIO_config.h"	 : it is used to change the configurations of DIO pins.
	   - "DIO_priv.h"	 : it is used to store private varibles to not to be known by user.
	   - "DIO_int.h"	 : it is used to provide the interfaces of DIO driver.
	   - "DIO_prog.c"	 : it is used to implement my  DIO driver.

	   - "GIE_reg.h"	 : it is used to store the register address of General interrupt.
	   - "GIE_config.h"	 : it is empty.
	   - "GIE_priv.h"	 : it is used to store private varibles to not to be known by user.
	   - "GIE_int.h"	 : it is used to provide the interfaces of General interrupt driver.
	   - "GIE_prog.c"	 : it is used to implement my  General interrupt driver.

	   - "INTERRUPT_reg.h"	 : it is used to store the register address of interrupt peripheral.
	   - "INTERRUPT_config.h": it is used to change the configurations of interrupt.
	   - "INTERRUPT_priv.h"	 : it is used to store private varibles to not to be known by user.
	   - "INTERRUPT_int.h"	 : it is used to provide the interfaces of interrupt driver.
	   - "INTERRUPT_prog.c"	 : it is used to implement my  interrupt driver.

	   - "TIMER_reg.h"	 : it is used to store the register address of timer peripheral.
	   - "TIMER_config.h"	 : it is used to change the configurations of timer. 
	   - "TIMER_priv.h"	 : it is used to store private varibles to not to be known by user.
	   - "TIMER_int.h"	 : it is used to provide the interfaces of timer driver.
	   - "TIMER_prog.c"	 : it is used to implement my  timer driver.

	   - "UART_reg.h"	 : it is used to store the register address of UART peripheral.
	   - "UART_config.h"	 : it is used to change the configurations of UART. 
	   - "UART_priv.h"	 : it is used to store private varibles to not to be known by user.
	   - "UART_int.h"	 : it is used to provide the interfaces of UART driver.
	   - "UART_prog.c"	 : it is used to implement my  UART driver.

	   - "ADC_reg.h"	 : it is used to store the register address of ADC peripheral.
	   - "ADC_config.h"	 : it is used to change the configurations of ADC. 
	   - "ADC_priv.h"	 : it is used to store private varibles to not to be known by user.
	   - "ADC_int.h"	 : it is used to provide the interfaces of UART driver.
	   - "ADC_prog.c"	 : it is used to implement my  ADC driver.

Apllication:-
	   - "main.c"		 : it is used to implement my application using thr drivers and libraries.


the used functions :-
---------------------

			- "DIO_voidInitialize" 		: it is used to initialize the direction of the ports.
			- "ADC_voidInitialize" 		: it is used to Set reference voltage,mode and prescaller.
			- "UART_voidInitialize" 	: it is used to initialize baud rate, speed mode, Data size, parity and stop bits of UART.
			- "EXTI_voidInitialize"		: it is used to initialize state and mode.
			- "TIM0_voidInitialize" 	: it is used to set prescaller.
			- "DIO_voidGetPinValue" 	: it is used to read the status of the button. 
			- "DIO_voidSetPinValue"		: it is used to switch the LED on and off by controlling the output value.
			- "UART_voidTX" 		: it is used to send the status of the button and led.
			- "ADC_voidStartConv"   	: it is used to choose the channel which i  get the input temperature from.
			- "ADC_u8GetResult" 		: it is used to get the temperature readings.
			- "TIM0_voidSetRegister" 	: it is used to put initial value in the register to start count from this value.
			- "TemperatureRead" 		: it is used to read the temperature and send it using UART.
			- "myfunc" 			: it is ISR handling of the timer and it calls the "TemperatureRead" function evry 3 sec.
			- "EXTI_voidSetInt0Callback" 	: it is used to point to "myInterrupt".	--->ISR of EXT INT
			- "TIM0_voidSetCallBack" 	: it is used to point to "myfunc".		--->ISR of TIMER INT
			- "GIE_voidEnable" 		: it is used to enable global interrupts of MC.
			- "TIM0_voidEnableInt" 		: it is used to enable timer to interrupt MC.
			- "EXTI_voidEnableInt0" 	: it is used to enable External interrupt0 to interrupt MC
			- "ADC_voidDisableInt" 		: it is used to disable ADC interrupt to interrupt MC



Finally , 
I used atmega 32 to test implement my functions and I submit its datasheet with my work
I wrote my software on eclipse not arduino software

I chose to implement the system using eclipse IDE because i don't have arduino UNO to test my software and i prefered to use my knowledge in implementing my drivers instead of using ready drivers.

 Thank you .....
