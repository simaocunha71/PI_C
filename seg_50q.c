#include <stdio.h>

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
        next = l->prox; 
               l->prox = prev;
                         prev = l;
                                l = next;
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

//Exercicio 81: cria uma lista ligada de inteiros a partir de uma travessia inorder de uma árvore binária
//Esq - Raiz - Dir
void inorder_aux (ABin a, LInt * l) {
    LInt new;
    if(a != NULL) {
        inorder_aux(a->dir,l);

        new = malloc(sizeof (LInt));
        new->valor = a->valor;
        new->prox = *l;

        *l = new;

        inorder_aux(a->esq,l);
    }
}

void inorder (ABin a, LInt *l){
    *l = NULL;
    inorder_aux (a,l);
}

//Exercicio 82: cria uma lista ligada de inteiros a partir de uma travessia preorder de uma árvore binária
//Raiz - Esq - Dir
void preorder_aux (ABin a, LInt * l) {
    LInt aux;
    if(a != NULL) {
        preorder_aux(a->dir,l);
        preorder_aux(a->esq,l);

        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;

        *l = aux;
    }
}

void preorder(ABin a, LInt * l) {
    *l = NULL;
    preorder_aux (a,l);
}

//Exercicio 83: cria uma lista ligada de inteiros a partir de uma travessia posorder de uma árvore binária
//Esq - Dir - Raiz
void posorder_aux (ABin a, LInt * l) {
    LInt aux;
    if(a != NULL) {
        aux = malloc(sizeof(struct lligada));
        aux->valor = a->valor;
        aux->prox = *l;

        *l = aux;
        
        posorder_aux(a->dir,l);
        posorder_aux(a->esq,l);


    }
}

void posorder (ABin a, LInt * l) {
    *l = NULL;
    posorder_aux (a,l);
}

//Exercicio 84: calcula o nivel (menor) a que um elemento está numa arvore binaria (-1 caso nao exista)
int depth (ABin a, int x) {
    if(a == NULL)
        return -1;

    if(a->valor == x) 
        return 1;

    int esq = depth(a->esq,x);
    int dir = depth(a->dir,x);

    if(esq == -1 && dir == -1) 
        return -1;
        
    if(esq == -1 && dir != -1)
        return 1 + dir;
    
    if(esq != -1 && dir == -1)
        return 1 + esq;
    
    return esq < dir ? 1 + esq : 1 + dir;
}

//Exercicio 85: liberta o espaço ocupado por uma arvore binaria, retornando o numero de nós removidos
int freeAB (ABin a) {
    int r = 0;
    //Remover os nós de baixo para cima da árvore e fazer uma travessia posorder (esq - dir - raiz)
    if (a != NULL){
        r += freeAB(a->esq);
        r += freeAB(a->dir);
        free(a);
        r++;        
    }
    return r;
}

//Exercicio 86: e remove (libertando o espaço respectivo) todos os elementos da árvore *a que estão a uma profundidade superior a l, retornando o numero de elementos removidos.
//Assuma que a profundidade da raiz da árvore é 1, e por isso a invocação pruneAB(&a,0) corresponde a remover todos os elementos da árvore a.
int pruneAB (ABin *a, int l) {
    int r;
    if((*a) == NULL)
        return 0;
    
    if(l == 0) {
        r = 1 + pruneAB(&((*a)->esq),0) + pruneAB(&((*a)->dir),0);
        free(*a);
        (*a) = NULL;
    }
    else 
        r = pruneAB(&((*a)->esq),l-1) + pruneAB(&((*a)->dir),l-1);
    
    return r;
}

//Exercicio 87: testa se duas árvores são iguais (têm os mesmos elementos e a mesma forma)
int iguaisAB (ABin a, ABin b) {
    int bool = 0;
    if (a == b) 
        bool = 1;
    if (a != NULL && b != NULL && a->valor == b->valor)
        bool = iguaisAB(a->esq, b->esq) && iguaisAB(a->dir, b->dir);
    return bool;
}

