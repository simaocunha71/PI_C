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

