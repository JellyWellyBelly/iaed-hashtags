/******************************************************************************
* File Name: avl.h
* Author:    Goncalo / Manuel
* Revision:
* NAME
*      avl - prototipos
* SYNOPSIS
*      #include <stdio.h>
*      #include <stdlib.h>
*      #include "item.h"
* DESCRIPTION
*		Implements input auxiliary functions
* DIAGNOSTICS
*          OK
*****************************************************************************/
#ifndef _AVL_
#define _AVL_
#include <stdio.h>
#include <stdlib.h>
#include "item.h"

typedef struct STnode* link;

struct STnode { 
	Item item; 
	link l, r; 
	int height;
};

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
void arvore_para_array(link h,Item *vec,int *i);

#endif