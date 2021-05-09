#include <stdio.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}

//Exercicio 1 

//alinea (a) - Calcula a altura de uma árvore binária

int max (int i, int j){
    return i > j ? i : j;
}

int altura (ABin a){
    if (a == NULL)
        return 0;
    else 
        return 1 + max (altura (a->esq),altura(a->dir));
}

//alinea (b) - calcula o numero de folhas (i.e., nodos cujas sub-arvores sao ambas vazias).
int nFolhas (ABin a){
    if (a == NULL)
        return 0;
    else if (a->esq == NULL || a->dir == NULL)
        return 1;
    else
        return 1 + nFolhas (a->esq) + nFolhas (a->dir);
}

//alinea (c) - calcula o nodo mais a esquerda de uma arvore
ABin maisEsquerda (ABin a){
    while(a != NULL){
        if (a->esq == NULL) 
            break;
        a=a->esq;
    } 
    return a;
}

//alinea (d) -  escreve no ecran os elementos da arvore que estao ao nivel l (Considere que a raiz de uma arvore se encontra no nivel 0) 
