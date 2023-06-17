#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Insira o tamanho do vetor a ser lido: ");
    scanf("%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Insira o valor para a posição %d do vetor: ", i);
        scanf("%d", &v[i]);
    }
    int par = 0, impar = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] % 2 == 0)
        {
            ++par;
        }
        else
        {
            ++impar;
        }
    }
    printf("Qtd. de números pares: %d\n", par);
    printf("Qtd. de números ímpares: %d", impar);
}