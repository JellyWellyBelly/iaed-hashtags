#include "Item.h"

Item newItem(char *hashtag,int rep)
{
    Item x = (Item)malloc(sizeof(struct hashtags));
    x->rep = rep;
    x->hashtag = strdup(hashtag);
	return x; 
}

void deleteItem(Item a)
{
    free(a->hashtag);
	free(a); 
}

void visitItem(Item a)
{
    printf("#%s %d\n",a->hashtag,a->rep);
}
