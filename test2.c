/*
 ============================================================================
 Name        : test-c.c
 Author      : Arthur
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

u_int8_t* byte_to_binary(u_int x){
    static u_int8_t b[9];
    b[0] = '\0';
    u_int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");

    }
    return b;
}


int main() {

	u_int8_t i = 0b11100001, n = 0, a = 0b11110000;
	u_int8_t bufi[9], bufa[9], bufn[9];

	memset(bufi, 0x00, 9);
	memset(bufa, 0x00, 9);
	memset(bufn, 0x00, 9);

	strcpy(bufi, byte_to_binary(i));
	strcpy(bufa, byte_to_binary(a));
	strcpy(bufn, byte_to_binary(n));

	printf(	"i = %s\n"
			"a = %s\n"
			"n = %s\n\n\n", bufi, bufa, bufn );

	n = (a >> 1) & ~i;

	strcpy(bufi, byte_to_binary(i));
	strcpy(bufa, byte_to_binary(a));
	strcpy(bufn, byte_to_binary(n));

	printf(	"i = %s\n"
			"a = %s\n"
			"n = %s\n\n\n", bufi, bufa, bufn );

	return 0;
}
