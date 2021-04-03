#include <stdio.h>
//https://github.com/jjgonc/PI_2019-2020/blob/main/50questoes.c

// 1: Programa que lê sequencia de numeros terminadas em 0 e imprime o maior elemento
void maior (){
    int valorLido, maior;
    scanf("%d", &valorLido);
    maior = valorLido;

    while (valorLido != 0)
    {
        scanf("%d", &valorLido);
        if (valorLido > maior)
            maior = valorLido;
    }

    printf("O maior valor é: %d.\n", maior);
}

//2:  Programa que lê sequencia de numeros terminadas em 0 e imprime a media
void media()
{
    int soma, valorLido, n = soma = 0;

    while (valorLido != 0)
    {
        scanf("%d", &valorLido);
        soma += valorLido;
        n++;
    }

    float media = (float)soma/n;

    printf("A média dos valores é: %0.5f.\n", media);
}

//3: Programa que lê sequencia de numeros terminadas em 0 e imprime o segundo elemento
void segundoMaior()
{
    int numMaior = -1;
    int segNumMaior = -1;
    int num;

    while (123) //ciclo infinito
    {
        scanf("%d", &num);
        if (num == 0)
            break;
        if (num > numMaior)
        {
            segNumMaior = numMaior;
            numMaior = num;
        }
        else if (num > segNumMaior)
            segNumMaior = num;
    }

    printf("Segundo Maior: %d\n", segNumMaior);
}

//4: Calcula o numero de bits iguais a 1 na representaçao binária do número x
int bitsUm(unsigned int x)
{
    int i = 0;
    while (x > 0)
    {
        if (x % 2 != 0)
            i++;
        x = x / 2;
    }
    return i;
}

//5:  Calcula o numero de bits a 0 no final da representação binária do número n
// Por exemplo: trailingZ (16) = 4, pois 16 = 10000 (em binario)
int trailingZ(unsigned int n)
{
    int r = 0;
    if (n == 0)
        r = 32;

    while (n > 0)
    {
        if (n % 2 == 0)
            r++;
        n = n / 2;
    }
    return r;
}

// 6: Calcula o numero de digitos necessários para escrever n em base decimal
int qDig(int n)
{
    int r = 0;

    while (n > 0)
    {
        r++;
        n = n / 10;
    }
    return r;
}

//7: Concatena 2 strings
char *mystrcat(char s1[], char s2[]) {
    int i,j;
    for (i = 0; s1[i] != '\0'; i++);
    for (j = 0; s2[j] != '\0'; j++)
        s1[i+j] = s2[j];
    s1[i+j] = '\0';
    return s1;
}

//8: Copia 2 strings
char *mystrcpy(char s1[], const char s2[]) {
    int i;
    for (i=0; s2[i] != '\0'; i++)
        s1[i] = s2[i];
    s1[i] = '\0';
    return s1;
}

//9: Compara lexicograficamente 2 strings
int mystrcmp(char s1[], char s2[]) {
    int i;
    
    // Calcula o numero de caracteres iguais, guardando o valor em i
    for (i = 0; s1[i]!='\0' &&
                s2[i]!='\0' && 
                s1[i]==s2[i]; 
                              i++);
    
    //Subtração entre o ultimo caractere igual comum às 2 strings
    return (s1[i]-s2[i]);
}

//10: Calcula a string comum às 2 (a contar da esquerda para a direita)
char *mystrstr (char s1[], char s2[]){
    int i= 0;
    int j= 0;
    
    while(s1[i] != '\0' && s2[j] != '\0'){
        if(s1[i]== s2[j]) 
            j++; // numero de caracteres iguais
        else 
            j= 0; // nao existem caracteres iguais
        i++;
    }
    
    if(s2[j] == '\0')
        return &(s1[i - j]); //apenas fica na string resultado os caracteres comuns consecutivos às 2 strings
    else 
        return NULL;
}

//11: Inverte um array
void strrev(char s[]){
    int size,i;
    
    for(size = 0; s[size] != '\0'; size++);
    
    char aux[size];
    
    for(i = 0; i < size; i++) 
        aux[i] = s[size - i - 1]; //aux é um array inverso de s (s ainda inalterado)
    
    for(i = 0; i < size; i++) 
        s[i] = aux[i]; // s está invertido 
}

