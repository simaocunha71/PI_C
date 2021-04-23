#include <stdio.h>
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
