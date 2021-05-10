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
void imprimeNivel (ABin a, int l){
    if (a == NULL)
        printf("NULL ");
    else if (l == 1)
        printf("%d ",a->valor);
    else{
        imprimeNivel (a->esq,l-1);
        imprimeNivel (a->dir,l-1);
    }
}

//alinea (e) - testa se x ocorre na arvore. Nao assuma qualquer propriedade sobre a arvore a.
int procuraE (ABin a, int x){
    int r = 0;
    if (a == NULL || a->valor == x)
        r = 1;
    else
        return procuraE(a->esq,x) || procuraE(a->dir,x);
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

//alinea(b) - calcula o nivel a que o elemento ocorre na arvore (-1 caso nao exista) - CORRIGIR
int nivel (ABin a, int x){
    if (x == a->valor)
        return 0;
    else if (x > a->valor)
        return 1 + nivel(a->esq,x);
    else
        return 1 + nivel(a->dir,x);
    return -1;
}

//alinea(c) - e imprime no ecran, por ordem crescente, todos os elementos da arvore que sao (estritamente) menores do que um dado valor - CORRIGIR
void imprimeAte (ABin a, int x){
    if (a == NULL)
        return;
    if (a->valor < x){
        printf("%d ",a->valor);
        imprimeAte (a->esq,x);
        imprimeAte (a->dir,x);
    }
}
