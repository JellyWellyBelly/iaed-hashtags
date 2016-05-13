#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "avl.h"
#include "auxiliares.h"

#define MAXCHAR 142

link avl;

int ordena(const void *a, const void *b) { 
	Item *ia = (Item *)a;
	Item *ib = (Item *)b;
	if((*ia)->rep == (*ib)->rep)
		return strcmp((*ia)->hashtag, (*ib)->hashtag);
	else
		return (*ib)->rep - (*ia)->rep;
} 

int main(){
	bool le_hashtag = false;
	int len_mensagem = 0, indice = 0, contador = 0, repeticoes = 0;
	char c, palavra[MAXCHAR], *p;
	Item aux, max_hashtag=NULL;
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
						aux = STsearch(avl, p);

						if (aux == NULLitem){
							contador++;
							repeticoes++;

							STinsert(&avl, newItem(p, 1));

							if (max_hashtag != NULL){
								//verifica a hashtag mais popular
								if (1 == max_hashtag->rep && strcmp(p, max_hashtag->hashtag) < 0){
									max_hashtag = STsearch(avl, p);
								}
							}
							else
								max_hashtag = STsearch(avl, p);

							//insere = newItem(criaItem(palavra, 1), p, 1);
							//hashInsert(insere);
							//STinsert(&avl, insere);
							//hashInsert(newItem(criaItem(palavra, 1), p, 1));

						}
						else{
							//STdelete(&avl, aux->item);
							aux->rep++;

							//verifica a hashtag mais popular
							if (aux->rep > max_hashtag->rep){
								max_hashtag = aux;
							}
							else if (aux->rep == max_hashtag->rep && strcmp(p, max_hashtag->hashtag) < 0){
								max_hashtag = aux;
							}

							repeticoes++;

							//insere = newItem(aux->item, p, aux->rep);
							//STinsert(&avl, insere);
							//STinsert(&avl, p, aux->rep);
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
				if (max_hashtag != NULL)
					printf("#%s %d\n", max_hashtag->hashtag, max_hashtag->rep);
				break;

			case 'l':
				{
				Item *vec;
				int ii=0;
				vec=(Item*)malloc(sizeof(Item)*contador);
				int a=0;
				T2A(avl,vec,&a);
				qsort(vec, contador, sizeof(Item), ordena);
				for(ii=0;ii<contador;ii++){
					printf("#%s %d\n",vec[ii]-> hashtag,vec[ii]->rep);
				}
				free(vec);
				break;
			}
		}
		if (c == 'x'){
			STfree(&avl);
			free(vec);
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
	//STinsert(&avl, newItem("3nbavsdnbasb", "nbavsdnbasb",0));
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