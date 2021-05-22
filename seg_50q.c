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
        free(temp);
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
            //Elemento anterior é NULL
            if (prev == NULL)
                *l = aux->prox; //ignora-se o valor igual a x
            else
                prev->prox = aux->prox; //prev aponta para o proximo elemento de aux (excluindo o elemento repetido)
            rmv++;
            free(aux); //liberta-se o nó que é repetido
        }
        else
            prev = aux;
        aux = aux->prox;
    }
    return rmv;
}

//Exercicio 61: remove os valores repetidos de uma lista (deixando apenas a primeira ocorrencia)
int removeDups (LInt *l){
    LInt aux = *l; LInt prev = NULL;
    LInt escravo;
    int c = 0;
    int isRepetido; 
    
    while (aux != NULL) {
        for(escravo = *l; escravo != aux; escravo = escravo->prox) {  
            isRepetido = 0;
            if(escravo->valor == aux->valor) { 
                isRepetido = 1;
                break;
            }
        }
        if (isRepetido == 1) {
            prev->prox = aux->prox;//ignora valor repetido de aux
            free(aux);
            c++;
        }
        else 
            prev = aux;//mantem valor na lista
            
        aux = aux->prox;
    }
    return c;
}

//Exercicio 62: remove (a primeira ocorrencia) o maior elemento de uma lista nao vazia, retornando o valor desse elemento.
int removeMaiorL (LInt *l){
    int r = (*l)->valor;
    int maior = maiorElemento(l);
    int flag = 0; //so queremos apagar a primeira ocorrencia do maior elemento
    LInt aux = *l;
    LInt prev = NULL;
    
    while(aux != NULL && flag == 0){
        if (aux->valor == maior){
            if (prev == NULL)
                *l = aux->prox;
            else{
                prev->prox = aux->prox;
                free(aux);
            }
            r = maior;
            flag = 1;
        }
        else
            prev = aux;
        aux=aux->prox;
    }
    return r;
}

//Exercicio 63: remove o ultimo elemento de uma lista nao vazia (libertando o correspondente espaço)
void init (LInt *l) {
    LInt prev = NULL;
    while((*l)->prox != NULL){
        prev = *l;
        l = &((*l)->prox);
    }

    if(prev == NULL) {
        free(*l);
        *l = NULL;
    }
    else {
        prev->prox = NULL;
        free(*l);
    }
}

//Exercicio 64: acrescenta um elemento no fim da lista.
void appendL (LInt *l, int x){
    LInt res = malloc (sizeof(struct lligada));
    res->valor = x;
    res->prox = NULL;
    
    if (*l != NULL){
        while ((*l)->prox != NULL)
            l = &((*l)->prox);
        (*l)->prox = res;
    }
    else
        *l = res;
}

//Exercicio 65: acrescenta a lista b à lista *a.
void concatL (LInt *a, LInt b){
    while ((*a) != NULL){
        a = &((*a)->prox);
    }
    *a = b;
}

//Exercicio 66: Copia uma lista ligada
LInt cloneL (LInt l) {
    if(l == NULL) 
        return NULL; 
    LInt new = malloc(sizeof(struct lligada));
    new->valor = l->valor;
    new->prox = cloneL(l->prox);
    return new;
}

//Exercicio 67: Copia uma lista ligada pela ordem inversa
LInt cloneRev (LInt l){
    LInt newReverse = NULL;
    LInt aux = NULL;

    while (l != NULL) {
        newReverse = malloc (sizeof(struct lligada));
        newReverse->valor = l->valor;
        newReverse->prox = aux; //a nova lista fica sempre a apontar para o ultimo elemento inserido
        aux = newReverse;
        l = l->prox;
    }

    return newReverse;
}

//Exercicio 68: calcula qual o maior valor armazenado numa lista nao vazia
int maximo (LInt l){
    int r = l->valor;
    while(l!=NULL){
        if (l->valor > r)
            r = l->valor;
        l = l->prox;
    }
    return r;
}

//Exercicio 69: dado um inteiro n e uma lista ligada de inteiros l, apaga de l todos os nodos para alem do n-esimo (libertando o respectivo espaço). 
// Se a lista tiver n ou menos nodos, a funçao nao altera a lista.
// A funçao deve retornar o comprimento final da lista. 
int take (int n, LInt *l){
    int i = 0;
    LInt aux;
    
    //mantem na lista todos os elementos desejados
    while (*l != NULL && i < n){
        i++;
        l = &((*l)->prox);
    }
    
    //percorremos o resto da lista que falta e apagamos todos esses elementos
    while (*l != NULL){
        aux = *l;
        free(aux);
        *l = (*l)->prox;
    }

    return i;
}

//Exercicio 70: dado um inteiro n e uma lista ligada de inteiros l, apaga de l os n primeiros elementos da lista (libertando o respectivo espaço). 
// Se a lista tiver n ou menos nodos, a funçao liberta a totalidade da lista.
//A funçao deve retornar o numero de elementos removidos.
int drop (int n, LInt *l){
    int i;
    LInt aux;
    for(i = 0; i < n && (*l); i++) {
        aux = (*l);
        (*l) = (*l)->prox;
        free(aux);
    }
    return i;
}

