#include <stdio.h>
#include <stdlib.h>

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
    int r = 0;
    if (a != NULL){
        if (a->esq == NULL && a->dir == NULL)
            r = 1;
        else
            r = nFolhas(a->esq) + nFolhas(a->dir);
    }
    return r;
}

//alinea (c) - calcula o nodo mais a esquerda de uma arvore
ABin maisEsquerda (ABin a){
    while (a != NULL && a->esq != NULL)
        a = a->esq;
    return a;
}

//alinea (d) -  escreve no ecran os elementos da arvore que estao ao nivel l (Considere que a raiz de uma arvore se encontra no nivel 0) 
void imprimeNivel (ABin a, int l){
    if (a == NULL)
        printf("NULL ");
    else if (l == 0)
        printf("%d ",a->valor);
    else{
        imprimeNivel (a->esq,l-1);
        imprimeNivel (a->dir,l-1);
    }
}
////////////////////////////////////////////////////////////////////////////////////////
/*
                                Travessias em árvores binárias

                 23
              /      \
            15         34
           / \        /  \ 
          6   18     29   45
              /       \
             16       31

inorder:    6 15 16 18 23 29 31 34 45
postorder:  6 16 18 15 31 29 45 34 23
preorder:  23 15  6 18 16 34 29 31 45 
*/

//Esq - Raiz - Dir
void inorder (ABin a){
    if (a!=NULL){
        inorder(a->esq);
        printf("%d ", a->valor);
        inorder(a->dir);
    }
}

//Raiz - Esq - Dir
void preorder (ABin a){
    if (a!=NULL){
        printf("%d ", a->valor);
        preorder(a->esq);
        preorder(a->dir);
    }
}

//Esq - Dir - Raiz
void postorder (ABin a){
    if (a!=NULL){
        postorder(a->esq);
        postorder(a->dir);
        printf("%d ", a->valor);
    } 
}

//Começar a libertar os nós pelas folhas (travessia postorder)
void freeABin (ABin a){
    if (a!=NULL){
        postorder(a->esq);
        postorder(a->dir);
        free(a);
    }  
}

////////////////////////////////////////////////////////////////////////////////////////

//alinea (e) - testa se x ocorre na arvore. Nao assuma qualquer propriedade sobre a arvore a.
int procuraE (ABin a, int x){
    int r = 0;
    if (a == NULL || a->valor == x)
        r = 1;
    else
        return procuraE(a->esq,x) || procuraE(a->dir,x);
}

int procuraE_v2 (ABin a, int x){
    int r = 0;
    if (a != NULL)
        r = a->valor == x || procuraE_v2(a->esq,x) || procuraE_v2(a->dir,x);
    return r;
}

//Exercicio 2
//alinea(a) - testa se x ocorre na arvore binaria de procura, devolvendo o nó onde ocorre (caso não seja possível, devolve NULL)
struct nodo *procura (ABin a, int x){
    if (a == NULL || a->valor == x)
        return a;
    else if (x > a->valor)
        return procura(a->dir,x);
    else
        return procura(a->esq,x);
}

ABin procura_v2 (ABin a, int x){
    ABin r;
    if (a == NULL || a->valor == x)
        r = a;
    else if (x > a->valor)
        r = procura_v2(a->dir,x);
    else
        r = procura_v2(a->esq,x);
    return r;
}

//alinea(b) - calcula o nivel a que o elemento ocorre na arvore (-1 caso nao exista) - CORRIGIR
int nivel (ABin a, int x){
    int n = -1;
    if (a == NULL)
        return -1;
    else if (x == a->valor)
        return 0;
    else{
        if (x > a->valor)
            n = nivel(a->dir,x);
        else
            n = nivel(a->esq,x);
        if(n==-1)
            return -1;
        else
            return 1+n;
     }
}

//alinea(c) - e imprime no ecran, por ordem crescente, todos os elementos da arvore que sao (estritamente) menores do que um dado valor - CORRIGIR
void imprimeAte (ABin a, int x){
    if (a == NULL)
        return;
    if (a->valor < x){
        imprimeAte(a->esq,x);
        printf("%d ",a->valor);
        imprimeAte(a->dir,x);
    }
    else
        imprimeAte(a->esq,x);
}
