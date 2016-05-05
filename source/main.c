#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"
#include "auxiliares.h"

#define MAXCHAR 140

tree *tree_hashtags;

int M;

int main(){

	bool le_hashtag = false;
	int contador = 0;
	char *palavra = (char*)malloc(sizeof(char)*MAXCHAR);

	while (1){
		c = getchar();

		switch (c){

			case 'a':
				while(c = getchar()){

					if(le_hashtag){
						*(palavra + contador++) = c;
					}

					if (c == '#' && !(le_hashtag)){
						le_hashtag = true;
					}

					if(e_caracter_branco(c)){
						le_hashtag = false;
						contador = 0;
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