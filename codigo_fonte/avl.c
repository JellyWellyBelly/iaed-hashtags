/******************************************************************************************
* File Name:   avl.c
* Author:      Goncalo Marques (84719) / Manuel Sousa (84740)
* Revision:
* NAME:        Hashtags - IST/IAED - 2015/2016 2º Semestre
* SYNOPSIS:    #include "avl.h" - prototipos das funcoes e estruturas da arvore
* DESCRIPTION: funcoes completas de uma arvore AVL
*              Item - estrutura dos elementos da arvore
*              Key - Tipo de dados definido como elemento principal (de procura) na arvore
* DIAGNOSTICS: tested
*****************************************************************************************/
#include "avl.h"

/******************************************************************************************
* AVLprocura()
*
* Arguments:    head:   ponteiro para a cabeca da arvore AVL
*               v:      key a procurar na arvore
*
* Returns: Item - retorna um Item se este for encontrado, senao retorna NULLitem
*
* Description:  chama funcao de procura na arvore
*****************************************************************************************/
Item AVLprocura(link head, Key v){
    return searchR(head, v);
}

/******************************************************************************************
* searchR()
*
* Arguments:    h:  ponteiro para um no da arvore
*               v:  key a procurar na arvore
*
* Returns: Item - retorna um Item se encontrado na arvore ou NULLitem caso contrario
*
* Description:  precorre a arvore para retornar o no correspondente a key dada
*****************************************************************************************/
Item searchR(link h, Key v){
    if (h == NULL)
        return NULLitem;
    if (eq(v, key(h->item)))
        return h->item;
    if (less(v, key(h->item)))
        return searchR(h->l, v);
    else
        return searchR(h->r, v);
}

/******************************************************************************************
* max()
*
* Arguments:    head:  ponteiro para a cabeca da arvore AVL
*
* Returns: link
* Description:  retorna o maior dos nos da arvore AVL
*****************************************************************************************/
link max(link head){
    if (head == NULL || head->r == NULL) 
        return head;
    else
        return max(head->r);
}

/******************************************************************************************
* min()
*
* Arguments:    head:  ponteiro para a cabeca da arvore AVL
*
* Returns: link
* Description:  retorna o menor dos nos da arvore AVL
*****************************************************************************************/
link min(link h){
    if (h == NULL || h->l == NULL) 
        return h;
    else
        return min(h->l);
}

/******************************************************************************************
* rotL()
*
* Arguments:    h:  ponteiro para um no da arvore
*
* Returns: link
* Description:  roda a arvore para a esquerda
*****************************************************************************************/
link rotL(link h){
    int peso_left, peso_right;
    link x = h->r;
    h->r = x->l;
    x->l = h;
    peso_left = peso(h->l); peso_right = peso(h->r);
    h->peso = peso_left > peso_right ?  peso_left + 1 :
    peso_right + 1;
    peso_left = peso(h->l); peso_right = peso(x->r);
    x->peso = peso_left > peso_right ?  peso_left + 1 :
    peso_right + 1;
    return x;
}

/******************************************************************************************
* rotR()
*
* Arguments:    h:  ponteiro para um no da arvore
*
* Returns: link
* Description:  roda a arvore para a direita
*****************************************************************************************/
link rotR(link h){
    int peso_left, peso_right;
    link x = h->l;
    h->l = x->r;
    x->r = h;
    peso_left = peso(h->l); 
    peso_right = peso(h->r);
    h->peso = peso_left > peso_right ?  peso_left + 1 : peso_right + 1;
    peso_left = peso(x->l); 
    peso_right = peso(h->r);
    x->peso = peso_left > peso_right ?  peso_left + 1 : peso_right + 1;
    return x;
}

/******************************************************************************************
* rotLR()
*
* Arguments:    h:  ponteiro para um no da arvore
*
* Returns: link
* Description:  faz uma rotacao dupla esquerda direita
*****************************************************************************************/
link rotLR(link h){
    if (h == NULL) 
        return h;
    h->l = rotL(h->l);
    return rotR(h);
}

