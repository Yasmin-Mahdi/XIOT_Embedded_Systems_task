/****************************************/
/* Author  : Yasmin_Mahdy				*/
/* Date    : 26/6/2018					*/
/* Version : V01						*/
/****************************************/

#ifndef _DIO_PRIV_H
#define _DIO_PRIV_H

/* OPERATION mode*/		
#define EXTI_u8_LOW_MODE		0
#define EXTI_u8_IOC_MODE		1
#define EXTI_u8_FAL_MODE		2
#define EXTI_u8_RIS_MODE		3



#define EXTI_u8_ENABLE_STATE		4
#define EXTI_u8_DISABLE_STATE		5

/*mode clear mask*/
#define EXTI_u8_INT0_MODE_CLEAR		0B11111100
/*pie bit index*/
#define EXTI_u8_INT0_PIE	     	6

/*pie bit index*/
#define EXTI_u8_INT0_PIF	     	6
#endif
