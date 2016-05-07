#include "Item.h"

Item newItem(char*item, char *hashtag,int rep)
{
    Item x = (Item)malloc(sizeof(struct hashtags));
    x->item = strdup(item);
    x->rep = rep;
    x->hashtag = strdup(hashtag);
	return x; 
}

void deleteItem(Item a)
{
    free(a->item);
	free(a); 
}

void visitItem(Item a) 
{
    printf("%s %d\n",a->hashtag,a->rep);
}
