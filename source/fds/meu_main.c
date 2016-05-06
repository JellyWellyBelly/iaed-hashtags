#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "table.h"
#include "auxiliares.h"

#define MAXCHAR 140

linkH *table;

int main()
{
	char str[4] = {"ola"};
	struct hashtag hush = {"ola", 0};
	Init(table);
	tableInsert(&hush, table);
	free(table);

	return 0;	
}

/*
int main(){

	bool le_hashtag = false;
	int contador = 0;
	char *palavra = (char*)malloc(sizeof(char)*MAXCHAR);

	//ignorar o primeiro espaço

	//so considera o # se o caracter anterior for um separador

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
