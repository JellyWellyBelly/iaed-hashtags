#include "table.h"

void hash_init(int M){
	int i;

	
}

int hashtable(char *v, int M){
	int h, a = 59356, b = 48563;

	for(h = 0; *v != '\0'; v++, a = a*b % (M-1))
		h = (a*h +*v) % M;
	return h;
}