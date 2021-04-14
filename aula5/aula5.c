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
    r=r * 10 / 6;
    return r;
}

/**
 * @brief Dada uma struct aluno, calcula a nota final
 * 
 * @param a Struct aluno
 * @return int Nota final
 */
int nota(Aluno a){
    int notaM = notaMiniTestes(a.miniT); // nao escrever a.miniT[6], dá erro
    int r = notaM*0.3 + a.teste * 0.7;

    if (notaM >= 8.0 && a.teste >= 8.0 && r >= 9.5)
        return r;
    else
        return 0;
}

//////////////////////////////////////////// Exercicio 2 ////////////////////////////////////////////

/**
 * @brief Retorna o indice do aluno do array t cujo numero é igual a num. Aproveita o facto de t estar ordenado
 * @param num Numero e verificar
 * @param t Array de alunos
 * @param N Tamanho do array de alunos
 * @return int Indice do aluno
 */
int procuraNum (int num, Aluno t[], int N) {
    int i = 0;
    int res = -1;
    while(i < N){
        if (t[i].numero == num) res = i;
        else if (t[i].numero < num) i = N;
        i++;
    }
    return res;
}

//////////////////////////////////////////// Exercicio 3 ////////////////////////////////////////////

/**
 * @brief Devolve o numero de um aluno
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
/*
------ Algoritmo bubbleSort ------
void ordenaPorNum (Aluno t [], int N){
    int p;
    int trocas = 1;
    Aluno aux;

    while(trocas){
       trocas = 0;
       p = 0;
       while(p < N-1){
           if(t[p].numero > t[p+1].numero) {
                aux = t[p];
                t[p] = t[p+1];
                t[p+1] = aux;
                trocas = 1;
            }
           p++;
       }
   }
}
*/

//////////////////////////////////////////// Exercicio 4 ////////////////////////////////////////////

/**
 * @brief Copia o array t1 para t2
 * @param t1 Array original
 * @param t2 Array copia
 * @param N Tamanho do array t1
 */
void copia(Aluno t1[], Aluno t2[], int N){
    for (int i = 0; i < N; i++){
        t2[i].numero = t1[i].numero;
        strcpy(t2[i].nome, t1[i].nome);
        for (int j = 0; j < 6; j++)
            t2[i].miniT[j] = t1[i].miniT[j];
        t2[i].teste = t1[i].teste;
    }
}

/**
 * @brief Inicializa o array ind a 0 
 * @param ind Array a inicializar
 * @param N Tamanho do array
 */
void init_ind(int ind[], int N){
    for (int i = 0; i < N; i++)
        ind[i] = 0;
}

/**
 * @brief Preenche o array ind com os indices do array t consoante uma ordenaçao por numero de aluno
 * @param t Array de alunos
 * @param N Tamanho do array aluno
 * @param ind Array de indices 
 */
void criaIndPorNum(Aluno t[], int N, int ind[]){
    Aluno aux[N];

    copia(t, aux, N);
    init_ind(ind, N);

    ordenaPorNum(aux, N);

    for (int k = 0; k < N; k++){
        int indice = procuraNum(t[k].numero, aux, N);
        ind[indice] = k;
    }
}

//////////////////////////////////////////// Exercicio 5 ////////////////////////////////////////////

/**
 * @brief Dado um aluno, imprime os seus dados
 * @param a Aluno a imprimir
 */
void print_aluno (Aluno a){
    printf("Nome: %s (nº%d) | Teste: %f | Minitestes: ", a.nome, a.numero, a.teste);
    for (int i = 0; i < 6; i++)
        printf("%d ", a.miniT[i]);
    printf("\n");
}

/**
 * @brief Dados um array de alunos e um array de indices que resulta da ordenação do array de alunos,
 * imprime a turma, tendo em conta os indices do array ind
 * @param ind Array de indices que resulta da ordenaçao de t
 * @param t Array de alunos
 * @param N Tamanho do array de alunos
 */
void imprimeTurmaInd(int ind[], Aluno t[], int N){
    for (int i = 0; i < N; i++){
        int indice_a_imprimir = ind[i];
        print_aluno(t[indice_a_imprimir]);
    }
}

//////////////////////////////////////////// Exercicio 6 ////////////////////////////////////////////
int procuraNum_com_Ind (int ind[], int num, Aluno t[], int N){
    return procuraNum(num,t,N);
}

//////////////////////////////////////////// Exercicio 7 ////////////////////////////////////////////

// Copia t1 para t2
void copia(Aluno t1[], Aluno t2[], int N){
    int i,j;
    for (i = 0; i < N; i++){
        t2[i].numero = t1[i].numero;
        strcpy(t2[i].nome, t1[i].nome);
        for (j = 0; j < 6; j++)
            t2[i].miniT[j] = t1[i].miniT[j];
        t2[i].teste = t1[i].teste;
    }
}

//Inicializa ind
void init_ind(int ind[], int N){
    int i;
    for (i = 0; i < N; i++)
        ind[i] = 0;
}

//Calcula o indice da maior string nome lexicografica
int maxInd(Aluno t[], int N){
    int i, r = 0;
    for (i = 1; i < N; i++){
        if (strcmp (t[i].nome ,t[r].nome) > 0)
            r = i;
    }
    return r;
}

//Troca 2 alunos
void swap(Aluno t[], int i, int j){
    Aluno temp = t[i];
    t[i] = t[j];
    t[j] = temp;
}

//Ordenar array t por nome (maxSort)
void ordenaPorNome(Aluno t[], int N){
    int x, indiceMaior;
    for (x = N; x > 0; x--){
        indiceMaior = maxInd(t, x);
        swap(t, x - 1, indiceMaior);
    }
}

//Dado um nome, devolve o indice onde esse nome ocorre
int procuraNome (char* nome, Aluno t[], int N){
    int i;
    for (i = 0; i < N; i++){
        if (strcmp (nome,t[i].nome) == 0)
            return i;
    }
    return -1;
}

//Preenche o array ind com a ordenação de t de acordo com o seu valor lexicografico 
void criaIndPorNome(Aluno t[], int N, int ind[]){
    Aluno aux[N];

    copia(t, aux, N);
    init_ind(ind, N);

    ordenaPorNome(aux, N);
    
    int k,indice;
    
    for (k = 0; k < N; k++){
        indice = procuraNome(t[k].nome, aux, N);
        ind[indice] = k;
    }
}