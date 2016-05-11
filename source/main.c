#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "hash.h"
#include "avl.h"
#include "auxiliares.h"

#define MAXCHAR 142

link avl;

int main(){
	bool le_hashtag = false;
	int len_mensagem = 0, indice = 0, contador = 0, repeticoes = 0, max_rep = 0;
	char c, palavra[MAXCHAR], *p, *max_hashtag = "";
	//Item tag = (Item)malloc(sizeof(struct hashtags));
	Item aux = (Item)malloc(sizeof(struct hashtags));

	hashInit(119551);
	STinit(&avl);

	while (1){
		c = getchar();
		switch (c){
			case 'a':
				c = getchar();
				len_mensagem = 0;
				
				while((c = getchar()))
				{ 
					len_mensagem++;
					
					if(e_caracter_branco(c) && le_hashtag){
						le_hashtag = false;
						palavra[indice] = '\0';
						indice = 0;
						p = palavra;
						p++;
						aux = hashSearch(p);

						if (aux == NULLitem){
							contador++;
							repeticoes++;

							//verifica a hashtag mais popular
							if (1 > max_rep){
								max_rep = 1;
								max_hashtag = strdup(palavra);
							}
							else if (1 == max_rep && strcmp(palavra, max_hashtag) < 0){
								max_hashtag = strdup(palavra);
							}

							//STsort(avl,visitItem);
							hashInsert(newItem(criaItem(palavra, 1), p, 1));
							STinsert(&avl, newItem(criaItem(palavra, 1), p, 1));
							//STsort(avl,visitItem);

						}
						else{
							//printf("############################################antes: \n");
							//STsort(avl,visitItem);
							//printf("A APAGAAAAAAAAAAAAAAAAAAAAARRRRR:%s\n",aux->item);
							STdelete(&avl, aux->item);
							//printf("############################################depois: \n");
							//STsort(avl,visitItem);
							aux->rep++;

							//verifica a hashtag mais popular
							if (aux->rep > max_rep){
								max_rep = aux->rep;
								max_hashtag = strdup(palavra);
							}
							else if (aux->rep == max_rep && strcmp(palavra, max_hashtag) < 0){
								max_hashtag = strdup(palavra);
							}

							repeticoes++;
							aux->item = strdup(criaItem(palavra, aux->rep));

							STinsert(&avl, newItem(aux->item, p, aux->rep));
						}
					}
					if(le_hashtag){
						if (c >= 65 && c <= 90)
							palavra[indice++] = tolower(c);
						else
							palavra[indice++] = c;
					}

					if (c == '#' && !(le_hashtag)){
						le_hashtag = true;
						palavra[indice++] = c;
					}
					if (c == '\n' || len_mensagem == MAXCHAR)
						break;
				}
				break;

			case 's':
				printf("%d %d\n", contador, repeticoes);
				break;

			case 'm':
				if (max_rep > 0)
					printf("%s %d\n", max_hashtag, max_rep);
				break;

			case 'l':
				STsort(avl,visitItem);
				break;
		}
		if (c == 'x'){
			STfree(&avl);
			return 0;
		}
	}
	return 0;
}

/*
int main()
{
	//STinsert(&avl, newItem("8#campeao","campeao" ,8));
	//STinsert(&avl, newItem("9#portugal","portugal" ,9));
	//STinsert(&avl, newItem("9#benfica","benfica", 9));
	//STinsert(&avl, newItem("0#lolitos","lolitos", 0));
	//STinsert(&avl, newItem("0#phahaha","phahaha", 0));
	//STinsert(&avl, newItem("1#nope", "nope",1));
	//STinsert(&avl, newItem("6#swag", "swag",6));
	//STinsert(&avl, newItem("0#nao", "nao",0));
	//STinsert(&avl, newItem("0#yolo", "yolo",0));
	//STinsert(&avl, newItem("0#nbavsdnbasb", "nbavsdnbasb",0));
	//STinsert(&avl, newItem("0#aaaa", "aaaa",0));
	//STinsert(&avl, newItem("0#yoloo", "yoloo",0));
	//STsort(avl,visitItem);
	//printf("ASDASDSADSADSADSADSDADASDSADASDAS\n");
	//STdelete(&avl,"9#portugal");
	//STdelete(&avl,"0#aaaa");
	//STdelete(&avl,"0#yoloo");
	//STdelete(&avl,"0#nbavsdnbasb");
	//STsort(avl,visitItem);
	//STfree(&avl);
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
	
	//print(avl);
	return 0;	
}
*/