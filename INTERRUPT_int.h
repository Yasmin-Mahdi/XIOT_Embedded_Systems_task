/********************************************/
/* Author  : Yasmin_Mahdy			    	*/
/* Date    : 26/6/2018				    	*/
/* Version : V01						    */
/********************************************/

#ifndef _INTERRUPT_INT_H
#define _INTERRUPT_INT_H

/********************************************/
/* Description : this function shall set
				 mode and state for the interrupt  	*/
/********************************************/
void EXTI_voidInitialize(void);

/********************************************/
/* Description : this function shall enable
				 interrupt  */
/********************************************/
void EXTI_voidEnableInt0(void);

/********************************************/
/* Description : this function shall disable
				 interrupt  */
/********************************************/
void EXTI_voidDisableInt0(void);

/********************************************/
/* Description : this function shall make
				 pointer to function  */
/********************************************/
void EXTI_voidSetInt0Callback(void (*Copy_Callback) (void));

#endif
