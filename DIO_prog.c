/****************************************/
/* Author  : Yasmin_Mahdy				*/
/* Date    : 26/6/2018					*/
/* Version : V01						*/
/****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_reg.h"
#include "DIO_priv.h"
#include "DIO_config.h"
#include "DIO_int.h"

/* PORT Directions						*/
#define DIO_GROUPA_DIRECTIONS	CONCBIT(DIO_u8_PIN_DIR_7,DIO_u8_PIN_DIR_6,DIO_u8_PIN_DIR_5,DIO_u8_PIN_DIR_4,DIO_u8_PIN_DIR_3,DIO_u8_PIN_DIR_2,DIO_u8_PIN_DIR_1,DIO_u8_PIN_DIR_0)
#define DIO_GROUPB_DIRECTIONS	CONCBIT(DIO_u8_PIN_DIR_15,DIO_u8_PIN_DIR_14,DIO_u8_PIN_DIR_13,DIO_u8_PIN_DIR_12,DIO_u8_PIN_DIR_11,DIO_u8_PIN_DIR_10,DIO_u8_PIN_DIR_9,DIO_u8_PIN_DIR_8)
#define DIO_GROUPC_DIRECTIONS	CONCBIT(DIO_u8_PIN_DIR_23,DIO_u8_PIN_DIR_22,DIO_u8_PIN_DIR_21,DIO_u8_PIN_DIR_20,DIO_u8_PIN_DIR_19,DIO_u8_PIN_DIR_18,DIO_u8_PIN_DIR_17,DIO_u8_PIN_DIR_16)
#define DIO_GROUPD_DIRECTIONS	CONCBIT(DIO_u8_PIN_DIR_31,DIO_u8_PIN_DIR_30,DIO_u8_PIN_DIR_29,DIO_u8_PIN_DIR_28,DIO_u8_PIN_DIR_27,DIO_u8_PIN_DIR_26,DIO_u8_PIN_DIR_25,DIO_u8_PIN_DIR_24)
/********************************************/
/* Description : this function shall set
				 direction for IO Pins  	*/
/********************************************/
void DIO_voidInitialize(void)
{
	DDRA = DIO_GROUPA_DIRECTIONS;
	DDRB = DIO_GROUPB_DIRECTIONS;
	DDRC = DIO_GROUPC_DIRECTIONS;
	DDRD = DIO_GROUPD_DIRECTIONS;
}


/* Description : this function shall set
				 digital values for IO Pins  */
void DIO_voidSetPinValue(u8 Copy_u8PinIndex, u8 Copy_u8PinVal)
{
	if((Copy_u8PinIndex >= DIO_u8_PORTA_START) && (Copy_u8PinIndex <= DIO_u8_PORTA_END))
	{
		if(Copy_u8PinVal == DIO_u8_HIGH)
		{
			SETBIT(PORTA,Copy_u8PinIndex);
		}
		else
		{
			CLRBIT(PORTA,Copy_u8PinIndex);
		}
	}
	else if((Copy_u8PinIndex >= DIO_u8_PORTB_START) && (Copy_u8PinIndex <= DIO_u8_PORTB_END))
	{
		Copy_u8PinIndex -= DIO_u8_PORTA_SIZE;
		if(Copy_u8PinVal == DIO_u8_HIGH)
		{
			SETBIT(PORTB,Copy_u8PinIndex);
		}
		else
		{
			CLRBIT(PORTB,Copy_u8PinIndex);
		}
	}
	else if((Copy_u8PinIndex >= DIO_u8_PORTC_START) && (Copy_u8PinIndex <= DIO_u8_PORTC_END))
	{
		Copy_u8PinIndex -= (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE) ;
		if(Copy_u8PinVal == DIO_u8_HIGH)
		{
			SETBIT(PORTC,Copy_u8PinIndex);
		}
		else
		{
			CLRBIT(PORTC,Copy_u8PinIndex);
		}
	}
	else if((Copy_u8PinIndex >= DIO_u8_PORTD_START) && (Copy_u8PinIndex <= DIO_u8_PORTD_END))
	{
		Copy_u8PinIndex -= (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE+DIO_u8_PORTC_SIZE);
		if(Copy_u8PinVal == DIO_u8_HIGH)
		{
			SETBIT(PORTD,Copy_u8PinIndex);
		}
		else
		{
			CLRBIT(PORTD,Copy_u8PinIndex);
		}
	}
}




/* Description : this function shall get
				 digital values for IO Pins  */
u8 DIO_voidGetPinValue(u8 Copy_u8PinIndex)
{
	u8 Local_u8Result;
	if((Copy_u8PinIndex >= DIO_u8_PORTA_START) && (Copy_u8PinIndex <= DIO_u8_PORTA_END))
	{

		if(GetBit(PINA,Copy_u8PinIndex))
		{
			Local_u8Result= DIO_u8_HIGH;
		}
		else
		{
			Local_u8Result= DIO_u8_LOW;
		}
	}
	else if((Copy_u8PinIndex >= DIO_u8_PORTB_START) && (Copy_u8PinIndex <= DIO_u8_PORTB_END))
	{

		Copy_u8PinIndex -= DIO_u8_PORTA_SIZE;
		if(GetBit(PINB,Copy_u8PinIndex))
		{
			Local_u8Result= DIO_u8_HIGH;
		}
		else
		{
			Local_u8Result= DIO_u8_LOW;
		}
	}
	else if((Copy_u8PinIndex >= DIO_u8_PORTC_START) && (Copy_u8PinIndex <= DIO_u8_PORTC_END))
	{

		Copy_u8PinIndex -= (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE) ;
		if(GetBit(PINC,Copy_u8PinIndex))
		{
			Local_u8Result= DIO_u8_HIGH;
		}
		else
		{
			Local_u8Result= DIO_u8_LOW;
		}
	}
	else if((Copy_u8PinIndex >= DIO_u8_PORTD_START) && (Copy_u8PinIndex <= DIO_u8_PORTD_END))
	{

		Copy_u8PinIndex -= (DIO_u8_PORTA_SIZE+DIO_u8_PORTB_SIZE+DIO_u8_PORTC_SIZE);
		if(GetBit(PIND,Copy_u8PinIndex))
		{
			Local_u8Result= DIO_u8_HIGH;
		}
		else
		{
			Local_u8Result= DIO_u8_LOW;
		}
	}
	return Local_u8Result;
}
