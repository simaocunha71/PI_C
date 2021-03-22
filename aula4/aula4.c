#include <stdio.h>
#include <string.h>

/* Funçoes sobre strings */

int testaVogal (char s){
    return s == 'a' || s == 'A' ||
           s == 'e' || s == 'E' ||
           s == 'i' || s == 'I' ||
           s == 'o' || s == 'O' ||
           s == 'u' || s == 'U';
}


//Exercicio 1
int contaVogais(char *s) {
    int r = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if (testaVogal(s[i]))
            r++;
    }
    return r;
}

//Exercicio 2

//Usa um array auxiliar aux
int retiraVogaisRep_v1 (char *s){
    char aux[50];
    int i,j=0;
    for (i=0; s[i] != '\0'; i++){
        if (testaVogal(s[i])){
            if (s[i] != s[i+1]){
                aux[j] = s[i];
                j++;
            }           
        }
        else
        {
            aux[j] = s[i];
            j++;
        }
        
    }
    aux[j] = '\0';
    strcpy (s,aux);

    return i-j;
}

//nao usa nenhum array auxiliar
int retiraVogaisRep_v2(char *s)
{
    int i, j = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (testaVogal(s[i]))
        {
            if (s[i] != s[i + 1])
            {
                s[j] = s[i];
                j++;
            }
        }
        else
        {
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';

    return i - j;
}

//Exercicio 3
// a corrigir
int duplicaVogais (char *s){
    char aux[50];
    int r = 0;
    int i, j = 0;
    for (i = 0; s[i] != '\0'; i++){
        if (testaVogal(s[i])){
            aux[j] = s[i];
            aux[j+1] = s[i];
            j++;
            r++;

        }
        else{
            aux[j] = s[i];
            j++;
        }
    }

    aux[j] = '\0';
    strcpy(s, aux);
    printf("dentro: %s\n",aux);

    return r;
}















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
   char s[50] = "tass a trrollar cunha";
   int r = duplicaVogais(s);

   printf("vogais duplicadas: %d\n", r);
   printf(" String 1 : %s\n",s);
   
   // int v[6] = {1,5,12,-1,4,10};
    //int v1[6] = {1,2,3,4,5,6};
    //int b = ordenado(v,6);
    //printf("bool: %d\n",b);
    
    return 0;
}