//12: Retira as vogais duma string 
void strnoV (char t[]){
    int i;
    int c = 0;
    
    for (i = 0; t[i] != '\0'; i++){
        if (t[i] == 'a'|| t[i] == 'A'||
            t[i] == 'e'|| t[i] == 'E'||
            t[i] == 'i'|| t[i] == 'I'||
            t[i] == 'o'|| t[i] == 'O'||
            t[i] == 'u'|| t[i] == 'U')
            c++;
        else
            t[i-c] = t[i];
    }
    
    t[i-c] = '\0';
}
//13: Trunca cada palavra de uma string com no maximo n caracteres
void truncW (char t[], int n){
    int i,j,k;
    i = j = k = 0;

    while (t[i] != '\0'){
        if (t[i] == ' '){
            t[k] = t[i];
            k++; i++; j = 0;
        }

        else if (j < n){
            t[k] = t[i];
            k++; i++; j++;
        }

        else if (j >= n) 
            i++;
    }

    t[k] = '\0';
}
//14: calcula o caractere mais frequente numa string
int freq (char c, char s[]){
    int i,r=0;
    for (i = 0; s[i] != '\0'; i++)
        if (s[i]==c)
            r++;
    return r;
}

char charMaisfreq (char s[]) {
    char char_res = ' ';
    if (*s=='\0')
        return 0;
    else{
        int i;
        int aux = 0;
        int max = 0;
        for (i = 0; s[i] != '\0';i++){
            aux = freq (s[i],s);
            if (aux > max){
                max=aux;
                char_res =s[i];
            }
        }
    }
    return char_res;
}

//15: calcula o comprimento da maior sub-string com caracteres iguais
int iguaisConsecutivos (char s[]) {
    int i;
    int iguaisConsec=1;
    int maximo=0;

    for (i=0; s[i]!= '\0'; i++){
        if (s[i]==s[i+1])
            iguaisConsec++;
        else
            iguaisConsec = 1;
        
        if (iguaisConsec > maximo)
            maximo = iguaisConsec;
    }
    return maximo;
}

//16: calcula o comprimento da maior sub-string com caracteres diferentes /////////(A CORRIGIR)/////////
int difConsecutivos (char s[]) {
    int i;
    int difConsec=1;
    int maximo=0;

    for (i=0; s[i]!= '\0'; i++){
        if (s[i]!=s[i+1])
            difConsec++;
        else
            difConsec = 1;
        
        if (difConsec > maximo)
            maximo = difConsec;
    }
    return maximo;
}
//17: Calcula o maior prefixo comum entre as 2 strings
int maiorPrefixo(char s1[], char s2[]){
    int i = 0, r = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] == s2[i])
            r++;
        else
            break;
        i++;
    }
    return r;
}

//18: Calcula o maior sufixo comum entre 2 strings
int maiorSufixo(char s1[], char s2[]){
    int i, j, r = 0;

    i = strlen(s1) - 1;
    j = strlen(s2) - 1;
    while (i >= 0 && j >= 0){
        if (s1[i] == s2[j])
            r++;
        else
            break;
        i--; j--;
    }
    return r;
}

//19:Calcula o maior sufixo de s1 que é prefixo de s2
int sufPref(char s1[], char s2[]){
    int i, j = 0, r = 0;

    for (i = 0; s1[i] != '\0'; i++){
        if (s1[i] == s2[j]){
            r++; // numero de caracteres iguais
            j++; // percorre s2
        }
        else{ //caso contrario, volta tudo a 0 e avança um caracter em s1
            r = j = 0;
        }
    }

    return r;
}

//20: Conta o numero de palavras de uma string
int contaPal(char s[])
{
    int r = 0;
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != ' ' && s[i] != '\n' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
            r++;
    }

    return r;
}

//21: Conta o numero de vogais de uma string
int testaVogal(char c)
{
    return c == 'a' || c == 'A' ||
           c == 'e' || c == 'E' ||
           c == 'i' || c == 'I' ||
           c == 'o' || c == 'O' ||
           c == 'u' || c == 'U';
}

int contaVogais(char *s)
{
    int r = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (testaVogal(s[i]))
            r++;
    }
    return r;
}

