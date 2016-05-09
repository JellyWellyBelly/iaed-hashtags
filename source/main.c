#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash.h"
#include "avl.h"
#include "auxiliares.h"

#define MAXCHAR 140


/*
int main(){
	bool le_hashtag = false;
	int len_mensagem = 0, contador = 0;
	char c, palavra[MAXCHAR];
	Item tag = (Item)malloc(sizeof(struct hashtags));
	Item aux;

	hashInit(100);

	while (1){
		c = getchar();
		switch (c){
			case 'a':
				c = getchar();
				while(c = getchar())
				{
					len_mensagem++;
					
					if(e_caracter_branco(c) && le_hashtag){
						le_hashtag = false;
						palavra[contador] = '\0';
						contador = 0;
						tag->hashtag = strdup(palavra);
						tag->rep = 1;
						aux = hashSearch(tag);

						if (aux == NULLitem){
							tag->item = strdup(criaItem(tag->hashtag, tag->rep));
							hashInsert(tag);
						}
						else{

							aux->rep++;
							aux->item = strdup(criaItem(aux->hashtag, aux->rep));
						}

					}
					if(le_hashtag){
						palavra[contador++] = c;
					}
					if (c == '#' && !(le_hashtag)){
						le_hashtag = true;
						palavra[contador++] = c;
					}
				}
				
				if (le_hashtag){
					le_hashtag = false;
					palavra[contador] = '\0';
					contador = 0;
					tag->hashtag = strdup(palavra);
					tag->rep = 1;
					aux = hashSearch(tag);

					if (aux == NULLitem){
						tag->item = strdup(criaItem(tag->hashtag, tag->rep));
						hashInsert(tag);
					}
					else{

						aux->rep++;
						aux->item = strdup(criaItem(aux->hashtag, aux->rep));
					}
				}
				break;
			case 's':
				c = getchar();
				break;
			case 'm':
				c = getchar();
				break;
		}
		if (c == 'x'){
			free(tag);
		}
	}
	return 0;
}
*/

int main()
{
	link avl;
	STinit(&avl);
	STinsert(&avl, newItem("8#campeao","campeao" ,8));
	STinsert(&avl, newItem("9#portugal","portugal" ,9));
	STinsert(&avl, newItem("9#benfica","benfica", 9));
	STinsert(&avl, newItem("0#lolitos","lolitos", 0));
	STinsert(&avl, newItem("0#phahaha","phahaha", 0));
	STinsert(&avl, newItem("1#nope", "nope",1));
	STinsert(&avl, newItem("6#swag", "swag",6));
	STinsert(&avl, newItem("0#nao", "nao",0));
	STinsert(&avl, newItem("0#yolo", "yolo",0));
	STinsert(&avl, newItem("0#nbavsdnbasb", "nbavsdnbasb",0));
	STinsert(&avl, newItem("0#aaaa", "aaaa",0));
	STinsert(&avl, newItem("0#yoloo", "yoloo",0));
	STsort(avl,visitItem);
	printf("ASDASDSADSADSADSADSDADASDSADASDAS\n");
	STdelete(&avl,"9#portugal");
	STdelete(&avl,"0#aaaa");
	STdelete(&avl,"0#yoloo");
	STdelete(&avl,"0#nbavsdnbasb");
	STsort(avl,visitItem);
	STfree(&avl);
	/*Item a,b;
	Item a,b;
  	char *achas="#ola";
  	char *achas2="5#ola";
  	a = (Item)malloc(sizeof(struct hashtags));
  	b = (Item)malloc(sizeof(struct hashtags));
  	a->item=strdup(achas2);
  	a->hashtag=strdup(achas);
  	a->rep=2;
  	hashInit(498257); //numero primo
  	hashInsert(a);
  	hashInsert(newItem("6#swag", "#swag",6));
  	b=hashSearch("#swag");
  	printf("%d\n",b==NULL);
	
	//print(avl);*/
	return 0;	
}
