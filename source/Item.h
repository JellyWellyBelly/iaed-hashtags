#ifndef _ITEM_
#define _ITEM_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* Key;

typedef struct hashtags{
char* item; 
int rep;
char* hashtag;
}* Item;


#define NULLitem NULL
#define key(a) (a != NULL || a!=NULLitem ? a->item : "")
#define less(a,b) (strcmp(a,b)<0)
#define greater(a,b) (strcmp(a,b)>0)
#define eq(a,b) (strcmp(a,b)==0)
#define exch(A, B) { Item t = A; A = B; B = t; }
#define compexch(A, B) if (less(B, A)) exch(A, B)	

Item newItem(char*item, char *hashtag,int rep);
void deleteItem(Item a);
void visitItem(Item a);


#endif


