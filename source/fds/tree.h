#ifndef _TREE_
#define _TREE_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hashtag.h"

#define MAXTAGLEN 140

typedef struct binary_tree{
	Item item;
	Item *l, *r;
} *tree;

extern tree *tree_hashtags;


#endif