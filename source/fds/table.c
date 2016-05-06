#include "table.h"


int hash(char *string){
	int h, a = 12957, b  15038;

	for (h = 0; *string != '\0'; string++, a = a*b % (M-1))
		h = (a*h + *string) % M;
	return h;
}


void Init(){
	int i;
	table = (linkH*)malloc(sizeof(linkH)*M);

	for (i = 0; i < M; i++){
		table[i] = NULL;
	}
}


ptr_hashtag tableSearch(char *string){
	int i = hash(string);
	return searchList(table[i], string);
}


void tableInsert(ptr_hashtag ptr){
	int i = hash(ptr->palavra);
	table[i] = insertBeginList(table[i], ptr);
}



//Auxiliares


ptr_hashtag searchList(linkH head, char *string){
	if (strcmp(head->tag->palavra, string))
		return head->tag;
	else if(head->next == NULL)
		return;
	else searchList(head->next, string);
}


linkH insertBeginList(linkH head, ptr){
	if (head == NULL){
		head->tag = ptr;
		head->next = NULL;
		return head;
	}
	else if(strcmp(head->tag->palavra, ptr->palavra)){
		head->tag->ocorrencias++;
		return head;
	}
	else {
		if (head->next != NULL){
			insertBeginList(head->next, ptr);
		}
		else{
			head->next->tag = ptr;
			head->next->next = NULL;
			return head;
		}
	}
}








