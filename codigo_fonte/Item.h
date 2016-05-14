/******************************************************************************
* File Name: item.h
* Author:      Goncalo Marques (84719) / Manuel Sousa (84740)
* Revision:
* NAME
*      item - prototipos
* SYNOPSIS:    #include <stdio.h>
	       #include <string.h> - strdup
	       #include <stdlib.h> 	- qsort	
	       #include <stdbool.h> - bool's
* DESCRIPTION
*		prototipos / estruturas / macros das funcoes que violam a abstracao de dados
* DIAGNOSTICS
*          OK
*****************************************************************************/
#ifndef _ITEM_
#define _ITEM_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char* Key;

//Estrutura das hashtags
typedef struct hashtags{
	int repeticoes;
	char *hashtag;
} *Item;

#define NULLitem NULL
#define key(a) (a == NULL ? "" : a->hashtag)
#define less(a,b) (strcmp(a,b) < 0)
#define greater(a,b) (strcmp(a,b) > 0)
#define eq(a,b) (strcmp(a,b) == 0)

Item NOVOItem(char *hashtag,int repeticoes);

void deleteItem(Item a);

void imprimeItem(Item a);

int ordenaHashtags(const void *a, const void *b);

#endif


