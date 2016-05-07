#ifndef _HASH_
#define _HASH_
#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

#define null(A) (key(st[A]) == "")

static int N, M;
static Item *st;

void hashExpand();
void hashInit(int max);
int hash(char *v, int M);
void hashInsert(Item item);
void hashExpand();
Item hashSearch(Key v);
void hashDelete(Item item);

#endif