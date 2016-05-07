#ifndef _HASH_
#define _HASH_
#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

#define null(A) (key(st[A]) == "")

static int N, M;
static Item *st;

void hashExpand();

#endif