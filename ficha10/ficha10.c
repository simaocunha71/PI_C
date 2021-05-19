#include <stdio.h>

typedef struct nodo{
    int valor;
    struct nodo *esq, *dir;
} * ABin;

//Exercicio 1

//alinea (a) - remove o nodo mais à esquerda de uma  ́arvore (retornando esse nodo)
ABin removeMenor (ABin *a){
    ABin res = NULL;
    //Descobre o elemento mais à esquerda da árvore binária
    while((*a)->esq != NULL && *a != NULL)
        a = &((*a)->esq);
    res = *a;
    //apontador para o valor apagado 
    //passa a ser o apontador o valor mais à direita do valor apagado
    *a = (*a)->dir;
    return res;
}

//alinea (b) - remove a raiz de uma arvore nao vazia (libertando o correspondente espaço)
void removeRaiz (ABin *a){
    ABin menorValor;
    if (*a != NULL){
        menorValor = removeMenor ((&(*a)->dir)); 
        if (menorValor != NULL){
            //menor valor da subárvore direita (nova raiz) existe
            menorValor->esq = (*a)->esq;
            menorValor->dir = (*a)->dir;
            free(*a);//liberta raiz antiga
            *a = menorValor;
        }
        else{
            //primeiro elemento da subarvore esquerda é a nova raiz
            menorValor = *a;
            *a = (*a)->esq;
            free(menorValor);
        }
    }
}

//alinea (c) - remove um elemento de uma ́arvore binaria, libertando o espaço correspondente. A funçao deverá retornar 0 se o elemento existia na ́arvore
int removeElem (ABin *a, int x){
    int r = -1;
    if (*a != NULL){
        if ((*a)->valor == x){
            removeRaiz(a);
            r = 0;
        }
        else if ((*a)->valor < x)
            r = removeElem(&((*a)->dir),x);
        else 
            r = removeElem(&((*a)->esq),x);
    }
    return r;
}

//Exercicio 2

//alinea (a) - promove o menor elemento de uma arvore para o nivel 0. A ́arvore resultante nao deve aumentar a altura da arvore em mais do que uma unidade.
void promoveMenor (ABin *a){
    if (*a != NULL && (*a)->esq != NULL){
        promoveMenor(&((*a)->esq));
        rodaDireita(a);
    }
}

//alinea (b) - promove o maior elemento de uma arvore para o nivel 0. A ́arvore resultante nao deve aumentar a altura da arvore em mais do que uma unidade.
void promoveMaior (ABin *a){
    if (*a != NULL && (*a)->dir != NULL){
        promoveMaior(&((*a)->dir));
        rodaEsquerda(a);
    }   
}

//alinea (c) - definição alternativa da função removeMenor descrita na questão 1
ABin removeMenorAlt (ABin *a){
    ABin r = NULL;
    promoveMenor(a);
    r = *a;
    *a = (*a)->dir;
    return r;
}
