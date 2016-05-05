#ifndef _TREE_
#define _TREE_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define DIM_TAB 1000
#define MAXTAGLEN 140

typedef struct hashtag{
	char palavra[MAXTAGLEN];
	int ocorrencias;
}*tag_ptr;

extern tree *tree_hashtags;


#endif