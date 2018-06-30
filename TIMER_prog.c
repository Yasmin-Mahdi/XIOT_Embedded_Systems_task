/****************************************/
/* Author  : Yasmin_Mahdy				*/
/* Date    : 26/6/2018					*/
/* Version : V01						*/
/****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_reg.h"
#include "TIMER_priv.h"
#include "TIMER_config.h"
#include "TIMER_int.h"

static void (*TIM0_callBack)(void);

/****************************************/
/* Description : this function shall disable
				 interrupt and select mode and
				 prescaler of the timer */
/****************************************/
void TIM0_voidInitialize(void){
	/* disable interrupt*/
	/* 3shan amn3o 2bl mygelo set 3la al callback*/
	CLRBIT(TIMSK,0);
	
	/*clear flag*/
	
	SETBIT(TIFR,0);
	
	
	/*SET mode and prescaler*/
	#if TIM0_u16_PRESCALER == TIM0_u16_DIV_1
		TCCR0=0b00000001;
	#elif TIM0_u16_PRESCALER == TIM0_u16_DIV_8
		TCCR0=0b00000010;
	#elif TIM0_u16_PRESCALER == TIM0_u16_DIV_64
		TCCR0=0b00000011;
	#elif TIM0_u16_PRESCALER == TIM0_u16_DIV_256
		TCCR0=0b00000100;
	#elif TIM0_u16_PRESCALER == TIM0_u16_DIV_1024
		TCCR0=0b00000101;
#endif
}
/****************************************/
/* Description : this function shall disable
				 interrupt  */
/****************************************/
void TIM0_voidDisableInt(void){
	CLRBIT(TIMSK,0);
}

/****************************************/
/* Description : this function shall enable
				 interrupt  */
/****************************************/
void TIM0_voidEnableInt(void){
	SETBIT(TIMSK,0);
}
 
/****************************************/
/* Description : this function shall put
				 initial value in TCNT0 register
				 to start count from this value */
/****************************************/
void TIM0_voidSetRegister(u8 Copy_u8Value){
	TCNT0=Copy_u8Value;
}

/****************************************/
/* Description : this function shall make
				 pointer to function  */
/****************************************/
void TIM0_voidSetCallBack(void (*Copy_ptr) (void)){
	TIM0_callBack=Copy_ptr;
}

/****************************************/
/*timer is handled by hardware*/
/*external interrupt0 is in index 11 in vector table*/
/****************************************/
void __vector_11 (void) __attribute__((signal,used));
void __vector_11 (void){
	TIM0_callBack();
}
