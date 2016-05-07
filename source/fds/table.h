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
	Item hashtag;
	struct node *next;
} *linkH;

int hash(char *string);
void Init(linkH *table);
Item tableSearch(char *string, linkH *table);
void tableInsert(Item ptr, linkH *table);
Item searchTable(linkH head, char *string);
linkH insertHash(linkH head, Item ptr);
linkH NewNode(Item ptr);


#endif