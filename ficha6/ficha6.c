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
    if (s->sp == Max)
        return 1;
    else{
        s->sp++;
        s->values[s->sp] = x;
        return 0;
    }
}

// alinea (d)
int Spop (SStack s, int *x){
    if (s->sp == 0)
        return 1;
    else{
        s->sp--;
        *x = s->values[s->sp];
        return 0;
    }
}

// alinea (e)
int Stop (SStack s, int *x){
    if (s->sp == 0)
        return 1;
    else{
        *x = s->values[s->sp - 1];
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
    q->front  = 0;
}

// alinea (b)
int SisEmptyQ (SQueue q){
    return q->length == 0;
}

// alinea (c)
int Senqueue (SQueue q, int x){
    if(q->length == Max) 
        return 1;
    else {
        int pos = (q->front + q->length)%10;
        q->values[pos] = x;
        q->length++;
        return 0;
    }
}

// alinea (d)
int Sdequeue (SQueue q, int *x){
    if (q->length == 0)
        return 1;
    else{
        *x = q->values[q->front];
        q->length--;
        q->front = (q->front + 1) % Max;
        return 0;
    }
}

// alinea (e)
int Sfront (SQueue q, int *x){
    if (q->length == 0)
        return 1;
    else{
        *x = q->values[q->front];
        return 0;
    }
}

////////////////////////////////////////  Exercicio 3  ////////////////////////////////////////
typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

/**
 * @brief Duplica o tamanho de uma stack dinâmica 
 * @param s Stack a alterar
 * @return int 0 se correu como esperado, 1 caso contrário
 */
int dupStack (DStack s) {
	int r = 0, i;
	int *t = malloc (2*s->size*sizeof(int));

	if (t == NULL) r = 1;
	else {
		for (i=0; i<s->size; i++) 
			t[i] = s->values[i];
		free (s->values);
		s->values = t;
		s->size*=2;
	}
	return r;
}

void DinitStack(DStack s){
    s->sp = 0;
    s->size = Max;
}

int DisEmpty(DStack s){
    return s->sp == 0;
}

int Dpush(DStack s, int x){
    int r = 0;
    if (s->sp == s->size){
        r = dupStack(s);
        if (!r){
            s->values[s->sp] = x;
            s->sp++;
        }
    }
    else{
        s->values[s->sp] = x;
        s->sp++;
    }
    return r;
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