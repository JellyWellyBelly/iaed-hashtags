#ifndef _HASH_
#define _HASH_
#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

#define null(A) (key(st[A]) == keyNull(NULLitem))

linkH *heads;

void insert(linkH x, Item item);
int hash(char *v, int M);
void hashInit(int max);
linkH NEW2(Item item);
linkH insertBeginList(linkH head, Item item);
Item searchList(linkH head, char* string);
void hashInsert(Item item);
Item hashSearch(Key v);
void hashFree();
void deleteHash(linkH head);

#endif