//22: testa se todos os caracteres da primeira string tambem aparecem na segunda
int char_contido (char c, char s[]){
    int i;
    int bool = 0;
    
    for (i = 0; s[i] != '\0'; i++)
        if (c == s[i])
            bool = 1;
    
    return bool;
}


int contida (char a[], char b[]) {
    int i,bool = 1;
    for (i = 0; a[i] != '\0'; i++){
        if (!char_contido (a[i],b))
            bool = 0;
    }
    return bool;
}

//23: Verifica se uma string é palindroma (lê-se igual nos 2 sentidos)
int palindroma (char s[]) {
    int bool = 1;
    int i;
    int j=strlen (s)-1;
    for (i = 0; i < j; i++,j--)
        if (s[i] != s[j] )
            bool = 0;
    return bool;
}

//24: Remove caracteres repetidos consecutivos de uma string
int remRep (char texto []) {
    int i, r = 0;
    for (i=0; texto[i] != '\0'; i++){
        if (texto[i] != texto[i+1]){
            texto[r] = texto[i];  
            r++;
        }
    }
    texto[r]='\0';
    return r;
}
//25: Remove os espaços consecutivos, mantendo apenas um espaço
int limpaEspacos (char texto[]) {
    int r=0,i;
    
    for(i=0;texto[i]!='\0';i++)
        if(texto[i]!=' ' || 
          (texto[i]==' ' && texto [i+1]!=' ')){
            texto[r]=texto[i];                 
            r++;
          }
          
    texto[r] = '\0';
    return r;
}
//26: insere um elemento (x) num vector ordenado
void insere (int v[], int N, int x){
    int j;
    //Empurra-se todos os elementos para a frente até chegarmos à posiçao onde temos de inserir x
    for (j=N-1; j >= 0 && v[j] > x; j--){ // j = N-1 porque na posiçao N o array ja está ordenado (por ter apenas um elemento)
        v[j+1] = v[j];
    }
    v[j+1] = x;
}

//27:dados vectores ordenados a (com na elementos) e b (com nb elementos), preenche o vector r (com na+nb elementos) com os elementos de a e b ordenados
void merge (int r [], int a[], int b[], int na, int nb){
    int i=0;
    int j=0;
    int indice=0;
    while(i<na || j<nb){
        if(i==na){                   
            r[indice]=b[j];
            indice++; j++;
        }
        else if(j==nb){
            r[indice]=a[i];
            indice++; i++;
        }
        else if(a[i]<b[j]){
            r[indice]=a[i];
            indice++; i++;
        }
        else{
            r[indice]=b[j];
            indice++; j++;
        }
     }
}
//28: Testa se um array de inteiros está ordenado entre 2 indices
int crescente (int a[], int i, int j){
       int bool=1;
       for (; i < j; i++){            
           if (a[i] > a[i+1])
            bool=0;
       }
    return bool;
}

//29: Retira todos os elementos negativos, retornando o numero de elementos mantidos
int retiraNeg (int v[], int N){
    int i,j,r=0;
    int aux[N];
    
    for (i = 0; i < N; i++){
        if (v[i] >= 0){
            aux[r] = v[i];
            r++;
        }
    }
    
    for (j = 0; j < N; j++)
        v[j] = aux[j];
    
    return r;
}

//38:preenche o vector Ac com as somas acumuladas do vector v. 
//   Por exemplo, na posiçao Ac[3] deve ser calculado como v[0]+v[1]+v[2]+v[3]
void somasAc (int v[], int Ac [], int N){
   int i,soma = 0;
   for (i = 0; i < N; i++){
       soma += v[i];
       Ac[i] = soma;
   }
}

//39: Testa se uma matriz é triangular superior
int triSup (int N, int m [N][N]) {
    int i,j,bool = 1;
    for (i = 1; i < N; i++){
        for (j = 0; j < i; j++){
            if (m[i][j] != 0)
                bool = 0;
        }
    }
    return bool;
}

//40: Calcula a matriz transposta
void transposta (int N, float m [N][N]) {
    int i,j,aux;
    for (i = 0; i < N; i++){
        for (j = 0; j < i; j++){
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
}

//41: Soma 2 matrizes
void addTo(int N, int M, int a [N][M], int b[N][M]) {
    int i,j;
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            a[i][j]+=b[i][j];
        }
    }
}

