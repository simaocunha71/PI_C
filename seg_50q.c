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

//Exercicio 58 - dada uma lista ligada l e um inteiro x, parte a lista em duas (retornando os endereços dos primeiros elementos da lista em *mx e *Mx): 
//uma com os elementos de l menores do que x e a outra com os restantes. 
void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if (l != NULL){
        if (l->valor < x){
            *mx = l;
            (*Mx) = NULL;
            splitQS(l->prox,x,&((*mx)->prox),Mx);
            
        }
        else{
            *Mx = l;
            (*mx)=NULL;
            splitQS(l->prox,x,mx,&((*Mx)->prox));   
        }      
    }
}

//Exercicio 59 - parte uma lista não vazia *l a meio. Se x contiver os elementos {1,2,3,4,5}, após a invocaçao y=parteAmeio(&x) a 
//lista y deverá conter os elementos {1,2} e a lista x os restantes {3,4,5}
int length (LInt l){
    int r = 0;
    while (l!=NULL){
        r++;
        l = l->prox;
    }
    return r;
}

LInt parteAmeio (LInt *l){
    int half = length(*l)/2;
    if(half == 0) 
        return NULL;
    LInt y = *l;
    LInt aux = NULL;
    int i;
    for(i = 0; i < half; i++){
        aux=(*l);
        (*l) = (*l)->prox;
    }
    aux->prox = NULL;
    return y;
}
//Exercicio 60 - remove todas as ocorrencias de um dado inteiro de uma lista, retornando o numero de celulas removidas.
int removeAll (LInt *l, int x){
    int rmv = 0;
    LInt aux = *l;
    LInt prev = NULL;
    while (aux != NULL) {
        if(aux->valor == x) {
            if (prev != NULL)
                prev->prox = aux->prox; //prev aponta para o proximo elemento de aux (excluindo o elemento repetido)
            else
                *l = aux->prox; //lista original aponta para o proximo elemento de aux (excluindo o elemento repetido)
            rmv++;
            free(aux); //liberta-se o nó que é repetido
        }
        else
            prev = aux;
        aux = aux->prox;
    }
    return rmv;
