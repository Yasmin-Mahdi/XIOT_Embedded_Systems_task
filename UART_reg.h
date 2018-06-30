/****************************************/
/* Author  : Yasmin_Mahdy				*/
/* Date    : 25/6/2018					*/
/* Version : V01						*/
/****************************************/

#ifndef _UART_REG_H
#define _UART_REG_H

#define UDR 		*((volatile u8*) 0x2C)
#define UCSRA		*((volatile u8*) 0x2B)
#define UCSRB 		*((volatile u8*) 0x2A)
#define UCSRC 		*((volatile u8*) 0x40)
#define UBRRL 		*((volatile u8*) 0x29)
#define UBRRH 		*((volatile u8*) 0x40)

#endif
