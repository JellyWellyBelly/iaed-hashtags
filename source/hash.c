#include "hash.h"

static int M;

int hash(char *v, int M)
{
  int h, a = 31415, b = 27183;
  for (h = 0; *v != '\0'; v++, a = a*b % (M-1))
	h = (a*h + *v) % M;
return h; }

void hashInit(int max) {
  int i;
  M = max;
  heads = (linkH*)malloc(M*sizeof(linkH));
  for (i = 0; i < M; i++) heads[i] = NULL;
}

linkH NEW2(Item item){
  linkH x = (linkH)malloc(sizeof(struct nodeH));
  x->conteudo = item;
  x->next = NULL;
  return x;
}

linkH insertBeginList(linkH head, Item item){
  linkH x = NEW2(item);
  x->next = head;
  return x;
}

Item searchList(linkH head, char* string){
  linkH t;
  for (t = head; t != NULL; t = t->next)
		if (!(strcmp(t->conteudo->hashtag, string)))
	  	return t->conteudo;
  return NULL;
}

void hashInsert(Item item){
  int i = hash(key2(item), M);
  heads[i] = insertBeginList(heads[i], item);
}

Item hashSearch(Key v){
  int i = hash(v, M);
  return searchList(heads[i], v);
}

void hashFree(){
  int i;

  for (i = 0; i < M; i++)
   if (heads[i] != NULL)
		deleteHash(heads[i]);
  free(heads);
}

void deleteHash(linkH head){
  linkH t;
  for (t = head; t != NULL; t = t->next)
	   deleteItem(t->conteudo);
  free(head);
}