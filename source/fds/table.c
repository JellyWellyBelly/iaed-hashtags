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

ptr_hashtag tableSearch(char *string, linkH *table){
	int i = hash(string);
	return searchTable(table[i], string);
}


void tableInsert(ptr_hashtag ptr, linkH *table){
	int i = hash(ptr->palavra);
	// table[i] = insertHash(table[i], ptr) necessario??
	insertHash(table[i], ptr);
}


//Auxiliares


ptr_hashtag searchTable(linkH head, char *string){
	if (strcmp(head->tag->palavra, string))
		return head->tag;
	else if(head->next != NULL)
		searchTable(head->next, string);
}

void insertHash(linkH head, ptr_hashtag ptr){
	//onde defino o new e como associa-lo ao node anterior
	if (head == NULL) {
		linkH new = (linkH)malloc(sizeof(struct node));
		new->tag = ptr;
		new->next = NULL;
		head = new;
	}
	else if(strcmp(head->tag->palavra, ptr->palavra)){
		head->tag->ocorrencias++;
	}
	else {
		if (head->next != NULL){
			insertHash(head->next, ptr);
		}
		else{
			linkH new = (linkH)malloc(sizeof(struct node));
			new->tag = ptr;
			new->next = NULL;
			head->next = new;
		}
	}
}
