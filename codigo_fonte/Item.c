/******************************************************************************************
* File Name:   main.c
* Author:      Goncalo Marques (84719) / Manuel Sousa (84740)
* Revision:
* NAME:        Hashtags - IST/IAED - 2015/2016 2º Semestre
* SYNOPSIS:    #include "item.h" - prototipos e macros
* DESCRIPTION: funcoes da arvore AVL que violam abstracao
* DIAGNOSTICS: tested
* USAGE:       make clean
*****************************************************************************************/
#include "item.h"

/******************************************************************************************
* NOVOItem()
*
* Arguments:	NOVOItem:  ponteiro para o nome da hashtag
*               repeticoes:  numero de repeticoes da hashtag
*
* Returns: void
* Description:  cria e aloca memoria para o hashtag
*****************************************************************************************/
Item NOVOItem(char *hashtag,int repeticoes){
    Item x = (Item)malloc(sizeof(struct hashtags));
    x->rep = repeticoes;
    x->hashtag = strdup(hashtag);
	return x; 
}

/******************************************************************************************
* deleteItem()
*
* Arguments:	a:  ponteiro para a estrutura da hashtag
*
* Returns: void
* Description:  liberta memoria alocada para o nome da hashtag e para a estrutura em si
*****************************************************************************************/
void deleteItem(Item a){
    free(a->hashtag);
	free(a); 
}

/******************************************************************************************
* imprimeItem()
*
* Arguments:	a:  ponteiro para a estrutura da hashtag
*
* Returns: void
* Description:  escreve o nome da hashtag e o seu numero de repeticoes
*****************************************************************************************/
void imprimeItem(Item a){
    printf("#%s %d\n", a->hashtag, a->rep);
}


/******************************************************************************************
* OrdenaAeroportosNome()
*
* Arguments:	a:  ponteiro para hashtag
*               b:  ponteiro para hashtag
*
* Returns: int 	retorna valor logico da comparacao de 2 hashtags
* Description:  decrescente por repeticoes e alfabeticamente em caso de empate | Usado no qsort
*****************************************************************************************/
int ordenaHashtags(const void *a, const void *b) { 
	Item *ia = (Item *)a;
	Item *ib = (Item *)b;
	if((*ia)->rep == (*ib)->rep)
		return strcmp((*ia)->hashtag, (*ib)->hashtag);
	else
		return (*ib)->rep - (*ia)->rep;
} 
