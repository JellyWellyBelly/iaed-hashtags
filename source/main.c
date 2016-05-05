#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "avl.h"
/*
#include "tree.h"
#include "table.h"
#include "auxiliares.h"

#define MAXCHAR 140

tree *tree_hashtags;

int M;

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