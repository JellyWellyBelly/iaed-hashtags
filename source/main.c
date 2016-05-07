#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "avl.h"
#include "table.h"
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
	link avl;
	STinit(&avl);
	STinsert(&avl, newItem("0#lolitos", 10));
	STinsert(&avl, newItem("0#yolo", 10));
	STinsert(&avl, newItem("1#nope", 10));
	STinsert(&avl, newItem("6#swag", 10));
	STinsert(&avl, newItem("7#sporting", 10));
	STinsert(&avl, newItem("8#campeao", 10));
	STinsert(&avl, newItem("9#portugal", 10));
	STsort(avl,visitItem);
	//STdelete(&avl,"asd");
	 printf("TOTAL: %d\n",STcount(avl));


	 //print(avl);
	return 0;	
}