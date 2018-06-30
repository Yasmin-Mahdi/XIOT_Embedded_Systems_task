/****************************************/
/* Author  : Yasmin_Mahdy				*/
/* Date    : 26/6/2018					*/
/* Version : V01						*/
/****************************************/

#ifndef _UART_CONFIG_H
#define _UART_CONFIG_H

/****************************************/
/* choose baud rate of UART	*/	
/****************************************/
/*	UART_u16_2400										
	UART_u16_4800										
	UART_u16_9600										
	UART_u16_14400										
	UART_u16_19200										
	UART_u16_28800										
	UART_u16_38400										
	UART_u16_57600										
	UART_u16_76800										
	UART_u16_115200										
	UART_u16_230400										
	UART_u16_250000										
	UART_u16_500000										
	UART_u16_1000000	*/
#define UART_u16_baud_rate			UART_u16_9600


/****************************************/
/* choose speed mode of UART	*/	
/****************************************/
/*	UART_u8_Single_Speed								
	UART_u8_Double_Speed	*/
#define UART_u8_Speed_Mode					UART_u8_Single_Speed


/****************************************/
/* choose data size of UART	*/	
/****************************************/
/*	UART_u8_Data_Size_5									
	UART_u8_Data_Size_6									
	UART_u8_Data_Size_7									
	UART_u8_Data_Size_8									
	UART_u8_Data_Size_9		*/
#define UART_u8_Data_Size_Selection					UART_u8_Data_Size_8


/****************************************/
/* choose synchronization of UART	*/	
/****************************************/
/*	UART_u8_Asynchronous												
	UART_u8_Synchronous		*/
#define UART_u8_Synchronization_Selection			UART_u8_Asynchronous


/****************************************/
/* choose parity of UART	*/	
/****************************************/
/*	UART_u8_No_Parity									
	UART_u8_Even_Parity									
	UART_u8_Odd_Parity	*/
#define UART_u8_Parity_Selection			UART_u8_No_Parity


/****************************************/
/* choose Stop bits of UART	*/	
/****************************************/
/*	UART_u8_One_Stop_bit								
	UART_u8_Two_Stop_bit		*/
#define UART_u8_Stop_Bit_Selection			UART_u8_One_Stop_bit
#endif
