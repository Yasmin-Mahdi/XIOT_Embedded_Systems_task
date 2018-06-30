/*
 * main.c

 *
 *  Created on: Jun 29, 2018
 *      Author: yasmin
 */
#include"STD_TYPES.h"
#include"DIO_reg.h"
#include"DIO_int.h"
#include"GIE_int.h"
#include"INTERRUPT_int.h"
#include"TIMER_int.h"
#include"ADC_int.h"
#include"UART_int.h"
#define	zero				0/*representation of zero value*/
#define	one					1/*representation of one value*/
#define	len1				2/*size	of	led	on	array*/
#define	len2				3/*size	of	led	off	array*/
#define	len3				7/*size	of	button	pressed	array*/
#define	vref				5/*reference voltage of MC*/
#define	max_overflows		92/*number of overflows of timer*/
#define	timer_initial_val	113/*initial value of timer*/
#define	resolution			256/*ADC register resolution*/
/*
 * initialVal and max_val are used in timer.
 * used 8 bit timer which make interrupt when it over flow.
 * i used prescaller of 1024 so i have interrupt evry"1024/8000000*256".
 * i need to get temperature value each 3 sec so i need to execute TemperatureRead()func
 * evry 3 sec and so i need to wait the timer to overflow to 91.55 times between executing it.
 * 0.55 need me to overflow before reaching to maximum value "256*0.55".
 * 0.55 need me to count 142 time so i set register with 255-140=113 to start count from this
 * value and over flow when it's value  reachs to 255.
*/

static u8 localU8lnitialVal=timer_initial_val;
static u8 localU8max_val=max_overflows;
static volatile u8 localU8counter=zero;/*it represent number of overflows of the timer*/
static u8 localU8flag=zero;/*it is flag to send the on state of the button on UART only one time*/
const u8 on[] = {'O','N'};/*array of characters to represent led on state which send on UART*/
const u8 off[] = {'O','F','F'};/*array of characters to represent led off state which send on UART*/
const u8 buttonpressed[] = {'P','r','e','s','s','e','d'};/*array of characters to represent button state which send on UART*/
static u8 localU8offFlag=zero;/*it is flag to send the off state of the button on UART only one time*/
static volatile u8 localU8val=zero;/*it represents temperature input value*/

void myInterrupt(void);
void myfunc(void);

void main(void) {
	PORTD=0x04;/*enable pull up resistor in interrupt pin*/
	DIO_voidInitialize();/*initialize DIO peripherals of MC*/
	ADC_voidInitialize();/*initialize ADC peripherals of MC*/
	UART_voidInitialize();/*initialize UART peripherals of MC*/
	EXTI_voidSetInt0Callback(myInterrupt);/*callback function of int0*/
	GIE_voidEnable();/*enable global interrupts to MC*/
	EXTI_voidInitialize();/*initialize External interrupt of MC*/
	TIM0_voidInitialize();/*initialize TIMER0 peripherals of MC*/
	TIM0_voidEnableInt();/*enable TIMER0 to	interrupt MC*/
	TIM0_voidSetCallBack(myfunc);/*callback function of TIMER0*/
	EXTI_voidEnableInt0();/*enable External interrupt to interrupt MC*/
	ADC_voidDisableInt();

	while (1) {
	}
}

/*
 * TemperatureRead() is the function to read the value of the temperature it gets analog value
 * and convert ti to digital value using ADC peripheral of the MC
 * theres is 8 channels for ADC
 * I use channel PORT A0
 * val is to represent the analog value in voltage
 * I need to make mapping from the input value of voltage to temperature in C
 * i use Vref as 5 Volt of MC and i use 8 bit register to represend the digital
 * value so i have 2^8 resolution of ADC "256"
 * after reading temperature I send it on UART
 */
void TemperatureRead() {
	ADC_voidStartConv(zero);/*choose channel A0 as ADC*/
	localU8val=ADC_u8GetResult();/*get temperature readings*/
	u8 localU8temp = (vref*localU8val/resolution);/* convert temperature reading into C value*/
	UART_voidTX1(localU8temp);/*send temperature value to UART*/
}

/*
 * when the timer overflows it will generate interrupt and then go to ISR to handle interrupt
 * myfunc() is the ISR and it is the callback function of the timer interrupt
 * in the ISR I check if I reached to 3 sec by reaching to the max_val of overflows
 * and if I reached it I will call TemperatureRead() function
 */
void myfunc(void){
	localU8counter++;/*the number of overflows is increased by 1*/
	if(localU8counter==localU8max_val){/*check if i reached to the last overflow*/
		localU8counter=zero;/*put zero value in  the counter */
		TIM0_voidSetRegister(localU8lnitialVal);/*make the timer to count 113 counts */
		TemperatureRead();/* call TemperatureRead()func to read temp and send it using UART*/
	}
}

/*myInterrupt() is the ISR and it is the callback function of the interrupt0
 * I put switch in the interrupt pin and check if it pressed i will switch the led on
 * and then send its state on UART
 * I have to flags:
 * 					-flag:to send the states of the led and button only one time in the UART
 * 						  if flag is 0: I can send the states of the led and switch on UART
 * 						  if flag is 1: I can't send the states of the led and switch on UART
 * 						  I need to check it when the putton is pressed if it is zero I can send on UART
 * 						  and then i need to change its state to 1 to not to send its state on UART
 * 						  and i need to reset its value again when the button is not pressed.
 * 					-offFlag:to send the states of the led only one time in the UART
 * 							 if flag is 0: I can send the states of the led on UART
 * 						 	 if flag is 1: I can't send the states of the led on UART
 * 						 	  I need to check it when the putton is not pressed if it is zero I can send on UART
 * 							  and then i need to change its state to 1 to not to send its state on UART
 * 							  and i need to reset its value again when the button is pressed.
 * I check if the putton is pressed " it will be pressed if pin 26 is low because I put pull up resistor "
 */

void myInterrupt(void){
	/*interrupt in pin 26*/
	/*led in pin 27*/
	if (DIO_voidGetPinValue(DIO_u8_PIN_26) == DIO_u8_LOW) {/*check if button is pressed*/
		if (zero == localU8flag) {/*chech if I send the on state of led and button state on UART*/
			localU8offFlag = zero;/*reset the flag of the off state of led which is send when button is not pressed*/
			UART_voidTX(buttonpressed, len3);/*send button state"pressed" on UART*/
			DIO_voidSetPinValue(DIO_u8_PIN_27, DIO_u8_HIGH);/*make the led on */
			UART_voidTX(on, len1);/*send led state"on" on UART*/
			localU8flag = one;/*set the flag to not to send the led nor button state*/
		}
	}
	else{
		localU8flag=zero;/*reset the flag of the on state*/
		if(zero==localU8offFlag){/*chech if I send the off state of led on UART*/
		DIO_voidSetPinValue(DIO_u8_PIN_27, DIO_u8_LOW);/*make the led off*/
		UART_voidTX(off, len2);/*send led state"off" on UART*/
		localU8offFlag=one;/*set the flag to not to send the led state*/
		}
	}
}

