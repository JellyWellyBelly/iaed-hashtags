#ifndef _TREE_
#define _TREE_

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
} *link;

static link *heads;

extern tree *tree_hashtags;

#endif