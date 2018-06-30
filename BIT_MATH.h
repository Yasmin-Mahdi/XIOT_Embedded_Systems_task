#ifndef BitCalc_h
#define BitCalc_h

	#define SETBIT(reg,BitNo)		(reg) |= (1 << (BitNo) )
	#define CLRBIT(reg,BitNo)		(reg) &= ~(1 << (BitNo) )
	#define ToggleBit(reg,BitNo)	(reg) ^= (1 << (BitNo) )
	#define GetBit(reg,BitNo)		( (reg) >> (BitNo) ) & 0x01
/*************************************************************/
	#define Set_Low_Nib(reg)	(reg) |= 0x0F
	#define Clr_Low_Nib(reg)	(reg) &= 0xF0
	#define Tog_Low_Nib(reg)	(reg) ^= 0x0F
/*************************************************************/
	#define Set_High_Nib(reg)	(reg) |= 0xF0
	#define Clr_High_Nib(reg)	(reg) &= 0x0F
	#define Tog_High_Nib(reg)	(reg) ^= 0xF0
/*************************************************************/
	#define CONCBIT(B7,B6,B5,B4,B3,B2,B1,B0)	CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)
	#define CONC_HELP(B7,B6,B5,B4,B3,B2,B1,B0)	0b##B7##B6##B5##B4##B3##B2##B1##B0

#endif