/******************************/
/* Author : Yasmin_Mahdy	  */
/* Date	  : 26/6/2018		  */
/* Version: V01			      */
/******************************/
#include "std_types.h"
#include "BIT_MATH.h"

#include "ADC_reg.h"

#include "ADC_priv.h"
#include "ADC_config.h"

#include "ADC_int.h"

static void(*ADC_CallBack)(void);

void ADC_voidInitialize(void)
{
	/* Set Vreference */
	#if ADC_u8_VREF_SELECTION ==ADC_u8_VREF_0
	CLRBIT(ADMUX,6);
	CLRBIT(ADMUX,7);
	#elif ADC_u8_VREF_SELECTION ==ADC_u8_VREF_1
	SETBIT(ADMUX,6);
	CLRBIT(ADMUX,7);
	#elif ADC_u8_VREF_SELECTION ==ADC_u8_VREF_2
	SETBIT(ADMUX,6);
	SETBIT(ADMUX,7);
	#endif


	/* Set Adjustment */
	#if ADC_u8_ADJUS_SELECTION ==ADC_u8_ADJUS_0
	CLRBIT(ADMUX,5);
	#elif ADC_u8_ADJUS_SELECTION ==ADC_u8_ADJUS_1
	SETBIT(ADMUX,5);
	#endif

	/* ADC Mode */
	#if ADC_u8_MODE_SELECTION ==ADC_u8_MODE_0
	CLRBIT(ADCSRA,5);
	#elif ADC_u8_MODE_SELECTION ==ADC_u8_MODE_1
	SETBIT(ADCSRA,5);
	#endif

	/* Set Prescaller */
	#if ADC_u8_PRESCALLER ==ADC_u8_DIV_02
	CLRBIT(ADCSRA,0);
	CLRBIT(ADCSRA,1);
	CLRBIT(ADCSRA,2);
	#elif ADC_u8_PRESCALLER ==ADC_u8_DIV_2
	SETBIT(ADCSRA,0);
	CLRBIT(ADCSRA,1);
	CLRBIT(ADCSRA,2);
	#elif ADC_u8_PRESCALLER ==ADC_u8_DIV_4
	CLRBIT(ADCSRA,0);
	SETBIT(ADCSRA,1);
	CLRBIT(ADCSRA,2);
	#elif ADC_u8_PRESCALLER ==ADC_u8_DIV_8
	SETBIT(ADCSRA,0);
	SETBIT(ADCSRA,1);
	CLRBIT(ADCSRA,2);
	#elif ADC_u8_PRESCALLER ==ADC_u8_DIV_16
	CLRBIT(ADCSRA,0);
	CLRBIT(ADCSRA,1);
	SETBIT(ADCSRA,2);
	#elif ADC_u8_PRESCALLER ==ADC_u8_DIV_32
	SETBIT(ADCSRA,0);
	CLRBIT(ADCSRA,1);
	SETBIT(ADCSRA,2);
	#elif ADC_u8_PRESCALLER ==ADC_u8_DIV_64
	CLRBIT(ADCSRA,0);
	SETBIT(ADCSRA,1);
	SETBIT(ADCSRA,2);
	#elif ADC_u8_PRESCALLER ==ADC_u8_DIV_128
	SETBIT(ADCSRA,0);
	SETBIT(ADCSRA,1);
	SETBIT(ADCSRA,2);
	#endif
	

	/*Clear Interupt Flag*/
	SETBIT(ADCSRA,4);

	/*Enable ADC*/
	SETBIT(ADCSRA,7);




}

/* Description: this function shall chose the channel*/
void ADC_voidStartConv(u8 Channel_Number)
{
	#if Channel_Number ==0
	CLRBIT(ADMUX,0);
	CLRBIT(ADMUX,1);
	CLRBIT(ADMUX,2);
	CLRBIT(ADMUX,3);
	CLRBIT(ADMUX,4);
	#elif Channel_Number ==1
	SETBIT(ADMUX,0);
	CLRBIT(ADMUX,1);
	CLRBIT(ADMUX,2);
	CLRBIT(ADMUX,3);
	CLRBIT(ADMUX,4);
	#elif Channel_Number ==2
	CLRBIT(ADMUX,0);
	SETBIT(ADMUX,1);
	CLRBIT(ADMUX,2);
	CLRBIT(ADMUX,3);
	CLRBIT(ADMUX,4);
	#elif Channel_Number ==3
	SETBIT(ADMUX,0);
	SETBIT(ADMUX,1);
	CLRBIT(ADMUX,2);
	CLRBIT(ADMUX,3);
	CLRBIT(ADMUX,4);
	#elif Channel_Number ==4
	CLRBIT(ADMUX,0);
	CLRBIT(ADMUX,1);
	SETBIT(ADMUX,2);
	CLRBIT(ADMUX,3);
	CLRBIT(ADMUX,4);
	#elif Channel_Number ==5
	SETBIT(ADMUX,0);
	CLRBIT(ADMUX,1);
	SETBIT(ADMUX,2);
	CLRBIT(ADMUX,3);
	CLRBIT(ADMUX,4);
	#elif Channel_Number ==6
	CLRBIT(ADMUX,0);
	SETBIT(ADMUX,1);
	SETBIT(ADMUX,2);
	CLRBIT(ADMUX,3);
	CLRBIT(ADMUX,4);
	#elif Channel_Number ==7
	SETBIT(ADMUX,0);
	SETBIT(ADMUX,1);
	SETBIT(ADMUX,2);
	CLRBIT(ADMUX,3);
	CLRBIT(ADMUX,4);
	#endif

	/*Start Conversion*/
	SETBIT(ADCSRA,6);
}


u8 ADC_u8GetResult(void)
{
	return ADCH;
}

void ADC_voidEnableInt(void)
{
	SETBIT(ADCSRA,3);
}

void ADC_voidDisableInt(void)
{
	CLRBIT(ADCSRA,3);
}

void ADC_voidSetCallBack(void (*Copy_ptr) (void))
{
	ADC_CallBack = Copy_ptr;
}

void __vector_16(void) __attribute__((signal,used));
void __vector_16(void)
{
	ADC_CallBack();
}