//Exercicio 88: dada uma árvore binária, constrói uma lista com os valores dos elementos que estão armazenados na árvore ao nível "n" (assuma que a raiz da árvore está ao nível "1")
LInt concat (LInt a, LInt b){ //concatena 2 listas
    if(a == NULL)
        return b;
    LInt aux = a;
    while(aux->prox != NULL)
        aux = aux->prox;
    aux->prox = b;
    return a;
}


LInt nivelL (ABin a, int n){
    if (a == NULL || n < 1)
        return NULL;

    if (n == 1){
        LInt new = malloc (sizeof(struct lligada));
        new->valor = a->valor;
        new->prox = NULL;
        return new;
    }
    else
        return(concat(nivelL(a->esq, n-1), nivelL (a->dir, n-1)));
}

//Exercicio 89: preenche o vector "v" com os elementos de "a" que se encontram no nível "n". 
//Considere que a raiz da árvore se encontra no nível "1". 
//A função deverá retornar o número de posições preenchidas do array. 
int nivelV (ABin a, int n, int v[]) {
    if (a == NULL || n < 1)
        return 0;
        
    int r = 0;

    if (a != NULL)
        if (n != 1) {
            r+= nivelV(a->esq,n-1,v);
            r+= nivelV(a->dir,n-1,v+r);
        } 
        else{
            v[r] = a->valor;
            r++;
        }
    return r;
}

//Exercicio 90: dada uma árvore "a", preenche o array "v" com os elementos da árvore segundo uma travessia inorder. 
//A função deverá preencher no máximo "N" elementos e retornar o número de elementos preenchidos.
int dumpAbin (ABin a, int v[], int N) {
    if (a == NULL)
        return 0;
    int r = 0;
    if (a != NULL && N > 0){
        r = dumpAbin (a->esq, v, N-1);
        v[r] = a->valor;
        r++;
        r+=dumpAbin (a->dir, v+r, N-r);
    }

    return r;
}

//Exercicio 91: dada uma árvore de inteiros, calcula a árvore das somas acumuladas dessa árvore.
// A árvore calculada deve ter a mesma forma da árvore recebida como argumento e em cada nodo deve conter a soma dos elementos da sub-árvore que aí se inicia.
ABin somasAcA (ABin a) {
    ABin new=NULL;

    if(a != NULL){
        new=malloc(sizeof(struct nodo));
        new->esq = somasAcA(a->esq);
        new->dir = somasAcA(a->dir);
        new->valor = a->valor;

        if(new->esq != NULL)
            new->valor += new->esq->valor;
            
        if(new->dir != NULL)
            new->valor += new->dir->valor;
    }

    return new;
}

//Exercicio 92: dada uma árvore binária de inteiros, conta quantos dos seus nodos são folhas, i.e., que não têm nenhum descendente.
int contaFolhas (ABin a) {
    int r = 0;
    if (a != NULL){
        if (a->esq == NULL && a->dir == NULL)
            r++;
        else
            r+= contaFolhas (a->esq) + contaFolhas (a->dir);
        
    }
    return r;
}

//Exercicio 93: cria uma árvore nova, com o resultado de inverter a árvore (efeito de espelho)
ABin cloneMirror (ABin a) {
    if (a == NULL)
        return NULL;

    ABin copia = malloc (sizeof (struct nodo));
    copia->valor = a->valor;
    copia->esq = cloneMirror(a->dir);
    copia->dir = cloneMirror(a->esq);
    return copia;
}

