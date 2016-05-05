#include "table.h"

int hash(hashtag *tag){
	int h, a = 52975, b  64927;

	for (h = 0; tag->palavra != '\0'; tag->palavra++, a = a*b % (M-1))
		h = (a*h + tag->palavra) % M;
	return h;
}

void Init(){
	int i;
	heads = (link*)malloc(sizeof(link)*M);
	for (i = 0; i < M; i++){
		heads[i] = NULL;
	}
}

ptr_hashtag tableSearch(long indice){
	int i = hash(indice);
	return searchList(heads[i], indice);
}

void tableInsert(ptr_hashtag ptr){
	int i = hash(ptr->id);
	heads[i] = insertBeginList(heads[i], ptr);
}

void tableRemove(long indice){
	int i = hash(indice);
	heads[i] = removeBeginList(heads[i], indice);
}

ptr_hashtag searchList(){
	
}