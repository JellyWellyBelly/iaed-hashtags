#ifndef _AVL_
#define _AVL_
#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

typedef struct STnode* link;
struct STnode { Item item; link l, r; int height;};
//static link head;
link avl;

void STinit(link*);
int STcount(link);
Item STsearch(link head, Key v);
Item searchR(link h, Key v);
void STinsert(link*,Item);
void STdelete(link*,Key);
void STsort(link ,void (*visit)(Item));
void STfree(link*);
void STinit(link*);
link NEW(Item item, link l, link r);
link AVLbalance(link h);
link rotR(link h);
link rotLR(link h);
link rotRL(link h);
int Balance(link h);
link insertR(link h, Item item);
#endif