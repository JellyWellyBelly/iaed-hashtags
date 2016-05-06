#ifndef _TABLE_
#define _TABLE_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hashtag.h"

#define MAXTAGLEN 140
#define M 100

typedef struct node{
	ptr_hashtag tag;
	struct node *next;
} *linkH;

int hash(char *string);
void Init(linkH *table);
ptr_hashtag tableSearch(char *string, linkH *table);
void tableInsert(ptr_hashtag ptr, linkH *table);
ptr_hashtag searchTable(linkH head, char *string);
void insertHash(linkH head, ptr_hashtag ptr);


#endif