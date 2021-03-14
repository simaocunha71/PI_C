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

//Exercicio 5 
void inverteArray_v1(int v[], int N){
    int i = N;
    int j = 0;
    while (j < i){
        swap(v,i,j);
        i--;
        j++;
    }
}

void inverteArray_v2(int v[], int N){
    int i = N - 1;
    int j = 0;
    while (j < i)
    {
        swapM(&v[i], &v[j]);
        i--;
        j++;
    }
}

//Exercicio 6
int maximum (int v[], int N, int *m){
    *m = v[0];
    if (N > 0)
    {
        for (int i = 1; i < N; i++)
            if (*m < v[i])
                *m = v[i];
        return 0;
    }
    else
        return -1;
}

//Exercicio 7
void quadrados (int q[], int N){
    for (int i = -1; i < N-1; i++){
        int r = i * i + (2 * i + 1);
        q[i+1] = r;
    }
}

//Exercicio 8 -(a)
void pascal (int v[], int N){
    if (N==1)
        v[0] = 1;
    else{
        int aux[N-1];
        pascal (aux,N-1);
        v[0] = v[N-1] = 1;
        for (int i = 1; i < N-1; i++)
            v[i] = aux[i-1]+aux[i];
    }
}

//Exercicio 8 -(b)

void desenha_trianguloPascal (int v[],int N){
    if (N == 1){
        v[0]=1;
        printf("%d \n",v[0]);
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            pascal(v, i);
            for (int j = 0; j < i; j++)
                printf("%d ", v[j]);
            printf("\n");
        }
    }
}
