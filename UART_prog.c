/****************************************/
/* Author  : Yasmin_Mahdy				*/
/* Date    : 26/6/2018					*/
/* Version : V01						*/
/****************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_reg.h"
#include "UART_priv.h"
#include "UART_config.h"
#include "UART_int.h"

#define BUFFER_SIZE   1000

static volatile u32 Rx_Count = 0;
static volatile u8 Rx_Data[BUFFER_SIZE] = {0};

/********************************************/
/* Description : this function shall initialize
				 baud rate, speed mode, Data size,
				 parity and stop bits of UART 	*/
/********************************************/
void UART_voidInitialize(void)
{
#if UART_u16_baud_rate==UART_u16_2400
	#if UART_u8_Speed_Mode==UART_u8_Single_Speed
		UBRRL=207;
	#elif UART_u8_Speed_Mode==UART_u8_Double_Speed
		UBRRL=416%256;
		UBRRH=416/256;
		UBRRH|=0b10000000;
	#endif
#elif UART_u16_baud_rate==UART_u16_4800
	#if UART_u8_Speed_Mode==UART_u8_Single_Speed
		UBRRL=103;
	#elif UART_u8_Speed_Mode==UART_u8_Double_Speed
		UBRRL=207;
	#endif	
#elif UART_u16_baud_rate==UART_u16_9600
	#if UART_u8_Speed_Mode==UART_u8_Single_Speed
		UBRRL=51;
	#elif UART_u8_Speed_Mode==UART_u8_Double_Speed
		UBRRL=103;
	#endif		
#elif UART_u16_baud_rate==UART_u16_14400
	#if UART_u8_Speed_Mode==UART_u8_Single_Speed
		UBRRL=34;
	#elif UART_u8_Speed_Mode==UART_u8_Double_Speed
		UBRRL=68;
	#endif	
#elif UART_u16_baud_rate==UART_u16_19200
	#if UART_u8_Speed_Mode==UART_u8_Single_Speed
		UBRRL=25;
	#elif UART_u8_Speed_Mode==UART_u8_Double_Speed
		UBRRL=51;
	#endif	
#endif		

#if UART_u8_Data_Size_Selection==UART_u8_Data_Size_9
	UCSRB = (1 << 7) | (1 << 4) | (1 << 3) | (1 << 2);	//enable RXIE, TX, RX, 9 bit data
#else
	UCSRB = (1 << 7) | (1 << 4) | (1 << 3);	//enable TX, RX, RXIE
	UCSRB &= ~(1 << 2 );
#endif	

#if UART_u8_Synchronization_Selection==UART_u8_Asynchronous
	#if UART_u8_Parity_Selection==UART_u8_No_Parity
		#if UART_u8_Stop_Bit_Selection==UART_u8_One_Stop_bit
			#if UART_u8_Data_Size_Selection==UART_u8_Data_Size_5
				UCSRC=0b10000000;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_6
				UCSRC=0b10000010;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_7
				UCSRC=0b10000100;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_8
				UCSRC=0b10000110;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_9
				UCSRC=0b10000110;
			#endif	
		#elif UART_u8_Stop_Bit_Selection==UART_u8_Two_Stop_bit
			#if UART_u8_Data_Size_Selection==UART_u8_Data_Size_5
				UCSRC=0b10001000;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_6
				UCSRC=0b10001010;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_7
				UCSRC=0b10001100;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_8
				UCSRC=0b10001110;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_9
				UCSRC=0b10001110;
			#endif
		#endif	
	#elif UART_u8_Parity_Selection==UART_u8_Even_Parity
		#if UART_u8_Stop_Bit_Selection==UART_u8_One_Stop_bit
			#if UART_u8_Data_Size_Selection==UART_u8_Data_Size_5
				UCSRC=0b10100000;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_6
				UCSRC=0b10100010;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_7
				UCSRC=0b10100100;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_8
				UCSRC=0b10100110;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_9
				UCSRC=0b10100110;
			#endif	
		#elif UART_u8_Stop_Bit_Selection==UART_u8_Two_Stop_bit
			#if UART_u8_Data_Size_Selection==UART_u8_Data_Size_5
				UCSRC=0b10101000;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_6
				UCSRC=0b10101010;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_7
				UCSRC=0b10101100;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_8
				UCSRC=0b10101110;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_9
				UCSRC=0b10101110;
			#endif
		#endif	
	#elif UART_u8_Parity_Selection==UART_u8_Odd_Parity
		#if UART_u8_Stop_Bit_Selection==UART_u8_One_Stop_bit
			#if UART_u8_Data_Size_Selection==UART_u8_Data_Size_5
				UCSRC=0b10110000;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_6
				UCSRC=0b10110010;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_7
				UCSRC=0b10110100;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_8
				UCSRC=0b10110110;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_9
				UCSRC=0b10110110;
			#endif	
		#elif UART_u8_Stop_Bit_Selection==UART_u8_Two_Stop_bit
			#if UART_u8_Data_Size_Selection==UART_u8_Data_Size_5
				UCSRC=0b10111000;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_6
				UCSRC=0b10111010;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_7
				UCSRC=0b10111100;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_8
				UCSRC=0b10111110;
			#elif UART_u8_Data_Size_Selection==UART_u8_Data_Size_9
				UCSRC=0b10111110;
			#endif
		#endif	
	#endif	
#elif UART_u8_Synchronization_Selection==UART_u8_Synchronous
	UCSRC = (1 << 6);
#endif
}




/* Description : this function shall send data */
void UART_voidTX(u16* copyU16Data,u16 copyU16length)
{
	u32 localIndex;
	for(localIndex=0; localIndex <copyU16length; localIndex++){
		while(!(UCSRA & (1 << 5)));		/*	wait until UDRE flag is ready to receive new data	*/
		UDR = copyU16Data[localIndex];
	}
	SETBIT(UCSRA,5);
}

/* Description : this function shall send only one data */
void UART_voidTX1(u16* copyU16Data)
{

		while(!(UCSRA & (1 << 5)));		/*	wait until UDRE flag is ready to receive new data	*/
		UDR = copyU16Data;

	SETBIT(UCSRA,5);
}

void __vector_13 (void) __attribute__((signal,used));

void __vector_13 (void){

	Rx_Data[Rx_Count] = UDR;
	Rx_Count++;
}


