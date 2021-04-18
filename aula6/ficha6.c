#include <stdio.h>
////////////////////////////////////////  Exercicio 1  ////////////////////////////////////////
struct staticStack {
    int sp;
    int values [Max];
} STACK, *SStack;

// alinea (a)
void SinitStack (SStack s){
    s->sp = 0;
}

// alinea (b)
int SisEmpty (SStack s){
    return s->sp == 0;
}

// alinea (c)
int Spush (SStack s, int x){
    s->sp++;
    if (s->sp == Max)
        return 1;
    else{
        s->values[s->sp] = x;
        return 0;
    }
}

// alinea (d)
int Spop (SStack s, int *x){
    if (s->sp - 1 == 0)
        return 1;
    else{
        *x = s->values[s->sp];
        s->sp--;
        return 0;
    }
}

// alinea (e)
int Stop (SStack s, int *x){
    if (s->sp == 0)
        return 1;
    else{
        *x = s->values[s->sp];
        return 0;
    }
}

////////////////////////////////////////  Exercicio 2  ////////////////////////////////////////
struct staticQueue {
    int front;
    int length;
    int values [Max];
} QUEUE, *SQueue;

// alinea (a)
void SinitQueue (SQueue q){
    q->length = 0;
}

// alinea (b)
int SisEmptyQ (SQueue q){
    return q->length == 0;
}

// alinea (c)
int Senqueue (SQueue q, int x){
    if(q->front + q->length >= Max) 
        return 1;
    else {
        q->values[q->front + q->length + 1] = x;
        q->length++;
        return 0;
    }
}

// alinea (d)
int Sdequeue (SQueue q, int *x){
    if (q->length == 0)
        return 1;
    else{
        *x = q->values[q->front + 1];
        (q->length)--;
        return 0;
    }
}

// alinea (e)
int Sfront (SQueue q, int *x){
    if(q->length == 0) 
        return 1;
    else {
        *x = q->valores[q->front];
        return 0;
    }
}

////////////////////////////////////////  Exercicio 3  ////////////////////////////////////////
typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

void DinitStack(DStack s){

}

int DisEmpty(DStack s){

}

int Dpush(DStack s, int x){

}

int Dpop(DStack s, int *x){

}

int Dtop(DStack s, int *x){

}

typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;

int DisEmptyQ(DQueue q){

}

int Denqueue(DQueue q, int x){

}

int Ddequeue(DQueue q, int *x){

}

int Dfront(DQueue q, int *x){

}