/************************************************/
/* Author  : Yasmin_Mahdy						*/
/* Date    : 26/6/2018							*/
/* Version : V01								*/
/************************************************/

#ifndef _UART_PRIV_H
#define _UART_PRIV_H

/* baud rate selection for UART							*/
#define UART_u16_2400										2400
#define UART_u16_4800										4800
#define UART_u16_9600										9600
#define UART_u16_14400										14400
#define UART_u16_19200										19200
#define UART_u16_28800										28800
#define UART_u16_38400										38400
#define UART_u16_57600										57600
#define UART_u16_76800										76800
#define UART_u16_115200										115200
#define UART_u16_230400										230400
#define UART_u16_250000										250000
#define UART_u16_500000										500000
#define UART_u16_1000000									1000000

/* speed mode of UART										*/
#define UART_u8_Single_Speed								0
#define UART_u8_Double_Speed								1
	
/* data size of UART												*/
#define UART_u8_Data_Size_5									5
#define UART_u8_Data_Size_6									6
#define UART_u8_Data_Size_7									7
#define UART_u8_Data_Size_8									8
#define UART_u8_Data_Size_9									9

/* Synchronization Mode of UART												*/
#define UART_u8_Asynchronous								0				
#define UART_u8_Synchronous									1

/* parity of UART													*/
#define UART_u8_No_Parity									0
#define UART_u8_Even_Parity									2
#define UART_u8_Odd_Parity									3

/* Stop bits of UART													*/
#define UART_u8_One_Stop_bit								0
#define UART_u8_Two_Stop_bit								1
#endif
