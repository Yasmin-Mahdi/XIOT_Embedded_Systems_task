/****************************************/
/* Author  : Yasmin_Mahdy				*/
/* Date    : 25/6/2018					*/
/* Version : V01						*/
/****************************************/

#ifndef _TIM0_REG_H
#define _TIM0_REG_H

/* Comment : TIMER0 Register			*/
#define TIMSK	*((volatile u8*)0x59)
#define TCNT0	*((volatile u8*)0x52)
#define TCCR0	*((volatile u8*)0x53)
#define TIFR	*((volatile u8*)0x58)

#endif
