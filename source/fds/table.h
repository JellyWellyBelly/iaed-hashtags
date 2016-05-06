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
void Init();
void tableInsert(ptr_hashtag ptr);
ptr_hashtag searchList(linkH head, char *string);
linkH insertBeginList(linkH head, ptr);


#endif