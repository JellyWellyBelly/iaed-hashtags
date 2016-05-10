#include "hash.h"


void hashInit(int max) {
  int i;

  N = 0; 
  M = 2 * max;

  st = (Item*)malloc(M*sizeof(Item));

  for (i = 0; i < M; i++) 
	 st[i] = NULLitem; 
}

int hash(char *v, int M)
{
  int h, a = 31415, b = 27183; //MUDAR PRIMOS
  for (h = 0; *v != '\0'; v++, a = a*b % (M-1))
	h = (a*h + *v) % M;
  return h; 
}

void hashInsert(Item item) {
  Key v = key2(item);
  int i = hash(v, M);

  while (!null(i)) 
	i = (i+1) % M;

  st[i] = item;

  if (N++ > M/2) 
	hashExpand();
}

void hashExpand() {
  int i; 
  Item *t = st;

  hashInit(M+M);

  for (i = 0; i < M/2; i++)
	if (key2(t[i]) != keyNull(NULLitem))
	  hashInsert(t[i]);
  free(t);
}

Item hashSearch(Key v)
{ 
  int i = hash(v, M);

  while (!null(i))
	if (eq(v, key2(st[i])))
	  return st[i];
	else
	  i = (i+1) % M;

  return NULLitem;
}

void hashDelete(Item item)
{ 
  int j, i = hash(key2(item), M);
  Item v;

  while (!null(i))
	if (eq(key2(item), key2(st[i]))) break;
	else i = (i+1) % M;

  if (null(i)) return;

  st[i] = NULLitem; 

  N--;
  for (j = (i+1) % M; !null(j); j = (j+1) % M, N--) {
	v = st[j]; 
	st[j] = NULLitem;
	hashInsert(v);
  }
}
