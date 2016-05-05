#ifndef _TAG_
#define _TAG_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXTAGLEN 140

typedef struct hashtag{
	char palavra[MAXTAGLEN];
	int ocorrencias;
}*ptr_hashtag;

#endif _TAG_