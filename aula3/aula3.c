#include <stdio.h>

// Exercicio 2
void swapM(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

//Exercicio 3
void swap (int v[], int i, int j){
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

//Exercicio 4
int soma(int v[], int N){
    int r = 0;
    for (int i = 0; i < N; i++)
        r+=v[i];
    return r;
}

//Exercicio 5 -- errado
void inverteArray_v1(int v[], int N){
    int i = N;
    int j = 0;
    while (i >= j){
        swap(v,i,j);
        i--;
        j++;
    }
}

void printArray (int v[], int N){
    for (int i = 0; i < N; i++)
        printf("%d ",v[i]);
}

int main()
{
    int v[10] = {0,1,2,3,4,5,6,7,8,9};

    inverteArray_v1(v,10);

    printArray(v,10);
    return 0;
}