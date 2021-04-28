#include <stdio.h>
#include <string.h>
typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
}*Palavras;

// Exercicio 1: liberta todo o espaço (da heap) ocupado pela lista de palavras
void libertaLista (Palavras l){
    Palavras aux;
    while (l != NULL){ // ou while (l){...}
        aux = l;
        free(aux); //liberta-se o nó atual
        l = l->prox;
    }
}

void libertaLista_rec (Palavras l){
    if (l != NULL){
        libertaLista_rec(l->prox); // começa a eliminar o ultimo nó
        free(l);
    }
}

// Exercicio 2: calcula quantas palavras (diferentes) existem armazenadas
int quantasP (Palavras l){
    int r = 0;
    while (l != NULL){
        r++;
        l=l->prox;
    }
    return r;
}

int quantasP_rec (Palavras l){
    if (l != NULL)
        return 1 + quantasP_rec(l->prox);
    else
        return 0;
}

// Exercicio 3: escreve no ecran, uma por linha, todas as palavras armazenadas, bem como o numero de ocorrencias
void listaPal(Palavras l){
    while (l != NULL){
        printf("Palavra: [%s] Ocorrencias: [%d]\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

// Exercicio 4: devolve a ultima palavra inserida na lista ligada
char* ultima (Palavras l){
    while (l != NULL){
        if (l->prox == NULL)
            return l->palavra;
        l = l->prox;
    }
    return NULL;
    /*
    while (l && l->prox)
        l=l->prox;
    return l ? l->palavra : NULL;
    */
}

// Exercicio 5: acrescenta uma palavra no inicio da lista (com 1 como numero de ocorrencias).
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras aux = malloc (sizeof(struct celula));
    aux->palavra = strdup(p); //alocar espaço para a string p
    aux->ocorr = 1;
    aux->prox = l;
    return aux;
}
/*DISCLAIMER: Como estamos a adicionar todos os elementos à cabeça, a primeira
string do array de strings irá ser a ultima string adicionada à lista*/

// Exercicio 6: acrescenta uma palavra no fim da lista (com 1 como numero de ocorrencias).
Palavras acrescentaFim(Palavras l, char *p){
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = strdup(p);
    new->ocorr = 1;
    new->prox = NULL;

    Palavras aux = l;

    //Encontra o ultimo elemento da lista
    while (l!=NULL && l->prox != NULL)
        l = l->prox;
    
    //Se a lista nao é vazia, insere o novo elemento na ultima posiçao
    if (l!=NULL){
        l->prox = new;
        return aux;
    }
    else //caso contrario, retorna uma lista apenas com o novo nó inserido
        return new;
}

// Exercicio 7: regista mais uma ocorrencia da palavra p.
// Se a palavra já existir, o numero de ocorrencias deve ser incrementado. 
// No outro caso deve ser inserida uma nova celula.
// A inserçao de uma nova celula pode ser feita no inicio da lista ou ordenadamente, assumindo
//que a lista está armazenada por ordem alfabetica.
Palavras acrescenta(Palavras l, char *p){
    if (l == NULL || strcmp(p,l->palavra) < 0)
        return acrescentaInicio(l,p); //insere à cabeça
    else{
        if (strcmp(p,l->palavra) == 0){
            l->ocorr++; // incrementa o numero de ocorrencias de uma palavra já existente
            return l;
        }
        else{
            l->prox = acrescenta(l->prox,p); //verifica as condiçoes para o proximo nodo
            return l;
        }
    }
}

// Exercicio 8: calcula a célula correspondente à palavra mais frequente. A CORRIGIR!
struct celula * maisFreq (Palavras l){
    int max = 0;
    Palavras res;
    while (l!=NULL){
        if (l->ocorr > max){
            max = l->ocorr;
            res = l;
        }
        l=l->prox;
    }
    return res;
}