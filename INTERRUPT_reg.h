/****************************************/
/* Author  : Yasmin_Mahdy				*/
/* Date    : 25/6/2018					*/
/* Version : V01						*/
/****************************************/

#ifndef _DIO_REG_H
#define _DIO_REG_H

/* Comment : interrupt Registers			*/
#define MCUCR	*((volatile u8*)0x55)
#define GICR	*((volatile u8*)0x5B)
#define GIFR	*((volatile u8*)0x5A)
#endif
