#include <stdio.h>

// Exercicio 1
float multInt1(int n, float m)
{
    float r = 0.0;
    while (n > 0){
        r+=m;
        n--;
    }
    return r;
}

// Exercicio 2 
float multInt2 (int n, float m){
    int r = 0;
    while (n > 0){
        if (n % 2 == 1)
            r += m;
        n/=2;
        m*=2;
    }
    return r;
}

//
/**
 * @brief Multiplica 2 numeros e conta o nº de operaçoes entre floats realizadas
 * 
 * @param n Numero 1 a multiplicar
 * @param m Numero 2 a multiplicar
 * @param count Numero de operaçoes realizadas entre floats
 * @return float Retorna (r = n*m) e o numero de operaçoes entre floats
 */
float multInt2_contador(int n, float m, int* count)
{
    *count = 0; // "o apontado de count é zero"
    int r = 0;
    while (n > 0)
    {
        if (n % 2 == 1){
            r += m;
            (*count)++;
        }
        n /= 2;
        m *= 2;
    }
    return r;
}

/**
 * @brief Troca o valor de 2 inteiros
 * 
 * @param a Valor 1 a trocar
 * @param b Valor 2 a trocar
 */
void swap (int *a, int *b)
{ // swap (&a,&b); -> forma de invocar
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}
// Exercicio 3
int mdc1 (int a, int b){
    int divisor;
    if (a < b)
        divisor = a;
    else
        divisor = b;

    while (((a%divisor != 0)||(b%divisor!=0))
             &&(divisor>1))
        divisor--;
    return divisor;
}


// Exercicio 4
int mdc2(int a, int b){
    int r=0;
    if (a>b)
        r+=mdc2(a-b,b);
    else if (a<b)
        r+=mdc2(a,b-a);
    else
        r+=a;
    
    return r;
}

int mdc3(int a, int b, int*count){
    while (a != b){
        if (a<b)
            b-=a;
        else 
            a-=b;
        (*count)++;
    }
    return a;
}

//Extra 
int mdc_extra(int a, int b){
    int r = 0;
    int maior = a > b ? a : b;
    for (int i = 1; i <= maior; i++)
    {
        if (a % i == 0 && b % i == 0)
            r = i;
    }
    return r;
}

//Exercicio 6 -(a)
int fib1 (int n){
    int r = 0;

    if (n < 2)
        r++;
    else
        r = r + fib1(n-1) + fib1(n-2);

    return r;
}

//Exercicio 6 -(b) 
int fib2(int n){
    int temp, acc1, acc2;
    acc1 = acc2 = 1;

    for (int i = 3; i<=n; i++){
        temp = acc2;
        acc2 += acc1;
        acc1 = temp;
    }

    return acc2;
}



int main()
{
    int i = 10;

    int x = fib1 (i);
    int r = fib2 (i);

    printf("Fib1: %d\n",x);
    printf("Fib2: %d\n",r);

    return 0;
}