//Exercicio 71: dada uma lista circular dá como resultado o endereço do elemento da lista que está N posiçoes à frente.
LInt NForward (LInt l, int N){
    for (int i = 0; i < N && l!=NULL; i++){
        l = l->prox;
    }
    LInt res = l;
    return res;
}

//Exercicio 72: dada uma lista l, preenche o array v com os elementos da lista.
// A função deverá preencher no maximo N elementos e retornar o numero de elementos preenchidos.
int listToArray (LInt l, int v[], int N){
    int i;
    for (i = 0; i < N && l != NULL; i++){
        v[i] = l->valor;
        l=l->prox;
    }
    return i;
}

//Exercicio 73: constroi uma lista com os elementos de um array, pela mesma ordem em que aparecem no array.
LInt arrayToList (int v[], int N){
    if(N == 0) 
        return NULL;
    LInt new = malloc(sizeof(struct lligada));
    new->valor = (*v);
    new->prox = arrayToList(v+1, N-1);
    return new;
}

//Exercicio 74: dada uma lista de inteiros, constroi uma nova lista de inteiros contendo as somas acumuladas da lista original (que deverá permanecer inalterada).
//Por exemplo, se a lista l tiver os valores [1,2,3,4] a lista construida pela invocação de somasAcL(l) deverá conter os valores[1, 3, 6, 10].
LInt somasAcL (LInt l) {
    int sum = 0;
    LInt res = NULL;
    LInt aux = NULL;
    while(l!=NULL){
        sum += l->valor;//Valor a adicionar em cada nó da nova lista

        //Alocação de um nó
        LInt new   = malloc(sizeof(struct lligada));
        new->valor = sum;
        new->prox  = NULL;  

        
        if(res == NULL)
            res = aux = new; //Caso seja para adicionar o primeiro novo nó
        else
            aux = aux->prox = new;
    
        l=l->prox;
    }
    return res;
}

//Exercicio 75: dada uma lista ordenada de inteiros, elimina dessa lista todos os valores repetidos assegurando que o espaço de memoria 
//correspondente aos nós removidos é correctamente libertado. 
void remreps (LInt l){
    LInt aux;
    LInt prev = NULL;

    while (l != NULL) {
        //Elimina elementos repetidos sucessivos (a lista deve estar ordenada)
        if (prev != NULL && prev-> valor == l->valor) {
            prev->prox = l->prox;
            aux = l;
            free(l);
        }
        else //Mantem elemento na lista 
            prev = l;
        l = l->prox;
    }
}

//Exercicio 76: coloca o primeiro elemento de uma lista no fim. 
//Se a lista for vazia ou tiver apenas um elemento, a funçao nao tem qualquer efeito pratico (i.e., devolve a mesma lista que recebe como argumento).
//Note que a sua funçao nao deve alocar nem libertar memoria. Apenas re-organizar as celulas da lista.
LInt rotateL (LInt l){
    if (l == NULL || l->prox == NULL)
        return l;

    LInt first = l;
    LInt r = l->prox;//ignora-se o primeiro elemento da lista original

    while ( l->prox != NULL)
        l = l->prox;

    l->prox = first;
    first->prox = NULL;

    return r;
}

//Exercicio 77: parte uma lista l em duas: na lista l ficam apenas os elementos das posiçoes impares; 
//na lista resultante ficam os restantes elementos (elementos das posiçoes pares).
//Assim, se a lista x tiver os elementos {1,2,3,4,5,6} a chamada y = parte (x), coloca na lista y os elementos {2,4,6} ficando em x apenas os elementos {1,3,5}
LInt parte (LInt l){
    if(l == NULL || l->prox == NULL)
        return NULL;
    LInt pares = l->prox;
    l->prox = l->prox->prox;
    pares->prox = parte(l->prox);
    return pares;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

//Exercicio 78: calcula a altura de uma arvore binaria
int max(int x, int y){
    return x > y ? x:y;
}

int altura (ABin a){
    int alt = 0;
    if (a == NULL)
        alt == 0;
    else
        alt = 1 + max(altura(a->esq),altura(a->dir));
	return alt;
}

//Exercicio 79: cria uma cópia de uma arvore binaria
ABin cloneAB (ABin a) {
    if (a != NULL){
        ABin res = malloc(sizeof(struct nodo));
        res->valor = a->valor;
        res->esq = cloneAB(a->esq);
        res->dir = cloneAB(a->dir);       
        return res;
    }
    return NULL;
}

//Exercicio 80:  inverte uma arvore (sem criar uma nova arvore)
void mirror (ABin *a) {
    ABin aux;
    if (*a != NULL){
        aux = (*a)->esq;
        (*a)->esq = (*a)->dir;
        (*a)->dir = aux;
        mirror(&((*a)->esq));
        mirror(&((*a)->dir));
    }
}

//Exercicio 81: 