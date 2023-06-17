#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char modifica(char *palavra);

int main()
{
    int n;
    printf("Insira o tamanho da string a ser lida: ");
    scanf("%d", &n);
    char *string = (char *)malloc(n * sizeof(char));
    printf("Digite a string a ser lida: ");
    scanf("%s", &*string);
    printf("String sem as vogais: %s", modifica(string));
}

char modifica(char *palavra)
{
    char *aux = (char *)malloc(strlen(palavra) * sizeof(char));
    for (int i = 0; i < strlen(palavra); i++)
    {
        if (palavra[i] != 'a' &&
            palavra[i] != 'e' &&
            palavra[i] != 'i' &&
            palavra[i] != 'o' &&
            palavra[i] != 'u')
            ;
        {
            aux[i] = palavra[i];
        }
    }
    return *aux;
}