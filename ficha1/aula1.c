#include <stdio.h>
// Aula1 PI

// Função que desenha um quadrado
void imprime_quadrado (int x){
    int i,j;
    for (i=0;i<x;i++){
        for (j=0;j<x;j++){
            putchar ('#');
        }
    printf ("\n");
    }
}

//Função que desenha um tabuleiro de xadrez
void imprime_xadrez (int x){
    int i,j;
    for (i=0;i<x;i++){
        for (j=0;j<x;j++){
            if (((j+i)%2)==0)
                printf("#");
            else
                printf("_");
        }
    printf ("\n");
    }
}

/* Raio 4
    #
  #####
 #######
 #######
#########
 #######
 #######
  #####
    #
*/

// Função que calcula a^b 
int pow_aux(int a, int b)
{
    int r = 1;
    for (; b > 0; b--)
    {
        r *= a;
    }
    return r;
}

int imprime_circulo (int x){
    int i, j;
    int nc = 0;
    for (i = 0; i <= 2 * x +1; i++)
    {
        for (j = 0; j <= 2 * x +1; j++)
        {
            if (pow_aux(i - x - 1, 2) + pow_aux(j - x - 1, 2) <= pow_aux(x, 2))
            {
                printf("#");
                nc++;
            }
            else
                printf (" ");
        }
        printf("\n");
    }
    return nc;
}

int main (){
    int x;
    int nc;
    scanf("%d", &x);
    //imprime_quadrado (x);
    //imprime_xadrez (x);
    nc = imprime_circulo(x);
    printf ("Existem %d simbolos.\n",nc);
    return 0;
}