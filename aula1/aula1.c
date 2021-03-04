#include <stdio.h>
#include <math.h>
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
int imprime_circulo (int x){
    int i, j;
    int nc = 0;
    for (i = 0; i < 2 * x +1; i++)
    {
        for (j = 0; j < 2 * x +1; j++)
        {
            if (pow(i-x-1,2) + pow (j-x-1,2) <= pow (x,2)){
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
    printf ("%d",nc);
    return 0;
}