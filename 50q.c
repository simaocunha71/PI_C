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

//16: calcula o comprimento da maior sub-string com caracteres iguais
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
