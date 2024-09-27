#ifndef FUNHELP_H_
#define FUNHELP_H_


#define PI 3.14159265358979
#define DEG_TO_RAD (PI / 180.0)


u8 STR_COMPARE(u8 * ptr1,u8 * ptr2);
u8 STR_LEN(const u8 *str) ;
void STR_COPY(u8 *dest, const u8 *src) ;
void itoi(u16 num, u8 *str, u16 base) ;
u32 map(u32 x, u32 in_min, u32 in_max, u32 out_min, u32 out_max) ;


f64 power(f64 base, u16 exp) ;
f64 factorial(u16 n) ;
f64 SIN(f64 angle) ;
f64 COS(f64 angle) ;
u8* STR_STR(const u8 *ptr1, const u8 *ptr2) ;


#endif /* STRING_COMPARE_H_ */
