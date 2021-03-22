#include <stdio.h>

/* Funçoes sobre strings */

//Exercicio 1
int contaVogais(char *s) {
    int r = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == 'a' || s[i] == 'A' ||
            s[i] == 'e' || s[i] == 'E' ||
            s[i] == 'i' || s[i] == 'I' ||
            s[i] == 'o' || s[i] == 'O' ||
            s[i] == 'u' || s[i] == 'U')
            r++;
    }
    return r;
}

//Exercicio 2



/* Arrays ordenados */

// Exercicio 1
int ordenado(int v[], int N)
{
    int bool = 1;
    for (int i = 0; i < N; i++)
    {
        if (v[i] > v[i + 1])
            bool = 0;
    }
    return bool;
}

// Exercicio 2


int main (){
   // char* s = "abcAbcgeFg";
   // int r = contaVogais(s);
   // printf("numero de vogais: %d\n", r);
    
    int v[6] = {1,5,12,-1,4,10};
    int v1[6] = {1,2,3,4,5,6};
    int b = ordenado(v,6);
    printf("bool: %d\n",b);
    
    return 0;
}