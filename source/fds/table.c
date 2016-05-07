#include "table.h"

int hash(char *string){
	int h, a = 12957, b = 15038;

	for (h = 0; *string != '\0'; string++, a = a*b % (M-1))
		h = (a*h + *string) % M;
	return h;
}

void Init(linkH *table){
	int i;
	table = (linkH*)malloc(sizeof(linkH)*M);

	for (i = 0; i < M; i++){
		table[i] = NULL;
	}
}

Item tableSearch(Item ptr, linkH *table){
	int i = hash(key(ptr));
	return searchTable(table[i], key(ptr));
}

void tableInsert(Item ptr, linkH *table){
	int i = hash(key(ptr));
	table[i] = insertHash(table[i], ptr);
}


//Auxiliares

Item searchTable(linkH head, char *string){
	linkH x;

	for(x = head; x != NULL; x = x->next){
		if (strcmp(x->key(hashtag), string) == 0)
			return x->hashtag;
	}
}

linkH insertHash(linkH head, Item ptr){
	linkH x;
	if (head == NULL){
		return NewNode(ptr);
	}
	else{
		for (x = head; x->next != NULL; x = x->next){
			if(strcmp(head->key(hashtag), key(ptr))){
				head->hashtag->ocorrencias++;
				return head;
			}
		}
		x->next = NewNode(ptr);

		//nao estava nos slides
		x->next->next = NULL;
		//nao estava nos slides

		return head;
	}
}

linkH NewNode(Item ptr){
	linkH x = (linkH)malloc(sizeof(struct node));
	x->hashtag = ptr;
	x->next = NULL;

	return x;
}