/******************************************************************************************
* rotRL()
*
* Arguments:    h:  ponteiro para um no da arvore
*
* Returns: link
* Description:  faz uma rotacao dupla direita esquerda
*****************************************************************************************/
link rotRL(link h){
    if (h==NULL) 
        return h;
    h->r = rotR(h->r);
    return rotL(h);
}

/******************************************************************************************
* NOVO()
*
* Arguments:    item:  elemento da arvore
*               l:  no (equerdo)
*               r:  no (direito)
*
* Returns: link retorna um no da arvore
* Description:  adiciona um novo elemento na arvore
*****************************************************************************************/
link NOVO(Item item, link l, link r){
    link x = (link)malloc(sizeof(struct STnode));
    x->item = item;
    x->l = l;
    x->r = r;
    x->peso = 1;
    return x; 
}

/******************************************************************************************
* AVLbalance()
*
* Arguments:    h:  ponteiro para um no da arvore
*
* Returns: link retorna um no da arvore
* Description:  balanceia a arvore AVL
*****************************************************************************************/
link AVLbalance(link h){
    int balanceFactor;
    if (h==NULL) 
        return h;
    balanceFactor = Balance(h);
    if(balanceFactor > 1){
        if (Balance(h->l) >= 0) 
            h=rotR(h);
        else                 
            h=rotLR(h);
    }
    else if(balanceFactor < -1){
        if (Balance(h->r) <= 0) 
            h = rotL(h);
        else                 
            h = rotRL(h);
    } else{
        int peso_left = peso(h->l); 
        int peso_right = peso(h->r);
        h->peso = peso_left > peso_right ?  peso_left + 1 : peso_right + 1;
    }
    return h; 
}

/******************************************************************************************
* deleteR()
*
* Arguments:    h:  ponteiro para um no da arvore
*               k:  key a procurar na arvore
*
* Returns: link
* Description:  apaga um no correspondente a key dada
*****************************************************************************************/
link deleteR(link h, Key k) {
    if (h==NULL) 
        return h;
    else if (less(k, key(h->item))) 
        h->l = deleteR(h->l, k);
    else if (less(key(h->item), k)) 
        h->r = deleteR(h->r, k);
    else {
        if (h->l != NULL && h->r != NULL){
            link aux = max(h->l);
            Item x; 
            x = h->item; 
            h->item = aux->item; 
            aux->item = x;
            h->l = deleteR(h->l, key(aux->item));
        } else {
            link aux = h;
            if (h->l == NULL && h->r == NULL) 
                h = NULL;
            else if (h->l == NULL) 
                h = h->r;
            else 
                h = h->l;
            deleteItem(aux->item);
            free(aux);
        }
    }   
    h = AVLbalance(h);
    return h;
}

/******************************************************************************************
* insertR()
*
* Arguments:    h:      ponteiro para um no da arvore
*       item:   item a inserir na arvore
*
* Returns: link
* Description:  insere um novo no na arvore associado ao item recebido
*****************************************************************************************/
link insertR(link h, Item item){
    if (h == NULL)
        return NOVO(item, NULL, NULL);
    if (less(key(item), key(h->item)))
        h->l = insertR(h->l, item);
    else
        h->r = insertR(h->r, item);
    h = AVLbalance(h);
    return h; 
}

/******************************************************************************************
* freeR()
*
* Arguments:    h:  ponteiro para um no da arvore
*
* Returns: void
* Description:  liberta a memoria alocada para os nos da arvore
*****************************************************************************************/
link freeR(link h){
    if (h == NULL)
        return h;
    h->l = freeR(h->l);
    h->r = freeR(h->r);
    return deleteR(h, key(h->item));
}

/******************************************************************************************
* AVLinicializa()
*
* Arguments:    head:  ponteiro para ponteiro para a cabeca da arvore AVL
*
* Returns: void
* Description:  inicia a cabeca arvore AVL com NULL
*****************************************************************************************/
void AVLinicializa(link *head){
    *head = NULL;
}