//Exercicio 94: adiciona um elemento a uma árvore binária de procura. 
//A função deverá retornar "1" se o elemento a inserir já existir na árvore ou "0" no outro caso.
//NAO RECURSIVO
int addOrd (ABin *a, int x) {
    while((*a)!=NULL) {
        if((*a)->valor == x) 
            return 1;
            
        if((*a)->valor > x) 
            a = &((*a)->esq);
        else 
            a = &((*a)->dir);
    }
    
    ABin new = malloc(sizeof(struct nodo));
    new->valor = x;
    new->esq = new->dir = NULL;
    
    (*a) = new;

    return 0;
}

//Exercicio 95: testa se um elemento pertence a uma árvore binária de procura.
//NAO RECURSIVO
int lookupAB (ABin a, int x) {
    while (a != NULL ){
        if (a->valor == x)
            return 1;
        if (a->valor < x)
            a = a->dir;
        else
            a = a->esq;

    }
    return 0;
}

//Exercicio 96: calcula o nível a que um elemento está numa árvore binária de procura ("-1" caso não exista)
int depthOrd (ABin a, int x) {
    int nivel;

    for (nivel = 1; a != NULL; nivel++)
        if (a->valor == x)
            return nivel;
        else if (x > a->valor)
            a = a-> dir;
        else
            a = a->esq;

    return -1;
}

//Exercicio 97: calcula o maior elemento de uma árvore binária de procura não vazia
//NAO RECURSIVO
int maiorAB (ABin a) {
    if (a == NULL)
        return -1;
    else{
        while (a->dir != NULL)
            a=a->dir;
        return (a->valor);        
    }
}

//Exercicio 98: remove o maior elemento de uma árvore binária de procura.
void removeMaiorA (ABin *a) {
    if((*a)->dir == NULL) {
        free(*a);
        (*a) = (*a)->esq;
    }
    else
        removeMaiorA(&((*a)->dir));
}

//Exercicio 99: dada uma árvore binária de procura de inteiros e um inteiro, conta quantos elementos da árvore são maiores que o inteiro dado
int quantosMaiores (ABin a, int x) {
    if (a == NULL)
        return 0;
    else if ( a->valor <= x)
        return quantosMaiores(a->dir, x);
    else
        return 1 + quantosMaiores(a->dir, x) + quantosMaiores(a->esq, x);
}

//Exercicio 100: constrói uma árvore binária de procura a partir de uma lista ligada ordenada
int length (LInt l) {
    int r = 0;

    while (l != NULL) {
        l = l->prox;
        r++;
    }

    return r;
}

LInt avanca_p_posicoes (LInt l, int p) {
    while (p > 0) {
        l = l->prox;
        p--;
    }
    return l;
}

void fromList(LInt l, ABin *a, int N) {
    int r,p;
    LInt aux;

    if (N > 0) {
        *a = malloc(sizeof(struct nodo));
        p = N/2;
        aux = avanca_p_posicoes(l, p);
        (*a)->valor = aux->valor;
        fromList(l, &(*a)->esq, p);
        fromList(aux->prox, &(*a)->dir, N - p - 1);
    } 
    else
        *a = NULL;
}

void listToBTree (LInt l, ABin *a) {
    int N = length(l);
    fromList(l, a, N);
}

//Exercicio 101: testa se é uma arvore binaria de procura
//Testa se os elementos da subarvore esquerda sao menores do que a raiz
int is_menor (ABin a, int x) {
    int res = 1;
    if (a != NULL){
        res = a->valor > x    && 
        is_menor (a->esq, x)  && 
        is_menor (a->dir, x);
    }
    return res;
}
//Testa se os elementos da subarvore direita sao maiores do que a raiz
int is_maior (ABin a, int x) {
    int res = 1;
    if (a!=NULL) 
        res = a->valor < x          && 
              is_maior (a->esq, x)  && 
              is_maior (a->dir, x);
    
    return res;
}

int deProcura (ABin a) {
    int res = 1;
    
    if (a!=NULL) 
        res = is_maior (a->esq, a->valor) && 
              is_menor (a->dir, a->valor) && 
              deProcura (a->esq)          && 
              deProcura (a->dir);
        
    return res;
}