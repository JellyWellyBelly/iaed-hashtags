#ifndef _TABLE_
#define _TABLE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM_TAB 1000
#define MAXTAGLEN 140

typedef struct hashtag{
	char palavra[MAXTAGLEN];
	int ocorrencias;
}*tag_ptr;

typedef struct hashtable{
	tag_ptr tag;
	struct lista *proximo;
}*table;



int hashtable(char *v, int M);

extern table *table_hashtags;


#endif