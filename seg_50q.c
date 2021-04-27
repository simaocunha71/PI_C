#include <stdio.h>
//https://github.com/62random/100_Questions_Imperative_Programming/blob/master/questoes2.c

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

// Exercicio 51 - Calcula o comprimento de uma lista
int length (LInt l){
    int r = 0;
    while (l != NULL){
        r++;
        l=l->prox;
    }
    return r;
}

// Exercicio 52 - Liberta o espaço ocupado por uma lista
void freeL (LInt l){
    LInt temp;
    while (l != NULL){
        temp = l;
        l = l->prox;
        free (tmp);
    }
}

// Exercicio 53 - Imprime todos os elementos de uma lista (um por linha
void imprimeL (LInt l){
    while (l != NULL){
        printf("%d\n",l->valor);
        l = l->prox;
    }
}

// Exercicio 54 - Inverte uma lista ligada
LInt reverseL (LInt l){
    LInt prev = NULL;
    LInt next = NULL;
    
    while (l!=NULL){
        next = l->prox; l->prox = prev;
        prev = l; l = next;
    }
    l = prev;
    return l;
}

// Exercicio 55 - Insere um elemento numa lista ligada ordenada
void insertOrd (LInt *l, int x){
    //Determina o local onde inserir um novo nodo
    while (*l!=NULL && (*l)->valor < x){
        l = &(*l)->prox;
    }
    //cria o novo nodo a inserir na lista
    *l= newLInt (x,*l);
}

// Exercicio 56 - remove um elemento de uma lista ordenada. Retorna 1 caso o elemento a remover nao exista, 0 no outro caso.
int removeOneOrd (LInt *l, int x){
    while (*l != NULL) {
        if ((*l)->valor == x) {
            if((*l)->prox == NULL)
                *l = NULL;
            else{
            	free(*l);
                *l = (*l)->prox;
            }
            return 0;
        }
        l = &(*l)->prox;
    }

    return 1;
}

// Exercicio 57 - junta duas listas ordenadas numa unica lista ordenada r
void merge (LInt *r, LInt a, LInt b){
    if (a == NULL && b==NULL)
        return;

    if (b == NULL || a != NULL && a->valor < b->valor){
        (*r) = a;
        merge (&((*r)->prox), a->prox, b);
    }
    else {
        (*r) = b;
        merge (&((*r)->prox), a, b->prox);
    }
}