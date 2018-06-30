/******************************/
/* Author : Yasmin_Mahdy	  */
/* Date	  : 26/6/2018		  */
/* Version: V01			      */
/******************************/
#ifndef _ADC_INT_H
#define _ADC_INT_H


/* Description:  */
void ADC_voidInitialize(void);

/* Description:  */
void ADC_voidStartConv(u8 Channel_Number);


u8 ADC_u8GetResult(void);

void ADC_voidSetCallBack(void (*Copy_ptr) (void));

void ADC_voidEnableInt(void);

void ADC_voidDisableInt(void);


#endif
