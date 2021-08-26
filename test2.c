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

const char * byte_to_binary(u_int x){
    static char * b;
    b = malloc(9);
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
	char bufi[9], bufa[9], bufn[9];
	char input;

	memset(bufi, 0x00, 9);
	memset(bufa, 0x00, 9);
	memset(bufn, 0x00, 9);

	strcpy(bufi, byte_to_binary(i));
	strcpy(bufa, byte_to_binary(a));
	strcpy(bufn, byte_to_binary(n));

	printf(	"i = %s\n"
			"a = %s\n"
			"n = %s\n\n\n", bufi, bufa, bufn );

	printf("input code. 1 - &, 2 - >>, 3 - ^, 4 - ~\n");

	while ((input = getchar()) != EOF){
		switch (input){
			case '1': n = i & a; break;
			case '2': n = i >> a; break;
			case '3': n = i ^ a; break;
			case '4': n = ~(a); break;
			case '\n': continue; break;
			default: printf("error of code\n"); break;
		}


		strcpy(bufi, byte_to_binary(i));
		strcpy(bufa, byte_to_binary(a));
		strcpy(bufn, byte_to_binary(n));

		printf(	"i = %s\n"
			"a = %s\n"
			"n = %s\n\n\n", bufi, bufa, bufn );
		printf("input code. 1 - &, 2 - >>, 3 - ^, 4 - ~\n");
	}
	return 0;

}
