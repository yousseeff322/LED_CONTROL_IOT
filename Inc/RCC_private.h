/*************************************************/
/* AUTHOR           : Youssef Hamed              */
/* Date             : 2 MAR 2024                 */
/* Version          : v01                        */ 
/*************************************************/
#ifndef RCC_PRAVITE_H_
#define RCC_PRAVITE_H_



typedef struct{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}RCC;

// M is Refer To MCal

#define MRCC ((volatile RCC *)0x40021000)




#define HSI                         1
#define HSE                         2
#define PLL                         3
#define PLL_HSI_DIVIDED_BY_2        4
#define PLL_HSE                     5
#define PLL_HSE_DIVIDED_BY_2        6
#define HSE_BYPASS                  7


 
#endif
