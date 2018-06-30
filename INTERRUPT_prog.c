/****************************************/
/* Author  : Yasmin_Mahdy				*/
/* Date    : 26/6/2018					*/
/* Version : V01						*/
/****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"



#include "INTERRUPT_reg.h"
#include "INTERRUPT_priv.h"
#include "INTERRUPT_config.h"
#include "INTERRUPT_int.h"

/* define callback variable*/
static void (*EXTI_u8Int0Callback)(void);

/********************************************/
/* Description : this function shall set
				 mode and state for the interrupt  	*/
/********************************************/
void EXTI_voidInitialize(void){
	/*bysfr al awl b3den y7t al mode*/
	/*set EXTI mode as configured */
	MCUCR = (MCUCR & EXTI_u8_INT0_MODE_CLEAR ) | EXTI_u8_INT0_MODE;
	/*initialize state*/
	#if EXTI_u8_INT0_INIT_STATE	==EXTI_u8_DISABLE_STATE
	SETBIT(GICR,EXTI_u8_INT0_PIE);
	#else
	CLRBIT(GICR,EXTI_u8_INT0_PIE);	
	#endif
	/*clear flag*/
	SETBIT(GIFR,EXTI_u8_INT0_PIE);
	
}

/********************************************/
/* Description : this function shall enable
				 interrupt  */
/********************************************/
void EXTI_voidEnableInt0(void){
	SETBIT(GICR,EXTI_u8_INT0_PIE);
}

/********************************************/
/* Description : this function shall disable
				 interrupt  */
/********************************************/
void EXTI_voidDisableInt0(void){
	CLRBIT(GICR,EXTI_u8_INT0_PIE);
}

/********************************************/
/* Description : this function shall make
				 pointer to function  */
/********************************************/
void EXTI_voidSetInt0Callback(void (*Copy_Callback) (void)){
	EXTI_u8Int0Callback=Copy_Callback;
}

/********************************************/
/*interrupt is handled by hardware*/
/*external interrupt0 is in index 1 in vector table*/
/********************************************/
void __vector_1(void)__attribute__((signal,used));
void __vector_1(void)
{
		EXTI_u8Int0Callback();
}
