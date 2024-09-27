/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 11 MAY 2024                 */
/* Version          : v01                        */ 
/*************************************************/

#ifndef FPEC_PRIVATE_H_
#define FPEC_PRIVATE_H_


typedef union
{
	struct{
		u32  PG    :1 ;
		u32  PER   :1 ;
		u32  MER   :1 ;
		u32  RES1  :1 ;
		u32  OPTPG :1 ;
		u32  OPTER :1 ;
		u32  STRT  :1 ;
		u32  LOCK  :1 ;
		u32  RES2  :1 ;
		u32  OPTWRE:1 ;
		u32  ERRIE :1 ;
		u32  RES3  :1 ;
		u32  EOPIE :1 ;
		u32  RES4  :19;
	}BitAccess;
	
	u32 WordAccess;
}FPEC_CR_TYPE;

#define FPEC_CR ((FPEC_CR_TYPE*)0x40022010)

typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 AR;
	volatile u32 RESERVED;
	volatile u32 OBR;
	volatile u32 WRPR;
}FPEC_TYPE;

#define FPEC		 (( volatile FPEC_TYPE*)0x40022000)


#define KEY_1						0x45670123
#define KEY_2						0xCDEF89AB
#define HALF_WORD					0b01


#endif
