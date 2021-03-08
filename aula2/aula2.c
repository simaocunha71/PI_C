#include <stdio.h>

// Exercicio 1
float multInt1(int n, float m)
{
    float r = 0;
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

// Exercicio 3

int mdc1 (int a, int b){
    int r = 0;
    int maior = a > b ? a:b;
    for (int i = 1; i <= maior; i++)
    {
        if (a % i == 0 && b % i == 0)
            r = i;
    }
    return r;
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

// Exercicio 5
int mdc3(int a, int b){
    return 0;
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

//Exercicio 6 -(b) -- ERRADO
int fib2(int n){
    int r = 0;
    int acc1, acc2;
    acc1 = acc2 = 1;

    for (int i = 3; i<=n; i++){
        r = r + acc1 + acc2;
        acc1 = i+1;
        acc2 = i+2;
    }

    return r;
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