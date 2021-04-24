#include <stdio.h>
typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
}*Palavras;

// Exercicio 1: liberta todo o espaço (da heap) ocupado pela lista de palavras
void libertaLista (Palavras l){
    Palavras aux;
    while (l != NULL){
        aux = l;
        free(aux);
        l = l->prox;
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

// Exercicio 3: escreve no ecran, uma por linha, todas as palavras armazenadas, bem como o numero de ocorrencias
void listaPal(Palavras l){
    while (l != NULL){
        printf("Palavra: [%s] Ocorrencias: [%d]\n", l->palavra, l->ocorr);
        l = l->prox;
    }
}

// Exercicio 4: devolve a ultima palavra inserida na lista ligada
char* ultima (Palavras l){
    char* res = NULL;
    while (l != NULL){
        if (l->prox == NULL)
            res = l->palavra;
        l = l->prox;
    }
    return res;
}

// Exercicio 5: acrescenta uma palavra no inicio da lista (com 1 como numero de ocorrencias).
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras aux = malloc (sizeof(struct celula));
    aux->palavra = p;
    aux->ocorr = 1;
    aux->prox = l;
    return aux;
}

// Exercicio 6: acrescenta uma palavra no fim da lista (com 1 como numero de ocorrencias).
Palavras acrescentaFim(Palavras l, char *p){
    Palavras fim = l;
    while (fim->prox != NULL)
        fim = fim->prox;

    Palavras inicio = malloc(sizeof(struct celula));
    inicio->palavra = p;
    inicio->ocorr = 1;
    
    fim->prox = inicio;
    
    return l;
}

// Exercicio 7: regista mais uma ocorrencia da palavra p.
// Se a palavra já existir, o numero de ocorrencias deve ser incrementado. 
// No outro caso deve ser inserida uma nova celula.
// A inserçao de uma nova celula pode ser feita no inicio da lista ou ordenadamente, assumindo
//que a lista está armazenada por ordem alfabetica.
Palavras acrescenta(Palavras l, char *p){

}

// Exercicio 8: calcula a célula correspondente à palavra mais frequente. A CORRIGIR!
struct celula * maisFreq (Palavras l){
    int max = 0;
    Palavras res = malloc (sizeof(struct celula));
    
    while (l != NULL){
        if (l->ocorr > max){
            max = l->ocorr;
            res = l;
        }
        l = l->prox;
    }
    return res;
}