//42: coloca no array r o resultado da uniao dos conjuntos v1 e v2
int unionSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for (i=0; i<N; i++){
        if (v1[i] > v2[i])
            r[i] = v1[i];
        else
            r[i] = v2[i];
    }
    return 0;
}

//43: coloca no array r o resultado da interseçao dos conjuntos v1 e v2
int intersectSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for (i=0; i<N; i++){
        if (v1[i] == v2[i])
            r[i] = v1[i];
        else
            r[i] = 0;
    }
    return 0;
}

//44: coloca no array r o resultado da interseção dos multi-conjuntos v1 e v2 
//{0,3,0,0,1,0,0,3} -> {1, 1, 1, 4, 7, 7, 7}
//{0,2,0,0,1,0,0,3} -> {1, 1   , 4, 7, 7, 7}

int intersectMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for (i=0;i<N;i++){
        if (v1[i]<v2[i]) //mete sempre o menor dos elementos
            r[i]=v1[i];                 
        else 
            r[i]=v2[i]; //restantes
        
    }
    return 0;
}

//45:coloca no array r o resultado da união dos multi-conjuntos v1 e v2
int unionMSet (int N, int v1[N], int v2[N], int r[N]){
    int i;
    for (i = 0; i < N; i++){
        if (v1[i] == v2[i])
            r[i] = v1[i]; //indiferente escolher v1 ou v2
        else if (v1[i] < v2[i])
            r[i] = v2[i]; //escolher o array maior
             else
                 r[i] = v1[i];
    }
    return 0;
}

//46:calcula a numero de elementos do multi-conjunto v
int cardinalMSet (int N, int v[N]){
    int i,c=0;
    for (i = 0; i < N; i++)
        c+=v[i];
    return c;
}

//47:dada uma posiçao inicial e um array com N movimentos, calcula a posiçao final do robot depois de efectuar essa sequencia de movimentos
typedef enum movimento {
    Norte, Oeste, Sul, Este
} Movimento;

typedef struct posicao {
    int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N){
    for (int i=0; i<N; i++){
        if (mov[i]==Norte)
            inicial.y +=1;
        else if (mov[i]==Sul)
            inicial.y -=1;
        else if (mov[i]==Oeste)
            inicial.x -=1;
        else 
            inicial.x +=1;
    }
    return inicial;
}

//48:dadas as posiçoes inicial e final do robot, preenche o array com os movimentos suficientes para que o robot passe de uma posiçao para a outra
typedef enum movimento {
    Norte, Oeste, Sul, Este
} Movimento;

typedef struct posicao {
    int x, y;
} Posicao;

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N){
    for (int i = 0; inicial.x != final.x || inicial.y != final.y; i++){
        if (inicial.y > final.y){
            inicial.y--;
            mov[i] = Sul;
        }
        else if (inicial.y < final.y){
            inicial.y++;
            mov[i] = Norte;
        }
        else if (inicial.x > final.x){
            inicial.x--;
            mov[i] = Oeste;
        }
        else{
            inicial.x++;
            mov[i] = Este;
        }
    }
    
    if (i>N) 
        return -1;
    else
        return i;
}

//49:dado um array com N posicoes, determina o ındice da posicao que esta mais perto da origem
typedef enum movimento {
    Norte, Oeste, Sul, Este
} Movimento;

typedef struct posicao {
    int x, y;
} Posicao;

int maiscentral (Posicao pos[], int N) {
    int r = 0;
    int distMin = (abs(pos[0].x) + abs(pos[0].y));
    
    for (int i=0; i<N; i++){
        if ((abs(pos[i].x) + abs(pos[i].y)) < distMin){
            distMin = (abs(pos[i].x) + abs(pos[i].y));
            r = i;
        }
    }
    
    return r;
}
//50:dada uma posicao e um array com N posicoes, calcula quantas dessas posicoes sao adjacentes a posicao dada
typedef enum movimento {
    Norte, Oeste, Sul, Este
} Movimento;

typedef struct posicao {
    int x, y;
} Posicao;

int vizinhos (Posicao p, Posicao pos[], int N) {
    int r=0;
    for (int i=0; i<N; i++)
        if ( abs(pos[i].x - p.x) + abs(pos[i].y - p.y) == 1)
            r++;
    return r;
}
