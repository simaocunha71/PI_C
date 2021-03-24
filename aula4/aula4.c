#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/***************************************** Funçoes sobre strings *****************************************/

int testaVogal (char c){
    return c == 'a' || c == 'A' ||
           c == 'e' || c == 'E' ||
           c == 'i' || c == 'I' ||
           c == 'o' || c == 'O' ||
           c == 'u' || c == 'U';
}


//Exercicio 1
int contaVogais_v1(char *s) {
    int r = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if (testaVogal(s[i]))
            r++;
    }
    return r;
}

int contaVogais_v2(char *s)
{
    int r = 0;
    while (*s){
        if (testaVogal(*s))
            r++;
        s++;
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

int duplicaVogais_v1 (char *s){
    char aux[50];
    int i, j = 0;
    int num_dupl = 0;

    for (i = 0; s[i] != '\0'; i++){
        if (testaVogal(s[i])){
            aux[j] = s[i];
            aux[j+1] = s[i];
            j+=2;
            num_dupl++;
        }
        else{
            aux[j] = s[i];
            j++;
        }
    }

    aux[j] = '\0';

    for (int j = 0; aux[j]!='\0'; j++)
        s[j] = aux[j];

    return num_dupl;
}

// a corrigir
int duplicaVogais_v2(char *s){
    int i=0,j,comp=0,vogais=0;
    vogais = 0;

    // Calcular tamanhos
    for (; s[i] != '\0'; i++){
        comp++; // tamanho de s
        if (testaVogal(s[i]))
            vogais++; // numero de vogais em s
    }

    //Processar a string
    i = comp -1;
    j = comp + vogais -1;

    while (i >= 0){
        if (testaVogal(s[i])){
            s[j] = s[i];
            j--;
            s[j] = s[i];
            j--;
        }
        else{
            s[j] = s[i];
            j--;
        }
        i--;
    }

    s[comp + vogais] = '\0';

    return vogais;
}

////////////////////////////// Extras //////////////////////////////////

/**
 * @brief Substitui todas as maiusculas pelas respetivas minusculas
 * 
 * @param s string
 * @return int Numero de alteraçoes feitas
 */
int minusculas (char s[]){
    int r = 0;
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32;
            r++;
        }
    }
    return r;
}

/**
 * @brief Conta o numero de linhas de uma string
 * 
 * @param s string
 * @return int numero de linhas
 */
int contalinhas (char s[]){
    int r = 0;
    int i;
    for (i = 0;s[i] != '\0'; i++){
        if (s[i] == '\n')
            r++;
    }
    if (s[i] == '\0') //ultimo caracter
        r++;
    return r;
}

/**
 * @brief Conta o numero de palavras numa string
 * 
 * @param s string
 * @return int Numero de palavras
 */
int contaPal (char s[]){
    int r = 0;
    int i;
    for (i = 0; s[i] != '\0'; i++){
        if (isspace (s[i]))
            r++;
    }
    if (s[i] == '\0') // ultimo caracter
        r++;
    return r;
}

/**
 * @brief Procura uma string p num array de strings ps
 * 
 * @param p string a procurar
 * @param ps array de strings
 * @param N tamanho do array de strings
 * @return int 1 se encontrou, 0 caso contrario
 */
int procura (char *p, char *ps[], int N){
    int i, bool = 0;

    for (i = 0; i < N; i++){
        if (strcmp (ps[i],p) == 0)
            bool = 1;
    }
    return bool;
}

/***************************************** Arrays ordenados *****************************************/

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

// Exercicio 2 - a corrigir 
void merge (int a[], int na, int b[], int nb, int r[]){
    int perc_r, perc_a, perc_b;
    perc_r = perc_a = perc_b = 0;

    while (perc_a < na && perc_b < nb){
        if (a[perc_a] > b[perc_b]){ // se elemento do array_a maior do que o elemento do array_b
            r[perc_r] = b[perc_b];  // preenche com o menor, ou seja, com o do array_b
            perc_b++;
        }
        else{
            r[perc_r] = a[perc_a]; //caso contrario, preenche com o do array_a
            perc_a++;
        }
        perc_r++;
    }

    // Caso o array_a seja totalmente utilizado
    while (perc_a == na && perc_b != nb){
        r[perc_r] = b[perc_b];
        perc_r++;
        perc_b++;
    }

    // Caso o array_b seja totalmente utilizado
    while (perc_a != na && perc_b == nb)
    {
        r[perc_r] = a[perc_a];
        perc_r++;
        perc_a++;
    }
}

int main (){
   
   char s[20] = "o simao e lindo";
   char *m[20] = {"ola", "o simao lindo", "o simao"};
   int r = duplicaVogais_v2(s);

   printf("numeros: %d\n", r);
   printf(" String 1 : %s\n",s);
   
   /*
   int v[6] = {1,5,12,-1,4,10};
   int v1[6] = {1,2,3,4,5,6};
   int b = ordenado(v,6);
   printf("bool: %d\n",b);
   */
   return 0;
}