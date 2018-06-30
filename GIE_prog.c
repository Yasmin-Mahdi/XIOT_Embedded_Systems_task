/****************************************/
/* Author  : Yasmin_Mahdy				*/
/* Date    : 25/6/2018					*/
/* Version : V01						*/
/****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_int.h"
#include"GIE_reg.h"
#include"GIE_priv.h"
#include"GIE_int.h"


/********************************************/
/* Description : this function shall enable Global
				 interrupts  */
void GIE_voidEnable(void){
	SETBIT(SREG,GIE_u8_BIT_INDEX);
}
/********************************************/


/* Description : this function shall disable Global
				 interrupt  */
void GIE_voidDisable(void){
	CLRBIT(SREG,GIE_u8_BIT_INDEX);
}
