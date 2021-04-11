#include <stdio.h>
#include <string.h>

typedef struct aluno{
    int numero;
    char nome[100];
    int miniT[6];
    float teste;
} Aluno;

//////////////////////////////////////////// Exercicio 1 ////////////////////////////////////////////

/**
 * @brief Calcula a nota obtida na componente dos minitestes (0 a 20)
 * 
 * @param miniT Array com as notas dos minitestes
 * @return int Nota de 0 a 20 obtida
 */
int notaMiniTestes(int miniT[6]){
    int i , r = 0;
    for (i = 0; i < 6; i++)
        r += miniT[i];
    r*=2;
    return r;
}

/**
 * @brief Dada uma struct aluno, calcula a nota final
 * 
 * @param a Struct aluno
 * @return int Nota final
 */
int nota(Aluno a){
    int r = 0.0;
    int notaM = notaMiniTestes(a.miniT); // nao escrever a.miniT[6], dá erro
    r = r + notaM*0.3 + a.teste * 0.7;

    if (notaM >= 8.0 && a.teste >= 8.0 && r >= 9.5)
        return r;
    else
        return 0;
}

//////////////////////////////////////////// Exercicio 2 ////////////////////////////////////////////

/**
 * @brief Verifica se um dado numero n é igual ao numero de aluno
 * @param n numero
 * @param a numero de aluno
 * @return int 1 de sao iguais, 0 caso contrário
 */
int igualNumero (int n, Aluno a){
    int bool = 0;
    if (n == a.numero)
        bool = 1;
    return bool;
}

int procuraNum (int num, Aluno t[], int N){
    int i;
    for (i = 0; i < N; i++){
        if (igualNumero (num,a))
            return i;
    }
    return -1;
}

//////////////////////////////////////////// Exercicio 3 ////////////////////////////////////////////

/**
 * @brief Devolve o numero de um aluno
 * 
 * @param a Struct a
 * @return int Numero de aluno
 */
int devolveNumero (Aluno a){
    return a.numero;
}

/**
 * @brief Calcula o indice do maior elemento
 * 
 * @param t Array de alunos
 * @param N Tamanho d array de alunos
 * @return int Indice do maior elemento
 */
int maxInd (Aluno t[], int N) {
    int i,r = 0;
    for(i = 1; i < N; i++){
        if(devolveNumero (t[i]) > devolveNumero(t[r]))
            r = i;
    }
    return r;
}

/**
 * @brief Troca 2 valores entre i e j num array de alunos
 * 
 * @param t array de alunos
 * @param i posiçao i
 * @param j posiçao j
 */
void swap(Aluno t[], int i, int j) {
    Aluno temp = t[i];
    t[i] = t[j];
    t[j] = temp;
}

/**
 * @brief Ordenar um array de alunos conforme o seu numero de aluno
 * 
 * @param t Array de alunos
 * @param N Tamanho do array de alunos
 */
void ordenaPorNum(Aluno t[], int N){
    int x,indiceMaior;
    for(x = N; x > 0; x--) {
        indiceMaior = maxInd(t,x);
        swap(t,x-1,indiceMaior);
    }
}

//////////////////////////////////////////// Exercicio 4 ////////////////////////////////////////////



