#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *n = (int *)malloc(sizeof(int));
    printf("Insira o tamanho do vetor a ser lido: ");
    scanf("%d", n);
    int *v = (int *)malloc(*n * sizeof(int));
    for (int i = 0; i < *n; i++)
    {
        printf("Insira o valor para a posição %d do vetor: ", i);
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", v[i]);
    }
    free(n);
    free(v);
}