#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "avl.h"
#include "auxiliares.h"

#define MAXCHAR 142

link avl;

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
						}
						else{
							aux->rep++;

							//verifica a hashtag mais popular
							if (aux->rep > max_hashtag->rep){
								max_hashtag = aux;
							}
							else if (aux->rep == max_hashtag->rep && strcmp(p, max_hashtag->hashtag) < 0){
								max_hashtag = aux;
							}

							repeticoes++;
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
				arvore_para_array(avl,vec,&a);
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
			return 0;
		}
	}
	return 0;
}
