#ifndef _TABLE_
#define _TABLE_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct hashtag{
	char *palavra;
	int ocorrencias;
}*tag_ptr;

typedef struct lista{
	tag_ptr tag;
	struct lista *proximo;
}*ligacao;

int hashtable(char *v, int M);

extern tag_ptr palavras;


#endif