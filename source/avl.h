#ifndef _ST_
#define _ST_
#include <stdlib.h>
#include <stdio.h>
#include "Item.h"

typedef struct STnode* link;
struct STnode { Item item; link l, r; int height;};
static link head;

void STinit(link*);
int STcount(link);
Item STsearch(link,Key);
void STinsert(link*,Item);
void STdelete(link*,Key);
void STsort(link,void (*visit)(Item));
void STfree(link*);
void STinit(link*);

link rotR(link h);
link rotLR(link h);
link rotRL(link h);
int Balance(link h);
link insertR(link h, Item item);
#endif