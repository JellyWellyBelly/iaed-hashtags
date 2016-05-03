#include "table.h"

void hash_init(int m){
	int i;
	M = m;

	table_hashtags = (table)malloc(M*sizeof(struct hashtable));
	for(i = 0; i < M; i++)
		hashtags[i] = NULL;

}

int hash(char *v, int M){
	int h, a = 59356, b = 48563;

	for(h = 0; *v != '\0'; v++, a = a*b % (M-1))
		h = (a*h +*v) % M;
	return h;
}