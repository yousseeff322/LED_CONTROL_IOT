

#include"STD_type.h"
#include "BIT_math.h"

#include "FunHelp.h"





u8 STR_COMPARE(u8 * ptr1,u8 * ptr2){

	u8 x,i=0;

	while( (ptr1[i]==ptr2[i])){

		i++;

		if(ptr1[i]=='\0' && ptr2[i]=='\0'){x=1;break;}

		else if( (ptr1[i]!='\0' && ptr2[i]=='\0') || (ptr1[i]=='\0' && ptr2[i]!='\0')){x=0;break;}

	}

	if(ptr1[i]!=ptr2[i]){x=0;}

	return x;
}

u8 STR_LEN(const u8 *str) {
    u8 length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}



void STR_COPY(u8 *dest, const u8 *src) {
    u8 i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';  // Add the null terminator to the end of the destination string
}






void itoi(u16 num, u8 *str, u16 base) {
    u16 i = 0;
    u16 isNegative = 0;

    // Handle 0 explicitly
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }

    // Handle negative numbers for base 10
    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    // Process individual digits
    while (num != 0) {
        u16 rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // Add negative sign if the number was negative
    if (isNegative) {
        str[i++] = '-';
    }

    // Append the null terminator to mark the end of the string
    str[i] = '\0';

    // Reverse the string to get the correct result
    u16 start = 0;
    u16 end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}



u32 map(u32 x, u32 in_min, u32 in_max, u32 out_min, u32 out_max) {
    // Calculate the mapped value
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}





f64 power(f64 base, u16 exp) {
	f64 result = 1.0;
    for (u16 i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

f64 factorial(u16 n) {
	f64 result = 1.0;
    for (u16 i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

f64 SIN(f64 angle) {
	f64 radians = angle * (3.14159265358979323846 / 180.0); // Convert to radians if input is in degrees
    f64 sin_value = 0.0;
    for (u16 n = 0; n < 10; n++) {
    	f64 term = power(-1, n) * power(radians, 2 * n + 1) / factorial(2 * n + 1);
        sin_value += term;
    }
    return sin_value;
}

f64 COS(f64 angle) {
	f64 radians = angle * (3.14159265358979323846 / 180.0); // Convert to radians if input is in degrees
	f64 cos_value = 0.0;
    for (u16 n = 0; n < 10; n++) {
    	f64 term = power(-1, n) * power(radians, 2 * n) / factorial(2 * n);
        cos_value += term;
    }
    return cos_value;
}

u8* STR_STR(const u8 *ptr1, const u8 *ptr2) {
    u8 i = 0, j = 0;

    if (*ptr2 == '\0') {
        return (u8*)ptr1;  // If ptr2 is empty, return ptr1
    }

    while (ptr1[i] != '\0') {
        if (ptr1[i] == ptr2[j]) {
            // Start matching substring
            j++;
            if (ptr2[j] == '\0') {
                return (u8*)&ptr1[i - j + 1];  // Match found, return the starting address
            }
        } else {
            // Mismatch, reset j and check next position
            j = 0;
        }
        i++;
    }

    return NULL;  // No match found
}
