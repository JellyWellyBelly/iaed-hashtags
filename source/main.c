#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash.h"
#include "auxiliares.h"

#define MAXCHAR 140
/*

int main(){

	bool le_hashtag = false;
	int contador = 0;
	palavra = struct hashtag;

	while (1){
		c = getchar();

		switch (c){

			case 'a':
				while(c = getchar())
				{

					if(e_caracter_branco(c))
					{
						le_hashtag = false;
						*(palavra + contador) = '\0';
						contador = 0;
					}

					if(le_hashtag)
					{
						*(palavra + contador++) = c;
					}

					if (c == '#' && !(le_hashtag))
					{
						le_hashtag = true;
					}
				}
				break;

			case 's':
				break;

			case 'm':
				break;

			case 'x':
				break;
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
  	char *achas="ola";
  	a = (Item)malloc(sizeof(struct hashtags));
  	b = (Item)malloc(sizeof(struct hashtags));
  	a->item=strdup(achas);
  	a->rep=2;
  	hashInit(100);
  	hashInsert(a);
  	b=hashSearch("as ndbsam");
  	printf("%d\n",b==NULLitem);
	
	 //print(avl);
	return 0;	
}