/********************************************/
/* Author  : Yasmin_Mahdy			    	*/
/* Date    : 26/6/2018				    	*/
/* Version : V01						    */
/********************************************/

#ifndef _TIMER0_INT_H
#define _TIMER0_INT_H



/****************************************/
/* Description : this function shall disable
				 interrupt and select mode and
				 prescaler of the timer */
/****************************************/
void TIM0_voidInitialize(void);
/****************************************/
/* Description : this function shall disable
				 interrupt  */
/****************************************/
void TIM0_voidDisableInt(void);

/****************************************/
/* Description : this function shall enable
				 interrupt  */
/****************************************/
void TIM0_voidEnableInt(void);

/****************************************/
/* Description : this function shall put
				 initial value in TCNT0 register
				 to start count from this value */
/****************************************/
void TIM0_voidSetRegister(u8 Copy_u8Value);

/****************************************/
/* Description : this function shall make
				 pointer to function  */
/****************************************/
void TIM0_voidSetCallBack(void (*Copy_ptr) (void));


#endif
