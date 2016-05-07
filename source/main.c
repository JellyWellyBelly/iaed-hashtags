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
	int len_mensagem = 0;
	int contador = 0;
	char *palavra;
	Item tag = (Item)malloc(sizeof(struct hashtags));
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
						*(palavra + contador) = '\0';
						contador = 0;
						tag->item = strdup(palavra);
						hashInsert(tag);
					}
					if(le_hashtag){
						*(palavra + contador++) = c;
					}
					if (c == '#' && !(le_hashtag)){
						le_hashtag = true;
						*(palavra + contador++) = c;
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
	/*link avl;
	STinit(&avl);
	STinsert(&avl, newItem("8#campeao","#campeao" ,8));
	STinsert(&avl, newItem("9#portugal","#portugal" ,9));
	STinsert(&avl, newItem("0#lolitos","#lolitos", 0));
	STinsert(&avl, newItem("1#nope", "#nope",1));
	STinsert(&avl, newItem("6#swag", "#swag",6));
	STinsert(&avl, newItem("0#nao", "#nao",0));
	STinsert(&avl, newItem("0#yolo", "#yolo",0));
	STinsert(&avl, newItem("0#yoloo", "#yoloo",0));
	STdelete(&avl,"0#yoloo");
	STsort(avl,visitItem);
	STfree(&avl);*/ 
	Item a,b;
  	char *achas="#ola";
  	char *achas2="5#ola";
  	a = (Item)malloc(sizeof(struct hashtags));
  	b = (Item)malloc(sizeof(struct hashtags));
  	a->item=strdup(achas2);
  	a->hashtag=strdup(achas);
  	a->rep=2;
  	hashInit(100);
  	hashInsert(a);
  	b=hashSearch("#ola");
  	printf("%s\n",b->hashtag);
	
	//print(avl);
	return 0;	
}