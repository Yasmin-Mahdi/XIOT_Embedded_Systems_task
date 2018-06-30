/******************************/
/* Author : Yasmin_Mahdy	  */
/* Date	  : 26/6/2018		  */
/* Version: V01			      */
/******************************/
#ifndef _ADC_CONFIG_H
#define _ADC_CONFIG_H


/* Reference Selection for the ADC*/
/* 		ADC_u8_VREF_0		Disable Internal Reference*/
/* 		ADC_u8_VREF_1		5Volt					  */
/* 		ADC_u8_VREF_2		2.5Volt					  */
#define ADC_u8_VREF_SELECTION	ADC_u8_VREF_1

/* Read Register Mode "Left or Right" */
/* 		ADC_u8_ADJUS_0		RIGHT */
/* 		ADC_u8_ADJUS_1		LEFT  */
#define ADC_u8_ADJUS_SELECTION	ADC_u8_ADJUS_1


/* ADC Mode */
/* 		ADC_u8_MODE_0		Single Conversion Mode */
/* 		ADC_u8_MODE_1		Auto Trigger  */
#define ADC_u8_MODE_SELECTION	ADC_u8_MODE_1


/*	Range:  ADC_u8_DIV_02 		*/
/*			ADC_u8_DIV_2 		*/
/*		 	ADC_u8_DIV_4		*/
/*			ADC_u8_DIV_8		*/
/*			ADC_u8_DIV_16		*/
/*		 	ADC_u8_DIV_32		*/
/*			ADC_u8_DIV_64		*/
/*			ADC_u8_DIV_128		*/
#define ADC_u8_PRESCALLER	ADC_u8_DIV_2

#endif
