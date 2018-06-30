/********************************************/
/* Author  : Yasmin_Mahdy			    	*/
/* Date    : 26/6/2018				    	*/
/* Version : V01						    */
/********************************************/

#ifndef _UART_INT_H
#define _UART_INT_H


/********************************************/
/* Description : this function shall initialize
				 baud rate, speed mode, Data size,
				 parity and stop bits of UART 	*/
/********************************************/
void UART_voidInitialize(void);



/* Description : this function shall send data */
void UART_voidTX(u16* data,u16 length);

/* Description : this function shall send only one data */
void UART_voidTX1(u16* copyU16Data);

#endif
