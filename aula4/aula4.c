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


int main (){
    char* s = "abcAbcgeFg";

    int r = contaVogais(s);
    printf("numero de vogais: %d\n", r);
    return 0;
}