/******************************************************************************************
* AVLapaga()
*
* Arguments:    head:   ponteiro para ponteiro para a cabeca da arvore AVL
*               k:      key a procurar na arvore
*
* Returns: void
* Description:  chama a funcao que apaga o no correspondente a key recebida da arvore
*****************************************************************************************/
void AVLapaga(link *head, Key k){
    *head = deleteR(*head, k);
}

/******************************************************************************************
* AVLinsere()
*
* Arguments:    head:  ponteiro para ponteiro para a cabeca da arvore AVL
*               item:  recebe item para inserir na arvore
*
* Returns: void
* Description:  atualiza a cabeca da arvore com novo elemento inserido
*****************************************************************************************/
void AVLinsere(link *head, Item item){
    *head = insertR(*head, item);
}

/******************************************************************************************
* decrescente()
*
* Arguments:    h:              ponteiro para um no da arvore
*               (*visit)(Item): ponteiro para funcao
*
* Returns: void
* Description:  imprime a arvore por ordem decrescente
*****************************************************************************************/
void decrescente(link h, void (*visit)(Item)){
    if (h == NULL)
        return;
    decrescente(h->l, visit);
    visit(h->item);
    decrescente(h->r, visit);
}

/******************************************************************************************
* AVLimprime()
*
* Arguments:    head:       ponteiro para a cabeca da arvore AVL
*               (*visit)(Item): ponteiro para funcao
*
* Returns: void
* Description:  chama funcao recursiva que imprimira a arvore
*****************************************************************************************/
void AVLimprime(link head, void (*visit)(Item)){
    decrescente(head, visit);
}

/******************************************************************************************
* AVLliberta()
*
* Arguments:    head:  ponteiro para ponteiro para a cabeca da arvore AVL
*
* Returns: void
* Description:  chama a funcao que liberta a memoria alocada para a arvore
*****************************************************************************************/
void AVLliberta(link *head){
    *head = freeR(*head);
}

/******************************************************************************************
* AVL_para_array()
*
* Arguments:    h:     ponteiro para um no da arvore
* Arguments:    vec:   ponteiro para ponteiro de um vetor de items
* Arguments:    i:     ponteiro para inteiro que e o iterador (muda recursivamente)
*
* Returns: void
* Description:  precorre a arvore por ordem decrescente e constroi um vetor de Items recursivamente
*****************************************************************************************/
void AVL_para_array(link h, Item *vec, int *i){
    if (h == NULL)
        return;
    AVL_para_array(h->l, vec, i);
    vec[(*i)++] = h->item;
    AVL_para_array(h->r, vec, i);
}

/******************************************************************************************
* AVLconta()
*
* Arguments:    head:  ponteiro para um no da arvore
*
* Returns: int  retorna profundidade da arvore
* Description:  retorna profundidade da arvore AVL
*****************************************************************************************/
int AVLconta(link head){
    return count(head);
}

/******************************************************************************************
* Balance()
*
* Arguments:    h:  ponteiro para um no da arvore
*
* Returns: int  retorna o novo peso
* Description:  retorna o novo peso para balanceamento
*****************************************************************************************/
int Balance(link h) {
    if(h == NULL) 
        return 0;
    return peso(h->l) - peso(h->r);
}

/******************************************************************************************
* count()
*
* Arguments:    head:  ponteiro para um no da arvore
*
* Returns: int  retorna profundidade da arvore a partir de um no
* Description:  funcao recursiva que calcula a profundadade da arvore AVL a partir de um no
*****************************************************************************************/
int count(link h){
    if (h==NULL) 
        return 0;
    else 
        return count(h->r) + count(h->l) + 1;
}

/******************************************************************************************
* peso()
*
* Arguments:    h:  ponteiro para um no da arvore
*
* Returns: int  retorna o valor do peso do no, NULL caso o no nao exista
* Description:  retorna o valor do peso
*****************************************************************************************/
int peso(link h){
    if (h == NULL) 
        return 0;
    return h->peso;
}