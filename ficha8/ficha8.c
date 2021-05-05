#include <stdio.h>

typedef struct slist{
    int valor;
    struct slist *prox;
} * LInt;

typedef LInt Stack;

typedef struct {
    LInt inicio,fim;
} Queue;

LInt newLInt(int x, LInt xs){
    LInt r = malloc(sizeof(struct slist));
    if (r != NULL){
        r->valor = x;
        r->prox = xs;
    }
    return r;
}

//////////////////////// Exercicio 1 ////////////////////////
void initStack (Stack *s){
    *s = NULL;
}

int SisEmpty (Stack s){
    return (s == NULL);
}

//Insere o elemento x na cabeça da stack 
int push (Stack *s, int x){
    Stack aux;
    int r = 0;
    aux = newLInt(x,*s);
    if (aux == NULL)
        *s = aux;
    else
        r = 1;
    return r;
}

//Retira o elemento que está na cabeça da stack
int pop (Stack *s, int *x){
    Stack aux;
    int r = 0;
    if (SisEmpty(*s))
        r = 1;
    else{
        *x = (*s)->valor;
        aux = *s;
        *s = (*s)->prox;
        free(aux);
    }
    return r;
}

//Devolve o elemento que está na cabeça da stack
int top(Stack s, int *x){
    Stack aux;
    int r = 0;
    if (SisEmpty(s))
        r = 1;
    else
        *x = s->valor;
    return r;
}

//////////////////////// Exercicio 2 ////////////////////////
void initQueue (Queue *q){ // QUEUE é uma estrutura e nao um apontador
    (*q).inicio = (*q).fim = NULL;
}

int QisEmpty(Queue q){
    return (q.inicio == NULL);
}

// Adiciona o elemento no fim da queue
int enqueue (Queue *q, int x){
    LInt aux;
    int r = 0;
    aux = newLInt(x,NULL);

    if (aux != NULL){
        if (QisEmpty(*q)){
            (*q).inicio = aux;
            (*q).fim = aux;
        }
        else{
            (*q).fim->prox = aux;
            (*q).fim = aux;
        }
    }
    else 
        r = 1;
    return r;
}

// Remove o elemento do inicio da queue
int dequeue (Queue *q, int *x){
    int r = 0;
    LInt aux;
    if (QisEmpty(*q))
        r = 1;
    else{
        *x = (*q).inicio->valor;
        aux = (*q).inicio;
        (*q).inicio = (*q).inicio->prox;
        free(aux);
    }
    return r;
}

// Devolve o elemento no inicio da queue
int front (Queue q, int *x){
    int r = 0;
    if (QisEmpty(q))
        r = 1;
    else
        *x = q.inicio->valor;
    return r;   
}