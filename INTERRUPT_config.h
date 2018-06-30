/****************************************/
/* Author  : Yasmin_Mahdy				*/
/* Date    : 26/6/2018					*/
/* Version : V01						*/
/****************************************/

#ifndef _INTERRUPT_CONFIG_H
#define _INTERRUPT_CONFIG_H

/* External  interrupt  mode	*/
/* Range:

				#define EXTI_u8_LOW_MODE		0
				#define EXTI_u8_IOC_MODE		1
				#define EXTI_u8_FAL_MODE		2
				#define EXTI_u8_RIS_MODE		3*/
#define EXTI_u8_INT0_MODE			EXTI_u8_IOC_MODE
/* External  interrupt  State	*/
/* Range:

				EXTI_u8_ENABLE_STATE
				EXTI_u8_DISABLE_STATE		*/
#define EXTI_u8_INT0_INIT_STATE			EXTI_u8_DISABLE_STATE
                                    


#endif
